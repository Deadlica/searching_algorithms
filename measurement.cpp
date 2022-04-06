//
// Created by samuel on 4/5/22.
//

#include "measurement.h"

measurement::measurement(size_t N, size_t startSize): samples(N), sizes(0), list(0) {
    for(int i = 1; i <= 10; i++) {
        sizes.push_back(startSize * i);
    }
    for(auto e: sizes) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

void measurement::operator()(algorithm algorithm) {
}
