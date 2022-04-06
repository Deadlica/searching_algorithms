//
// Created by samuel on 4/3/22.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <forward_list>

template<typename T>
class hashtable {
public:
    hashtable() = default;

    template<typename it>
    hashtable(it first, it last): m_hashtable(last - first) {
        for(it current = first; current != last; current++) {
            add(*current);
        }
    }

    template<typename it>
    void generateNumbers(it first, it last) {
        m_hashtable.resize(last - first);
        for(it current = first; current != last; current++) {
            add(*current);
        }
    }

    void add(T value) {
        auto index = hash(value);
        m_hashtable[index].push_front(value);
    }

    T* get(T value) {
        auto index = hash(value);
        auto it = m_hashtable[index].begin(), end = m_hashtable[index].end();
        for(;it != end; it++) {
            if(*it == value) {
                T* found = &value;
                return found;
            }
        }
        return nullptr;
    }

private:
    std::vector<std::forward_list<T>> m_hashtable;

    const size_t hash(T value) const {
        return value % m_hashtable.size();
    }
};

#endif