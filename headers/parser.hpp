
#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "lexem.hpp"
#include "syntax_tree.hpp"
#include "symbol.hpp"

class Parser {
private:
    std::vector<Lexem>* _tokens;
    SyntaxTree* AST;

    std::unordered_map<std::string, Symbol> sym_table;

    Symbol* try_get_symbol(std::string key);
    void push_symbol(Symbol symbol);

    AST_NODE* parse_statement();
    AST_NODE* parse_expression();
    AST_NODE* parse_int();
    AST_NODE* parse_function();
    AST_NODE* parse_identifier();
    AST_NODE* parse_program();

public:
    Parser(std::vector<Lexem>* tokens);
    ~Parser();

    void parse();

    SyntaxTree* get_ast();
    std::unordered_map<std::string, Symbol>* get_sym_table();
};