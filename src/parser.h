#ifndef LEXICA_PARSER_H
#define LEXICA_PARSER_H

#include "scanner.h"

typedef enum {
    state1 = 1,
    state2,
    state3,
    state4,
    state5,
    state6,
    state7,
    state8,
    state9,
    state10,
    state11,
    state12,
    state13,
    state14,
    state15,
    state16,
    state17,
    state18,
    state19,
    final
} State;

static State states[30][30] = {
        [state1][WHILE] = state2,
        [state2][LITERAL] = state3,
        [state2][NIL] = state3,

        [state3][NOT_EQUAL] = state4,
        [state3][EQUAL] = state4,

        [state4][LITERAL] = state5,
        [state4][NIL] = state5,

        [state5][DO] = state6,
        [state6][BEGIN] = state7,
        [state6][LITERAL] = state13,

        [state7][IF] = state8,
        [state8][LITERAL] = state9,
        [state9][DOT] = state8,

        [state9][EQUAL] = state8,

        [state9][LPAREN] = state10,
        [state10][LITERAL] = state11,
        [state11][RPAREN] = state12,

        [state12][THEN] = state7,
        [state12][END] = state17,
        [state13][ASSIGN] = state14,
        [state13][DOT] = state6,
        [state14][LITERAL] = state15,
        [state15][POINTER] = state16,
        [state15][DOT] = state14,
        [state16][DOT] = state14,

        [state15][SEMI] = state6,
        [state15][PLUS] = state14,
        [state15][LITERAL] = state13,
        [state15][SLASH] = state14,
        [state15][END] = state17,

        [state15][LPAREN] = state10,

        [state14][NUMBER] = state17,
        [state17][SEMI] = state6,

//        [state18][LITERAL] = state17,

        [state7][LITERAL] = state13

//        [final][WHILE] = final
};

void parse(FILE *fp, char *token, size_t size);

#endif //LEXICA_PARSER_H
