
#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

#include "lexem.hpp"


class Lexer {
    private:
        std::string fileName;
        std::string read_file_to_string();
        bool is_number(std::string s);
        Lexem create_lexem(int id, std::string symbol);

        std::vector<Lexem> t_lexems;

    public:
        Lexer(std::string filePath);
        void lex();
        std::vector<Lexem>* get_lexems();
        void print_lexems();
};
