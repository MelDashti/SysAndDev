#include <iostream>
#include <string>

using namespace std;

class Foo {
public:
    string name;
    int age;

    // constructor
    Foo() {
        this->age = 22;
        this->name = "Mel";
    }

    // copy constructor
    Foo(const Foo &foo) {
        this->age = foo.age;
        this->name = foo.name;
    }

    // copy assignment operator
    Foo &operator=(const Foo &foo) {
        this->name = foo.name;
        this->age = foo.age;
        return *this;
    }

    // Move constructor
    Foo(Foo &&foo);

    // Move assigment
    Foo& operator = (Foo&& f) noexcept {}


    // ~ destructor
    ~Foo() {

    }
};

int main() {
    Foo foo;
    cout << foo.name; // this is direct initialization

    Foo foo1 = foo; // this copies the right handside to lefthandside



}








