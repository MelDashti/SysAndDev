#include <iostream>
#include <semaphore>
#include <thread>
#include <unistd.h>
#include <string>

using namespace std;
counting_semaphore sp{1}, sm{0}, ss{0}, sl{0};
int counter = 0;

static void TP(int np, int numOfChars) {
    int n = 0;
    while (1) {
        sp.acquire();
        string s(numOfChars, '+');
        cout << s << endl;
        n++;
        if (np < n) {
            sp.release();
        } else {
            n = 0;
            sm.release();
        }
    }
}

static void TM(int nm, int numOfChars) {
    int n = 0;
    while (1) {
        sm.acquire();
        string s(numOfChars, '-');
        cout << s << endl;
        n++;
        if (nm < n) {
            sm.release();
        } else {
            n = 0;
            ss.release();
        }
    }
}

static void TS(int ns, int numOfChars) {
    int n = 0;
    while (1) {
        ss.acquire();
        string s(numOfChars, '*');
        cout << s << endl;
        n++;
        if (ns < n) {
            ss.release();
        } else {
            n = 0;
            sl.release();
        }
    }
}

static void TNL(int nl) {
    int n = 0;
    while (1) {
        sl.acquire();
        n++;
        cout  << endl;
        if (n == 1) {
            sl.release();
        } else {
            if (n == 2) {
                ss.release();
            } else {
                sp.release();
                n = 0;
            }
        }
    }
}


int main() {
    int nP = 2, nm = 2, ns = 2, nl = 1, numOfCHars = 10;
    thread t1(TP, nP, numOfCHars);
    thread t2(TM, nm, numOfCHars);
    thread t3(TS, ns, numOfCHars);
    thread t4(TNL, nl);
    t1.join();
    t2.join();
    t3.join();
    t4.join();


}