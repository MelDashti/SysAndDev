cmake_minimum_required(VERSION 3.27)
project(SADlab)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex4 Ex4Main.cpp ex4.cpp)
add_executable(ex3 Ex3Main.cpp ex3.cpp)
add_executable(ex1 ex1.cpp)
add_executable(unit03 ../LectureNotes/Unit3-cppBasics/revision.cpp)
add_executable(unit04 ../LectureNotes/Unit4-cppLibrary/notes.cpp ../LectureNotes/Unit4-cppLibrary/notes2.cpp)
add_executable(unit05 ../LectureNotes/Unit5-multithreading/notesUnit5.cpp)
add_executable(ex2 ex2.cpp)
