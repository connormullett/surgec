
#include "symbol/symbol.h"
#include <string>

using std::string;


Symbol::Symbol(string ident) {
    identifier = ident;
}

SymbolType Symbol::get_type() {
    return _type;
}

string Symbol::get_identifier() {
    return identifier;
}


IntegerSymbol::IntegerSymbol(string identifier, int value) :
    Symbol(identifier)
{
    _type = SymbolType::IntVariable;
}

int IntegerSymbol::get_value() {
    return _value;
}


FunctionSymbol::FunctionSymbol(string identifier, Node* body) :
    Symbol(identifier)
{
    _type = SymbolType::FunctionDeclaration;
}