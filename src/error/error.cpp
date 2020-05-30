
#include "error/error.h"

void print_error_and_exit(error error) {
    cout << error.message << endl;
    std::exit( error.exit_code );
}