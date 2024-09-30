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
            tokens.push_back(ToLowerCase(token));
        }
    }
}
std::string Lexer::ToLowerCase(std::string token) {
    std::string lower_case;
    std::transform(token.begin(), token.end(), std::back_inserter(lower_case), [](char c) {
        return std::tolower(c);
    } );

    return lower_case;
}