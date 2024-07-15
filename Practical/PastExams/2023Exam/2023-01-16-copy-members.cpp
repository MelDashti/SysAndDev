#include <iostream>
using namespace std;

class Y {

public: //the five copy-control members
    //constructors
    Y()  { std::cout << "dc " << std::endl; } //default constructor dc
    Y(const Y &) {  std::cout << "cc" << std::endl; } //copy constructor cc
    Y(Y &&) noexcept { std::cout << "mc" << std::endl; }; //move constructor mc
    //assignments
    Y &operator=(const Y &) { std::cout << "ca" << std::endl; } //copy assignment ca
    Y &operator=(Y &&) {std::cout << "ma" << std::endl;} //move assignment ma
    //destructor
    ~Y() { std::cout << "d" << std::endl; } //destructor d
};

Y* f_a(){ return new(Y);}
Y f_b(Y& y_b){ return Y(y_b);}

int main() {

    cout << "line 1:" << endl ;
    Y y0;

    cout  << endl << "line 2:" << endl ;
    Y *y1 = f_a();

    cout  << endl << "line 3:" << endl ;
    Y y2 = f_b(y0);

    cout  << endl << "line 4:" << endl ;
    delete(y1);

    cout  << endl << "line 5:" << endl ;
    return 0;
}


