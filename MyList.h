
#ifndef LINKED_LISTS_PROJ9_MYLIST_H
#define LINKED_LISTS_PROJ9_MYLIST_H

#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"
#include <iostream>

template <class T>
class MyList : public ContainerIfc <T> {
public:
    MyList();
    ~ MyList();
    MyList(const MyList&);
    MyList <T>& operator = (const MyList&);
    MyList <T>& pushFront(T);
    MyList <T>& pushBack(T);
    MyList <T>& popFront(T&);
    MyList <T>& popBack(T&);
    int getSize();
    bool isEmpty();
    T front();
    T back();
    T& operator [](int);
    void erase();

protected:
    Node<T> *head;
};



template <class T>
MyList<T>::MyList() {
    head = NULL;
}

template <class T>
MyList<T>::~MyList() {
    erase();
}

template <class T>
MyList<T>::MyList(const MyList<T>& other) {
    head = NULL;
    Node<T> *otherNode = other.head;
    while (otherNode != NULL) {
        pushBack(otherNode->data);
        otherNode = otherNode->next;
    }
}

template <class T>
MyList<T>& MyList<T>::operator=(const MyList<T>& other) {
    if (this != &other) {
        erase();
        Node<T> *otherNode = other.head;
        while (otherNode != NULL) {
            pushBack(otherNode->data);
            otherNode = otherNode->next;
        }
    }
    return *this;
}

template <class T>
MyList<T>& MyList<T>::pushFront(T element) {
    Node<T> *newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    return *this;
}

template <class T>
MyList<T>& MyList<T>::pushBack(T element) {
    Node<T> *newNode = new Node<T>(element);
    if (head == NULL) {
        head = newNode;
    } else {
        Node<T> *currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    return *this;
}

template <class T>
MyList<T>& MyList<T>::popFront(T& element) {
    if (head == NULL) {
        throw BADINDEX();
    }
    element = head->data;
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    return *this;
}

template <class T>
MyList<T>& MyList<T>::popBack(T& element) {
    if (head == NULL) {
        throw BADINDEX();
    }
    if (head->next == NULL) {
        element = head->data;
        delete head;
        head = NULL;
    } else {
        Node<T> *currentNode = head;
        while (currentNode->next->next != NULL) {
            currentNode = currentNode->next;
        }
        element = currentNode->next->data;
        delete currentNode->next;
        currentNode->next = NULL;
    }
    return *this;
}

template <class T>
int MyList<T>::getSize() {
    int count = 0;
    Node<T> *currentNode = head;
    while (currentNode != NULL) {
        count++;
        currentNode = currentNode->next;
    }
    return count;
}

template <class T>
bool MyList<T>::isEmpty() {
    return (head == NULL);
}

template <class T>
T MyList<T>::front() {
    if (head == NULL) {
        throw BADINDEX();
    }
    return head->data;
}

template <class T>
T MyList<T>::back() {
    if (head == NULL) {
        throw BADINDEX();
    }
    Node<T> *currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template <class T>
T& MyList<T>::operator[](int index) {
    if (index < 0 || index >= getSize()) {
        throw BADINDEX();
    }
    Node<T> *currentNode = head;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template <class T>
void MyList<T>::erase() {
    Node<T> *currentNode = head;
    while (currentNode != NULL) {
        Node<T> *temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    head = NULL;
}


#endif //LINKED_LISTS_PROJ9_MYLIST_H
