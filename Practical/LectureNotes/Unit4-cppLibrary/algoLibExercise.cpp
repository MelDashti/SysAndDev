#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//
// Created by meela on 5/10/2024.
//
using namespace std;


struct Student {
    int studentId;
    string name;
    int grade;
};


int main() {

    int n;
    cout << "Enter num of student records you want to enter" << endl;
    cin >> n;
    vector<Student> vs;
    for (int i = 0; i < n; i++) {
        Student s;
        cout << "Enter a new student record: " << endl;
        cin >> s.name >> s.studentId >> s.grade;
        vs.push_back(s);
    }
    // Now we sort the student records by id in ascending order.
    std::sort(vs.begin(), vs.end(), [](Student &s1, Student &s2) -> bool {
        return s1.studentId < s2.studentId;
    });
    // list sorted based on student id
    for (auto a: vs) {
        cout << a.studentId << endl;
    }
    // Now we sort the students by name in alphabetic order
    std::sort(vs.begin(), vs.end(), [](Student s1, Student s2) -> bool {
        return s1.name < s2.name;
    });

    // Now we sort the students grade in descending order
    std::sort(vs.begin(), vs.end(), [](Student s1, Student s2) -> bool {
        return int(s1.grade) > int(s2.grade);
    });


}


void algoLibEx(){
// Question.
// Write a C++ program that manages a list of
//student records and performs the following tasks
//  Allow the user to input student records one by
//one. Each record should include the student's ID,
//name, and grade
//  Store the student records in a sequential container
//  Sort the students by
//  ID in ascending order
//  Name in alphabetical order
//  Grade in descending order
//  Use lambda functions to define custom sorting
//criteria for the sorting function
}
