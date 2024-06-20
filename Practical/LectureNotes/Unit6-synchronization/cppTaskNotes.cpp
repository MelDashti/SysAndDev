// Futures and Promises in C++
#include <iostream>
#include <thread>
#include <future>
#include <vector>

using namespace std;

void my_f(int n) {
    cout << "thread my_f" << endl;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n >= 3) return true;
    return false;
}


int sum(int a, int b) {
    this_thread::sleep_for(chrono::seconds(2));
    return a + b;
};


int main() {
    auto f1 = async(launch::async, my_f,
                    10); // here launch::async is the policy that tells the compiler to run the function in a new thread
    // my_f(10); // this will run in the main thread

    auto f2 = async(launch::deferred, my_f, 20);
    // thread function my_f will not run until we call get its result or wait for it to finish

    auto f3 = async(launch::async | launch::deferred, my_f, 30);
    // the system decides when to run my_f! Possibly it never runs my_f.

    f2.wait();
    // invokes the deferred function f2 (i.e., run it).
    // f2.get(); // this will run the function in the main thread

    auto f = async(my_f, 40);
//    f.wait_for(0s): This checks the status of the future without waiting (0 seconds). It returns immediately with the status of the future.
//    std::future_status::deferred: This status indicates that the task is deferred and has not started yet. It will only start when get() or wait() is called on the future.
    if (f.wait_for(chrono::seconds(0)) == future_status::deferred) {
//        If the future's status is deferred, the task has not started yet. Calling f.wait() forces the task to start and waits for it to complete.
        f.wait();
    } else {
        while (f.wait_for(100ms) != future_status::ready) {
            cout << "waiting for the task to finish" << endl;
        }
    }

    future<bool> fut = async(launch::async, is_prime, 117);
    bool prime = fut.get();

    // with lambda functions
    auto fut2 = async(launch::async, []() {
        vector<int> v;
        for (int i = 0; i < 100; i++) {
            v.push_back(i);
        }
        return v;
    });
    auto ret = fut2.get();
    for (auto e: ret) {
        cout << e << endl;
    }

    // unique future
    future<int> future = async(launch::async, sum, 2, 3);

    int result1 = future.get();
    cout << result1;
    int result2 = future.get(); // terminate called after throwing an error!
    cout << result2;

    // shared future
    shared_future<int> future1 = async(launch::async, sum, 10, 20);

    int result = future1.get();
    cout << "Result : " << result << endl;

    int result3 = future1.get(); // this works perfectly fine
    cout << "Result: " << result << endl;

    // this is the producer write end
    promise<int> promise;
    // this is the consumer read end
    auto future5 = promise.get_future();

    thread t([&promise]() {
        promise.set_value(sum(2, 44));
    });
    cout << future5.get() << endl;

    // promise and future. Two threads (lambdas)
    auto promise2 = std::promise<int>();
    auto future6 = promise2.get_future();


    return 0;
}


