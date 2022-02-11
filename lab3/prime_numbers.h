#ifndef PRIME_NUMBA
#define PRIME_NUMBA

#include <iostream>
#include <vector>

class PrimeNumber {
public:
    PrimeNumber(int end, int maxNumber);
    void print(std::ostream &out);
private:
    int end;
    int maxNumber;
    bool* prime;
    void sievePrimes();
};

#endif
