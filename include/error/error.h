
#pragma once

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

typedef struct error {
    string message;
    int exit_code;
} error;

void print_error_and_exit(error error);
