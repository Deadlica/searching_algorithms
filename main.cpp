#include <iostream>
#include "search.h"
#include "tree.h"
#include "prime.h"
#include "hashtable.h"
#include "measurement.h"

int main() {
    std::srand((unsigned) std::time(nullptr));
    measurement benchmark(20, 20000);

    benchmark(LINEAR_SEARCH, "Linear search.csv");
    benchmark(BINARY_TREE_SEARCH, "Binary tree search.csv");
    benchmark(HASH_SEARCH, "Hashtable search.csv");
    benchmark(BINARY_SEARCH, "Binary search.csv");
    benchmark(INTERPOLATION_SEARCH, "Interpolation search.csv");

    return 0;
}