
#pragma once

#include <string>
#include <vector>
#include "lexer/tokens.h"

std::vector<std::string> explode(std::string input);
void create_token(vector<Token*>* tokens, string s);

std::vector<Token*> lex(std::string source);
std::string read_file_to_string(std::string filename);
