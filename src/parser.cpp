
#include "../headers/parser.hpp"
#include "../headers/lexem.hpp"

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

Parser::Parser(std::vector<Lexem>* tokens) {
    _tokens = tokens;
}

Parser::~Parser() {
    delete AST;
    delete _tokens;
}

SyntaxTree* Parser::get_ast() {
    return AST;
}

std::unordered_map<std::string, Symbol>* Parser::get_sym_table() {
    return &sym_table;
}

Symbol* Parser::try_get_symbol(std::string key) {
    auto got = sym_table.find(key);
    if (got != sym_table.end())
        return &got->second;
    else return nullptr;
}

void Parser::push_symbol(Symbol symbol) {
    std::pair<std::string, Symbol> tmp (symbol.name, symbol);
    sym_table.insert(tmp);
}

void Parser::parse() {

}
