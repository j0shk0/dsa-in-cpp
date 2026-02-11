# dsa-in-cpp

- [Overview](#Overview)
- [About](#About)
- [data-structures](#data-structures)
- [sorting-algorithms](#sorting-algorithms)
- [other-algorithms](#other-algorithms)
- [Contribution](#Contribution)

## Overview

A collection of common data structures and algorithms that I implemented.

## About

This Repository is intended to be a reference for common data structures and algorithms in CS.

_If you are new to C++:_ Make sure to install `cmake` and get the GNU Compiler Collection (This Projects uses `g++`).
Each "collection" of Data Structures and/or Algorithms has its own `CMakeList.txt`. You can execute the test by running the
following commands in your `bash` shell assuming you are using a UNIX based Operating System (e.g. Linux Distribution or MacOS)
and you have navigated in the respective folder

```bash
mkdir -p build
cd build
cmake ..
make
./test
```
If you are done you can remove the folder with `rm -rf build`.

### data-structures

- Graph
    - Parent Array Tree Representation
    - Left-Child Right-Sibling Tree Representation
- Heap
    - Heap class and Template: Please note that, to use the Template, a member `int priority` must be implemented in your **own** class/struct. Please make sure to assign a priority to each object you want the Heap to be instantiated with.
- Fibonacci-Heap
    - An interesting alternative to Binary Heaps are Fibonacci-Heaps. Theoretically they have an interesting performance Profile and are a viable choice to increase the performance of the SSSP Algorithm (aka Dijkstra's Algorithm). However in real-world application it has been shown that the pairing-heap is, with regards to implementation, a simpler and also faster solution compared to the Fibonacci-Heap. 


### sorting-algorithms

- Bubble Sort
- Merge Sort
- Quick Sort

### other-algorithms

- Matrix Product utilizing `std::experimental::simd` and `OpenMP`.
- Binary Search

## Contribution

Please feel free to contribute. I am always very happy about ideas and hints for further improvement.
