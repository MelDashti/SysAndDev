#include <iostream>

using namespace std;

int main(){
    //01 What is dynamic memory allocation in c++.
    // Ans: Dynamic memory allocation in c++ is done using  the keywords DELETE AND NEW.
    // A pointer is returned which points to the address of the beginning of the allocated block of memory.
    //Official Ans: Dynamic memory allocation in C++ refers to the process of allocating
    //memory at runtime, allowing programs to request and release memory as
    //needed. This is typically done using operators such as new and delete
    //or with smart pointers.

    //02. Explain the difference between stack memory and heap memory?
    // Ans: Stack memory is used to store static objects or static data members defined inside classes.
    // Heap memory is used to store dynamic objects,
    // Official Ans: Stack memory is used for local variables and function call frames, and its allocation and deallocation
    // are managed by the compiler. Heap memory, on the other hand, is used for dynamically allocated memory, and it's
    // allocation and deallocation are managed by the programmer.

    //03. What is the new operator in C++, and how does it relate to dynamic memory allocation?
    // Ans. The NEW operator in c++ is used for dynamic memory allocation, it returns a pointer pointing to the address of
    // the beginning of the new memory block allocated.
    // Official Ans: The new operator is used in c++ to dynamically allocate memory for a single object or an array of objs.
    // It allocates memory from the heap and returns a pointer to the allocated memory.

    //04. What is the purpose of the delete operator in C++?
    // Ans: Delete operator is used to deallocated allocated memory created from the New operator. It is used to prevent
    // memory leaks
    // Official Ans: The delete operator is used in C++ to deallocate memory that was allocated using the new operator.
    // It releases the memory back to the system so that it can be reused.

    // 05. What are memory leaks, and how can dynamic memory allocation contribute to them?
    //ans:  Memory leaks are caused when dynamic memory is located and isn't deallocated after use.
    //official ans: Memory leaks occur when memory that is no longer needed is not
    //properly deallocated, leading to a gradual depletion of available
    //memory. Dynamic memory allocation can contribute to memory leaks if
    //memory allocated with new is not properly deallocated with delete.

    // 06. What are smart pointers in C++, and why are they used?
    // Official Ans: Smart pointers are objects that manage dynamically allocated memory
    //automatically, ensuring proper deallocation when the pointer goes out
    //of scope. They are used to prevent memory leaks and simplify memory
    //management in C++.

    // 07. Describe the differences between std::unique_ptr, std::shared_ptr,
    //    and std::weak_ptr.
    // my ans: unique,shared and weak pointer are three different pointers used for dynamic memory allocation they avoid memory leaks and dangling pointers.
    //Unique pointer is used to allocate memory efficiently to a single variable or array, no other variable can use from this pointer or assign it to another value.
    //For example: unique_ptr<int> a(new int(3));
    //unique_ptr<int> b = a; // this will give an error because unique pointer is designed to maintain an exclusive ownership on the object.
    //Shared pointer on the hand, can be used by other variables and the ownership is not exclusive.
    //shared_ptr<int> p1 = make_shared<int>(3);
    //shared_ptr<int> p2 = p1; // this will not generate an error as they can be shared
    //Finally, we have weak_ptr which doens't update it's count when a pointer is shared with another, this change in structure help avoid error circular loops in reference.
    // Official Ans: std::unique_ptr provides exclusive ownership of dynamically allocated memory and is non-copyable;
    // std::shared_ptr allows multiple pointers to share ownership of the same dynamically allocated memory .
    // std::weak_ptr is used in conjunction with std::shared_ptr to break circular references and prevent memory leaks.

    //08. How do smart pointers help prevent memory leaks and other
    //memory-related issues?
    //Official Ans: Smart pointers automatically manage the lifetime of dynamically allocated memory, ensuring that memory is deallocated when it is no
    //longer needed. This helps prevent memory leaks and other memory-related issues.

    // 09.  What is the role of the destructor in smart pointers?
    // Official ans: The destructor of a smart pointer is responsible for deallocating the dynamically allocated memory it owns when the smart pointer goes out of score.

    //10. Explain the concept of ownership semantics in the context of smart pointers.
    // Official Ans: Ownership semantics refer to the rules that govern which smart pointer
    //is responsible for deallocating dynamically allocated memory. For
    //example, std::unique_ptr follows a "single ownership" model, while
    //std::shared_ptr follows a "shared ownership" model.

    // 11. Discuss the potential pitfalls of using raw pointers in C++ and
    // how smart pointers address these issues.
    // official ans: Raw pointers in c++ do no manage memory automatically, leading to potential memory leaks and dangling pointers. Smart pointers address these issues by automatically
    // managing the lifetime of dynamically allocated memory.

    //12. Describe the role of custom deleters in smart pointers and provide examples of scenarios where they might be necessary?
    // official ans: Custom deleters allow developers to specify custom cleanup actions
    //when a smart pointer goes out of scope. This can be useful for
    //resources other than dynamically allocated memory, such as file
    //handles or network connections.

    //13.Discuss the potential overhead associated with using smart pointers compared to raw pointers and strategies for minimizing it.
    //Smart pointers typically incur some overhead compared to raw pointers due to the additional bookkeeping required for memory
    //management. However, this overhead is usually minimal and outweighed by the benefits of automatic memory management. Strategies for
    //minimizing overhead include using std::unique_ptr when exclusive ownership is sufficient and avoiding unnecessary shared ownership.

}