/*
 * cut_rod.cpp - Rod cutting problem (naive recursive solution)
 * Copyright (C) 2026  Joshua Spingler <j0shk0@proton.me>
 *
 * Based on CUT-ROD from Cormen, Leiserson, Rivest, Stein:
 * "Introduction to Algorithms", chapter on dynamic programming.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <array>
#include <iostream>
#include <limits>
#include <vector>

// An LUT for the prices. 1-indexing is used here.
// Index of the Array is the revenue per length of the rod.
constexpr std::array P = {1, 5, 8, 9, 10, 17, 20, 24, 30};
// Length of the rod in question.
constexpr int N = 4;

// Recursive version.
template<typename T>
int cut_rod(const T& p, const int n) {
    if (n == 0) return 0;

    int q = -std::numeric_limits<int>::infinity();
    for (int i = 1; i <= n; ++i) {
        q = std::max(q, p[i - 1] + cut_rod(p, n - i));
    }
    return q;
};

// Bottom-Up version.
template<typename T>
int cut_rod_ub(const T& p, const int n) {
    std::vector<int> r{0};
    if (n == 0) return 0;

    int q = -std::numeric_limits<int>::infinity();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            q = std::max(q, p[j - 1] + r[i - j]);
        }
        r.push_back(q);
    }
    return q;
};

int main() {
    auto opt_r = cut_rod(P, N);
    auto opt_d = cut_rod_ub(P, N);
    std::cout << "Optional Solution for the (recursive) rod cutting problem of size " << N << " is " << opt_r
              << std::endl;
    std::cout << "Optional Solution for the (dynamic) rod cutting problem of size " << N << " is " << opt_d << std::endl;
}
