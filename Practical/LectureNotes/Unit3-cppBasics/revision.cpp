#include<iostream>
using namespace std;
int main()
{
    int v1, v2; // define two integers 
    std::cout << "Enter two numbers: "<< std::endl;
    std::cin >> v1 >> v2; // Read input value
    std::cout << "Revision" << std::endl;
    std::cout << "Hi!" << std::flush;
    std::cout << "HEllo" << std::ends;

    int sum = 0, value = 0;
    while (std::cin >> value)
        sum+=value;
    std::cout<<sum<<std::endl;

    // std is a namespace
    // a namespace is a way to group named entities that otherwise would have global scope into narrower scopes
    // The prefix std:: indicates that the name cout is defined inside the namespace named std
    // libraries seperate their symbols(functions and variables) into namespaces to avoid name collisions

    // The "using" declaration makes all the names in the namespace available without the namespace prefix
    // For example, if you put using namespace std; at the top of your code, you could just write cout and cin
    // instead of std::cout and std::cin. However, this can lead to name collisions if you're not careful,
    // so it's often recommended to use the std:: prefix for standard library entities.
    
    // because i place using namespace std; at the top of the code, i can use cout and cin without the std:: prefix
    cout<<"Hello World"<<endl;
    



    return 0;}
