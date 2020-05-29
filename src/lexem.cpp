
#include "../headers/lexem.hpp"

#include <string>

Lexem::Lexem(int id, LexemTypes type, std::string symbol) :
    id(id), type(type), symbol(symbol) { }


std::string Lexem::to_string() {
    std::string type_str;
    if (type == LexemTypes::IDENT) return "IDENT";
    if (type == LexemTypes::INT_KEYW) return "INT_K";
    if (type == LexemTypes::INT_LITERAL) return "INT_L";
    if (type == LexemTypes::LBRACE) return "LBRAC";
    if (type == LexemTypes::LPAREN) return "L_PAR";
    if (type == LexemTypes::NEW_LINE) return "NEW_L";
    if (type == LexemTypes::RET_KEYW) return "RET_K";
    if (type == LexemTypes::RPAREN) return "R_PAR";
    if (type == LexemTypes::RBRACE) return "RBRAC";
    if (type == LexemTypes::SEMICOLON) return "SEMIC";
    if (type == LexemTypes::ASSIGNMENT) return "ASSIG";
    if (type == LexemTypes::NEGATION) return "NEGATE";
    if (type == LexemTypes::BOOL_KEYW) return "BOOL_K";
    if (type == LexemTypes::FALSE_VAL) return "false";
    if (type == LexemTypes::TRUE_VAL) return "true";
    return "NULL_T";
}
