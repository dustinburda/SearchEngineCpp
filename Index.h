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
        AddDocument(d);
    }

    Index(const Collection& collection) {
        for(auto& document : collection) {
            AddDocument(document);
        }
    }

    void AddDocument(const Document& d) {
        for(auto& token : d.Tokens()) {
            index_[token].AddPosting(d.Id());
        }
    }

private:
    struct TermInfo {

        void AddPosting(DocId id) {
            postings_list_.push_back(id);
            term_freq_++;
        }

        uint16_t term_freq_;
        std::list<DocId> postings_list_;
    };

    // Sorts automatically by key
    std::map<Token, TermInfo> index_;
};


#endif //SEARCHENGINE_INDEX_H
