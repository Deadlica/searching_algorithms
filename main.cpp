#include <iostream>
#include "search.h"
#include "tree.h"
#include "prime.h"
#include "hashtable.h"
#include "measurement.h"

int main() {
    Prime buffer(20000);
    buffer.print();
    std::cout << buffer.size() << std::endl;

    tree::Tree<int> BST;
    BST.generateData(buffer.begin(), buffer.end());

    hashtable<int> table(buffer.begin(), buffer.end());
    measurement lol(10, 20000);

    return 0;
}