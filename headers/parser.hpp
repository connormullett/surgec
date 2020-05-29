
#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <iterator>

#include "lexem.hpp"

class Parser {
private:
    std::vector<Lexem>* _tokens;
    std::vector<Lexem>::iterator _token_iter;
    
    void print_error_and_exit(std::string message, int status);

public:
    Parser(std::vector<Lexem>* tokens);
    ~Parser();

    void parse();
};