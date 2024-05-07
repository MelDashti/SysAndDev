#include<iostream>
using namespace std;
int main()
{
// A pointer is an object that can point to another object. It is a variable that stores the address
// of another variable.
    int i = 0;
    int &r = i, &r2 = i; // r is a reference to i. It is another name for i
    // int &wrong_ref; // this is wrong. A reference must be initialized when it is created
    cout << r << i << endl; 

    //int &wrong_ref2 = 0; // this is wrong. A reference must be initialized with an object
    float f;
    //  int &rf = f; // this is wrong. A reference must be initialized with an object of the same type
    float &rf = f;

    // Qualifiers. A qualifier is a keyword that is used to modify the properties of a variable.
    // A simpler way to think of a qualifier is that it is a keyword that is used to change the meaning of a data type.
    // const-qualified and volatile-qualified are the two qualifiers in c++
    // const-qualified is used to create a read-only variable. A variable that is const-qualified cannot be modified
    // volatile-qualified is used to create a variable that can be modified by something outside the program.

    const int c = 0;
    // c = 1; // this is wrong. c is const-qualified and cannot be modified
    volatile int v = 0;
    const volatile int cv = 0; // cv is both const-qualified and volatile-qualified
    // what does it mean to be const-qualified and volatile-qualified at the same time?
    // it means that the variable is read-only and can be modified by something outside the program
    volatile const int vc = 0; // vc is both volatile-qualified and const-qualified
    // the order of the qualifiers does not matter. const volatile int cv is the same as volatile const int vc

    int x = 0;
    // difference between * and & in c++ is that * is used to declare a pointer and & is used to declare a reference.
    // A pointer is an object that can point to another object. It is a variable that stores the address of another variable.
    // A reference is another name for an object. The difference between a pointer and a reference is that a pointer can be null and a reference cannot be null.

    int x1 = 5;
    int *p = &x1; // p is a pointer to x1. It stores the address of x1
    cout<<*p<<endl; // *p is the value of x1. which is 5
    *p = 20;
    cout<<*p<<x1<<endl; // *p is the value of x1. which is 20
   // In this example, p is a pointer to x. The & operator is used to get the address of x, and the * operator is 
   //used to dereference the pointer (i.e., access the variable it points to).
    cout<<&x1<<&*p<<endl; // &x1 is the address of x1. &*p is the address of x1

    int *const p1 = &x1; // Top - level constant. The pointer p1 cannot change
    const int *p2 = &x1; // Low-level constant. The value of x1 cannot change. The pointer p2 can change
    const double *const p3 = 3.14; // constant pointer to a constant value.
    // top level const and low level const: top level const is a const that is at the top level of a declaration. It is a const that is not part of the base type of a variable
    // low level const is a const that is part of the base type of a variable. It is a const that is part of the base type of a variable

    // From void * to int *

    int i = 42;
    void *vp = &i; // vp is a void pointer to i
    int *ip = static_cast<int*>(vp); // ip is an int pointer to i
    //  x = sum (i, j); 
    //y = sum (i, static_cast<int>(y));
 // z = sum (static_cast<int>(x),static_cast<int>(y));

    // convert a constant into a non-constant
    // const_cast<new_type>(expression)
    // most useful in the context of overloaded functions


    











    // unsigned is a type modifier. It tells the compiler to use the unsigned version of the data type
    // By unsigned we mean that the variable can only store positive values or zero
    // unsigned int is different from int because of the range of values they can store. unsigned int can store
    // a larger positive value than int and int can store negative values

    // unsigned u = 19;
    // int i = -42;
    // cout << i + i << endl; // the sum -42 + -42 = -84
    // cout << u + i << endl; // the sum is 4294967264
    // // the sum is so greater because the value of i is converted to unsigned int. 
    // the value of i is -42 and when it is converted to unsigned int, it becomes a very large positive value

    // difference between int i = 0 and int i = {0} is that the first one is direct initialization and the second one is list initialization
    // list initialization is a feature in c++ that allows you to initalize variables with a 
    // brace-enclosed comma serparated list of values. It can be use with arrays, vectors and othe containers types, as well as with simple types like int.

    // int i1 = 0;
    // int i2 = {0};
    
 
    
    return 0;
}
