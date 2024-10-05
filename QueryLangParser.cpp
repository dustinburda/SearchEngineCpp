//
// Created by Dustin on 10/4/24.
//

#include "QueryLangParser.h"

    void QueryLangParser::ScanTokens() {
        while(!IsEnd()) {
            auto curr_char = Advance();

            if(curr_char == std::nullopt)
                break;

            std::string lexeme  { curr_char.value() };
            switch (curr_char) {
                case '(':
                    tokens_.emplace_back(lexeme, TokenType::LeftParen);
                    break;
                case ')':
                    tokens_.emplace_back(lexeme, TokenType::RightParen);
                    break;
                case 'A':
                    if(PeekAhead(1).value() == 'N' && PeekAhead(2).value() == 'D') {
                        lexeme.push_back(Advance().value());
                        lexeme.push_back(Advance().value());
                        tokens_.emplace_back(lexeme, TokenType::AND);
                        break;
                    }
                case 'O':
                    if(PeekAhead(1).value() == 'R') {
                        lexeme.push_back(Advance().value());
                        tokens_.emplace_back(lexeme, TokenType::OR);
                        break;
                    }
                case 'N':
                    if(PeekAhead(1).value() == 'O' && PeekAhead(2).value() == 'T') {
                        lexeme.push_back(Advance().value());
                        lexeme.push_back(Advance().value());
                        tokens_.emplace_back(lexeme, TokenType::NOT);
                        break;
                    }
            }
        }
    }

    bool QueryLangParser::IsEnd() {
        return index_ >= src_.size();
    }

    std::optional<char> QueryLangParser::Peek() {
        if (IsEnd())
            return std::nullopt;

        return src_[index_];
    }

    std::optional<char> QueryLangParser::PeekAhead(size_t n) {
        if(index_ + n - 1 >= src_.size())
            return std::nullopt;

        return src_[index_ + n - 1];
    }

    std::optional<char> QueryLangParser::Advance() {
        if (IsEnd())
            return std::nullopt;

        char curr_char = src_[index_];
        index_++;

        return curr_char;
    }