#include<iostream>
#include<catch2/catch_test_macros.hpp>
#include"fibonacci-heap.hpp"

TEST_CASE("Basic Functionality Test") {

    SECTION("Test1") {

        Vertex v;
        v.priority = 4;
        v.value = 5;

        Vertex w;
        w.priority = 6;
        w.value = 5;

        Vertex a;
        a.priority = 2;
        a.value = 1;

        Vertex x;
        x.priority = 3;
        x.value = 2;

        Vertex y;
        y.priority = 7;
        y.value = 8;

        Vertex z;
        z.priority = 0;
        z.value = 9;

        FibonacciHeap f;
        std::cout << "test" << std::endl;
        f.Insert(&v);
        f.Insert(&w);
        f.Insert(&a);
        f.Insert(&x);
        f.Insert(&y);
        f.Insert(&z);
        f.DecreaseKey(&y, 0);
        f.DecreaseKey(&v, 0);

        Vertex output1 = f.GetMin();
        std::cout << output1.priority << std::endl;
        std::cout << output1.value<< std::endl;
        Vertex output2 = f.GetMin();
        std::cout << output2.priority << std::endl;
        std::cout << output2.value<< std::endl;
        Vertex output3 = f.GetMin();
        std::cout << output3.priority << std::endl;
        std::cout << output3.value<< std::endl;
        Vertex output4 = f.GetMin();
        std::cout << output4.priority << std::endl;
        std::cout << output4.value<< std::endl;
        Vertex output5 = f.GetMin();
        std::cout << output5.priority << std::endl;
        std::cout << output5.value<< std::endl;
        Vertex output6 = f.GetMin();
        std::cout << output6.priority << std::endl;
        std::cout << output6.value<< std::endl;
        std::cout << "TEST" << std::endl;

    }

}
