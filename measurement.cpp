//
// Created by samuel on 4/5/22.
//

#include "measurement.h"

measurement::measurement(size_t N, size_t startSize): samples(N), sizes(0), list(0) {
    for(int i = 1; i <= 10; i++) {
        sizes.push_back(startSize * i);
    }
}

void measurement::operator()(algorithm algorithm, std::string filename) {
    this->filename = filename;
    for(auto e: sizes) {
        currentSize = e;
        generate(algorithm);
        for(int i = 0; i < samples; i++) {
            measurement::search(algorithm);
        }
        m_std_dev = std_dev();
        exportToFile();
    }
    std::cout << filename << " DONE!" << std::endl;
}

void measurement::search(algorithm algorithm) {
    size_t randomIndex = std::rand() % list.size();
    int element = list[randomIndex];
    std::vector<int>::iterator it;
    tree::node<int>* tree_it;
    int* hash_it;
    switch(algorithm) {
        case LINEAR_SEARCH:
            timer.start();
            it = linear_search(list.begin(), list.end(), element);
            timer.stop();
            break;
        case BINARY_SEARCH:
            timer.start();
            it = alg::binary_search(list.begin(), list.end(), element);
            timer.stop();
            break;
        case INTERPOLATION_SEARCH:
            timer.start();
            it = interp_search(list.begin(), list.end(), element);
            timer.stop();
            break;
        case BINARY_TREE_SEARCH:
            timer.start();
            tree_it = tree_binary_search(tree.root, element);
            timer.stop();
            break;
        case HASH_SEARCH:
            timer.start();
            hash_it = table.get(element);
            timer.stop();
            break;
    }
    it++;
    hash_it++;
    tree_it++;
    timeMeasurements.push_back(timer.time());
}

void measurement::generate(algorithm algorithm) {
    list.resize(currentSize);
    switch(algorithm) {
        case BINARY_TREE_SEARCH:
            tree.reset();
            tree.generateData(list.begin(), list.end());
            break;
        case HASH_SEARCH:
            table.generateNumbers(list.begin(), list.end());
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

void measurement::exportToFile() {
    std::ofstream file(filename, std::ios_base::app);
    if(file.is_open()) {
        file << currentSize << "\t" << mean << "\t" << m_std_dev << "\t" << samples << std::endl;
        file.close();
    }
}
