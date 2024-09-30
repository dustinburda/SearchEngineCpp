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
    Index(const Document& d) {
        AddDocument(d);
    }

    Index(const Collection& collection) {
        for(auto& document : collection) {
            AddDocument(*document);
        }
    }

    void AddDocument(const Document& d) {
        std::unordered_set<Token> seen_tokens;
        for(auto& token : d.Tokens()) {
            if (seen_tokens.count(token) > 0)
                continue;

            seen_tokens.insert(token);
            auto& term_info = index_[token];
            term_info.AddPosting(d.Id());
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const Index& index) {
        for( auto& [token,term_info] : index.index_) {
            stream << "Token: " << token << "  " << "  Document Frequency: " << term_info.doc_freq_;
            stream << "  Postings List:";
            for(DocId id : term_info.postings_list_) {
                stream << " " <<  id;
            }
            stream << "\n";
        }

        return stream;
    }

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
