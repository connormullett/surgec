
#pragma once

#include "enums.h"
#include <string>

class Lexeme {
    public:
        int id;
        LexemeTypes type;
        std::string symbol;
        
        Lexeme(int id, LexemeTypes type, std::string symbol);

        Lexeme() = default;

        std::string to_string();
};