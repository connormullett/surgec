
#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "lexem.hpp"
#include "syntax_tree.hpp"
#include "types.hpp"

class Parser {
private:
    std::vector<Lexem> _tokens;
    SyntaxTree* AST;

    // stores identifier data where key = Symbol->name
    std::unordered_map<std::string, Symbol> symTable;

public:
    Parser(std::vector<Lexem> tokens);
    ~Parser();

    void parse();

    SyntaxTree* getAST();
};