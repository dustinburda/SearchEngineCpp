//
// Created by Dustin Burda on 9/29/24.
//

#ifndef SEARCHENGINE_DOCUMENT_H
#define SEARCHENGINE_DOCUMENT_H

#include <fstream>
#include <sstream>
#include <filesystem>
#include <cassert>
#include <cstdint>
#include <vector>

#include "Globals.h"
#include "Lexer.h"




class Document {
public:
    Document() = delete;

    explicit Document(const std::filesystem::path& path) : id_ { g_docId++ }, tokens_ {} {
        std::ifstream document { path };
        assert(document.is_open() );

        std::stringstream s;
        buffer_ << document.rdbuf();
    }

    explicit Document(const std::string& extension) : id_ { g_docId++ }, tokens_{} {
        auto current_path = std::filesystem::current_path().parent_path();
        std::filesystem::path document_path = current_path.concat("/" + extension);

        std::ifstream document { document_path };
        assert(document.is_open() );

        buffer_ << document.rdbuf();

        Lexer l { buffer_.str() };
        l.Lex(tokens_);
    }

    const std::vector<Token>& Tokens() const { return tokens_; }
    DocId Id() const { return id_; }

private:
    DocId id_;
    std::vector<Token> tokens_;
    std::stringstream buffer_;
};

using Collection = std::vector<Document>;

#endif //SEARCHENGINE_DOCUMENT_H
