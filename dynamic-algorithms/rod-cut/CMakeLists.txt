cmake_minimum_required(VERSION 3.15...3.30)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(other-algorithms VERSION 1.0
    DESCRIPTION "rod-cut implementation."
                  LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(main main.cpp)
