#include <iostream>
#include "Queue.h"

using namespace std;
// It is a first in first out structure.

// Here queue is the type of list.
// To insert a new string
void Queue::enqueue(string s) {
    queue.push_back(s);
}

// To extract the last string that has been inserted into the queue
string Queue::dequeue() {
    // queue.end() returns an iterator to the last element of the list
    string lastElement = queue.back();
    queue.pop_back();
}

// visit, to display all elements contained by the queue
void Queue::visit() {
    for (string a: queue) {
        cout << a << endl;
    }
}

// returns the size of the queue
int Queue::getSize() {
    return queue.size();
}

// checks if empty
bool Queue::empty() {
    return queue.empty();
}





