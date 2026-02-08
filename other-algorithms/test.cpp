#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>

#include "binary_search.hpp"
#include "matrix-calc.hpp"

TEST_CASE("Test Transpose") {
    // initialize matrix to transpose.
    std::vector<std::vector<int>> mat(5, std::vector<int>(5));
    for (auto i = 0; i < mat.size(); i++) {
        for (auto j = 0; j < mat[0].size(); j++) {
            mat[i][j] = i;
        }
    }

    // initialize transposed matrix.
    std::vector<std::vector<int>> matTest(5, std::vector<int>(5));
    for (auto i = 0; i < matTest.size(); i++) {
        for (auto j = 0; j < matTest[0].size(); j++) {
            matTest[i][j] = j;
        }
    }

    // Test the output of transpose<int>
    auto matT = transpose<int>(mat);

    for (auto i = 0; i < mat.size(); i++) {
        for (auto j = 0; j < mat[0].size(); j++) {
            REQUIRE(matT[i][j] == matTest[i][j]);
        }
    }
}

TEST_CASE("Test Matrix Product") {
    // Test A
    const std::vector<std::vector<int>> matA = {{1, 2}, {3, 4}};
    const std::vector<std::vector<int>> matB = {{2, 0}, {1, 2}};
    const std::vector<std::vector<int>> matValid = {{2, 5}, {6, 11}};
    const auto output = matrix_prod<int>(matA, matB);
    for (auto i = 0; i < output.size(); i++) {
        for (auto j = 0; j < output[0].size(); j++) {
            REQUIRE(output[i][j] == matValid[i][j]);
        }
    }

    // Test B
    const std::vector<std::vector<int>> mat2A = {{1, 645, 65, 2, 45, 2}, {0, 654, 6, 0, 0, 654},
                                                 {654, 0, 6, 45, 4, 2},  {164, 64, 54, 2, 5, 45},
                                                 {41, 5, 45, 41, 5, 4},  {4, 566, 0, 15, 0, 4}};
    const std::vector<std::vector<int>> mat2B = {{0, 0, 64, 4, 4, 8},       {0, 4, 5, 4, 0, 31},
                                                 {6456, 0, 46456, 4, 0, 0}, {4, 564, 0, 6, 468, 46},
                                                 {65, 65, 5, 5, 2, 5},      {45, 44, 0, 445, 16, 65}};
    const std::vector<std::vector<int>> mat2Valid = {
            {4364, 2975, 3026104, 384948, 42425, 30165}, {5616, 22920, 278736, 398940, 45810, 71286},
            {596, 272, 4501140, 4850, 42783, 49649},     {3844, 1929, 3567416, 41174, 15335, 14091},
            {3096, 533, 2355380, 5754, 3450, 20650},     {92, 2448, 25884, 319514, 37145, 32019}};
    const auto output2 = matrix_prod<int>(mat2A, mat2B);
    for (auto i = 0; i < output2.size(); i++) {
        for (auto j = 0; j < output2[0].size(); j++) {
            REQUIRE(output2[i][j] == mat2Valid[i][j]);
        }
    }
}

TEST_CASE("Test Binary Search") {
    std::vector vecTest{1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int index0 = binary_search(vecTest, 1);
    const int index1 = binary_search(vecTest, 2);
    const int index2 = binary_search(vecTest, 3);
    const int index3 = binary_search(vecTest, 4);
    const int index4 = binary_search(vecTest, 5);
    const int index5 = binary_search(vecTest, 6);
    const int index6 = binary_search(vecTest, 7);
    const int index7 = binary_search(vecTest, 8);
    const int index8 = binary_search(vecTest, 9);
    REQUIRE(index0 == 0);
    REQUIRE(index1 == 1);
    REQUIRE(index2== 2);
    REQUIRE(index3 == 3);
    REQUIRE(index4 == 4);
    REQUIRE(index5 == 5);
    REQUIRE(index6 == 6);
    REQUIRE(index7 == 7);
    REQUIRE(index8 == 8);
}
