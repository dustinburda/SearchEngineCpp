//
// Created by Dustin on 10/4/24.
//

#ifndef QUERYLANGPARSER_H
#define QUERYLANGPARSER_H

#include <string>
#include <utility>
#include <vector>
#include <optional>

#include "Lexer.h"
#include "TokenNode.h"




class QueryLangLexer {
public:
    QueryLangLexer() = delete;
    explicit QueryLangLexer(std::string src) : src_{std::move(src)}, index_ {0}, tokens_{} {
        ScanTokens();
    }

    const std::vector<TokenNode>& Tokens() const { return tokens_; }

private:

    void ScanTokens();
    bool IsEnd();
    std::optional<char> Peek();
    std::optional<char> PeekAhead(size_t n);
    std::optional<char> Advance();
    void AdvanceWhitespace();

    std::string src_;
    size_t index_;
    std::vector<TokenNode> tokens_;
};



#endif //QUERYLANGPARSER_H
