#ifndef LEXER_HHH
#define LEXER_HHH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "token.h"

typedef struct Lexer {
    const char* const SOURCE;
    unsigned int index;
    Token* tokens;
    unsigned int outputIndex;
    size_t outputCapacity;
} Lexer;

Lexer createLexer(const char* src);
void advanceLexer(Lexer* lexer);
void parseLexer(Lexer* lexer);
void destroyLexer(Lexer* lexer);
void appendToken(Lexer* lexer, Token t);

#endif // LEXER_HHH
