//
// Created by samuel on 4/5/22.
//

#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include "timer.h"
#include "prime.h"
#include "search.h"
#include "tree.h"
#include "hashtable.h"

enum algorithm {LINEAR_SEARCH, BINARY_SEARCH, INTERPOLATION_SEARCH, BINARY_TREE_SEARCH, HASH_SEARCH};

class measurement {
public:
    measurement(size_t N, size_t startSize);

    void operator()(algorithm algorithm);

    void search(algorithm algorithm);

    void generate(algorithm algorithm);

    double std_dev();

private:
    Timer timer;
    size_t samples;
    double m_std_dev, mean, currentSize;
    std::vector<double> timeMeasurements;
    std::vector<size_t> sizes;
    Prime list;
    hashtable<int> table;
    tree::Tree<int> tree;
};


#endif