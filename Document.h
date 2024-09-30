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

    explicit Document(const std::filesystem::path& path);
    explicit Document(const std::string& extension);

    const std::vector<Token>& Tokens() const { return tokens_; }
    DocId Id() const { return id_; }

private:
    DocId id_;
    std::vector<Token> tokens_;
    std::stringstream buffer_;
};

using Collection = std::vector<std::unique_ptr<Document>>;

#endif //SEARCHENGINE_DOCUMENT_H
