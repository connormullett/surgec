
#include "symbol/symbol_table.h"
#include "symbol/symbol.h"
#include "parser/nodes.h"

#include <string>
#include <unordered_map>

using std::pair;
using std::string;
using std::unordered_map;


void SymbolTable::push_symbol(string key, Symbol* symbol) {
    symbol_table.insert( std::make_pair(key, symbol) );
}

bool SymbolTable::key_exists(string key) {
    if (symbol_table.find(key) != symbol_table.end()) return true;
    else return false;
}

Symbol* SymbolTable::get_symbol(string key) {
    return symbol_table.at(key);
}

void SymbolTable::drop_symbol(string key) {
    symbol_table.erase(key);
}

SymbolTable::~SymbolTable() {
    symbol_table.clear();
}
