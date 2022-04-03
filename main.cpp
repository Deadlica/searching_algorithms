#include <iostream>
#include "search.h"
#include "tree.h"
#include "../sorting_algorithms/timer.h"
#include "../sorting_algorithms/measurements.h"
#include "prime.h"
#include "hashtable.h"

int main() {
    Prime buffer(18);

    tree::Tree<int> BST;
    BST.generateData(buffer.begin(), buffer.end());

    return 0;
}