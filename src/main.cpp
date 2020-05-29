
#include "../headers/lex.hpp"
#include "../headers/parser.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "not enough arguments" << endl;
        return 1;
    }

    Lexer lexer(argv[1]);
    lexer.lex();
    lexer.print_lexems();

    Parser parser(lexer.get_lexems());

    return 0;
}
