// First call 2023 question.
// Use tasks promises and future to implement three threads T1, T2, and T3 executed directly by the main thread
// such that:
// T1 reads astring from standard input, transfers that string to T2, and terminates.
// T2 transforms the string received from T1 into capital letters, transfers it to T3,and terminates.
// T3 displays the string received from T2 on standard output and terminates.
#include <algorithm> // for using transform
#include <cctype> // for using toupper
#include <iostream>
#include <future>
#include <thread>

using namespace std;

void T1(promise<string> p1) {
    string a;
    cout << "Enter a string";
    cin >> a;
    p1.set_value(a);
}

void T2(future<string> f1, promise<string> p2) {
    string b = f1.get();
    transform(b.begin(), b.end(), b.begin(), ::toupper);
    p2.set_value(b);
}

void T3(future<string> fres) {
    cout << fres.get();
}

int main() {
    promise<string> p1;
    future<string> f1 = p1.get_future();
    promise<string> p2;
    future<string> res = p2.get_future();

    auto th1 = async(::launch::async, T1, ::move(p1));
    auto th2 = async(::launch::async, T2, ::move(f1), ::move(p2));
    auto th3 = async(launch::async, T3, ::move(res));

    th1.get();
    th2.get();
    th3.get();
}

// Cyclic Solution
//#include <algorithm>
//#include <cctype>
//#include <iostream>
//#include <future>
//#include <thread>
//
//using namespace std;
//
//void T1(promise<string> p1) {
//    string a;
//    cout << "Enter a string (type 'exit' to quit): ";
//    cin >> a;
//    p1.set_value(a);
//}
//
//void T2(future<string> f1, promise<string> p2) {
//    string b = f1.get();
//    transform(b.begin(), b.end(), b.begin(), ::toupper);
//    p2.set_value(b);
//}
//
//void T3(future<string> fres) {
//    cout << fres.get() << endl;
//}
//
//int main() {
//    while (true) {
//        // Set up promises and futures
//        promise<string> p1;
//        future<string> f1 = p1.get_future();
//        promise<string> p2;
//        future<string> res = p2.get_future();
//
//        // Launch threads using async
//        auto th1 = async(::launch::async, T1, ::move(p1));
//        auto th2 = async(::launch::async, T2, ::move(f1), ::move(p2));
//        auto th3 = async(::launch::async, T3, ::move(res));
//
//        // Wait for threads to complete
//        th1.get();
//        th2.get();
//        th3.get();
//
//        // Check for termination condition
//        if (f1.get() == "exit") {
//            break;
//        }
//    }
//
//    return 0;
//}

