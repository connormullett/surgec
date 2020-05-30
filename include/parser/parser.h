
# pragma once

#include "parser/nodes.h"
#include "lexer/tokens.h"

#include <vector>
using std::vector;


typedef vector<Token*> token_vec;


bool check_function_declaration(token_vec tokens);
FunctionDeclaration* parse_function_declaration(vector<Token> x);

bool check_program(token_vec tokens);
Program* parse_program(token_vec tokens);

bool check_statement(token_vec tokens);
Statement* parse_statement(token_vec tokens);

bool check_expression(token_vec tokens);
Expression* parse_expression(token_vec tokens);


Node* parse(token_vec tokens);
