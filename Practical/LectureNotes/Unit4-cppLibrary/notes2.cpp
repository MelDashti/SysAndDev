#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

int main() {

}

void copyControl() {
    // Copy control is performed by copy and move constructors, destructor, and copy and move assignment operators.
    // Copy control is used to manage the copying and moving of objects.
}


void algorithmLibrary() {

    // Instead of defining each operation as part of each container, the standard library defines
    // a set of generic algorithms.
    // Generic because they operate on elements of different type.
    // Algorithms because they implement classical procedures, like sorting, searching, etc.

    // In all the examples: b is the begin iterator, e is the end iterator
    // v a value.


    // It is essential
    // many algorithms require a predicate. A predicate is a function that returns a boolean value. For example, we can create a predicate that returns true if the element is even and false otherwise.
    // It returns a value that can be used as a condition.
    // The default version of algorithm usually uses a standard predicate. For example, the default version of the find algorithm uses the equal_to predicate.
    // eg. <, ==, >, <=, >=, !=, etc.
    // The extended version usually supplies its own predicate.
    // The extended version usually supplies its own predicate.

    // Search has several variants possible. find(begin, end, value) is the simplest. It returns an iterator to the first element that matches the value.
    // find_if(begin, end, predicate) is used to find the first element that satisfies the predicate.
    // find_if_not(begin, end, predicate) is used to find the first element that does not satisfy the predicate.

    vector<int> v = {1, 2, 3, 4, 5, 2, 1};
    auto res1 = std::find(v.begin(), v.end(), 2);
    // if value exists the first position of the value 2 is returned if not v.end().
    if (res1 == v.end()) {
        cout << "NOT FOUND";
    }

    // Sort has several variants possible. sort(begin, end) is the simplest. It sorts the elements in ascending order.

    vector<unsigned> v2 = {3, 1, 4, 1, 5, 9};
    sort(v2.begin(), v2.end());// no predicate is used. The elements are sorted in ascending order.
    // // now v is {1, 1, 3, 4, 5, 9}  sort uses the standard less predicate.

    // Binary Search
    // time complexity is o(log(n)). The elements must be sorted.

    vector<int> arr1 = {10, 15, 20, 25, 30, 35};
    vector<int> arr2 = {10, 15, 20, 20, 25, 30, 35};
    vector<int> arr3 = {10, 15, 25, 30, 35};
    // prints 2
    cout << lower_bound(arr1.begin(), arr1.end(), 20) - arr1.begin() << endl;
    // prints 2
    cout <<
         lower_bound(arr2.begin(), arr2.end(), 20) - arr2.begin() << endl;
    // prints 2 (index of next higher)
    cout <<
         lower_bound(arr3.begin(), arr3.end(), 20) - arr3.begin();

    //  we use binary_search to check if 15 exists
    if (binary_search(arr1.begin(), arr1.end(), 15)) //
        cout << "15 exists in vector";
    else
        cout << "15 does not exist";

    std::vector<string> words = {};

    vector<int> v20{39, 20, 30, 40, 55, 66, 77, 93, 100};

    sort(v20.begin(), v20.end());
    for (int i: v20) {
        cout << i;
    }


    //    bool isShorter(const string &s1, const string &s2){
//        return s1.size() < s2.size();
//    };// Ad - hoc predicate
//    sort(words.begin(), words.end(), isShorter()); // sort uses the isShorter predicate.

    // Ad hoc means for a particular purpose. It is used to describe something that is created for a specific purpose.

    // Permutations

    // Print all permutations of 'abc'
    string a = "abc";
    sort(a.begin(), a.end());
    do {
        cout << a << '\n';
    } while (next_permutation(a.begin(), a.end()));


    // Introduction to set.
    // A set is a container that stores unique elements. It is a sequence container that stores unique elements.
    // The elements of the set are sorted in ascending order. The elements of the set are sorted in ascending order.


    // Lambda expressions
    // [capture_list] (parameter_list) -> return_type {body}
    // A lambda expression is an anonymous function. It is a function that does not have a name. It is a function that does not have a name.
    //    It can be thought of as an unnamed, inlinefunction
    //     Like any other function, a lambda has
    //     A parameter list, a return type, and a function body Unlike any other function, a lambda
    //     May be defined inside a function
    //     Being an internal function has a capture list
    // Capture list is used to capture variables from the enclosing scope. It is used to capture variables from the enclosing scope.
    // The parameter list is used to pass arguments to the lambda expression. It is used to pass arguments to the lambda expression.
    // The return type is used to specify the return type of the lambda expression. It is used to specify the return type of the lambda expression.
    // For example, we can create a lambda expression that takes two integers as arguments and returns the sum of the two integers. Like in the following:
    auto sum = [](int a, int b) -> int { return a + b; };
    // Auto is used to automatically deduce the type of the variable. It is used to automatically deduce the type of the variable.
    auto minus = [](int a, int b) -> int { return a - b; };
    // Here [] is the capture list. It is used to capture variables from the enclosing scope. Here [] is the capture list. It is used to capture variables from the enclosing scope.
    // We use the function call operator () to call the lambda expression. We use the function call operator () to call the lambda expression.
    minus(10, 5); // this will return 5.

    // [](const string &a, cont string &b) {return a.size() < b.size();} is a lambda expression that takes two strings as arguments and returns true if the size of the first string is less than the size of the second string.
    // You might ask we use const string &a instead of string a. The reason is that we want to pass the string by reference. If we pass the string by value, then the changes made to the string inside the lambda expression will not be reflected outside the lambda expression.

//    [my_size](const string &a) { return a.size() >= my_size; }

//    auto wc = find_if(words.begin();
//    words.end();)
//    [sz](const string &a)
//    { return a.size() >= sz; });

    // int callFunc(int (*func)(int, int), int arg1, int arg2) {return func(arg1, arg2);
    //}
    //auto lambda = [](int arg1, int arg2) {
    //return arg1 + arg2;
    //};
    //int i = callFunc(lambda, 2, 4);
    //// Now i = 6
    //int j = lambda(5, 6);
    //// Now j = 11

//    int i = 0;
//    int j = 42;
//    auto lambda1 = [i](){}; // i by-copy
//    auto lambda2 = [&i](){}; // i by-reference
//    auto lambda3 = [&j, i](){}; // j by-reference, i by-copyauto lambda4 = [=, &i](){}; // j by-copy, i by-reference// ERROR: non-diverging capture types
//    auto lambda5 = [&, &i](){};
//// ERROR: non-diverging capture types
//    auto lambda6 = [=, i](){};

//    The capture is done at the definition, thus
//     In the capture by value, the value is persistent
//     In the capture by reference, the reference is
//    persistent (not the value)
    int i = 20;
    auto lambda1 = [i]() { return i + 42; };
    auto lambda2 = [&i]() { return i + 42; };
    i = 0;
    int r = lambda1();
// Now a = 20+42 = 62
    int b = lambda2();
// Now b = 0+42 = 42

//    transform (v.begin(), v.end(), v.begin(),
//               [](int i) { return i < 0 ? –i : i; }
//    );
//    transform (v.begin(), v.end(), v.begin(),
//               [](int i) -> int
//               { if (i<0) return –i; else return i; }
//    );
//    The algorithm transform takes three iterators:
//    It transform the values included in the range specified by the first two iterators copying them to the third iteratorThere is only a return statement in the
//    body; the type of the lambda is automatic
//    Here, there are other statements, we need to
//    define the return type with the trailing return
}

void dynamicMemory() {


// Programs can use heap memory. The heap is used to store dynamic objects.
// The strategy directly derives from the C language.


// in C functions, Malloc, calloc and free are used to allocate and deallocate memory.
// C++ function: new and delete are used to create and destroy objects.

// Old c like functions can also be used in c++ or new and delete can be used.
// New is similar to malloc and delete is similar to free. Like in c memory is managed directly.

// Like in C, a pointer does not know the type of the object to which it is pointing to
// It just knows the address of the first element.

    int *t = new int; // this is like malloc cuz it is a single variable with no initialization (malloc)
    // hence *t is undefined

    int *t2 = new int(); // this is like calloc, cuz single variable initalized to 0;

    int *t3 = new int(12); // this is a single variable initalized to 12 similar to calloc.

    int *p2 = new int; // if allocation fails it throws bad_alloc.

    // but when we write it this way
    int *p1 = new(nothrow) int; // if the allocation fails it returns nullptr

    int *p3 = new(nothrow) int[20]; // array of size 20 or a nullptr

    // It is possible to allocate constant objects
    const int *ptr = new const int(100); // returned pointer is pointer to the constant object

    // const my_class *p5 = new const my_class;

    // A pointer doesn't know the number of elements to which it is pointing to
    // It just knows the address of the first element.

    double *ptr1 = new double;
    *ptr1 = 7.3; // works fine
    ptr1[0] = 8; // this is equivalent to (ptr1 + 0) so fine
    ptr1[3] = 9; // this doesn't work

    double *ptr2 = new double[20];
    *ptr2 = 7.3; // works fine
    ptr2[0] = 8; // this is equivalent to (ptr1 + 0) so fine
    ptr2[3] = 9; // this works well now

    // again just like in c the pointer also does not know the type of the object to which it is pointing to
    // it just knows the address of the first element.

    // To avoid memory exhaustion, we must return the allocated memory to the system.
    // A dynamic object exists until
    delete (ptr); // this is how you delete for single objects
    delete[] (ptr2); // this is how we delete for an array
    // for a class just delete p.  It calls the destructor.

    // Dynamic objects managed through built-in pointers exist until they are explicitly deleted
    // Dangling pointers and mem leaks

    // To avoid dangling pointers we can set the pointer to nullptr when we define a pointer
    // or delete a pointer

    int *ptrr = nullptr;

    // after deleting
    delete (ptrr);
    ptrr = nullptr;
    // Unfortunately, bugs are easy to introduce and these tricks are not to avoid dangling pointers and mem leaks

    // we can use sequential and associative containers which don't require the explicit use of new and delete
    // Or we can use an automatic garbage collector.
    // C++ implements this technique through smart pointers.
    // Automatically deletes when out of scope
    // this techinique is often referred to as RAII
    //    A resource is available during the entire lifetime of
    //    the object (pointer)
    //     The resource is released when the lifetime of the
    //    object (pointer) ends

    // We have three different types of smart pointers.
    // we have three types, shared_ptr, unique_ptr, and weak_ptr

    // Shared pointers.
    // the safest way to allocate mem is to call make_shared.
    // this func allocates and initializes a resource into the heap
    // and returns a shared pointer pointing to it.

    shared_ptr<string> sharedPtr; // shared pointer points to a string, if we don't initialize it will point to a nullptr
    shared_ptr<vector<int>> sharedPtr1;

    // we can allocate shared pointers using the new operator in c++
    // It's possible to use new, but its not the recommended way as it's less efficient and requires two allocations
    // one for the mem and another for the counter that keeps track of how many shared pointers are pointing to the same location.
//    shared_ptr<int> p11 = new int(42); // incorrect
    shared_ptr<int> p11(new int(42)); // this works
//    shared_ptr<int> p3 = shared_pointer<int>(new int(9)); // this works too

    shared_ptr<int> p0 = make_shared<int>(20);
    shared_ptr<int> p = make_shared<int>(10);
    p0 = p;
    // p now points to q.

    // unique pointers
    unique_ptr<int> uniquePtr(new int(14));
    // unique pointers can't be copied but when they are about to be destroyed you can return like this
    // return unique_prt<int>(new int(ptr));




    //

}

