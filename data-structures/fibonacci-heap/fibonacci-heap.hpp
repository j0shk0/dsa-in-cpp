#pragma once
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include <vector>

template<typename T>
concept Heap_Compatible = requires(T a) {
    { a } -> std::convertible_to<T>;
    { a.parent } -> std::convertible_to<T*>;
    // TODO: Is it necessary that priority is an int or can I further abstract this ?
    { a.priority } -> std::convertible_to<int>;
    { a.children } -> std::convertible_to<std::vector<T*>>;
};

template<Heap_Compatible T>
class FibonacciHeap {
    std::vector<T*> root_list;
    std::vector<T*> marked;
    T* minimum = nullptr;
    std::unordered_map<int, T*> degree_map;

    int KeyIsPresent(int key) {
        // Searching for element with key
        if (!degree_map.contains(key)) {
            return 0;
        } else {
            return 1;
        }
    };
    int CleanRoots(int children_amount, T* root) {
        if (KeyIsPresent(children_amount)) {
            T* second_root = degree_map.at(children_amount);
            if (root->priority < second_root->priority) {
                auto element_found = std::find((root->children).begin(), (root->children).end(), second_root);
                if (element_found == (root->children).end()) {
                    (root->children).push_back(second_root);
                }
                second_root->parent = root;
                int modified_children_amount = (root->children).size();
                degree_map.erase(children_amount);
                CleanRoots(modified_children_amount, root);
                return 0;
            } else {
                auto element_found = std::find((second_root->children).begin(), (second_root->children).end(), root);
                if (element_found == (second_root->children).end()) {
                    (second_root->children).push_back(root);
                }
                root->parent = second_root;
                int modified_children_amount = (second_root->children).size();
                degree_map.erase(children_amount);
                CleanRoots(modified_children_amount, second_root);
                return 0;
            }
        }
        root->parent = nullptr;
        degree_map.insert(std::make_pair(children_amount, root));
        return -1;
        return 0;
    };

    void HandleMarkedVertex(T* decreased_key_vertex) {
        T* parent_vertex = decreased_key_vertex->parent;
        // We check if the parent vertex is already a marked vertex.
        auto element_found = std::find(marked.begin(), marked.end(), parent_vertex);
        if (element_found == marked.end()) {  // In this case the vertex is not a marked vertex.
            // We copy the value of the parent_vertex pointer, so that we can Override the cell.
            T tmp = *parent_vertex;
            marked.push_back(&tmp);  // We "mark" the vertex by pushing it in the marked vector.
            parent_vertex = nullptr;

            // We push the whole subtree with the decresed_key_vertex to the root_list.
            Insert(decreased_key_vertex);
            // We update the children vector of the parent Vertex accordingly.
            std::erase(tmp.children, decreased_key_vertex);
            return;
        }
        for (auto child: decreased_key_vertex->children) {
            child->parent = nullptr;
            Insert(child);
        }
        decreased_key_vertex->ClearChildren();
        std::erase(marked, parent_vertex);

        Insert(decreased_key_vertex);
        // We update the children vector of the parent Vertex accordingly.
        std::erase(parent_vertex->children, decreased_key_vertex);
        if (parent_vertex != nullptr) {
            T tmp = *parent_vertex;
            parent_vertex = nullptr;
            HandleMarkedVertex(&tmp);
        }
    }

public:
    void Insert(T* other_value) {
        root_list.push_back(other_value);
        if (minimum != nullptr) {
            minimum = other_value->priority < minimum->priority ? other_value : minimum;
        } else {
            minimum = other_value;
        }
    };
    T GetMin() {
        T* min_vertex = minimum;

        for (auto child: (min_vertex->children)) {
            child->parent = nullptr;
            root_list.push_back(child);
        }

        if (minimum) {
            std::erase(root_list, minimum);
        } else {
            throw std::runtime_error("The Root List is empty. Please add an Element before trying to remove it.");
        }

        for (auto root: root_list) {
            if (root->parent != nullptr) {
                continue;
            }

            int children_amount = (root->children).size();
            CleanRoots(children_amount, root);
        }
        degree_map.clear();

        auto bad_roots = std::erase_if(root_list, [](T* x) { return (x->parent) != nullptr; });

        /*
        for (auto root : root_list) {
            cout << root->priority << " ";
        }
        cout << endl;
        */

        minimum = nullptr;
        for (auto root: root_list) {
            if (minimum != nullptr) {
                minimum = root->priority < minimum->priority ? root : minimum;
            } else {
                minimum = root;
            }
        }

        return *min_vertex;
    }

    void DecreaseKey(T* vertex_to_change, int new_priority) {
        if (vertex_to_change->priority < new_priority) {
            throw std::runtime_error("new_priority must be smaller that the current one.");
        }

        vertex_to_change->priority = new_priority;
        T* parent_vertex = vertex_to_change->parent;

        // It's possible that the decreased priority lead to a new minimum => update
        if (parent_vertex == nullptr) {
            for (auto root: root_list) {
                if (minimum != nullptr) {
                    minimum = root->priority < minimum->priority ? root : minimum;
                } else {
                    minimum = root;
                }
            }
            return;
        }

        if (parent_vertex->priority > new_priority) {
            HandleMarkedVertex(vertex_to_change);
        }

        for (auto root: root_list) {
            if (minimum != nullptr) {
                minimum = root->priority < minimum->priority ? root : minimum;
            } else {
                minimum = root;
            }
        }
    }
};
