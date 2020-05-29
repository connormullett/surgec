
#pragma once

#include "enums.hpp"
#include <string>

class Lexem {
    public:
        int id;
        LexemTypes type;
        std::string symbol;
        
        Lexem(int id, LexemTypes type, std::string symbol);

        Lexem() = default;

        std::string to_string();
};