
#pragma once

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

enum NodeType {
    CONST,
    EXPRES,
    FUNC_DECL,
    PROG,
    STATEM,
    INT_LIT,
};

enum Scope {
    FUNCT_PARAM,
    GLOBAL,
    BLOCK_LOC,
};

enum SymbolType {
    INT,
    FUNCTION,
    STRING,
};
