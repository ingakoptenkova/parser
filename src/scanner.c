#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int safe_assign(char *token, size_t size, int c, int *i) {
    if ((*i + 1) < size) {
        *(token + (*i)++) = c;
    } else {
        fprintf(stderr, "Error: token char array is too small!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int assign(TokenType type, char *token, TokenType *tokenType, size_t size, int c, int *i) {
    *tokenType = type;
    return safe_assign(token, size, c, i);
}

void process_operator(FILE *fp, char *token, TokenType *tokenType, size_t size, int c, int *i) {
    switch (c) {
        case '.':
            assign(DOT, token, tokenType, size, c, i);
            break;
        case '/':
            assign(SLASH, token, tokenType, size, c, i);
            break;
        case '^':
            assign(POINTER, token, tokenType, size, c, i);
            break;
        case '+':
            assign(PLUS, token, tokenType, size, c, i);
            break;
        case ')':
            assign(RPAREN, token, tokenType, size, c, i);
            break;
        case '(':
            assign(LPAREN, token, tokenType, size, c, i);
            break;
        case '=':
            assign(EQUAL, token, tokenType, size, c, i);
            break;
        case '<':
            assign(LT, token, tokenType, size, c, i);
            c = fgetc(fp);
            if (c == '>') {
                assign(NOT_EQUAL, token, tokenType, size, c, i);
            } else {
                ungetc(c, fp);
            }
            break;
        case '>':
            assign(GT, token, tokenType, size, c, i);
            break;
        case ':':
            assign(COLON, token, tokenType, size, c, i);
            c = fgetc(fp);
            if (c == '=') {
                assign(ASSIGN, token, tokenType, size, c, i);
            } else {
                ungetc(c, fp);
            }
            break;
        case ';':
            assign(SEMI, token, tokenType, size, c, i);
            break;
        default:
            fprintf(stderr, "Unsupported punctuation character [%c]\n", c);
            break;
    }
}

int process_alpha_token(FILE *fp, char *token, TokenType *tokenType, size_t size, int c, int *i) {
    do {
        if (safe_assign(token, size, c, i)) {
            return EXIT_FAILURE;
        }
        c = fgetc(fp);
    } while (isalnum(c));
    ungetc(c, fp);
    *tokenType = LITERAL;

    return EXIT_SUCCESS;
}


int process_number_token(FILE *fp, char *token, TokenType *tokenType, size_t size, int c, int *i) {
    do {
        if (safe_assign(token, size, c, i)) {
            return EXIT_FAILURE;
        }
        c = fgetc(fp);
    } while (isdigit(c));
    ungetc(c, fp);
    *tokenType = NUMBER;

    return EXIT_SUCCESS;
}

// BEZ UCHETA REGISTRA SRAVNENIE MASSIVOV
int strcicmp(char const *a, char const *b) {
    for (; ; a++, b++) {
        int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
            return d;
    }
}

const char *TokenTypeString[] = {
        "NUMBER",
        "LITERAL",
        "ASSIGN",
        "NOT_EQUAL",
        "EQUAL",
        "POINTER",
        "DOT",
        "LPAREN",
        "RPAREN",
        "PLUS",
        "SLASH",
        "LT",
        "GT",
        "COLON",
        "SEMI",
        "IF",
        "THEN",
        "WHILE",
        "DO",
        "BEGIN",
        "END",
        "NIL"
};

void scan(FILE *fp, char *token, size_t size) {
    TokenType type;
    while (get_token(fp, token, &type, size) != EOF) {
        fprintf(stdout, "Token - %15s, Type - %10s\n", token, TokenTypeString[type]);
    }
}

const char* to_str(TokenType tokenType) {
    return TokenTypeString[tokenType];
}

int get_token(FILE *fp, char *token, TokenType *tokenType, size_t size) {
    int i = 0;

    int c;
    do {
        c = fgetc(fp);
    } while (isspace(c));

    if (isdigit(c)) {
        process_number_token(fp, token, tokenType, size, c, &i);
    } else if (isalpha(c)) {
        process_alpha_token(fp, token, tokenType, size, c, &i);
    } else if (ispunct(c)) {
        process_operator(fp, token, tokenType, size, c, &i);
    } else if (c == EOF) {
        return EOF;
    }

    *(token + i) = '\0';

    if (*tokenType == LITERAL) {
        for (int j = 0; j < sizeof(keywords) / sizeof(keywords[0]); j++) {
            if (!strcicmp(keywords[j].token, token)) {
                *tokenType = keywords[j].tokenType;
                break;
            }
        }
    }

    return 0;
}


