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
#include <numeric>
#include <complex>
#include <algorithm>
#include <fstream>

enum algorithm {LINEAR_SEARCH, BINARY_SEARCH, INTERPOLATION_SEARCH, BINARY_TREE_SEARCH, HASH_SEARCH};

class measurement {
public:
    measurement(size_t N, size_t startSize);

    void operator()(algorithm algorithm, std::string filename);

    double search(algorithm algorithm);

    void generate(algorithm algorithm);

    double std_dev();

    void exportToFile();

private:
    Timer timer;
    size_t samples, currentSize;
    std::string filename;
    double m_std_dev, mean;
    std::vector<double> timeMeasurements;
    std::vector<size_t> sizes;
    Prime list;
    hashtable<int> table;
    tree::Tree<int> tree;
};


#endif