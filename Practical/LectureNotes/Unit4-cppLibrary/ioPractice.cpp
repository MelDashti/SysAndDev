#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

    // an ifstream object name file is created to read from a file.
    //
    ifstream file(
            "C:\\Users\\meela\\Desktop\\System And Device Programming\\Practical\\LectureNotes\\Unit2-recap\\test.txt");

    // the program checks if the file was successfully opened using an if statement.
    if (!file) {
        cout << "error occurred while opening the file";
        return -1;
    }
    string line;
    // using the >> operator will read words separated by spaces, tabs or newlines.
    while (file >> line) {
        cout << line;
    }

    // the second while loop doesn't print anything because when the file pointer reaches the end of the file
    // during the execution of the first while loop.

    // in order to reset the file pointer to the beginning we can use
    file.clear();
    file.seekg(0, ios::beg);

    string line2;
    // with getLine we can read every line.
    while (getline(file, line2)) {
        string word;
        cout << line2 << endl;
    }

    // we close the file
    file.close();
    // now we reopen the file to write to it
    ofstream file2(
            "C:\\Users\\meela\\Desktop\\System And Device Programming\\Practical\\LectureNotes\\Unit2-recap\\test.txt",
            ios::app); // this is the append mode
    if (!file2) {
        cout << "error occurred while opening the file";
        return -1;
    }
    file2 << "Hello World" << endl;
    file2 << "what is up" << endl;

    file2.close();

    // fstream can be used to read and write to file.
    fstream file3(
            "C:\\Users\\meela\\Desktop\\System And Device Programming\\Practical\\LectureNotes\\Unit2-recap\\test.txt");
    // This opens "filename" for both input and output in binary mode. If you just use fstream file("filename"); without specifying the mode,
    // it defaults to std::ios_base::in | std::ios_base::out, meaning it opens the file for both reading and writing in text mode

    if (!file3) {
        cout << "error occurred while opening the file";
        return -1;
    }
    if(file3.is_open()){
        string line3;
        while(getline(file3, line3)){
            cout << line3 << endl;
        }
        // Write a specific string instead of line3, which is empty at this point
        file3 << "New content to write" << endl;
    }
    file3.close();

    // The IO classes also define functions and flags that we can check to understand the
    // status of the stream.
    // if s is stream we can interrogate its status.

    file3.eof(); // returns true if the end of the file has been reached
    file3.fail(); // returns true if an operation failed
    file3.bad(); // returns true if the stream is in a bad state
    file3.good(); // returns true if none of the above flags are set
    file3.clear(); // clears the error flags










}