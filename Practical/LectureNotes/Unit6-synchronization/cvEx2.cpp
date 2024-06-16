#include <iostream>
#include <thread>
#include <condition_variable>
#include <vector>
#include <cstdlib>
#include "stdlib.h"
#include <ctime>

using namespace std;

mutex m;
condition_variable cv_all_done, cv_var_reached;
int var;
int final = 0;

void admin() {
    unique_lock<mutex> u_lock(m);
    var = 10; // initializes to 10
    cout << "Variable initialized to 10" << endl;

    // Wait for all adder threads to finish or var to reach 15
    while (final != 3 || var < 15) {
        if (final == 3) {
            cv_var_reached.wait(u_lock);
        } else {
            cv_all_done.wait(u_lock);
        }
    }
    cout << "Final value of var: " << var << endl;
}

void adder() {
    sleep(rand() % 2); // sleep for a random time
    int a = rand() % 4 + 2; // generates a random num between 2 and 5
    unique_lock<mutex> u_lock(m);
    var += a;
    cout << "Added " << a << ", new value of var: " << var << endl;
    if (var >= 15) {
        cv_var_reached.notify_one();
    }
    final++;
    if (final == 3) {
        cv_all_done.notify_one();
    }
}





// in the below code its not creating three threads so again the revised version is above.

//mutex m;
//condition_variable cv_all_done, cv_var_reached;
//int var;
//int final = 0;
//
//void admin(int numOfThreads) {
//    var = 10; // initializes to 10
//    unique_lock<mutex> u_lock(m);
//    while (final != numOfThreads) {
//        cv_all_done.wait(u_lock);
//    }
//    while (var < 15) {
//        cv_var_reached.wait(u_lock);
//    }
//    cout << var;
//}
//
//void adder(int numOfThreads) {
//    for (int i = 0; i < numOfThreads; i++) {
//        sleep(rand() % 2); // sleep for a random time
//        cout << "thread " << i << " running" << endl;
//        int a = rand() % 4 + 2; // generates a random num between 2 and 5
//        unique_lock<mutex> u_lock(m);
//        var += a;
//        if (var >= 15) {
//            cv_var_reached.notify_one();
//        }
//        final++;
//        if (final == numOfThreads) {
//            cv_all_done.notify_one();
//        }
//    }
//}
//
//int main() {
//    srand(time(0)); // initialize random number generator
//    int numOfThreads = 3;
//    // here we initialized the admin thread
//    thread adm(admin, numOfThreads);
//    // and now we initialize adder thread
//    thread ad(adder, numOfThreads);
//
//    adm.join();
//    ad.join();
//}
// my previous solution was with one condition variable:



//mutex m;
//condition_variable cv;
//int var;
//int final = 0;
//
//void admin(int numOfThreads) {
//    var = 10; // initializes to 10
//    unique_lock<mutex> u_lock(m);
//    while (final != numOfThreads || var < 15) {
//        cv.wait(u_lock);
//    }
//    cout << var;
//}
//
//void adder(int numOfThreads) {
//    for (int i = 0; i < numOfThreads; i++) {
//        sleep(rand() % 2); // sleep for a random time
//        cout << "thread " << i << "running" << endl;
//        int a = rand() % 4 + 2; // generates a random num between 2 and 5
//        unique_lock<mutex> u_lock(m);
//        var += a;
//        final++;
//        if (final == numOfThreads || var >= 15) {
//            cv.notify_one();
//        }
//    }
//}
//
//int main() {
//    srand(time(0)); // initialize random number generator
//    int numOfThreads = 3;
//    // here we initialized the admin thread
//    thread adm(admin, numOfThreads);
//    // and now we initialize adder thread
//    thread ad(adder, numOfThreads);
//
//    adm.join();
//    ad.join();
//}

























