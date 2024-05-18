#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // First we will test the Queue class
    Queue<string> queue;
    queue.enqueue("Hello");
    queue.enqueue("World");
    queue.enqueue("!");
    queue.visit();

    // Now we will test the stack
    Stack<double> stack;
    stack.push(1.1);
    stack.push(2.2);
    stack.push(3.3);
    stack.visit();

    return 0;
}
