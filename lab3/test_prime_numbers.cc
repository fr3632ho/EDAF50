#include "prime_numbers.h"
#include <iostream>

int main() {
    PrimeNumber pn(0, 35, 100000);
    pn.print(std::cout);
}