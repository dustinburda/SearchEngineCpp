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
#include <list>
#include <map>

class Document;
class Index;
class Lexer;


using Token = std::string;
using Collection = std::vector<Document>;
using DocId = uint16_t;

DocId g_docId = 0;


class Index {
public:
    Index() = delete;
    Index(const Document& d) {

    }

    Index(std::vector<Document>& d) {

    }

    void AddDocument(const Document& d) {

    }

private:
    struct TermInfo {
        uint16_t doc_freq_;
        std::list<uint16_t> postings_list_;
    };

    // Sorts automatically by key
    std::map<Token, TermInfo> index_;
};


class Lexer {
public:
    Lexer() = delete;
    explicit Lexer(const std::string& src) : src_{ src } {}

    // for now, just split on whitespace
    // create a real lexer later
    void Lex(std::vector<Token>& tokens) {

        std::string line;
        while(std::getline(src_, line)) {
            std::stringstream s { line };

            std::string token;
            while(std::getline(s, token, ' ')) {
                tokens.push_back(token);
            }
        }
    }
private:
    std::stringstream src_;
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

        Lexer l { buffer_.str() };
        l.Lex(tokens_);
    }
private:
    uint16_t id_;
    std::vector<Token> tokens_;
    std::stringstream buffer_;
};

int main() {
    std::string extension1  { "words1.txt" };
    Document d1 { extension1 };

    std::string extension2 { "words2.txt" };
    Document d2 { extension2 };
    return 0;
}