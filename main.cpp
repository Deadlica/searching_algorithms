#include <iostream>
#include "search.h"
#include "tree.h"
#include "prime.h"
#include "hashtable.h"
#include "measurement.h"

int main() {
    std::srand((unsigned) std::time(nullptr));
    measurement benchmark(50, 20000);

    benchmark(LINEAR_SEARCH, "Linear search.data");
    benchmark(BINARY_SEARCH, "Binary search.data");
    //benchmark(INTERPOLATION_SEARCH);
    benchmark(BINARY_TREE_SEARCH, "Binary tree search.data");
    benchmark(HASH_SEARCH, "Hashtable search.data");

    return 0;
}