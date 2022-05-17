//
// Created by samuel on 4/1/22.
//

#ifndef SEARCH_H
#define SEARCH_H

#include <memory>
#include <cassert>
#include <iterator>
#include "tree.h"

template<typename it, typename T>
it linear_search(it first, it last, T element) {
    for(;first != last; first++) {
        if(*first == element) { //Found element
            return first;
        }
    }
    return last; //Returns last if element isn't found
}

namespace alg {

    template<typename it, typename T>
    it binary_search(it first, it last, T element) {
        if (first < last) { //Range isn't empty
            it result;
            it middle = first + (last - first) / 2; //Get pointer to middle

            if (*middle == element) { //Element found
                return middle;
            } else if (*middle > element) { //Search to the left
                result = alg::binary_search(first, middle - 1, element);
            } else { //Search to the right
                result = alg::binary_search(middle + 1, last, element);

            }
            if (*result == element) //Element found somewhere to the left/right of middle
                return result;
        }
        return last; //Element wasn't found
    }

}

template<typename it, typename T>
it interp_search(it first, it last, T element) {
    if(first < last) { //Range isn't empty
        it result;
        double d_y = *(last - 1) - *first;
        double k = std::distance(first, last - 1) / d_y;
        double d_element = element - (*first);
        //it pos = first + k * d_element;
        //it pos = first + (std::distance(first, last-1) / (*(last - 1) - *first)) * (element - *first); //Calculates the new "middle" position
        it pos = first + std::distance(first, last - 1) * (element - *(first))/ (*(last - 1) - *(first));


        if (*pos == element) { //Element found
            return pos;
        }
        else if (*pos > element) { //Search for the element to the left of pos
            result = interp_search(first, pos, element);
        }
        else { //Search for the element to the right of pos
            result = interp_search(pos + 1, last, element);

        }
        if(*result == element) //The element was found somewhere to the left or right of the middle
            return result;
    }
    return last; //Element wasn't found
}

template<typename T>
tree::node<T>* tree_binary_search(std::unique_ptr<tree::node<T>> &root, T element) {
    if(root != nullptr) {
        if(root->data == element) { //Element found
            return root.get();
        }
        else if(root->data > element) { //Search to the left
            return tree_binary_search(root->left, element);
        }
        else { //Search to the right
            return tree_binary_search(root->right, element);
        }
    }
    return nullptr; //Returns null if the element isn't found
}

#endif
