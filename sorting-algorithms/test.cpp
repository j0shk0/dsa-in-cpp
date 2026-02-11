#include <catch2/catch_test_macros.hpp>

#include "bubble-sort.hpp"
#include "quicksort.hpp"
#include "merge-sort.hpp"

TEST_CASE("Test Bubble-Sort") {
    const std::vector numbersInt = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    const std::vector resultInt = bubble_sort<int>(numbersInt);
    int lastInt = 0;
    for (const auto element : resultInt) {
        REQUIRE(lastInt < element);
        lastInt = element;
    }

    const std::vector numbersFloat = {9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
    const std::vector resultFloat = bubble_sort<float>(numbersFloat);
    float lastFloat = 0;
    for (const auto element : resultFloat) {
        REQUIRE(lastFloat < element);
        lastFloat = element;
    }
}

TEST_CASE("Test Quicksort") {
    const std::vector numbersInt = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    const std::vector resultInt = quicksort<int>(numbersInt);
    int lastInt = 0;
    for (const auto element : resultInt) {
        REQUIRE(lastInt < element);
        lastInt = element;
    }

    const std::vector numbersFloat = {9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
    const std::vector resultFloat = quicksort<float>(numbersFloat);
    float lastFloat = 0;
    for (const auto element : resultFloat) {
        REQUIRE(lastFloat < element);
        lastFloat = element;
    }
}

TEST_CASE("Test Merge-Sort") {
    const std::vector numbersInt = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    const std::vector resultInt = merge_sort<int>(numbersInt);
    int lastInt = 0;
    for (const auto element : resultInt) {
        REQUIRE(lastInt < element);
        lastInt = element;
    }

    const std::vector numbersFloat = {9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
    const std::vector resultFloat = merge_sort<float>(numbersFloat);
    float lastFloat = 0;
    for (const auto element : resultFloat) {
        REQUIRE(lastFloat < element);
        lastFloat = element;
    }
}