//
// Created by Dustin Burda on 9/29/24.
//

#ifndef SEARCHENGINE_LEXER_H
#define SEARCHENGINE_LEXER_H

#include <string>
#include <vector>
#include <sstream>

using Token = std::string;

class Lexer {
public:
    Lexer() = delete;
    explicit Lexer(const std::string& src) : src_{ src } {}

    // for now, just split on whitespace
    // create a real lexer later
    void Lex(std::vector<Token>& tokens);
private:
    std::stringstream src_;
};

#endif //SEARCHENGINE_LEXER_H
