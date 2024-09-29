//
// Created by Dustin Burda on 9/29/24.
//

#ifndef SEARCHENGINE_INDEX_H
#define SEARCHENGINE_INDEX_H

#include <list>
#include <map>

#include "Document.h"

class Index {
public:
    Index() = delete;
    Index(const Document& d) {

    }

    Index(const Collection& d) {

    }

    void AddDocument(const Document& d) {
        for(auto& token : d.Tokens()) {

        }
    }

private:
    struct TermInfo {
        uint16_t doc_freq_;
        std::list<uint16_t> postings_list_;
    };

    // Sorts automatically by key
    std::map<Token, TermInfo> index_;
};


#endif //SEARCHENGINE_INDEX_H
