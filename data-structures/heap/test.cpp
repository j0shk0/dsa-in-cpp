#include <catch2/catch_template_test_macros.hpp>
#include <vector>

#include "heap.hpp"
#include "template/heapT.hpp"

TEST_CASE("Test Heap Implementation - Basic Functionality") {
    const std::vector start_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Heap heap{start_vector};
    heap.build_heap();
    // The current Heap implementation is a Max-Heap.
    // If delete_max works correctly we can sort the initial values with the Heap.
    for (int i = 10; i > 0; --i) {
        const int max = heap.delete_max();
        REQUIRE(max == i);
    }
}

struct Vertex {
    int priority;
};

TEST_CASE("Test HeapT - Basic Functionality") {
    constexpr Vertex vertex1{1};
    constexpr Vertex vertex2{2};
    constexpr Vertex vertex3{3};
    constexpr Vertex vertex4{4};
    constexpr Vertex vertex5{5};
    constexpr Vertex vertex6{6};
    const std::vector vertexVector{vertex1, vertex2, vertex3, vertex4, vertex5, vertex6};
    HeapT heap{vertexVector};
    heap.build_heap();
    for (int i = 6; i > 0; --i) {
        const auto [priority] = heap.delete_max();
        REQUIRE(priority == i);
    }
}
