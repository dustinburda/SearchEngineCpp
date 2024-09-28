//
// Created by Dustin on 9/27/24.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cassert>
#include <cstdint>
#include <vector>

uint16_t g_docId = 0;
using Token = std::string;

class Lexer {

};

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
    }
private:
    uint16_t id_;
    std::vector<Token> tokens_;
    std::stringstream buffer_;
};

int main() {
    std::string extension  { "shakespeare.txt" };
    Document d { extension };
}