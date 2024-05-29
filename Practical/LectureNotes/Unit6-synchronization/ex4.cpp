#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

#define N 10

struct Best {
    int rank;
    std::thread::id id;
    int num_votes;
    std::mutex mutex;
};

Best* best;
std::condition_variable cv;

int main() {
    best = new Best();
    best->rank = best->num_votes = 0;

    std::vector<std::thread> threads;

    for (int i = 0; i < N; i++) {
        threads.emplace_back([i]() {
            int rank = i; // Assign a rank to pi
            std::thread::id id = std::this_thread::get_id();

            std::unique_lock<std::mutex> lock(best->mutex);
            if (rank > best->rank) {
                best->rank = rank;
                best->id = id;
            }
            best->num_votes++;
            if (best->num_votes < N) {
                cv.wait(lock);
            } else {
                cv.notify_all();
            }
            lock.unlock();

            std::cout << "my_id=" << id << " my_rank=" << rank << " leader_id=" << best->id << " leader_rank=" << best->rank << std::endl;
        });
    }

    for (auto& th : threads) {
        th.join();
    }

    delete best;

    return 0;
}