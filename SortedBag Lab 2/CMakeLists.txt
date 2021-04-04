cmake_minimum_required(VERSION 3.17)
project(SortedBag_Lab_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortedBag_Lab_2
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h)