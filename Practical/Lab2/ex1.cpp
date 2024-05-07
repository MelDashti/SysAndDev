#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++) {
        threads.push_back(std::thread([]() {
            cout << "Hello from thread " << this_thread::get_id() << endl;
        }));
    }
    for (auto &thread: threads) {
        thread.join();
    }
    return 0;
}


