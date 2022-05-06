//
// Created by samuel on 4/1/22.
//

#ifndef TREE_H
#define TREE_H

#include <memory>
#include "prime.h"

namespace tree {

    template<typename T>
    struct node {
        node(T data) : data(data), left(nullptr), right(nullptr) {}

        T data;
        std::unique_ptr<node> left; // nullptr leaf
        std::unique_ptr<node> right; // nullptr leaf
    };

    template<typename T>
    class Tree {
    public:
        Tree() : root(nullptr) {}

        template<typename it>
        void generateData(it first, it last) { //Takes elements from container and inserts them to the tree
            if (first != last) {
                it middle = first + (last - first) / 2;
                insert(root, *middle);
                generateData(first, middle);
                generateData(middle + 1, last);
            }
        }

        void insert(std::unique_ptr<node<T>> &root, T data) {
            if (root == nullptr) { //No node exist
                root = std::make_unique<node<T>>(node<T>(data));
            } else if (root->data > data) { //data is less than parent data
                insert(root->left, data);
            } else { //data is greater than parent data
                insert(root->right, data);
            }
        }

        void inverse(std::unique_ptr<node<T>> &node) {
            if(node != nullptr) {
                std::swap(node->left, node->right);
                inverse(node->left);
                inverse(node->right);
            }
        }

        void reset() {
            auto temp = std::move(root);
        }

        std::unique_ptr<node<T>> root;
    private:

    };

}

#endif
