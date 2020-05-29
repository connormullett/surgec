
#include "../headers/parser.hpp"
#include "../headers/lexem.hpp"

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <iostream>


Parser::Parser(std::vector<Lexem>* tokens) {
    _tokens = tokens;
    _token_iter = tokens->begin();
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

AST_NODE* Parser::parse_statement(std::vector<Lexem>::iterator token) {
    if (token->type != LexemTypes::RET_KEYW) {
        print_error_and_exit("expected return statement", EXIT_FAILURE);
    }
    token = std::next(token);
    if (token->type != LexemTypes::INT_LITERAL)
        print_error_and_exit("expected int literal", EXIT_FAILURE);

    return nullptr;
}

void Parser::parse() {
    // create program root and pass first token to right function
}

void Parser::print_error_and_exit(std::string message, int status) {
    std::cout << message << std::endl;
    exit(status);
}
