
#pragma once

#include "parser/nodes.h"
#include <string>

using std::string;

enum SymbolType {
    FunctionDeclaration,
    IntVariable
};

class Symbol {
protected:
    SymbolType _type;
    string identifier;

public: 
    Symbol(string ident);
    SymbolType get_type();
    string get_identifier();
};

class IntegerSymbol : public Symbol {
private:
    int _value;

public:
    IntegerSymbol(string identifier, int value);
    int get_value();
};

class FunctionSymbol : public Symbol {
private:
    FunctionSymbol(string identifier, Node* body);
};