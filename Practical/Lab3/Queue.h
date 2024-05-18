#ifndef SADLAB_QUEUE_H
#define SADLAB_QUEUE_H

#include <list>
#include <iostream>

using namespace std;

template<typename T>
class Queue {
    list<T> queue;
public:
    void enqueue(T element) {
        queue.push_back(element);
    }

    T dequeue() {
        T element = queue.front();
        queue.pop_front();
        return element;
    }

    void visit() {
        for (T element : queue) {
            cout << element << " ";
        }
        cout << endl;
    }

    int getSize() {
        return queue.size();
    }

    bool empty() {
        return queue.empty();
    }
};

#endif //SADLAB_QUEUE_H