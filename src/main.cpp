
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "parser/nodes.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "not enough arguments" << endl;
        return 1;
    }

    string source = read_file_to_string(argv[1]);
    auto tokens = lex(source);

    Node* tree_root = parse(tokens);

    tree_root->set_left( new Program() );
    
    return 0;
}
