
#pragma once

#include <string>
#include "enums.hpp"


typedef struct Symbol {
    std::string name;
    SymbolType type;
    std::string attribute;
    Scope scope;
} Symbol;
