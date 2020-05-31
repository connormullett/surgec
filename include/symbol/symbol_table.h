
#pragma once

#include <string>
#include <unordered_map>

#include "parser/nodes.h"

using std::pair;
using std::string;
using std::unordered_map;

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

/*
todo : per scope symbol table and 
todo : chaining with procedures (functions)
*/

static class SymbolTable {
private:
    unordered_map<string, Symbol*> symbol_table;

public:
    void push_symbol(string key, Symbol* symbol);
    bool key_exists(string key);
    void drop_symbol(string key);
    Symbol* get_symbol(string key);

    ~SymbolTable();

} symbol_table;
