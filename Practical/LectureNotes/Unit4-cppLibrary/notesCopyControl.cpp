#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

template<typename T>
class Stack {
private:
    std::vector<T> data;
public:
    void push(T element) {
        data.push_back(element);
    }

    T pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        T element = data.back();
        data.pop_back();
        return element;
    }

    T top() {
        if (data.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return data.back();
    }

    bool empty() {
        return data.empty();
    }
};


class Rectangle {
private:
    int m_width;
    int m_length;

public:
    // Default constructor
    Rectangle() : m_width(0), m_length(0) {}

    // Parameterized constructor
    Rectangle(int width, int length) : m_width(width), m_length(length) {}

    // Copy constructor
    Rectangle(const Rectangle &to_copy) {
        // Copying width and length from the 'to_copy' object
        this->m_width = to_copy.m_width;
        this->m_length = to_copy.m_length;
    }

    // copy assignment operator
    Rectangle &operator=(const Rectangle &);

    // Member function to display dimensions
    void displayDimensions() {
        std::cout << "Width: " << m_width << ", Length: " << m_length << std::endl;
    }
};


class Car {
public:
    int speed;

    // default constructor
    Car();

    // copy constructor
    Car(const Car &other);

    // destructor
    ~Car() {
        cout << "Destructor called" << endl;
    }

};

Car::Car() {
    speed = 0;
    cout << "Default constructor called" << endl;
}

// now we implement the constructor
Car::Car(const Car &other) {
//    When declaring a copy constructor, you typically want to pass the object to be copied by reference rather than by value. Passing by reference (Car&) is more efficient than passing by value (Car) because it avoids making a copy of the object being passed, especially for large objects.
//    Passing by reference allows the copy constructor to access the original object directly, without the overhead of creating a new copy of the object.
    cout << "Copy constructor called" << endl;
    // You might also notice the const keywork in the copy constructor.
    // In the copy constructor declaration, you might see const Car& instead of just Car&. Adding const indicates that the reference is to a constant object, meaning the copy constructor promises not to modify the original object
}

// Class with dynamic memory allocation
class DynamicClass {
public:
    DynamicClass(const char *str);

    ~DynamicClass();
};

DynamicClass::DynamicClass(const char *str) {
    // Allocate memory for the string
    char *m_string = new char[strlen(str) + 1]; // +1 to account for null terminator
    // Copy the string into the allocated memory
    strcpy(m_string, str); // strcpy is a function that copies a string from one location to another
    // It copies the string pointed to by str to the location pointed to by m_string
}
//Memory Allocation:
//new char[strlen(str) + 1] dynamically allocates memory on the heap for storing a string.
//strlen(str) calculates the length of the input string str, and +1 is added to account for the null terminator ('\0') required at the end of the string.
//The result is a pointer to the first character of the allocated memory block, which is assigned to the pointer variable m_string.
//String Copying:
//strcpy(m_string, str) copies the content of the input string str to the dynamically allocated memory block pointed to by m_string.
//This function iterates through each character of the source string str and copies it to the destination string m_string, including the null terminator.


class Foo {
private:
    string number;
    int sold;
    double revenue;
public:
    // this is the copy constructor
    Foo(const Foo &foo) {
        this->number = foo.number;
        this->sold = foo.sold;
        this->revenue = foo.revenue;
    }

    // this is the copy assignment operator
    Foo &operator=(const Foo &foo) {
        this->number = foo.number;
        this->sold = foo.sold;
        this->revenue = foo.revenue;
        return *this;
    }

    ~Foo();


};


//Copy constructor & Assignment
class sales {
public:
    // Copy constructor
    sales(const sales &orig) :
            number(orig.number),
            sold(orig.sold),
            revenue(orig.revenue) {}

    // Copy assignment operator
    sales &operator=(const sales &orig) {
        number = orig.number;
        sold = orig.sold;
        revenue = orig.revenue;
        return *this;
    }

private:
    std::string number;
    int sold = 0;
    double revenue = 0.0;
};

int main() {
    Car c1; // here we create the original car object
    Car c2(c1); // here we create a new car object and pass the original car object to it
    delete &c1; // destructor is called here

    // Move semantics
    // They were introduced in c++11, they are designed to efficiently transfer resources (like dynamically allocated memory) from one
    // one object to another. Typically in cases where creating a copy is uncessary or expensive.






}