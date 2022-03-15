# cmake_minimum_required(VERSION <specify CMake version here>)
project(Ex1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ex1
        doctest.h
        main.cpp
        mat.cpp
        mat.hpp
        StudentTest1.cpp
        StudentTest2.cpp
        StudentTest3.cpp
        Test.cpp
        TestRunner.cpp)
