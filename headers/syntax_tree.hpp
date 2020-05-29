
#pragma once

#include <vector>

#include "ast_node.hpp"
#include "lexem.hpp"

class SyntaxTree {
private:
    AST_NODE* _root;
    unsigned int _size;
    std::vector<Lexem>* _tokens;

public:
    SyntaxTree(std::vector<Lexem>* tokens);
    ~SyntaxTree();
};