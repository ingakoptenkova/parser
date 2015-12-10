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

        [state7][IF] = state8,
        [state8][LITERAL] = state9,
        [state9][DOT] = state8,

        [state9][EQUAL] = state8,

        [state9][LPAREN] = state10,
        [state10][LITERAL] = state11,
        [state11][RPAREN] = state12,

        [state12][THEN] = state14,
        [state14][LITERAL] = state15,
        [state15][ASSIGN] = state16,
        [state16][LITERAL] = state17,
        [state16][NUMBER] = state17,

        [state17][PLUS] = state16,

        [state17][SEMI] = final,

//        // left
//        [state2][NIL] = state3,
//        [state3][NOT_EQUAL] = state7,
//        [state3][EQUAL] = state7,
//
//        [state2][LITERAL] = state4,
//        [state4][DOT] = state6,
//        [state4][POINTER] = state5,
//        [state4][EQUAL] = state7,
//        [state4][NOT_EQUAL] = state7,
//        [state5][DOT] = state6,
//        [state6][LITERAL] = state4,
//
//        // right
//        [state7][NIL] = state8,
//        [state7][LITERAL] = state9,
//        [state9][DOT] = state12,
//        [state9][POINTER] = state11,
//        [state9][DO] = state13,
//        [state10][POINTER] = state11,
//        [state11][DOT] = state12,
//        [state12][LITERAL] = state9,
//
//        [state8][DO] = state13,
//        [state13][BEGIN] = state14,
//        [state13][IF] = state14,
//
//
//        [state4][NIL] = state5,
//        [state4][LITERAL] = state5,
//        [state5][DO] = state6,
//        [state6][BEGIN] = state7,
//        [state7][IF] = state7,
//
//
//
////        [final][WHILE] = final,
////        [final][WHILE] = final,
////        [final][WHILE] = final,
////        [final][WHILE] = final,
        [final][WHILE] = final
};

void parse(FILE *fp, char *token, size_t size);

#endif //LEXICA_PARSER_H
