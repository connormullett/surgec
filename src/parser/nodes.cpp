
#include "parser/nodes.h"


#pragma region Node
Node::~Node() {
    delete left_child;
    delete right_child;
}

Node* Node::get_left() {
    return left_child;
}

Node* Node::get_right() {
    return right_child;
}

void Node::set_left(Node* node) {
    left_child = node;
}

void Node::set_right(Node* node) {
    right_child = node;
}


Program::Program() {
    type = NodeType::PROGRAM;
}
#pragma endregion


FunctionDeclaration::FunctionDeclaration() {
    type = NodeType::FUNCTION_DECLARATION;
}


Statement::Statement() {
    type = NodeType::STATEMENT;
}


Expression::Expression() {
    type = NodeType::EXPRESSION;
}
