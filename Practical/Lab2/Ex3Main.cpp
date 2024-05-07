#include "Stack.h"

int main() {
    Stack s;
    s.push(10);
    s.push(15);
    s.push(25);
    s.pop();
    s.visit();
}