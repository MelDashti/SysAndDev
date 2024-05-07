// Stack.h
#ifndef SADLAB_STACK_H
#define SADLAB_STACK_H

#include <vector>

class Stack {
    std::vector<int> stack;

public:
    void push(int x);

    int pop();

    void visit();

    int getSize();

    bool isEmpty();

};


#endif //SADLAB_STACK_H
