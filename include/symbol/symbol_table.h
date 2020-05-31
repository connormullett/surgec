
#pragma once

#include <string>
#include <unordered_map>
#include "symbol/symbol.h"

#include "parser/nodes.h"

using std::pair;
using std::string;
using std::unordered_map;

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
