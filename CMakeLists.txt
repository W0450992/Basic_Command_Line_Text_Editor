cmake_minimum_required(VERSION 3.17)
project(Assignment1)

set(CMAKE_CXX_STANDARD 17)

add_executable(EDIT
        src/main.cpp src/LinkedListNode.cpp src/LinkedListNode.h src/LinkedList.cpp src/LinkedList.h src/ReadFile.cpp src/ReadFile.h src/TextEditor.cpp src/TextEditor.h)
