#include <iostream>
#include "search.h"
#include "tree.h"
#include "prime.h"
#include "hashtable.h"
#include "measurement.h"

int main() {
    std::srand((unsigned) std::time(0));
    measurement benchmark(50, 20000);

    benchmark(LINEAR_SEARCH, "Linear search.csv");
    benchmark(BINARY_SEARCH, "Binary search.csv");
    //benchmark(INTERPOLATION_SEARCH);
    benchmark(BINARY_TREE_SEARCH, "Binary tree search.csv");
    benchmark(HASH_SEARCH, "Hashtable search.csv");

    return 0;
}