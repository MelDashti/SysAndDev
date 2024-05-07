
#ifndef SADLAB_QUEUE_H
#define SADLAB_QUEUE_H

#include <list>
#include <string>

using namespace std;

class Queue {
    list <string> queue;
public:
    void enqueue(string);

    string dequeue();

    void visit();

    int getSize();

    bool empty();

};


#endif //SADLAB_QUEUE_H
