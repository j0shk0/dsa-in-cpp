cmake_minimum_required(VERSION 3.15...3.30)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(heap VERSION 1.0
DESCRIPTION "Implementations of a heap."
LANGUAGES CXX)

file(GLOB SOURCES
        heap.hpp
        heap.cpp
)

find_package(Catch2 3 REQUIRED)

add_executable(test test.cpp ${SOURCES})

target_link_libraries(test PRIVATE Catch2::Catch2WithMain)
