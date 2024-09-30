//
// Created by Dustin Burda on 9/29/24.
//

#include "Index.h"

Index::Index(const Document& d) {
    AddDocument(d);
}

Index::Index(const Collection& collection) {
    for(auto& document : collection) {
        AddDocument(*document);
    }
}

void Index::AddDocument(const Document& d) {
    std::unordered_set<Token> seen_tokens;
    for(auto& token : d.Tokens()) {
        if (seen_tokens.count(token) > 0)
            continue;

        seen_tokens.insert(token);
        auto& term_info = index_[token];
        term_info.AddPosting(d.Id());
    }
}

std::ostream& operator<<(std::ostream& stream, const Index& index) {
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