
#include "lexer/tokens.h"


TokenType Token::getType() {
    return type;
}


ostream & operator << (ostream &out, const Token &c) {
    out << string("token");
    return out;
}


Identifier::Identifier(string s) : symbol(s) {
    type = TokenType::IDENT;
}

string Identifier::getSymbol() {
    return symbol;
}

ostream & operator << (ostream &out, const Identifier &c) {
    out << c.symbol;
    return out;
}

Int::Int() {
    type = TokenType::INT_KEYW;
}


LeftParenthesis::LeftParenthesis() {
    type = TokenType::LEFT_PAREN;
}


RightParenthesis::RightParenthesis() {
    type = TokenType::RIGHT_PAREN;
}


LeftBrace::LeftBrace() {
    type = TokenType::LEFT_BRACE;
}


RightBrace::RightBrace() {
    type = TokenType::RIGHT_BRACE;
}


Return::Return() {
    type = TokenType::RETURN;
}


IntegerLiteral::IntegerLiteral(int x) {
    type = TokenType::INTEGER_LITERAL;
    value = x;
}


Semicolon::Semicolon() {
    type = TokenType::SEMICOLON;
}
