#include <iostream>
#include "proj9-MyList.h"

// Aiden Grajo


using namespace std;
int main() {
    cout << "Creating a new test object" << endl << endl;
    MyList<int> test;

    cout << "Test pushFront() and pushBack()" << endl << endl;
    test.pushFront(1);
    test.pushBack(2);
    test.pushFront(3);
    test.pushBack(4);

    cout << "Test getSize() and isEmpty()" << endl;
    cout << "Size of list: " << test.getSize() << endl;
    cout << "Is list empty? " << (test.isEmpty() ? "Yes" : "No") << endl << endl;

    cout << "Test front() and back()" << endl;
    cout << "First element: " << test.front() << endl;
    cout << "Last element: " << test.back() << endl << endl;

    cout << "Test operator[]" << endl;
    cout << "Element at index 1: " << test[1] << endl << endl;

    cout << "Test popFront() and popBack()" << endl;
    int frontElement, backElement;
    test.popFront(frontElement);
    test.popBack(backElement);
    cout << "Removed first element: " << frontElement << endl;
    cout << "Removed last element: " << backElement << endl << endl;

    cout << "Test erase()" << endl;
    test.erase();

    cout << "Test getSize() and isEmpty() again" << endl;
    cout << "Size of list: " << test.getSize() << endl;
    cout << "Is list empty? " << (test.isEmpty() ? "Yes" : "No") << endl;

    return 0;

}
