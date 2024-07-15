#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i = 0;
    vector<int> v{1,2,3};
    auto l = [&](int& a){ memcpy(&v[i],&a,1*sizeof(int));};

    int temp;
    while( i<3 ){
        temp = v[i]*2;
        cout << temp << endl;
        l(temp);
        i++;
    }

    cout << "***" << endl;
    for(auto e: v){
        cout << e << endl;
    }
}


