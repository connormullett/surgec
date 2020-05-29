
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

    // stores identifier data where key = Symbol->name
    std::unordered_map<std::string, Symbol> sym_table;

    Symbol* try_get_symbol(std::string key);
    void push_symbol(Symbol symbol);

    AST_NODE* parse_statement();

public:
    Parser(std::vector<Lexem>* tokens);
    ~Parser();

    void parse();

    SyntaxTree* get_ast();
    std::unordered_map<std::string, Symbol>* get_sym_table();
};