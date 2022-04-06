//
// Created by samuel on 4/2/22.
//

#include "prime.h"

Prime::Prime(size_t size): isPrime(limit, true), m_size(size) {
    SieveOfErastosthenes();
}

int &Prime::operator[](size_t index) {
    return primeNumbers[index];
}

void Prime::resize(size_t size) {
    m_size = size;
    primeNumbers.clear();
    fill();
}

size_t Prime::size() const {
    return primeNumbers.size();
}

void Prime::clear() {
    primeNumbers.clear();
    isPrime.clear();
}

void Prime::print() const {
    for(int i = 0; i < primeNumbers.size(); i++) {
        std::cout << primeNumbers[i];
        if(i != primeNumbers.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

std::vector<int>::iterator Prime::begin() {
    return primeNumbers.begin();
}

std::vector<int>::iterator Prime::end() {
    return primeNumbers.end();
}

std::vector<int>::const_iterator Prime::begin() const {
    return primeNumbers.begin();
}

std::vector<int>::const_iterator Prime::end() const {
    return primeNumbers.begin();
}

void Prime::SieveOfErastosthenes() {
    isPrime[0] = false;
    isPrime[1] = false;
    int i = 2;
    while(i < limit / 2) {
        int divisor = i * 2;
        while(divisor < limit) {
            isPrime[divisor] = false;
            divisor += i;
        }
        i++;
        while(!isPrime[i]) {
            i++;
        }
    }
    fill();
}

void Prime::fill() {
    for(int i = 0; primeNumbers.size() < m_size; i++) {
        if(isPrime[i]) {
            primeNumbers.push_back(i);
        }
    }
}