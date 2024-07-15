#include <iostream>
#include <thread>
#include <semaphore>

using namespace std;

counting_semaphore sA{1}, sBorC{0}, sD{0}, sE{0};
mutex mtx;
bool isEnd;
bool dAndE;

void TA() {
    while (1) {
        sA.acquire();
        mtx.lock();
        cout << "A";
        if (isEnd) {
            cout << endl;
            sA.release();
            isEnd = false;
        } else {
            cout << "-";
            sBorC.release();
        }
        mtx.unlock();
    }
}

// sB or sC
void TB() {
    while (1) {
        sBorC.acquire();
        cout << "B-";
        sD.release();
        sE.release();
    }
}

void TC() {
    while (1) {
        sBorC.acquire();
        cout << "C-";
        sD.release();
        sE.release();
    }
}

void TD() {
    while (1) {
        sD.acquire();
        cout << "D-";
        mtx.lock();
        if (dAndE) {
            sA.release();
            dAndE = false;
            isEnd = true;
        } else
            dAndE = true;
        mtx.unlock();
    }
}

void TE() {
    while (1) {
        sE.acquire();
        cout << "E-";
        mtx.lock();
        if (dAndE) {
            sA.release();
            dAndE = false;
            isEnd = true;
        } else
            dAndE = true;
        mtx.unlock();
    }
}

int main() {

    thread t1(TA);
    thread t2(TB);
    thread t3(TC);
    thread t4(TD);
    thread t5(TE);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

}