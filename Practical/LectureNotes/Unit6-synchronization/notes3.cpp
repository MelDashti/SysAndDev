#include <chrono>
#include <iostream>
#include <semaphore>
#include <thread>

using namespace std;

binary_semaphore m2t{0}, t2m{0};

void tf() {
    m2t.acquire(); // Wait for main. // this will make the thread wait for the main thread to send a signal
    cout << "[thread] Got signal \n";
    this_thread::sleep_for(3s); // what this does is it makes the thread sleep for 3 seconds
    cout << "[thread] Send signal \n";
    t2m.release(); // Send signal to main // this will send a signal to the main thread
}

int main() {
    thread thr(tf); // Create thread
    cout << "[main] Send signal \n";
    m2t.release();
    t2m.acquire();
    cout << "[main] Got signal \n";
    thr.join();
}
