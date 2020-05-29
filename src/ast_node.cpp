
#include "../headers/ast_node.hpp"


AST_NODE::AST_NODE(LexemTypes tokType, NodeType nodeType, Lexem* token,
        int* integer_value, std::string string_literal, 
        std::string operation, AST_NODE* left_child, AST_NODE* right_child) {
}

AST_NODE::~AST_NODE() {
    delete _token;
    delete _integer_literal;
    delete _left_child;
    delete _right_child;
}
