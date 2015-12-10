#include <stdio.h>
#include "parser.h"

void parse(FILE *fp, char *token, size_t size) {
    int result;
    TokenType tokenType;

    State state = state1, next;
    do {
        result = get_token(fp, token, &tokenType, size);
        if (result == EOF) {
            break;
        }
        next = states[state][tokenType];
        if (next == 0) {
            fprintf(stderr, "Error: current state = %3d, tokenType = %10s, next state = %3d\n", state, to_str(tokenType), next);
            break;
        }
        fprintf(stdout, "current state = %3d, tokenType = %10s, (%s) next state = %3d\n", state, to_str(tokenType), token, next);
        state = next;
    } while (1);
}