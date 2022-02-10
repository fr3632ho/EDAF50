#include <iostream>
#include "tag_remover.h"

int main() {
    TagRemover tr(std::cin); // read from cin
    tr.print(std::cout);
}