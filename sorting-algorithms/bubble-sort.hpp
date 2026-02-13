#pragma once
#include <vector>

template<typename T>
requires std::three_way_comparable<T> && std::is_swappable_v<T>
std::vector<T> bubble_sort(std::vector<T> unsorted_v) {
    // upper_bound to not iterate beyond the vector.
    T* upper_bound = &unsorted_v.back();
    // Defining the start point for the iteration.
    T* lower_bound = &unsorted_v[0];
    // Sorted will become true if no value in the list is preceded
    // by a bigger value.
    bool sorted = false;
    while (sorted == false) {
        sorted = true;
        for (T* i = lower_bound ; i != upper_bound; i++) {
            // If a value is preceded by a bigger value they need to be swapped.
            if (i != upper_bound && *i > *(i + 1)) {
               sorted = false;
               std::swap(*i, *(i + 1));
            }
           }
        }
    return unsorted_v;
}

