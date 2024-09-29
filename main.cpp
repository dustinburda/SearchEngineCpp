//
// Created by Dustin on 9/27/24.
//

#include <iostream>
#include <string>

#include "Document.h"


int main() {
    std::string extension1  { "words1.txt" };
    Document d1 { extension1 };

    std::string extension2 { "words2.txt" };
    Document d2 { extension2 };

    return 0;
}