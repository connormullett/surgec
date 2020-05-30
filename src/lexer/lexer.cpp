
#include "lexer/lexer.h"
#include <string>
#include <iostream>

using namespace std;

Lexer::Lexer(std::string filePath) : fileName{filePath} { }

void Lexer::lex() {
    std::string token;
    std::vector<Lexeme> lexems;
    Lexeme lexeme;
    bool flag_complete_lexeme = false;
    unsigned int lexeme_id = 1;

    std::string source = read_file_to_string();

    for (std::string::size_type i = 0; i < source.size(); ++i) {
        switch (source[i]) {
            case ' ':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::NULL_TOK, " ");
                flag_complete_lexeme = true;
                break;
            case '\n':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::NEW_LINE, "\n");
                flag_complete_lexeme = true;
                break;
            case '(':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::LPAREN, "(");
                flag_complete_lexeme = true;
                break;
            case ')':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::RPAREN, ")");
                flag_complete_lexeme = true;
                break;
            case '{':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::LBRACE, "{");
                flag_complete_lexeme = true;
                break;
            case '}':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::RBRACE, "}");
                flag_complete_lexeme = true;
                break;
            case '=':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::ASSIGNMENT, "=");
                flag_complete_lexeme = true;
                break;
            case ';':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::SEMICOLON, ";");
                flag_complete_lexeme = true;
                break;
            case '!':
                lexeme = Lexeme(lexeme_id++, LexemeTypes::NEGATION, "!");
                flag_complete_lexeme = true;
                break;
            default:
                token.push_back(source[i]);
                break;
        }

        if (flag_complete_lexeme) {
            if (token != "") {
                auto t_lexeme = create_lexeme(lexeme_id++, token);
                lexems.push_back(t_lexeme);
            }
            lexems.push_back(lexeme);
            token.clear();
            flag_complete_lexeme = false;
        }
    }

    t_lexems = lexems;
}

Lexeme Lexer::create_lexeme(int id, std::string symbol){
    if (symbol.compare("int") == 0) return Lexeme(id, LexemeTypes::INT_KEYW, symbol);
    if (symbol.compare("return") == 0) return Lexeme(id, LexemeTypes::RET_KEYW, symbol);
    if (symbol.compare("bool") == 0) return Lexeme(id, LexemeTypes::BOOL_KEYW, symbol);
    if (symbol.compare("false") == 0) return Lexeme(id, LexemeTypes::FALSE_VAL, symbol);
    if (symbol.compare("true") == 0) return Lexeme(id, LexemeTypes::TRUE_VAL, symbol);
    if (is_number(symbol)) return Lexeme(id, LexemeTypes::INT_LITERAL, symbol);
    return Lexeme(id, LexemeTypes::IDENT, symbol);
}

bool Lexer::is_number(std::string s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
    }

    return true;
}

void Lexer::print_lexems() {
    for (unsigned int i = 0; i < t_lexems.size(); i++) {
        if (t_lexems[i].type == LexemeTypes::NULL_TOK) continue;
        if (t_lexems[i].type == LexemeTypes::NEW_LINE) continue;

        std::cout << "(" << t_lexems[i].id 
            << ") (" << t_lexems[i].to_string()
            << ") ( " << t_lexems[i].symbol << " ) " << std::endl;
    }
}

std::string Lexer::read_file_to_string() {
    ifstream ifs(fileName);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
        (std::istreambuf_iterator<char>()   ) );
    return content;
}

std::vector<Lexeme>* Lexer::get_lexems() {
    return &t_lexems;
}
