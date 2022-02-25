#include "lexer.h"

Lexer createLexer(const char* src) {
    const int startingCap = 200;
    Lexer l = (Lexer){src, 0, 0, 0, startingCap};
    l.tokens = malloc(sizeof(Token) * startingCap);
}
void advanceLexer(Lexer* lexer) {
    lexer->index++;
}
void parseLexer(Lexer* lexer) {
    char current = lexer.SOURCE[lexer->index];
    while (current != NULL) {
        if (current == ' ')
            goto ADVANCE;
        if (current == '\n')
            goto ADVANCE;
        if (current == '\r')
            goto ADVANCE;
        if (current == ';') {
            Token t;
            t.type = ENDLINE;
            t.value = 0;
            appendToken(lexer, t);
            goto ADVANCE;
        }
ADVANCE:
        advanceLexer(lexer);
        current = lexer.SOURCE[lexer->index];
    }
}
void destroyLexer(Lexer* lexer) {
    free(lexer->tokens);
}
void appendToken(Lexer* lexer, Token t) {
    lexer->tokens[lexer->outputIndex] = t;
    if (lexer->outputCapacity - outputIndex < 5) {
        lexer->outputCapacity *= 2;
        lexer->tokens = realloc(lexer->tokens, lexer->outputCapacity);
    }
}


