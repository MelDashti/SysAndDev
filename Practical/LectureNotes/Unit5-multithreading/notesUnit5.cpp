#include <iostream>
#include <vector>
#include <thread>
// multithreading in c++
// The header thread defines the class std::thread, that can be used to start new threads.
// Using this class is the best way to use platform independent threads.

using namespace std;


void threadFunction(int id) {
    cout << "Thread id: " << id << endl;
}

// Function definition without parameters
void f1() {
    std::cout << "Function f1 called\n";
}

// Function definition with parameters
void f2(int a, int b) {
    std::cout << "Function f2 called with parameters: " << a << ", " << b << "\n";
}



int main() {
    // Create a thread and start it with threadFunction
    thread t0(threadFunction,
              1);// The two arguments are the function to be called and the arguments to be passed to that function.

    // join the thread with the main thread
    t0.join(); // The main thread waits for the thread to finish its execution.
    cout << "Print this after the main thread has joined the thread t1" << endl;

    std::thread t1;

    // Starts an object thread that calls f1()
    std::thread t2(f1);

    // Starts an object thread that calls f2() with parameters 123 and 456
    std::thread t3(f2, 123, 456);

    // Starts an object thread that calls f2() with parameters 123 and 456 using lambda expression
    std::thread t4([]{ f2(123, 456); });

    // Join threads to the main thread
    t2.join();
    t3.join();
    t4.join();

    return 0;



}






