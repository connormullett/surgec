
#include "../headers/lex.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "not enough arguments" << endl;
        return 1;
    }

    Lexer lexer(argv[1]);
    lexer.lex();
    return 0;
}
