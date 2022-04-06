#include <iostream>
#include "search.h"
#include "tree.h"
#include "prime.h"
#include "hashtable.h"
#include "measurement.h"

int main() {
    std::srand((unsigned) std::time(0));
    measurement benchmark(50, 20000);

    benchmark(LINEAR_SEARCH, "Linear search.txt");
    benchmark(BINARY_SEARCH, "Binary search.txt");
    //benchmark(INTERPOLATION_SEARCH);
    benchmark(BINARY_TREE_SEARCH, "Binary tree search.txt");
    benchmark(HASH_SEARCH, "Hashtable search.txt");

    return 0;
}