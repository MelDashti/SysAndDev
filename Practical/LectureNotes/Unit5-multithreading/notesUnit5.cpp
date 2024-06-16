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

// function definition without parameters
void f3(){
    std::cout << "Function f3 called\n";
}

// function definition with parameters
void f4(int a, int b){
    std::cout << "Function f4 called with parameters: " << a << ", " << b << "\n";
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
    std::thread t4([] { f2(123, 456); });

    std::thread t5([] {
        cout << "before calling Thread 5 " << endl;
        f2(123, 456);
        cout << "After calling Thread 5 " << endl;
    });

    // Join threads to the main thread
    t2.join();
    t3.join();
    t4.join();


    // Starts an object thread that calls f3()
    std::thread t6(f3);

    // Starts an object thread that calls f4() with parameters 123 and 456
    std::thread t7(f4, 123, 456);

    // move() transfers ownership of a thread object to a new thread object
    std::thread t8 = std::move(t7); // t7 is no longer a thread object
    // after move t7 is no longer a thread object. Detach will cause the main thread to not wait for the thread to finish.
    t7.detach();

    // check if t7 is still a thread.
    if (t7.joinable()) {
        std::cout << "t7 is a thread object\n";
    } else {
        std::cout << "t7 is not a thread object\n";
    }

    // check if t8 is a thread.
    if (t8.joinable()) {
        std::cout << "t8 is a thread object\n";
    } else {
        std::cout << "t8 is not a thread object\n";
    }

    // Join threads to the main thread
    t6.join();
    t8.join();





    return 0;


}






