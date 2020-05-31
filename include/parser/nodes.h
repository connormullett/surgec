
#pragma once


enum NodeType {
    PROGRAM,
    FUNCTION_DECLARATION,
    STATEMENT,
    EXPRESSION
};  


class Node {
protected:
    NodeType type;
    Node* left_child;
    Node* right_child;

public:
    Node* get_left();
    Node* get_right();

    void set_left(Node* node);
    void set_right(Node* node);

    NodeType get_type();

    ~Node();
};


class Program : public Node {
public:
    Program();
};


class FunctionDeclaration : public Node {
public:
    FunctionDeclaration();
};


class Statement : public Node {
public:
    Statement();
};


class Expression : public Node {
public:
    Expression();
};
