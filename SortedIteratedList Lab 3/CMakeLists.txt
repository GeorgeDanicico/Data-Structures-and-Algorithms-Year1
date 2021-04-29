cmake_minimum_required(VERSION 3.17)
project(SortedIteratedList_Lab_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortedIteratedList_Lab_3 App.cpp
        ListIterator.cpp
        ListIterator.h
        ShortTest.h
        ShortTest.cpp
        SortedIteratedList.cpp
        SortedIteratedList.h
        ExtendedTest.h
        ExtendedTest.cpp
        test_function.h
        test_function.cpp)