
# pragma once

#include "parser/nodes.h"
#include "lexer/tokens.h"

#include <vector>
using std::vector;


bool check_function_declaration(vector<Token*>::iterator tokens);
FunctionDeclaration* parse_function_declaration(vector<Token>::iterator x);

bool check_program(vector<Token*>::iterator tokens);
Program* parse_program(vector<Token*>::iterator tokens);

bool check_statement(vector<Token*>::iterator tokens);
Statement* parse_statement(vector<Token*>::iterator tokens);

bool check_expression(vector<Token*>::iterator tokens);
Expression* parse_expression(vector<Token*>::iterator tokens);


Node* parse_nodes(vector<Token*>::iterator tokens);

Node* parse(vector<Token*> tokens);
