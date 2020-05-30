
#pragma once

#include <string>

using namespace std;

enum TokenType {
    INT_KEYW,
    IDENT,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RETURN,
    INTEGER_LITERAL,
    SEMICOLON,
    RIGHT_BRACE,
};

class Token {
protected:
    TokenType type;

    friend ostream & operator << (ostream &out, const Token &c);
public:
    TokenType getType();
};


class Int : public Token {
    friend ostream & operator << (ostream &out, const Int &c);

public:
    Int();
};


class Identifier : public Token {
private:
    string symbol;

public:
    Identifier(string s);
    void setSymbol(string value);
    string getSymbol();
    friend ostream & operator << (ostream &out, const Identifier &c);
};


class LeftParenthesis : public Token {
    friend ostream & operator << (ostream &out, const LeftParenthesis &c);

public:
    LeftParenthesis();
};


class RightParenthesis : public Token {
    friend ostream & operator << (ostream &out, const RightParenthesis &c);

public:
    RightParenthesis();
};


class LeftBrace : public Token {
public:
    LeftBrace();
    friend ostream & operator << (ostream &out, const LeftBrace &c);
};


class RightBrace : public Token {
public:
    RightBrace();
    friend ostream & operator << (ostream &out, const RightBrace &c);
};


class Return : public Token {
public:
    Return();
    friend ostream & operator << (ostream &out, const Return &c);
};


class IntegerLiteral : public Token {
private:
    int value;

public:
    IntegerLiteral(int x);
    void setValue(int x);
    int getValue();
    friend ostream & operator << (ostream &out, const IntegerLiteral &c);
};


class Semicolon : public Token {
public:
    Semicolon();
    friend ostream & operator << (ostream &out, const Semicolon &c);
};
