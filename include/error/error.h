
#pragma once

#include <string>
#include <iostream>

typedef struct error {
    std::string message;
    int exit_code;
} error;

void print_error_and_exit(error error);
