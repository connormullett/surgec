
#include "parser/nodes.h"
#include "parser/parser.h"
#include "error/error.h"
#include "lexer/tokens.h"

#include <vector>
using std::vector;


typedef vector<Token*> token_vec;


bool check_function_declaration(token_vec tokens) {
    return true;
}

FunctionDeclaration* parse_function_declaration(vector<Token> x) {
    return new FunctionDeclaration();
}


bool check_program(token_vec tokens) {
    return true;
}

Program* parse_program(token_vec tokens) {
    return new Program();
}


bool check_statement(token_vec tokens) {
    return true;
}

Statement* parse_statement(token_vec tokens) {
    return new Statement();
}


bool check_expression(token_vec tokens) {
    return true;
}

Expression* parse_expression(token_vec tokens) {
    return new Expression();
}


Node* parse(token_vec tokens) {
    return new Node();
}
