
#include "lexer/lexeme.h"

#include <string>

Lexeme::Lexeme(int id, LexemeTypes type, std::string symbol) :
    id(id), type(type), symbol(symbol) { }


std::string Lexeme::to_string() {
    std::string type_str;
    if (type == LexemeTypes::IDENT) return "IDENT";
    if (type == LexemeTypes::INT_KEYW) return "INT_K";
    if (type == LexemeTypes::INT_LITERAL) return "INT_L";
    if (type == LexemeTypes::LBRACE) return "LBRAC";
    if (type == LexemeTypes::LPAREN) return "L_PAR";
    if (type == LexemeTypes::NEW_LINE) return "NEW_L";
    if (type == LexemeTypes::RET_KEYW) return "RET_K";
    if (type == LexemeTypes::RPAREN) return "R_PAR";
    if (type == LexemeTypes::RBRACE) return "RBRAC";
    if (type == LexemeTypes::SEMICOLON) return "SEMIC";
    if (type == LexemeTypes::ASSIGNMENT) return "ASSIG";
    if (type == LexemeTypes::NEGATION) return "NEGATE";
    if (type == LexemeTypes::BOOL_KEYW) return "BOOL_K";
    if (type == LexemeTypes::FALSE_VAL) return "false";
    if (type == LexemeTypes::TRUE_VAL) return "true";
    return "NULL_T";
}
