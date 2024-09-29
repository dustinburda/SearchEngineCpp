//
// Created by Dustin Burda on 9/29/24.
//

#include "Lexer.h"

void Lexer::Lex(std::vector<Token>& tokens) {

    std::string line;
    while(std::getline(src_, line)) {
        std::stringstream s { line };

        std::string token;
        while(std::getline(s, token, ' ')) {
            tokens.push_back(token);
        }
    }
}