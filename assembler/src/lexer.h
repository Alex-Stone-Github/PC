#ifndef LEXER_HHH
#define LEXER_HHH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "token.h"

typedef struct Lexer {
    const char* const SOURCE;
    unsigned int index;
    Token* output;
    unsigned int outputIndex;
    size_t outputCapacity;
} Lexer;

Lexer createLexer(const char* src);
void advanceLexer(Lexer* lexer);
void parseLexer(Lexer* lexer);

#endif // LEXER_HHH
