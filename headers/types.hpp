#ifndef __LEX_TYPES_H
#define __LEX_TYPES_H

#include <string>
#include <vector>
#include <unordered_map>

#include "enums.hpp"

class Lexem {
    public:
        int id;
        LexemTypes type;
        std::string symbol;
        
        Lexem(int id, LexemTypes type, std::string symbol);

        Lexem() { }

        std::string toString();
};

#define INT_MAX 2147483647
#define INT_MIN -2147483647 - 1


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


typedef struct Symbol {
    std::string name;
    SymbolType type;
    std::string attribute;
    Scope scope;
} Symbol;


class SyntaxTree {
private:
    AST_NODE _root;
    unsigned int _size;
    std::vector<Lexem> _tokens;

public:
    SyntaxTree(std::vector<Lexem> tokens);
    ~SyntaxTree();
};

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

#endif
