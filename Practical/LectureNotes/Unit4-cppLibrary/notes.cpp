#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <deque>
#include <array>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
using std::vector;
using std::list;

int main() {


}


void sequentialContainers() {
    // Basic data structures Arrays, matrices, lists, stacks, queues, trees,
    //heaps, hash-tables, etc. Read this before you start: https://www.geeksforgeeks.org/sequential-containers-in-c-stl/ Because these are sequential containers.
    // Sequential containers are the containers that store elements in a sequential manner.

    // In c++ we can use c-like arrays. Arrays can be of data type integer(float), Character, String ( a special type of character array). Pointers are used to access the elements of the array.
    constexpr unsigned N1 = 10;
    const unsigned N2 = 3;
    // the difference between const and constexpr is that const is evaluated at runtime and constexpr is evaluated at compile time.
    // So does it make a difference if we use const or constexpr? Yes, it does. If we use const, then the value of the variable will be evaluated at runtime.
    int v1[N1]; // v1 is an array of integers of size N1.
    int v2[] = {1, 2, 3, 4, 5};// don't need to mention the size it will be calculated on its own
//    int v6[]; // this will raise an error
    int v3[N1] = {1, 2, 3}; // this will be equal to 1, 2, 3, 0, 0, 0, 0, 0, 0, 0

    char s1[] = {'a', 'b', 'c'};
    char s2[] = "C--"; // creates a c like string with a null character at the end. so the array contains : C, -, -, \0
    // in c++ multidimensional arrays are also possible. For example, a 2D array is an array of arrays.

    // C-like strings are not a type, they are array of characters, null terminated.


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
    // Array: Fixed size array. Fast random access.

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
    // unlike vectors and strings, which require potentially expensive reallocation.



    // Deque
    // Are more complicated. The memory is not contiguous. It is a double ended queue. It is a sequence container that allows insertion and deletion at both ends.
    // Support Random access memory, and it's difficult to add and remove elements in the middle of the deque.
    // Fast for removing and adding elements at the front and the back. It is a sequence container that encapsulates double ended queues.
    // The memory is not contiguous.

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
    vector<int> v8(v); // v8 is a vector of integers that is a copy of v.
    // To create a new container we can use an assignment operator. For example, we can create a vector of integers using the assignment operator.
    vector<int> v5 = v; // v5 is a vector of integers that is a copy of v.
    // any changes made to v5 will not be reflected in v. Cuz it's just a copy


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
    // The reason why swap is good, because we don't need to copy the elements of the two containers. We just need to swap the pointers of the two containers.

    // All containers but arrays provide flexible memory management. We can add or remove elements at runtime.

    list<string> s10;
    s10.push_back("hello"); // push_back is used to add an element at the end of the list.
    s10.emplace_back("world"); // emplace_back is used to add an element at the end of the list.
    // difference between push_back and emplace_back is that push_back copies the element to the list and emplace_back moves the element to the list.
    s10.push_front("world");
    s10.emplace_front("hello");
    s10.insert(s10.begin(), "!"); // insert is used to insert an element at a specific position in the list.
    // doubly linked list. Bi-directional sequential accesss.
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
        if (*it % 2 == 0)
            it = st.erase(it);
    }// this will remove the even elements of the list
    struct student_t {
        int rn;
        string last_name, first_name;
        int mark;
    } myt;
    vector<student_t> students;

}


void associativeContainersEx() {
//    Write a C++ program that reads a paragraph of
//    text (a line of text) from the user
//     Tokenize the input paragraph into words
//     Ignore punctuation, consider only alphabetic
//    characters, and transform characters in lowercase
//     Create a map in which
//     Words (in the text) are keys
//     Values are frequencies (of that word in the text)
//     Display the list of unique words and their
//    frequencies alphabetically
//     Find and display the total number of unique words
//    in the paragrap
//    Prompt the user to enter a word and then search
//    the map to display the frequency of that word
//     Create a set containing the unique words from the
//    paragraph
//     Display the unique words in the set sorted
//    alphabetically
}

void associativeContainers() {
    // Associative containers are the containers that store elements in a sorted order, typically based on keys associated with the elements.
    // The main associative containers in C++ are set, map, multiset, multimap, unordered_set, unordered_map, unordered_multiset, and unordered_multimap.
    // The two primary associative containers are set and map.
    // Maps, whose elements are key-value pairs. The key is used to access the value.
    // Sets, whose elements are just keys.

    // The word multi means multiple keys. Unordered means the use of a hash function.
    map<string, int> myMap;  // emppty map
    map<string, string> authors = {
            {"Meelad", "Dashti"},
            {"name",   "lastName"}
    };
    map<string, size_t> word_count;
    word_count.insert({"hello", 1});
    word_count.insert({"world", 2});
    word_count.insert({"!", 3});
    word_count.insert({"!", 4});
    word_count.insert(pair<string, size_t>("!", 5));
    // pair is a template class that stores two values. The first value is the key and the second value is the value.
    word_count.insert(make_pair("!", 6));
    // make_pair is a function that creates a pair object. It takes two arguments and returns a pair object.
    word_count.insert(map<string, size_t>::value_type("!", 7));
    // value_type is a type that is used to store the key and the value of the map.

    // The pair type
    pair<string, int> anon; // default constructor; anon has an empty string and 0
    pair<int, int> p(42, 21); // p has the value 42 and 21
    pair<int, int> p2 = make_pair(42, 21); // same as p

    // Compute the absolute frequency of input words.
    map<string, size_t> word_count2;
    string word;
    while (cin >> word) {
        auto ret = word_count2.insert({word, 1});
        if (!ret.second) {
            ++ret.first->second;
        }
    }
    // Iterating through a map.
    for (const auto &w: word_count2) {
        cout << w.first << " occurs " << w.second << " times." << endl;
    }
    // or
    auto it = word_count2.begin();
    while (it != word_count2.end()) {
        cout << it->first << " occurs " << it->second << " times." << endl;
        it++;
    }

    // Set
    set<int> s = {0, 2, 3, 1, 4, 5, 6, 7, 8, 9};
    auto it1 = s.find(1);
    // the find function returns an iterator pointing to the element
    // if it is found, otherwise it returns an iterator pointing to set::end.

    auto it2 = s.find(11); // since we don't have 11 it returns an iterator pointing to the end

    auto n1 = s.count(1); // since the occurrences are always 1.
    // it will return the num of occurence as 1 if exists.

    vector<int> vec2 = {2, 3, 4, 3, 4, 5, 6, 6};
    s.insert(vec2.begin() + 1, vec2.end());




    // Associative array exercise
    associativeContainersEx();
}





