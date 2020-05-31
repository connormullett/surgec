
# pragma once

#include "parser/nodes.h"
#include "lexer/tokens.h"

#include <vector>
using std::vector;


FunctionDeclaration* parse_function_declaration(vector<Token>::iterator x);

Program* parse_program(vector<Token*>::iterator tokens);

Statement* parse_statement(vector<Token*>::iterator tokens);

Expression* parse_expression(vector<Token*>::iterator tokens);


Node* create_ast(vector<Token*>::iterator tokens);

Node* parse(vector<Token*> tokens);
