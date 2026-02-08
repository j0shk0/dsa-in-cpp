#pragma once
#include <vector>

int binary_search(const std::vector<int>& v, const int& param) {
    const int vSize = v.size();

    if (vSize == 1) {
        return v[0] == param ? 0 : -1;
    }

    int begin = 0;
    int end = vSize - 1;
    int middleIndex = (vSize - 1) / 2;

    while (end - begin > 1) {
        if (v[middleIndex] == param) {
            return middleIndex;
        }
        if (v[middleIndex] > param) {
            end = middleIndex - 1;
        } else {
            begin = middleIndex + 1;
        }

        middleIndex = (begin + end) / 2;
    }

    if (v[begin] == param) return begin;
    if (v[end] == param) return end;

    return -1;
}
