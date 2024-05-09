#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {


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
//    int i = 20;
//    auto lambda1 = [i]() { return i + 42; };
//    auto lambda2 = [&i]() { return i + 42; };
//    i = 0;
//    int a = lambda1();
//// Now a = 20+42 = 62
//    int b = lambda2();
//// Now b = 0+42 = 42

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

void algoLibEx() {

}

void dynamicMemory() {

// Dynamic Memory
// Our C++ programs so far have use only
// static memory, that store static objects.
// Objects allocated in the static and stack memory.

// Programs can use heap memory. The heap is used to store dynamic objects.
// The strategy directly derives from the C language.


// in C functions, Malloc, calloc and free are used to allocate and deallocate memory.
// C++ function: new and delete are used to create and destroy objects.

// The new operator is used to allocate memory for an object. Allocates unnamed objects, thus returns a new pointer.

// int * v1 = new int; // single variable initialized to 0

// There are two versions of new.
// The normal version where it fires an exception when memory is not available. Never returns a null pointer.
// The nothrow version where it returns a null pointer when memory is not available. Never fires an exception.

// Like in c, a pointer does not know the number of elements to which is pointing to. It just knows the address of the first element.

// The delete operator free previously allocated memory.
}