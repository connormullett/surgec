
#include "parser/nodes.h"
#include "parser/parser.h"
#include "error/error.h"
#include "lexer/tokens.h"

#include <iostream>

#include <vector>
using std::vector;
using std::cout;
using std::endl;



FunctionDeclaration* parse_function_declaration(vector<Token*>::iterator x) {
    return new FunctionDeclaration();
}


Program* parse_program(vector<Token*>::iterator tokens) {
    return new Program();
}


Statement* parse_statement(vector<Token*>::iterator tokens) {
    auto token = *(tokens);
    cout << token->getType() << endl;
    if (token->getType() != TokenType::RETURN) {
        print_error_and_exit( error{"expected return", 1} );
    }

    token = *(next(tokens));
    cout << token->getType() << endl;
    if (token->getType() != TokenType::INTEGER_LITERAL) {
        print_error_and_exit( error{"expected integer", 1} );
    }

    Expression* exp = parse_expression(tokens);
    auto statement = new Statement();
    statement->set_left(exp);

    token = *(next(tokens, 2));
    cout << token->getType() << endl;
    if (token->getType() != TokenType::SEMICOLON) {
        print_error_and_exit( error{"expected semicolon", 1} );
    }

    return statement;
}


Expression* parse_expression(vector<Token*>::iterator tokens) {
    return new Expression();
}



Node* create_ast(vector<Token*>::iterator tokens) {
    return parse_statement(tokens);
}

Node* parse(vector<Token*> tokens) {
    auto iter = tokens.begin();
    
    Node* root = create_ast(iter);

    return root;
}
