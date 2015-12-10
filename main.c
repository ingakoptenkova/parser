#include <stdio.h>
#include <stdlib.h>
#include "src/parser.h"

int main() {
    char token[20];

    FILE *fp = fopen("c:\\users\\inga\\git\\lexica\\example.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error in opening file\n");
        exit(EXIT_FAILURE);
    }

    parse(fp, token, sizeof(token));

    fclose(fp);

    return EXIT_SUCCESS;
}