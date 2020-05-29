
#include "../headers/syntax_tree.hpp"

SyntaxTree::SyntaxTree(std::vector<Lexem>* tokens) {
    _tokens = tokens;
}

SyntaxTree::~SyntaxTree() {
    delete _root;
}
