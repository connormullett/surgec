
#include "lexer/lexer.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "not enough arguments" << endl;
        return 1;
    }

    string source = read_file_to_string(argv[1]);
    auto tokens = lex(source);

    for (auto t : tokens) {
        cout << t->getType() << endl;
    }

    tokens.push_back( new Token() );

    return 0;
}
