
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "parser/nodes.h"
#include "error/error.h"

#include <fstream>
#include <string>

using namespace std;

bool file_exists(const std::string& filename) {
    ifstream ifile(filename.c_str());
    return (bool)ifile;
}

int main(int argc, char *argv[]) {

    if (argc < 2) print_error_and_exit( error{"not enough arguments", 1} );

    if( !file_exists(argv[1]) )
        print_error_and_exit( error{"file not found", 1} );

    string source = read_file_to_string(argv[1]);
    auto tokens = lex(source);

    Node* tree_root = parse(tokens);

    tree_root->set_left( new Program() );
    
    print_error_and_exit( error{"done", 0} );
}
