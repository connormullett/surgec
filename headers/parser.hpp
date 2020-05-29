
#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <iterator>

#include "lexem.hpp"
#include "syntax_tree.hpp"
#include "symbol.hpp"

class Parser {
private:
    std::vector<Lexem>* _tokens;
    std::vector<Lexem>::iterator _token_iter;
    SyntaxTree* AST;

    std::unordered_map<std::string, Symbol> sym_table;

    Symbol* try_get_symbol(std::string key);
    void push_symbol(Symbol symbol);

    AST_NODE* parse_statement(std::vector<Lexem>::iterator token);
    AST_NODE* parse_expression(std::vector<Lexem>::iterator token);
    AST_NODE* parse_int(std::vector<Lexem>::iterator token);
    AST_NODE* parse_function(std::vector<Lexem>::iterator token);
    AST_NODE* parse_identifier(std::vector<Lexem>::iterator token);
    AST_NODE* parse_program(std::vector<Lexem>::iterator token);

    void print_error_and_exit(std::string message, int status);

public:
    Parser(std::vector<Lexem>* tokens);
    ~Parser();
    
    void parse();

    SyntaxTree* get_ast();
    std::unordered_map<std::string, Symbol>* get_sym_table();
};