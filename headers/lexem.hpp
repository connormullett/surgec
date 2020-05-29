
#pragma once

#include "enums.hpp"

class Lexem {
    public:
        int id;
        LexemTypes type;
        std::string symbol;
        
        Lexem(int id, LexemTypes type, std::string symbol);

        Lexem() = default;

        std::string toString();
};