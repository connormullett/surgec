
#pragma once

class AST_NODE {
public:
    LexemTypes _tokType;
    NodeType _nodeType;
    Lexem* _token;
    int* _integerValue;
    std::string _stringLiteralValue;
    std::string _operation;
    AST_NODE* _leftChild;
    AST_NODE* _rightChild;

    AST_NODE(LexemTypes tokType, NodeType nodeType, Lexem* token,
        int* integerValue, std::string stringLiteralValue, 
        std::string operation, AST_NODE* leftChild, AST_NODE* rightChild);
    ~AST_NODE();
};