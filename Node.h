
#ifndef LINKED_LISTS_PROJ9_NODE_H
#define LINKED_LISTS_PROJ9_NODE_H

#include <cstddef>

template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T e) {
        data = e;
        next = NULL;
    }
};

#endif //LINKED_LISTS_PROJ9_NODE_H
