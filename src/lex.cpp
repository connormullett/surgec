
#include "../headers/lex.hpp"
#include <string>
#include <iostream>

using namespace std;

Lexer::Lexer(std::string filePath) : fileName{filePath} { }

void Lexer::lex() {
    std::string token;
    std::vector<Lexem> lexems;
    Lexem lexem;
    bool flag_complete_lexem = false;
    unsigned int lexem_id = 1;

    std::string source = read_file_to_string();

    for (std::string::size_type i = 0; i < source.size(); ++i) {
        switch (source[i]) {
            case ' ':
                lexem = Lexem(lexem_id++, LexemTypes::NULL_TOK, " ");
                flag_complete_lexem = true;
                break;
            case '\n':
                lexem = Lexem(lexem_id++, LexemTypes::NEW_LINE, "\n");
                flag_complete_lexem = true;
                break;
            case '(':
                lexem = Lexem(lexem_id++, LexemTypes::LPAREN, "(");
                flag_complete_lexem = true;
                break;
            case ')':
                lexem = Lexem(lexem_id++, LexemTypes::RPAREN, ")");
                flag_complete_lexem = true;
                break;
            case '{':
                lexem = Lexem(lexem_id++, LexemTypes::LBRACE, "{");
                flag_complete_lexem = true;
                break;
            case '}':
                lexem = Lexem(lexem_id++, LexemTypes::RBRACE, "}");
                flag_complete_lexem = true;
                break;
            case '=':
                lexem = Lexem(lexem_id++, LexemTypes::ASSIGNMENT, "=");
                flag_complete_lexem = true;
                break;
            case ';':
                lexem = Lexem(lexem_id++, LexemTypes::SEMICOLON, ";");
                flag_complete_lexem = true;
                break;
            case '!':
                lexem = Lexem(lexem_id++, LexemTypes::NEGATION, "!");
                flag_complete_lexem = true;
                break;
            default:
                token.push_back(source[i]);
                break;
        }

        if (flag_complete_lexem) {
            if (token != "") {
                auto t_lexem = create_lexem(lexem_id++, token);
                lexems.push_back(t_lexem);
            }
            lexems.push_back(lexem);
            token.clear();
            flag_complete_lexem = false;
        }
    }

    t_lexems = lexems;
}

Lexem Lexer::create_lexem(int id, std::string symbol){
    if (symbol.compare("int") == 0) return Lexem(id, LexemTypes::INT_KEYW, symbol);
    if (symbol.compare("return") == 0) return Lexem(id, LexemTypes::RET_KEYW, symbol);
    if (symbol.compare("bool") == 0) return Lexem(id, LexemTypes::BOOL_KEYW, symbol);
    if (symbol.compare("false") == 0) return Lexem(id, LexemTypes::FALSE_VAL, symbol);
    if (symbol.compare("true") == 0) return Lexem(id, LexemTypes::TRUE_VAL, symbol);
    if (is_number(symbol)) return Lexem(id, LexemTypes::INT_LITERAL, symbol);
    return Lexem(id, LexemTypes::IDENT, symbol);
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
        if (t_lexems[i].type == LexemTypes::NULL_TOK) continue;
        if (t_lexems[i].type == LexemTypes::NEW_LINE) continue;

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
