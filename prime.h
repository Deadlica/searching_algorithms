//
// Created by samuel on 4/2/22.
//

#ifndef PRIME_H
#define PRIME_H


#include <vector>
#include <iostream>

class Prime {
public:
    Prime(size_t limit);

    int& operator[](size_t index);
    void resize(size_t limit);
    size_t size() const;
    void clear();
    void print() const;
    std::vector<int>::iterator begin();
    std::vector<int>::iterator end();
    std::vector<int>::const_iterator begin() const;
    std::vector<int>::const_iterator end() const;

private:
    std::vector<int> primeNumbers;
    std::vector<bool> isPrime;
    size_t limit;

    void SieveOfErastosthenes();
};


#endif
