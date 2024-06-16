#include <iostream>
#include <mutex>
#include <condition_variable>
#include <semaphore>

using namespace std;


struct Semaphore {
    int counter;
    mutex t;
    condition_variable cv;
};


// increases the counter
void release() {

    t.lock();
    while (counter) {

    }


}

// here the semaphore decreases the counter
void acquire() {

    t.lock();
    while (counter) {

    }

}


int main() {
    unique_lock<mutex> u_lock(mutex);


}

