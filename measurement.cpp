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
        timeMeasurements.clear();
    }
    std::cout << filename << " DONE!" << std::endl;
}

void measurement::search(algorithm algorithm) {
    int max_element = list[list.size() - 1];
    int element = rand() % ++max_element;
    std::vector<int>::iterator it;
    tree::node<int>* tree_it;
    int* hash_it;
    double total_time = 0;
    int loops = 100;
    for(int i = 0; i < loops; i++) {
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
        total_time += timer.time();
    }

    it++;
    hash_it++;
    tree_it++;
    timeMeasurements.push_back(total_time / loops);
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
    double sum = std::accumulate(timeMeasurements.begin(), timeMeasurements.end(), 0.0);
    double n = timeMeasurements.size();
    mean = sum / n;

    double dev_sum = 0;
    for(int i = 0; i < n; i++) {
        dev_sum += (timeMeasurements[i] - mean) * (timeMeasurements[i] - mean);
    }
    std::cout << 1 / (n-1) << std::endl;

    return std::sqrt(((1 / (n - 1)) * dev_sum) / n);
}

void measurement::exportToFile() {
    std::ofstream file(filename, std::ios_base::app);
    if(file.is_open()) {
        file << currentSize << "\t" << mean << "\t" << m_std_dev << "\t" << samples << std::endl;
        file.close();
    }
}
