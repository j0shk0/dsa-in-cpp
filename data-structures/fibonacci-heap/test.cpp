#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "fibonacci-heap.hpp"

struct Vertex {
    int priority{0};
    int value{0};
    Vertex* parent = nullptr;
    std::vector<Vertex*> children;

    // TODO: Get rid of this function.
    void ClearChildren() { children.clear(); }
};

TEST_CASE("Test Fibonacci Heap - Basic Functionality") {

    SECTION("Test1") {
        Vertex v;
        v.priority = 4;
        v.value = 0;

        Vertex w;
        w.priority = 6;
        w.value = 1;

        Vertex a;
        a.priority = 2;
        a.value = 2;

        Vertex x;
        x.priority = 3;
        x.value = 3;

        Vertex y;
        y.priority = 7;
        y.value = 4;

        Vertex z;
        z.priority = 0;
        z.value = 5;

        FibonacciHeap<Vertex> f;

        f.Insert(&v);
        f.Insert(&w);
        f.Insert(&a);
        f.Insert(&x);
        f.Insert(&y);
        f.Insert(&z);
        f.DecreaseKey(&y, 0);
        f.DecreaseKey(&v, 0);

        // Correct order should be : z v y a x w
        // Lets check:

        Vertex output1 = f.GetMin();
        REQUIRE(output1.value == 5);
        Vertex output2 = f.GetMin();
        REQUIRE(output2.value == 0);
        Vertex output3 = f.GetMin();
        REQUIRE(output3.value == 4);
        Vertex output4 = f.GetMin();
        REQUIRE(output4.value == 2);
        Vertex output5 = f.GetMin();
        REQUIRE(output5.value == 3);
        Vertex output6 = f.GetMin();
        REQUIRE(output6.value == 1);
    }
}
