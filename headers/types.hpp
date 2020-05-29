
#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "enums.hpp"
#include "enums.hpp"

#define INT_MAX 2147483647
#define INT_MIN -2147483647 - 1

typedef struct Symbol {
    std::string name;
    SymbolType type;
    std::string attribute;
    Scope scope;
} Symbol;
