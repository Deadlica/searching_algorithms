//
// Created by samuel on 4/3/22.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

template<typename T>
struct node {
    T data;
    node<T>* next;
};

std::vector<std::unique_ptr<node<int>>> hashtable;

#endif