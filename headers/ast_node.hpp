
#pragma once

#include "lexem.hpp"

#include <string>

class AST_NODE {
public:
    LexemTypes _tok_type;
    NodeType _node_type;
    Lexem* _token;
    int* _integer_literal;
    std::string _string_literal;
    std::string _operation;
    AST_NODE* _left_child;
    AST_NODE* _right_child;

    AST_NODE(LexemTypes tok_type, NodeType node_type, Lexem* token,
        int* integer_literal, std::string string_literal, 
        std::string operation, AST_NODE* left_child, AST_NODE* right_child);
    ~AST_NODE();
};