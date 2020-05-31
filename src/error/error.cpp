
#include "error/error.h"

#include <string>
#include <iostream>

void print_error_and_exit(error error) {
    std::cout << error.message << std::endl;
    std::exit( error.exit_code );
}
