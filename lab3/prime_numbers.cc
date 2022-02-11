#include "prime_numbers.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>

PrimeNumber::PrimeNumber(int end, int maxNumber) {
    this->end = end;
    this->maxNumber = maxNumber;
    prime = (bool*) calloc(maxNumber+1, sizeof(bool));
    for(int i = 0; i <= maxNumber; i++) {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    sievePrimes();
}

void PrimeNumber::print(std::ostream &out) {
    std::string ans;
    std::string ansNumber;
    for(int i = 0; i < end+1; i++) {
        if(prime[i]) {
            ans.append("P");
            ansNumber.append(std::to_string(i) + " ");
        } else {
            ans.append("C");
        }
    }
    out << ans << "\n" << ansNumber << "\n";
    int i = maxNumber;
    while(i > 0) {
        if(prime[i]) {
            out << std::to_string(i);
            break;
        }
        i--;
    }
}

void PrimeNumber::sievePrimes() {
    int n = ceil(sqrt(maxNumber))+1;
    for(int i = 0; i < n; i++) {
        if(prime[i]) {
            for(int j = i+i; j < maxNumber+1; j += i) {
                prime[j] = false;
            }
        }
    }
}