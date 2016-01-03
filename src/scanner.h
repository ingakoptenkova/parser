#ifndef LEXICA_SCANNER_H
#define LEXICA_SCANNER_H

typedef enum {
    INT,
    ID,
    DELIM,
    DELIM2,

    IF,
    THEN,
    WHILE,
    DO,
    BEGIN,
    END,
    NIL
} TokenType;

typedef struct {
    TokenType tokenType;
    char token[20];
} Keyword;


static Keyword keywords[] = {
        {IF,    "if"},
        {THEN,  "then"},
        {WHILE, "while"},
        {DO,    "do"},
        {BEGIN, "begin"},
        {END,   "end"},
        {NIL,   "nil"},
};

int get_token(FILE *fp, char *token, TokenType *tokenType, size_t size);

const char* to_str(TokenType tokenType);

void scan(FILE *fp, char *token, size_t size);

#endif // LEXICA_SCANNER_H
