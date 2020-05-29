
#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

#include "lexem.hpp"


class Lexer {
    private:
        std::string fileName;
        std::string readFileToString();
        bool isNumber(std::string s);
        Lexem createLexem(int id, std::string symbol);

        std::vector<Lexem> t_lexems;

    public:
        Lexer(std::string filePath);
        void lex();
        void printLexems();
};
