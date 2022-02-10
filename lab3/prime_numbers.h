#ifndef PRIME_NUMBA
#define PRIME_NUMBA

#include <iostream>
#include <vector>

class PrimeNumber {
public:
    PrimeNumber(int begin, int end, int maxNumber);
    void print(std::ostream &out);
private:
    int begin;
    int end;
    std::vector<int> sievePrimes() const;
};

#endif
