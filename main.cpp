//
// Created by Dustin on 9/27/24.
//

#include <iostream>
#include <memory>
#include <string>

#include "Document.h"
#include "Index.h"


int main() {
    std::string extension1  { "words1.txt" };
    auto d1_ptr = std::make_unique<Document>(extension1 );

    std::string extension2 { "words2.txt" };
    auto d2_ptr = std::make_unique<Document>(extension2 );

    Collection c;
    c.push_back(std::move(d1_ptr));
    c.push_back(std::move(d2_ptr));

    Index i(c);

    std::cout << i << std::endl;
    return 0;
}