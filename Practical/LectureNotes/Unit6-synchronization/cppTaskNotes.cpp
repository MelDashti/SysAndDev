// Futures and Promises in C++
#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main() {
    promise<int> promise; // Create a promise object
    future<int> future = promise.get_future(); // Get a future object associated with the promise object

    thread t([&promise] {
        promise.set_value(10); // Set the value of the future object
    });



}
