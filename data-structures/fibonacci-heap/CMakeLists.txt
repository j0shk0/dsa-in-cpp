cmake_minimum_required(VERSION 3.15...3.30)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(dsa-in-cpp VERSION 1.0
DESCRIPTION "Implementations of algorithms and data structures in cpp."
LANGUAGES CXX)

find_package(Catch2 3 REQUIRED)

add_executable(test test.cpp)

target_link_libraries(test PRIVATE Catch2::Catch2WithMain)
