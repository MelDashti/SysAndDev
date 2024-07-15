#include<iostream>
#include<vector>
#include<string>

using namespace std;

void slide1To2() {
    int v1, v2; // define two integers
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> v1 >> v2; // Read input value
    std::cout << "Revision" << std::endl;
    std::cout << "Hi!" << std::flush; // flushes the buffer
    std::cout << "HEllo" << std::ends;

    int sum = 0, value = 0;
    while (std::cin >> value)
        sum += value;
    std::cout << sum << std::endl;

    unsigned i = 10;
    int j = -44;
    cout << i + j << endl; // here we get the sum 4294967262 because the value of j is converted to unsigned int
    cout << i + i << endl; // here we get the sum 20
    cout << j + j << endl; // here we get the sum -88

    // pointers
    int *p; // pointer to an integer
    int x = 42;
    p = &x; // p holds the address of x
    // *p is the object to which p points. Dereferencing p yields the object to which p points
    cout << *p << endl; // prints 42
    // pointers are use for dynamic memory allocation
    int arr[5] = {2, 3, 1, 2, 3};
    int *p1 = arr; // p1 points to the first element of the array
    p1++; // p1 now points to the second element of the array
    cout << *p1 << endl; // prints 3

    int *ptr = nullptr; // null pointer, don't point to any valid address.

    // pointers
    int arr2[5] = {1, 6, 7, 2, 5};
    int *p3 = arr2;
    p3++;
    // p3 now points to the second element of the array
    cout << p3 << endl; // prints the address of the second element of the array
    cout << *p3 << endl; // prints 6
    int (*p4)[5] = &arr2; // p4 points to an array of 5 integers
    cout << (*p4)[0] << endl; // prints 1


    // reference
    int r = 33;
    int &ref = r; // ref is a reference to x
    int y = r;
    cout << ref << endl; // prints 33
    cout << r << endl; // prints 33
    cout << y << endl; // prints 33
    ref = 44; // changes the value of x to 44 but not y
    cout << ref << endl; // prints 44
    cout << r << endl; // prints 44
    cout << y << endl; // prints 33

    // Qualifiers
    int v3 = 10;
    int *const p5 = &v3; // p5 is a constant pointer to an integer, here the value of p1 cannot be changed
    int const *p6 = &v3; // p6 is a pointer to a constant integer, here the value of v1 cannot be changed
    cout << *p5 << endl; // prints 10
    cout << *p6 << endl; // prints 10

    // p6++; // error: increment of read-only variable ‘p1’
    p6++; // works fine

//    p1 = nullptr; // error: assignment of read-only variable ‘p1’
    p6 = nullptr; // works fine
// The auto specifier
    // A variable defined with the auto specifier must be initialized.
    auto i20 = 0;
//    auto a; // error: ‘a’ declared as auto without initializer
    auto a = 10;
//    Although auto deduces the type of a variable at compile time, it still provides compile-time type checking. This means that the type inferred by auto must be compatible with the initializer expression, preventing type mismatch errors.
    auto x2 = 42; // Compiler infers x as an int
//    x = "Hello"; // Error: Cannot assign a string literal to an int

    // decltype specifier
    // used to deduce the type of variable at compile time.
    int x3 = 10;
    decltype(x3) y4 = 20; // declares y with the same type as x (int)

    /// Type conversion
    // Implicit type conversion
    int i0 = 10;
    double h = i0; // implicit conversion from int to double
    cout << h << endl; // prints 10.0

    // Explicit type conversion
    double d1 = 10.5;
    int d2 = (int) d1; // explicit conversion from double to int
    cout << d2 << endl; // prints 10

    // static_cast
    double d3 = 10.5;
    int d4 = static_cast<int>(d3); // explicit conversion from double to int
    cout << d4 << endl; // prints 10
    // static_cast can be used for pointer conversions between related types, but it doesn't perform any runtime type checking. It assumes that the conversion is valid based on the static type information known at compile time.
    int d5 = 10;
    void *voidptr = &d5;
    int *intptr = static_cast<int *>(voidptr); // explicit conversion from void* to int*

    // Difference between null pointer and void pointer
    // A null pointer is a pointer that doesn't point to any memory location. It is used to represent that the pointer is not pointing to a valid memory location.
    // A void pointer is a pointer that doesn't have any type associated with it. It can be used to store the address of any type of object.

    // const_cast
    // const_cast is used to add or remove the const qualifier from a variable. It is mainly used to cast away the constness of a variable.
    const int i22 = 10;
    int *p22 = const_cast<int *>(&i22); // cast away the constness of i
    *p22 = 20; // changes the value of i
    cout << i22 << endl; // prints 20

    // reinterpret_cast
    // reinterpret_cast is used to convert one pointer type to another pointer type. It is mainly used for low-level programming where you need to interpret the bit pattern of a pointer as a different type.
    int i33 = 10;
    auto *p33 = reinterpret_cast<double *>(&i33); // reinterpret i as a double pointer

    vector<int> v4 = {1, 2, 3, 4, 5};
    for (auto k: v4) {
        k += 2;
        cout << k << endl;
    }// adds values to the copies of the array elements
    for (auto &g: v4) {
        g += 2;
        cout << g << endl;
    }// creates a ref to elements of the array and adds 2 to the elements of the array.



}

void slide3and4() {
    // slides3 is easy to understand from the slides itself
    // Structs and unions are two different ways of organizing data in C++.
    struct Person {
        string a;
        int x;
        int y;
    };
    Person person1;
    person1.a = "John";
    person1.x = 25;
    person1.y = 30;
    cout << person1.a << endl;
    cout << person1.x << endl;
    cout << person1.y << endl;

    // Unions
    // A union is a user-defined data type that allows you to store different data types in the same memory location. Unlike structures, unions can only store one value at a time.
    union Data {
        int i;
        float f;
        char str[20];
    };
    Data data;
    data.i = 10;
    data.f = 220.5; // this will overwrite the value of i
    cout << data.i << endl;

    struct my_class {
        int code;

        int get_code() {
            return code;
        }

        void print_code();
    };
//
//    void my_class::print_code(){
//        cout << code << endl;
//    }

    // Struct, objects are public by default
    // Class, objects are private by default

    class my_class2 {
    private:
        int code;
    public:
        //Member initialization is a feature in C++ that allows you to initialize member variables of a class or struct directly in the constructor's initialization list rather than within the constructor body.
        my_class2() : code(0) {}

        my_class2(int c) { code = c; }

        int get_code() {
            return code;
        }

        void print_code();
    };
    // destructor
    // A destructor is a special member function of a class that is called when an object of the class goes out of scope or is explicitly deleted. It is used to release resources acquired by the object during its lifetime.
    // no need of destructor if we only use static resources, but if we use dynamic resources then we need to delete them in the destructor.


}


int main() {


    return 0;
}
