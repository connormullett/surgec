
#include "../headers/parser.hpp"
#include "../headers/lexem.hpp"

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <iostream>


Parser::Parser(std::vector<Lexem>* tokens) {
    _tokens = tokens;
    _token_iter = tokens->begin();
}

Parser::~Parser() {
    delete _tokens;
}

void Parser::parse() {
    // create program root and pass first token to right function
}

void Parser::print_error_and_exit(std::string message, int status) {
    std::cout << message << std::endl;
    exit(status);
}
