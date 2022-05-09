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
        timeMeasurements.clear();
        currentSize = e;
        generate(algorithm);
        for(int i = 0; i < samples; i++) {
            double search_time = search(algorithm);
            timeMeasurements.push_back(search_time);
        }
        m_std_dev = std_dev();
        exportToFile();
    }
    std::cout << filename << " DONE!" << std::endl;
}

double measurement::search(algorithm algorithm) {
    int max_element = list[list.size() - 1];
    int element = rand() % ++max_element;
    std::vector<int>::iterator it;
    tree::node<int>* tree_it;
    int* hash_it;
    double total_time = 0;
    int loops = 10000;
    timer.start();
    for(int i = 0; i < loops; i++) {
        switch(algorithm) {
            case LINEAR_SEARCH:
                it = linear_search(list.begin(), list.end(), element);
                break;
            case BINARY_SEARCH:
                it = alg::binary_search(list.begin(), list.end(), element);
                break;
            case INTERPOLATION_SEARCH:
                it = interp_search(list.begin(), list.end(), element);
                break;
            case BINARY_TREE_SEARCH:
                tree_it = tree_binary_search(tree.root, element);
                break;
            case HASH_SEARCH:
                hash_it = table.get(element);
                break;
        }
    }
    timer.stop();
    if(it == list.begin()) {
        if (std::isdigit(*it)) {std::cout << "";}
    }
    if(hash_it != nullptr) {
        if (std::isdigit(*hash_it)) {std::cout << "";}
    }
    if(tree_it != nullptr) {
       std::cout << "";
    }
    total_time = timer.time();
    return total_time / loops;
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
    return std::sqrt(((1 / (n - 1)) * dev_sum) / n);
}

void measurement::exportToFile() {
    std::ofstream file(filename, std::ios_base::app);
    if(file.is_open()) {
        file << currentSize << "\t" << mean << "\t" << m_std_dev << "\t" << samples << std::endl;
        file.close();
    }
}
