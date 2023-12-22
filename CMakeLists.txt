cmake_minimum_required(VERSION 3.26)
project(Task_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_1 ListGraph.cpp
        MatrixGraph.cpp
        MatrixGraph.h
        ListGraph.h
        SetGraph.cpp
        SetGraph.h
        ArcGraph.cpp
        ArcGraph.h
        main.cpp)
