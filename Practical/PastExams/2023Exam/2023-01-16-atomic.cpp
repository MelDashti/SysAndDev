#include <iostream>
#include <vector>
#include <future>

using namespace std;
std::atomic<int> ai ;


void write(int n){
    ai.fetch_add(n);
}


int main () {
    ai = 0;
  vector<future<void>> writers;

    for(int i = 0; i < 3; i++){
      writers.emplace_back( async(std::launch::deferred,write,i));
    }

    //comment or uncomment to check the effect
    //for(auto& w : writers ){ w.get();}

    cout << "ai: " << ai << endl;

    return 0;
}



