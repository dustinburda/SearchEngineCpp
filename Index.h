//
// Created by Dustin Burda on 9/29/24.
//

#ifndef SEARCHENGINE_INDEX_H
#define SEARCHENGINE_INDEX_H

#include <list>
#include <map>
#include <unordered_set>

#include "Document.h"

class Index {
public:
    Index() = delete;

    Index(const Document& d);
    Index(const Collection& collection);

    void AddDocument(const Document& d);
    friend std::ostream& operator<<(std::ostream& stream, const Index& index);

private:
    struct TermInfo {

        void AddPosting(DocId id) {
            postings_list_.push_back(id);
            doc_freq_++;
        }

        uint16_t doc_freq_;
        std::list<DocId> postings_list_;
    };

    // Sorts automatically by key
    std::map<Token, TermInfo> index_;
};


#endif //SEARCHENGINE_INDEX_H
