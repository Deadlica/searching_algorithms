//
// Created by samuel on 4/5/22.
//

#include <numeric>
#include <complex>
#include <algorithm>
#include "measurement.h"

measurement::measurement(size_t N, size_t startSize): samples(N), sizes(0), list(0) {
    for(int i = 1; i <= 10; i++) {
        sizes.push_back(startSize * i);
    }
}

void measurement::operator()(algorithm algorithm) {
    for(auto e: sizes) {
        currentSize = e;
        for(int i = 0; i < samples; i++) {

            measurement::search(algorithm);
        }
        m_std_dev = std_dev();
    }
}

void measurement::search(algorithm algorithm) {
    switch(algorithm) {
        case LINEAR_SEARCH:
            break;
        case BINARY_SEARCH:
            break;
        case INTERPOLATION_SEARCH:
            break;
        case BINARY_TREE_SEARCH:
            break;
        case HASH_SEARCH:
            break;
    }
}

void measurement::generate(algorithm algorithm) {
    switch(algorithm) {
        case LINEAR_SEARCH:
            list.resize(currentSize);
            break;
        case BINARY_SEARCH:
            list.resize(currentSize);
            break;
        case INTERPOLATION_SEARCH:
            list.resize(currentSize);
            break;
        case BINARY_TREE_SEARCH:
            list.resize(algorithm);
            tree.generateData(list.begin(), list.end());
            break;
        case HASH_SEARCH:

            break;
    }
}

double measurement::std_dev() {
    const int N = samples;
    double sum = std::accumulate(timeMeasurements.begin(), timeMeasurements.end(), 0.0);
    mean = sum / N;

    auto devSum = [this](double measurement) {return std::pow(measurement - mean, 2);};
    std::transform(timeMeasurements.begin(), timeMeasurements.end(), timeMeasurements.begin(), devSum);
    double squareSum = std::accumulate(timeMeasurements.begin(), timeMeasurements.end(), 0.0);

    return (std::sqrt((1.0 / (N - 1.0)) * squareSum) / samples);
}
