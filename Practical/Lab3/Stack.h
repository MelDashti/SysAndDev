#ifndef SADLAB_STACK_H
#define SADLAB_STACK_H

#include<vector>
#include<iostream>

using namespace std;

// because we are using templates, we need to define the class and its functions in the header file.
// Or we have to define it in different file but also have the main defined there.

template<typename T>
class Stack {
    vector<T> stack;
public:
    void push(T element) {
        stack.push_back(element);
    }

    T pop() {
        T element = stack.back();
        stack.pop_back();
        return element;
    }

    void visit() {
        for (int i = 0; i < stack.size(); i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    int getSize() {
        return stack.size();
    }

    bool isEmpty() {
        return stack.empty();
    }
};

#endif //SADLAB_STACK_H