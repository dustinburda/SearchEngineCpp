//
// Created by Dustin Burda on 9/29/24.
//

#include "Document.h"

Document::Document(const std::filesystem::path& path) : id_ { g_docId++ }, tokens_ {} {
    std::ifstream document { path };
    assert(document.is_open() );

    std::stringstream s;
    buffer_ << document.rdbuf();
}

Document::Document(const std::string& extension) : id_ { g_docId++ }, tokens_{} {
    auto current_path = std::filesystem::current_path().parent_path();
    std::filesystem::path document_path = current_path.concat("/" + extension);

    std::ifstream document { document_path };
    assert(document.is_open() );

    buffer_ << document.rdbuf();

    Lexer l { buffer_.str() };
    l.Lex(tokens_);
}
