
#pragma once

#include <string>
#include <unordered_map>

using std::pair;
using std::string;
using std::unordered_map;

enum SymbolType {
    FunctionDeclaration,
    IntVariable
};

class Symbol {
private:
    SymbolType _type;

public: 
    Symbol(SymbolType type);
    SymbolType get_type();

};


static class SymbolTable {
private:
    unordered_map<string, Symbol> symbol_table;

public:
    void push_symbol(string key, Symbol symbol);
    bool key_exists(string key);

    Symbol get_symbol(string key);

} symbol_table;
