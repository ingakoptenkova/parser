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
   /* state13,
    state14,
    state15,
    state16,
    state17*/
} State;

static State states[30][30] = {
       /* if Tmp.Num = StrToInt(S) then
        i := i+1;*/

        [state1][IF] = state2,
        [state2][LITERAL] = state3,

        [state3][DOT] = state2,
        [state3][EQUAL] = state2,
        [state3][LPAREN] = state4,

        [state4][LITERAL] = state5,

        [state5][RPAREN] = state6,

        [state6][THEN] = state7,

        [state7][LITERAL] = state8,

        [state8][ASSIGN] = state9,

        [state9][LITERAL] = state10,

        [state10][PLUS] = state11,

        [state11][NUMBER] = state12,

        [state12][SEMI] = state1

};

void parse(FILE *fp, char *token, size_t size);

#endif //LEXICA_PARSER_H
