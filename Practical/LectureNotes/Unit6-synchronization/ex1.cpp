#include <iostream>
#include <semaphore>
#include <thread>
#include <unistd.h> // This is for the sleep function.

using namespace std;

// Mutexes cannot be used because they must be locked and unlocked by the same thread
counting_semaphore sa{1}, sb{2}, me{1};
// we have 2 semaphores sa and sb initialized with values 1 and 2.
// Semaphores are used for controlling access to a common resource by multiple processes in a concurrent system
// such as multitasking os.
// we also have a semaphore initialized with value 1, which is used as a mutex to ensure mutual exclusion when printing
// incrementing the counter.

int n; // counter

// The TA thread function acquires the sa semaphore, prints A, increments the counter n, and if n is greater than or
// equal to 3, it prints a newline character, resets the counter n to 0, and releases the semaphores sa and sb twice.
// The me semaphore is released at the end to allow other thread to print.
static void TA(int nc) {
    for (int i = 0; i < nc; i++) {
        sleep(rand() % 2); // sleep for a random time
        sa.acquire();
        me.acquire();
        cout << "A";
        n++; // this will increment the value of n by 1.
        if(n>=3){
            cout << endl;
            n = 0;
            sa.release();
            sb.release();
            sb.release();
        }
        me.release();
    }
    return;

}

static void TB(int nc){
    for (int i = 0; i< nc; i++){
        sleep(rand() % 2); // sleep for a random time
        sb.acquire();
        me.acquire();
        cout << "B";
        n++; // this will increment the value of n by 1.
        if(n>=3){
            cout << endl;
            n = 0;
            sa.release();
            sb.release();
            sb.release();
        }
        me.release();
    }
}



int main(int argc, char **argv) {
        int n1 = 1, n2 = 2; // Default values for n1 and n2

        thread ta(TA, n1); // Here n1 is 1, which means the TA function will be called once.
        thread tb(TB, n2); // here n2 is 2, which means the TB function will be called twice.

        ta.join(); // this will wait for the thread to finish.
        tb.join(); // this will wait for the thread to finish.

        return 0;
}