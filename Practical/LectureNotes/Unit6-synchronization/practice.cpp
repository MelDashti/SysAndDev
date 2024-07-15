#include <iostream>
#include <semaphore>
#include <mutex>
#include <unistd.h>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cv;

void atomNa() {
    unique_lock<mutex> sl(m);
    while (1) {
        this_thread::sleep_for(chrono::seconds(5));
        cout << "created Na atom";
    }
}

void atomCL() {
    unique_lock<mutex> cl(m);
    while (1) {
        this_thread::sleep_for(chrono::seconds(5));
        cout << "created CL atom";
    }
}

void atomNacl() {
    unique_lock<mutex> ul(m);
    while (!(Na && Cl)) {
        cv.wait(ul);
        cout << "created Nacl atom";
    }


}

int main() {


}