// exercise (exam 5th July 2021)
// Write a c++ program with three tasks
// Thread take reads a number from command line
// Thread check checks whether the number is prime
// Thread give displays the answer to standard output
#include <iostream>
#include <thread>
#include <future>

using namespace std;

void take(promise<int> p) {
    cout << "enter a number";
    int num;
    cin >> num;
    p.set_value(num);
}

void check(future<int> f, promise<bool> res) {
    // here future gets the value and checks if it a prime number
    int number = f.get();
    if (number == 1) res.set_value(true);
    if (number % 2 == 0 || number % 3 == 0) {
        res.set_value(false);
    } else res.set_value(true);
}

void display(future<bool> f) {
    if (f.get()) {
        cout << "The number is prime.\n";
    } else {
        cout << "The number is not prime.\n";
    }
}


int main() {
    promise<bool> p2;
    auto future2 = p2.get_future();

    promise<int> p;
    auto future = p.get_future();
    auto ftake = async(::launch::async, take, ::move(p));
    auto fcheck = async(launch::async, check, ::move(future), ::move(p2));
    auto fdisplay = async(launch::async, display, ::move(future2));

    ftake.get();
    fcheck.get();
    fdisplay.get();
    return 0;

}//
// Created by meela on 6/21/2024.
//
