#include <iostream>
#include "search.h"
#include "tree.h"
#include "prime.h"
#include "hashtable.h"
#include "measurement.h"
#include "timer.h"

int interpolationSearch(int arr[], int n, int x)
{
    // Find indexes of two corners
    int lo = 0, hi = (n - 1);
 
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x) return lo;
            return -1;
        }
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = lo + (((double)(hi - lo) /
            (arr[hi] - arr[lo])) * (x - arr[lo]));
 
        // Condition of target found
        if (arr[pos] == x)
            return pos;
 
        // If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;
 
        // If x is smaller, x is in the lower part
        else
            hi = pos - 1;
    }
    return -1;
}

int main() {
    std::srand((unsigned) std::time(nullptr));
    measurement benchmark(50, 20000);

    //benchmark(LINEAR_SEARCH, "Linear search.csv");
    //benchmark(BINARY_TREE_SEARCH, "Binary tree search.csv");
    //benchmark(HASH_SEARCH, "Hashtable search.csv");
    //benchmark(BINARY_SEARCH, "Binary search.csv");
    //benchmark(INTERPOLATION_SEARCH, "Interpolation search.csv");

    /*Prime buffer(200000);
    int arr[200000];

    std::copy(buffer.begin(), buffer.end(), arr);
    int n = sizeof(arr)/sizeof(arr[0]);

    Timer timer;
    int hits = 0;
    int loops = 100000;
    int index;


    timer.start();
    for(int i = 0; i < loops; i++) {
        int element = std::rand() % (buffer[buffer.size() - 1] + 1);
        index = interpolationSearch(arr, n, element);
        if(arr[index] == element) hits++;
    }
    timer.stop();

    std::cout << "Interpolation Search: " << timer.time() / loops << std::endl << "Found the element " << hits << " times.";
    */

    std::vector<int> buffer;

    for(int i = 0; i < 200; i++) {
        buffer.push_back(i * i);
    }

    int element = 139 * 139;

    auto it = interp_search(buffer.begin(), buffer.end(), element);


    std::cout << *it << std::endl;

    return 0;
}