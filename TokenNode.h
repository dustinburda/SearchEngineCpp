//
// Created by Dustin on 10/4/24.
//

#ifndef TOKENNODE_H
#define TOKENNODE_H

#include <string>

enum class TokenType {
    LeftParen,
    RightParen,
    AND,
    NOT,
    OR,
    String
};

class TokenNode {
public:
    TokenNode() = delete;
    TokenNode(std::string lexeme, TokenType type) : lexeme_{lexeme}, type_{type} {}
private:
    std::string lexeme_;
    TokenType type_;
};


#endif //TOKENNODE_H
