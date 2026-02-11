#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
requires std::is_arithmetic_v<T>
vector<T> quicksort(vector<T> v) {
    if (v.size() == 1 || v.empty()) {
            return v;
        }
    if (v.size() == 2 && v[0] > v[1]) {
            swap(v[0], v[1]);
            return v;
        }
    T l = 0;
    T r = v.size() - 2;
    T pivot = v.back();

    while(l < r) {
        while (v[l] <= pivot && l <= r) {
            l++;
        }
        while (v[r] > pivot && l <= r) {
            r--;
        }
        if (l < r) {
            swap(v[r], v[l]);
        }
        }
    if (v[l] > pivot) {
            swap(v[l], v.back());
    }
    vector<T> lower_val = vector<T>(v.begin(), v.begin() + l);
    vector<T> higher_val = vector<T>(v.begin() + l + 1, v.end());

    vector<T> sorted_lower = quicksort(lower_val);
    vector<T> sorted_higher = quicksort(higher_val);

    sorted_lower.push_back(v[l]);
    sorted_lower.insert(sorted_lower.end(), sorted_higher.begin(), sorted_higher.end());

    return sorted_lower;
}
