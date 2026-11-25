cmake_minimum_required(VERSION 3.15...3.30)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sorting-algorithms VERSION 1.0
    DESCRIPTION "Tests for sorting-algorithms."
                  LANGUAGES CXX)

find_package(Catch2 3 REQUIRED)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(test test.cpp)

target_link_libraries(test PRIVATE Catch2::Catch2WithMain)
