#include<vector>
#include<unordered_map>

class FibonacciHeap;

struct Vertex {
    int priority = 0;
    int value = 0;
    Vertex* parent = nullptr;
    std::vector<Vertex*> children;

    void ClearChildren() {
        children.clear();
    }
};

class FibonacciHeap {

    std::vector<Vertex*> root_list;
    std::vector<Vertex*> marked;
    Vertex* minimum = nullptr;
    std::unordered_map<int, Vertex*> degree_map; 

    int KeyIsPresent(int key);
    int CleanRoots(int children_amount, Vertex* root);
    void HandleMarkedVertex(Vertex* decreased_key_vertex);

    public:

    void Insert(Vertex* other_value);
    Vertex GetMin();
    void DecreaseKey(Vertex* vertex_to_change, int new_priority);

};