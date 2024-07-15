#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i = 0;
    vector<int> v;
    auto l = [&](int& a){i++; v.push_back(a);};

    while( i<5 ){
        l(i);
        i++;
    }

    for(auto e: v){
        cout << e << endl;
    }

}


