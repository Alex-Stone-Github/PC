#include "lexer.h"

Lexer createLexer(const char* src) {
    return (Lexer){src, -1, &NULL, 0, 0};
    // nullptr I think I don't cpp
}
void advanceLexer(Lexer* lexer) {
    lexer->index++;
}
void parseLexer(Lexer* lexer) {
    char current = lexer.SOURCE[lexer->index];
    while (current != NULL) {
        //
    }
}


