
#include "lexer/lexer.h"
#include "lexer/tokens.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


vector<Token*> lex(string source) {
    vector<Token*> tokens;

    auto lexemes = explode(source);
    
    for (auto s : lexemes) {
        create_token(&tokens, s);
    }

    return tokens;
}


void create_token(vector<Token*>* tokens, string s) {

    if (s.size() == 0) {
        return;
    }

    char s_start = s[0];

    if ((s_start >= 65 && s_start <= 90) || (s_start >= 97 && s_start <= 122)) {
        s_start = 'a';
    }
    
    switch(s_start) {
        case ';':
            tokens->push_back( new Semicolon() );
            s.erase(0, 1);
            create_token(tokens, s);
            break;
        case '{':
            tokens->push_back( new LeftBrace() );
            s.erase(0, 1);
            create_token(tokens, s);
            break;
        case '}':
            tokens->push_back( new RightBrace() );
            s.erase(0, 1);
            create_token(tokens, s);
            break;
        case '(':
            tokens->push_back( new LeftParenthesis() );
            s.erase(0, 1);
            create_token(tokens, s);
            break;
        case ')':
            tokens->push_back( new RightParenthesis() );
            s.erase(0, 1);
            create_token(tokens, s);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            {
                int pos = 1;
                while (true) {
                    if (s.size() >= pos && (s[pos] < 48 || s[pos] > 57)) {
                        tokens->push_back( new IntegerLiteral( stoi(s.substr(0, pos))) );
                        s.erase(0, pos);
                        create_token(tokens, s);
                        break;
                    }
                    ++pos;
                }
                break;
            }
        case 'a':
            {
                int pos = 1;
                while (true) {
                    if (s.size() >= pos && !(  // + 1 exists
                        (s[pos] >= 48 && s[pos] <= 57 ) || // if its a number
                        (s[pos] >= 65 && s[pos] <= 90 ) ||  // capital letter
                        (s[pos] >= 97 && s[pos] <= 122) ||  // if its a letter
                         s[pos] == 95) ) {  // an underscore
                        
                        // extract keywords
                        if (!s.substr(0, pos).compare("return")) {
                            tokens->push_back( new Return() );
                        } else if (!s.substr(0, pos).compare("int")) {
                            tokens->push_back( new Int() );
                        } else {
                            tokens->push_back( new Identifier(s.substr(0, pos)) );
                        }

                        s.erase(0, pos);
                        create_token(tokens, s);
                        break;
                    }
                    ++pos;
                }
                break;
            }
            break;
        default:
            tokens->push_back( new Identifier(s) );
            break;
    }

    return;
}


std::string read_file_to_string(std::string filename) {
    ifstream ifs(filename);
    string content( (istreambuf_iterator<char>(ifs) ),
        (istreambuf_iterator<char>()   ) );
    return content;
}


std::vector<std::string> explode(string input) {
    string buff{""};
    char c = ' ';
    char newline = '\n';
    char tab = '\t';
	vector<string> v;
	
	for(auto n:input)
	{
		if(n != c && n != newline && n != tab) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}