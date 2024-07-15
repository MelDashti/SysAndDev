#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


// C++ templates are used to make functions and classes independent of data types, supporting
// generic programming. If we use templates we can write more general classes and functions that accept
// any type of data. At compile-time, the compiler produces the needed version of the functions and classes
// depending on the parameters used for calling them. We need to define a template before defining a function/class using that template.


// for functions
template<typename T>
bool compare(T first, T second) {
    return first < second;
}

// for classes
template<typename T>
class Foo {
private:
    T element;
public:
    T get_elem() {
        cout << element << endl;
    }
};

// note we can use different types of template
template<typename T, typename R>
void print(T first, R second) {
    cout << first << second;
}


int main() {
// When we call such functions and classes from the main, for functions we can omit
// the datatype, but for classes the compiler cannot deduce the type and we must specify it.
    print(2, 3);
    Foo<int> t; // for this one we have to define it.
}

// To organize the code this code into separate files we have numerous options,
// we can define and declare template classes and functions in a .h file,  to be includes in the main cpp file.
// declare the template classes and functions in a h file, write the template class or function implementation in a
// .hpp file, and then include both .h and .hpp files in the main cpp file.
// declare the class and the template in the .h file, write the template class or function implementation in a
// .cpp file, adding into the latter an explicit template instantiation, such as template class FifoList<string>;
// template class FifoList<int>;

