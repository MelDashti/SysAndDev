#include <iostream>
#include <vector>
#include "Stack.h"

using namespace std;
using std::vector; // by using this, you can use vector without the std:: prefix
// similarly for Stack.h you can use the following:

void Stack::push(int x) {
    stack.push_back(x); // push_back inserts an element at the end of the vector
}

int Stack::pop() {
    int lastElement = stack.back();
    stack.pop_back();
    return lastElement;
}

// to display all elements contained by the stack
void Stack::visit() {
    for (int a: stack) {
        cout << a << endl;
    }
}

int Stack::getSize() {
    return stack.size();
}

bool Stack::isEmpty() {
    return stack.empty();
}
