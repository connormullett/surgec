
#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

#include "lexeme.h"


class Lexer {
    private:
        std::string fileName;
        std::string read_file_to_string();
        bool is_number(std::string s);
        Lexeme create_lexeme(int id, std::string symbol);

        std::vector<Lexeme> t_lexems;

    public:
        Lexer(std::string filePath);
        void lex();
        std::vector<Lexeme>* get_lexems();
        void print_lexems();
};
