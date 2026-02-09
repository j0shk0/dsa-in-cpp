/* This is an exploratory implementation of a parentArray in C++.
 * Parent-Arrays are one way to implement Trees with the advantage that the parent of a vertex
 * can be determined with O(1).
 *
 * Author: Joshua Spingler
 * Date: 04.09.2024
 */

#include <cstring>
#include <iostream>

using namespace std;

class parentArray {
    // Items in a class a automatically declared as private.
    int arraySize;
    // This is the Array where on index i for each vertex i, the parent index is saved.
    int* data;

public:
    // This is the Constructor of the class. (I am writing this because I am an absolute rookie in cpp).
    parentArray(const int s) : arraySize(s) {
        data = new int[arraySize];
        // We initialize with -1 because this value can not be used as an array and therefore
        // allows to detect if a value is called before it is assigned.
        memset(data, -1, arraySize * sizeof(int));
    }
    // This is the Destructor of the class. (I am writing this because I am an absolute rookie in cpp).
    ~parentArray() { delete[] data; }
    // This public function allows to add data in a controlled way to the Parent-Array.
    void add(const int child, const int parent) const { data[child] = parent; };
    // This function retrieves the parent of a Vertex of the tree.
    int get_parent(const int child) const {
        if (child != -1) {
            return data[child];
        }
        // If a vertex is requested that was not yet assigned, the user is informed.
        cout << "The Vertex you chose has never been assigned."
             << "Please assign it or choose another one." << endl;
        return -1;
        ;
    };
};

int main() {
    const parentArray tree(100);
    tree.add(0, 4);
    cout << tree.get_parent(0) << endl;
}
