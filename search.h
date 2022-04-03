//
// Created by samuel on 4/1/22.
//

#ifndef SEARCH_H
#define SEARCH_H

template<typename it, typename T>
it linear_search(it first, it last, T element) {
    for(;first != last; first++) {
        if(*first == element) { //Found element
            return first;
        }
    }
    return last; //Returns last if element isn't found
}

template<typename it, typename T>
it binary_search(it first, it last, T element) {
    if(first < last) { //Range isn't empty
        it result;
        it middle = first + (last - first) / 2; //Get pointer to middle

        if (*middle == element) { //Element found
            return middle;
        }
        else if (*middle > element) { //Search to the left
            result = binary_search(first, middle - 1, element);
        }
        else { //Search to the right
            result = binary_search(middle + 1, last, element);

        }
        if(*result == element) //Element found somewhere to the left/right of middle
            return result;
    }
    return last; //Element wasn't found
}

template<typename it, typename T>
T interp_search(it first, it last, T element) {
    if(first < last) { //Range isn't empty
        it result;
        it pos = first + (double((last - first) / (*last - *first))) * (element - *first); //Calculates the new "middle" position

        if (*pos == element) { //Element found
            return pos;
        }
        else if (*pos > element) { //Search for the element to the left of pos
            result = binary_search(first, pos - 1, element);
        }
        else { //Search for the element to the right of pos
            result = binary_search(pos + 1, last, element);

        }
        if(*result == element) //The element was found somewhere to the left or right of the middle
            return result;
    }
    return last; //Element wasn't found
}

template<typename it, typename T>
bool tree_binary_search(it &root, T element) {
    if(root != nullptr) {
        if(root->data == element) { //Element found
            return true;
        }
        else if(root->data > element) { //Search to the left
            return tree_binary_search(root->left, element);
        }
        else { //Search to the right
            return tree_binary_search(root->right, element);
        }
    }
    return false; //Returns null if the element isn't found
}

#endif
