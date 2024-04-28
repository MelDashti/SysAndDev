#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <deque>
#include <array>

using namespace std;
using std::vector;
using std::list;

void sequentialContainers() {
    // Basic data structures Arrays, matrices, lists, stacks, queues, trees,
    //heaps, hash-tables, etc. Read this before you start: https://www.geeksforgeeks.org/sequential-containers-in-c-stl/ Because these are sequential containers.
    // Sequential containers are the containers that store elements in a sequential manner.

    // In c++ we can use c-like arrays. Arrays can be of data type integer(float), Character, String ( a special type of character array). Pointers are used to access the elements of the array.
    constexpr unsigned N1 = 10;
    const unsigned N2 = 3; // const is used to declare a constant variable. constexpr is used to declare a constant expression.
    int v1[N1]; // v1 is an array of integers of size N1.



    char s2[] = "C--"; //

    // in c++ multidimensional arrays are also possible. For example, a 2D array is an array of arrays.

    constexpr int R = 3;
    constexpr int C = 4;
    int m[R][C]; // m is a 2D array of integers of size R x C.



    // standar for nested loops
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            cout << i << " " << j << endl;
        }
    }
    // Range for nested loops
    for (auto &r: m) {
        for (auto &c: r) {
            cout << c << " ";
        }
        cout << endl;
    }
    // we need the ampersand sign to modify the elements of the array. If we remove the ampersand sign, then the elements of the array will be passed by value.
    // So for example, if we change the value of c, then the value of the element of the array will not be changed.


    // VLA (Variable Length Arrays) are not allowed in c++. VLA is a feature of C99 standard. It allows the creation of arrays whose length is determined at runtime.

    // Generic type are not allowed in c++. In c++ we can use templates to create generic types.
    // Templates are used to create generic types. For example, we can create a generic type of array.

    // we have standard and non standard  containers.

    // Sequential containers are the containers (standard container) that store elements in a sequential manner.
    // Vector : Flexible array that can grow or shrink in size.
    // String: Similar to vector but optimized for strings.
    // List : Doubly linked list. Bi-directional sequential accesss.
    // Forward list: Singly linked list. Unidirectional sequential access.
    // Dequeue: Double ended queue. Bi-directional sequential access. Fast insertion and deletion at both ends.
    // Aarray: Fixed size array. Fast random access.

    // Vectors and strings
    // Inserting an element on the back (yellow) is easy. That depends on the memory we have. Everything depends on the logic  of reallocation of an array. We can use ReAlloc.
    // We can use realloc to increase the size of the array. We can use realloc to decrease the size of the array. We can use realloc to change the size of the array.
    // Realloc is used to change the size of the memory block pointed to by the pointer. It is used to change the size of the memory block pointed to by the pointer.
    // We first copy the elements of the old array to the new array. Then we delete the old array. Then we point the old array to the new array.
    // this is how we use realloc.
    int v0[5] = {1, 2, 3, 4, 5};
    int *p = v0;
    int *q = (int *) realloc(p, 10 * sizeof(int));
    if (q == NULL) {
        cout << "Memory allocation failed." << endl;
    } else {
        p = q;
        for (int i = 5; i < 10; i++) {
            p[i] = i + 1;
        }
        for (int i = 0; i < 10; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        free(p);
    }

    // List and forward lists
    // It is efficient to add or remove an element from anywhere.

    // Deque
    // Are more complicated. The memory is not contiguous. It is a double ended queue. It is a sequence container that allows insertion and deletion at both ends.

    // Array
    // Fixed size array. Fast random access. It is a sequence container that encapsulates fixed size arrays.

    // Selecting a container
    // Use containers whenever possible. Can be used easily and manipulated easily.
    // Small elements and memory matters: Use list or forward list.
    // Random access use a vector or a deque
    //  To insert or delete elements in the middle of the
    //container, use list or forward_list
    //  To insert or delete elements at the front and the
    //back (but not in the middle) use a deque
    // When in doubts, use a vector
    //  Strings have a specific use (to store sequences of
    //characters)

    // To create a new container we can use a default constructor. For example, we can create a vector of integers using the default constructor.
    vector<int> v; // v is a vector of integers.
    // To create a new container we can use a copy constructor. For example, we can create a vector of integers using the copy constructor.
    vector<int> v3(v); // v1 is a vector of integers that is a copy of v.
    // To create a new container we can use an assignment operator. For example, we can create a vector of integers using the assignment operator.
    vector<int> v5 = v; // v2 is a vector of integers that is a copy of v.

    // C c; // default constructor; c is an object of class C

    // First include the header file <vector> or <list> to use the vector container.
    vector<int> r1(10); // 10 values of 0
    vector<int> r2{10}; // 1 value of 10
    vector<int> r3(10, 1); // 10 values of 1
    vector<int> r4{10, 1}; // 2 values of 10 and 1. so the output will be 10 1

    vector<string> rs1{"hello", "world"}; // 2 values of hello and world
    vector<string> rs2{"hello", "world", "!"}; // 3 values of hello, world, and !
    // vector<string> rs3("hello", "world", "!"); // this will give an error. The reason is that the constructor of the vector class takes only one argument.

    list<float> myconst = {1.1, 2.2, 3.3, 4.4, 5.5}; // myconst is a list of floats.
    list<string> authors = {"Milton", "Shakespeare", "Austen"}; // authors is a list of strings.
    // list and vector are prettu much the same. The only difference is that list is a doubly linked list and vector is a dynamic array.
    // the initialization of list and vector is the same. The only difference is that we use curly braces to initialize a list and we use parentheses to initialize a vector.

    deque<string> sd(10); // 10 empty strings

    array<int, 3> a1{{1, 2, 3}}; // double braces required in C++11 prior to N3922
    array<int, 3> a2 = {1, 2, 3}; // double braces not required after C++11

    vector<vector<int>> vvi = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}}; // vvi is a vector of vectors of integers.
    // A container can include another container. For example, we can create a vector of vectors of integers.

    vector<string> vs(10);
    vector<string> vs2(20);
    swap(vs,
         vs2); // swap is used to swap the elements of two containers.  Now vs has 20 elements and vs2 has 10 elements.

    // All containers but arrays provide flexible memory management. They can grow or shrink in size.
    // we add or remove elements at run time.





    list<string> s1;
    s1.push_back("hello");
    s1.push_front("world");
    // doubly linked list. Bi-directional sequential accesss.
    s1.insert(s1.begin(), "!"); // insert is used to insert an element at a specific position in the list.
    // begin() is an iterator.

    vector<string> se;
    cout << se[0];
    // this will give an error. The reason is that the vector is empty.

    // begin() and end() are iterators. They are used to access the first and the last element of the container.
    list<int> st = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = st.begin(); // it is an iterator that points to the first element of the list.
    while (it != st.end()) {
        cout << *it << " ";
        it++;
    }// this will print the elements of the list.
    while (it != st.end()) {
        if (*it % 2 == 0) {
            it = st.erase(it);
        }// this will remove the even elements of the list.









    }
}


void algorithmLibrary() {
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




    // Sort has several variants possible. sort(begin, end) is the simplest. It sorts the elements in ascending order.



    // Examples
    // #include <algorithm>
    // #include <vector>
    // std::vector<unsigned> v = {3, 1, 4, 1, 5, 9};
    // std::sort(v.begin(), v.end());// no predicate is used. The elements are sorted in ascending order.
    // // now v is {1, 1, 3, 4, 5, 9}  sort uses the standard less predicate.

    // include <algorithm>
    // #include <vector>
    // std::vector<string> words = {...};
    // bool isShorter(const string &s1, const string &s2) {
    // return s1.size() < s2.size();  // Ad - hoc predicate
    // sort(words.begin(), words.end(), isShorter); // sort uses the isShorter predicate.
    // Ad hoc means for a particular purpose. It is used to describe something that is created for a specific purpose.

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

    // [my_size](const string &a)
    //{ return a.size() >= my_size; }

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

void input() {
    cout << "Enter the student records (ID, Name< Grade): " << endl;


    cout << "Choose sorting criteria" << endl << "1. Sort By ID" << endl << "2. Sort by Name" << endl
         << "3. Sort by Grade" << endl;


}

struct Student {
    int id;
    std::string name;
    double grade;
    // data structure and output function
};

int main() {
    std::vector<Student> students;
    int id;
    std::string name;
    double grade;
    cout << "Enter the student records (ID, Name< Grade): " << endl;
    while (true) {
        std::cout << ">";
        if (!(std::cin >> id >> name >> grade)) {
            break;
        }
        students.push_back({id, name, grade});
    }
    int n;
    cout << "Enter your choice:" << endl;
    cin >> n;


}


void exercise() {
    int id;
    string name;
    string;


}


int sum(vector<int> &nums) { // how would it be differnt if we remove the & sign?
    // The & sign is used to pass the argument by reference. If we remove the & sign, then the argument will be passed by value.
    // When we pass the argument by value, then the changes made to the argument inside the function will not be reflected outside the function.
    // What is vector in c++? Vector is a sequence container that encapsulates dynamic size arrays.
    // For example, you can create a vector of integers and use it as an array.
    // It is basically an array that can change its size.
    // In java it is called ArrayList. And in python it is called list.
    // In c++ it is called vector.
    int sum = 0;
    for (int k: nums) {
        cout << k << " ";
        sum += k;
    }
    cout << "The sum of the above sequence of numbers is: " << sum << endl;
    cout
            << "As nums vector is passed by reference, the changes made to the nums vector inside the function will be reflected outside the function."
            << endl;
    // Vector has methods like push_back, pop_back, insert, erase, clear, empty, size, etc.
    nums.push_back(100);// push_back is used to add an element at the end of the vector.
    nums.pop_back();// pop_back is used to remove the last element of the vector.
    nums.resize(10);// resize is used to change the size of the vector.
    nums.insert(nums.begin() + 2, 200);// insert is used to insert an element at a specific position in the vector.
    // here we are inserting 200 at the 3rd position of the vector.
    // the reason why nums.insert(3,200) gives an error is because the first argument of the insert method is an iterator.
    // nums.begin() + 2 is an iterator that points to the 3rd element of the vector.
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sum(nums);
    cout << "The changes made to the nums vector inside the function are reflected outside the function." << endl;
    cout << nums.size() << endl;
    return 0;
}
