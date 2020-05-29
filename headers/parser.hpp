
#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <iterator>

#include "lexeme.hpp"

class Parser {
private:
    std::vector<Lexeme>* _tokens;
    std::vector<Lexeme>::iterator _token_iter;
    
    void print_error_and_exit(std::string message, int status);

public:
    Parser(std::vector<Lexeme>* tokens);
    ~Parser();

    void parse();
};