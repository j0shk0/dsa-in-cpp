// This is implementation of a Merge-Sort-Algorithm.
#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
    requires std::is_swappable_v<T> && std::three_way_comparable<T>
vector<T> merge_sort(vector<T> v) {
    const int vector_size = v.size();
    // The base case of the Recursion.
    if (vector_size == 2 && v[0] > v[1]) {
        swap(v[1], v[0]);
        return v;
    }
    if (vector_size > 2) {
        vector<T> next_v_1 = vector<T>(v.begin(), v.begin() + vector_size / 2);
        vector<T> next_v_2 = vector<T>(v.begin() + vector_size / 2, v.end());
        vector<T> v_1 = merge_sort(next_v_1);
        vector<T> v_2 = merge_sort(next_v_2);

        vector<T> output_v;

        while ((not v_1.empty()) && (not v_2.empty())) {
            // While the case of trying to do calculations without values in the vectors
            // is ruled out, they can be merged, comparing the first values one by one.
            if (v_1.front() < v_2.front()) {
                output_v.push_back(v_1.front());
                v_1.erase(v_1.begin());
            } else {
                output_v.push_back(v_2.front());
                v_2.erase(v_2.begin());
            }
        }
        // If one of the vectors is bigger than the other, the values have to be added to
        // the output as well, by adding them to the end.
        if (not v_1.empty()) {
            output_v.reserve(output_v.size() + distance(v_1.begin(), v_1.end()));
            output_v.insert(output_v.end(), v_1.begin(), v_1.end());
        } else if (not v_2.empty()) {
            output_v.reserve(output_v.size() + distance(v_2.begin(), v_2.end()));
            output_v.insert(output_v.end(), v_2.begin(), v_2.end());
        }
        return output_v;
    }
    return v;
}
