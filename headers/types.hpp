#ifndef __LEX_TYPES_H
#define __LEX_TYPES_H

#include <string>

enum LexemTypes {
    NEW_LINE,
    NULL_TOK,
    INT_KEYW,
    IDENT,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    RET_KEYW,
    INT_LITERAL,
    ASSIGNMENT,
    SEMICOLON,
    NEGATION,
    BOOL_KEYW,
    TRUE_VAL,
    FALSE_VAL,
};

class Lexem {
    public:
        int id;
        LexemTypes type;
        std::string symbol;
        
        Lexem(int id, LexemTypes type, std::string symbol);

        Lexem() { }

        std::string toString();
};

#endif
