cmake_minimum_required(VERSION 3.17)
project(ADT_Set_Lab_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ADT_Set_Lab_4 App.cpp
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h
        ExtendedTest.cpp
        ExtendedTest.h
        tests.cpp
        tests.h)