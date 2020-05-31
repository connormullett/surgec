
#include "symbol/symbol_table.h"


using std::pair;
using std::string;
using std::unordered_map;


Symbol::Symbol(SymbolType type) {
    _type = type;
}

SymbolType Symbol::get_type() {
    return _type;
}


void SymbolTable::push_symbol(string key, Symbol symbol) {

}

bool SymbolTable::key_exists(string key) {

}

Symbol SymbolTable::get_symbol(string key) {
    
}
