
#include "symbol/symbol_table.h"


using std::pair;
using std::string;
using std::unordered_map;


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
