//#include <iostream>
//#include "Stack.h"
//#include <vector>
//
// *******
// If we use this approach we also need to define the main function in the same file.

//using namespace std;
//
//template<class T>
//void Stack<T>::push(T element) {
//    stack.push_back(element);
//}
//
////n C++ templates, you need to specify template<class T> or template<typename T>
//// before each function definition in the class. This is because each function is a template function, not just the class itself.
//template<typename T>
//T Stack<T>::pop() {
//    T element = stack.back();
//    stack.pop_back();
//    return element;
//}
//
//template<typename T>
//void Stack<T>::visit() {
//    for (int i = 0; i < stack.size(); i++) {
//        cout << stack[i] << " ";
//    }
//    cout << endl;
//}
//
//template<typename T>
//int Stack<T>::getSize() {
//    return stack.size();
//}
//
//template<typename T>
//bool Stack<T>::isEmpty() {
//    return stack.empty();
//}
