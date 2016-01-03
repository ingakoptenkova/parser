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
        [state2][ID] = state3,

        [state3][DELIM] = state2,
        [state3][DELIM] = state2,
        [state3][DELIM] = state4,

        [state4][ID] = state5,

        [state5][DELIM] = state6,

        [state6][THEN] = state7,
        [state6][ID] = state5,

        [state7][ID] = state8,

        [state8][DELIM2] = state9,

        [state9][ID] = state10,

        [state10][DELIM] = state11,

        [state11][INT] = state12,

        [state12][DELIM] = state1

};

void parse(FILE *fp, char *token, size_t size);

#endif //LEXICA_PARSER_H
