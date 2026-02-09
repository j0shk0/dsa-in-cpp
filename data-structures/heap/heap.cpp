/*This is an implementation file of heap.h
* Every step is documented in detail for educational purposes.
*/

#include "heap.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

	
// We declare repair_up(wards) and repair_down(wards) to repair the heap-order if it is violated.
	
void Heap::repair_up(int index) {
	// The vector size must be bigger than 1 (otherwise there is no need to assign a parent to the vertex).
	// The index must be above 0 as we can't call repair_up on the root of the heap.
	// The index must be below data_array.size() otherwise there will be undefined behavior as there is 1-Indexing.
	if ((data_array.size() > 1) && 
			(index > 0) && 
			(index <= data_array.size() - 1)) {

		// The index must be increased by one for the calculation of the father vertex.
		// The current parent of the vertex in question has index / 2 in the definition I'm using.
		int father = ((index + 1) / 2)  - 1;

		// This must be changed if the heap should be transformed in a min Heap.
		// In the standard implementation repair_up will bring a vertex higher in the tree until the structure
		// is repaired (the father must have an equal or higher value than the vertex repaired. If not, they have to switch places.
		while (data_array[father] < data_array[index]) {
			// This will swap the values stored on the two addresses within the vector and is similar to calling swap(*vertex_a_pointer, *vertex_b_pointer).
			iter_swap(data_array.begin() + index, 
					data_array.begin() + father);
			// Now as the value was assigned to the father vertex we have to update the index to the index of the father vertex.
			index = father;
			// And calculate the index of the father vertex.
			father = ((index + 1) / 2) - 1;
		}
	}
}

void Heap::repair_down(int index) {
	// The vector size must be bigger than 1 (otherwise there is no need to assign a parent to the vertex).
	// The index must be above 0 as we can't call repair_up on the root of the heap.
	// The index must be below data_array.size() otherwise there will be undefined behavior as there is 1-Indexing.
	if ((data_array.size() > 1) && 
			(index >= 0) && 
			(index < data_array.size() - 1)) {

		// Calculate the indices of potential child vertices and from the last index.
		int possible_child_index_a = ((index + 1) * 2) - 1;
		int possible_child_index_b = possible_child_index_a + 1;
        const int last_possible_index = data_array.size() - 1;

		// Decision if child vertices exist.
		// If not the value of the child will be set equal to the current index and thereby never be 
		// bigger or smaller that the current index. This will falsify the while loop if both indices are 
		int child_index_a = possible_child_index_a <= last_possible_index ? possible_child_index_b : index;
		int child_index_b = possible_child_index_b <= last_possible_index ? possible_child_index_b : index;

		// Swap values in the Vertex as explained in repair_up but downwards as long as the Heap-Order is not restored
		// and as long as there are values to swap.
		while ((data_array[index] < data_array[child_index_a]) ||
				(data_array[index] < data_array[child_index_b])) {

			if (data_array[child_index_a] > data_array[child_index_b]) {
				iter_swap(data_array.begin() + index,
						data_array.begin() + child_index_a);
				index = child_index_a;
			}
			else {
				iter_swap(data_array.begin() + index,
						data_array.begin() + child_index_b);
				index = child_index_b;
			}

			// Recalculate the indices for the next children.
			possible_child_index_a = ((index + 1) * 2) - 1;
			possible_child_index_b = possible_child_index_a + 1;

			// Get the priority of the children if they exist.
			child_index_a = possible_child_index_a <= last_possible_index ? possible_child_index_a : index;
			child_index_b = possible_child_index_b <= last_possible_index ? possible_child_index_b : index;
		}
	}

}

// Constructor
Heap::Heap(const vector<int>& start_vector) : data_array(start_vector) {}

// Destructor
Heap::~Heap() {
	// When the Heap is destructed the memory of the arrays must be released.
	data_array.clear();
}

// Copy Constructor
Heap::Heap(const Heap& other) : data_array( other.data_array ) {}

// Copy Assignment Operator
Heap&  Heap::operator=(const Heap& other) {
	if (this == &other) return *this;
	data_array = other.data_array;
	return *this;
}

// Move Constructor
Heap::Heap(Heap&& other) noexcept : data_array( other.data_array ) {
	other.data_array.clear();
}

// Move Assignment Operator
Heap& Heap::operator=(Heap&& other) noexcept {
	if (this == &other)  return *this;
	data_array = other.data_array;
	other.data_array.clear();
	return *this;
}

vector<int> Heap::read() const {
	return data_array;
}

void Heap::add(const int element) {
	// push_back adds an element at the End of the vector in increases the size if necessary.
	data_array.push_back(element);
}

void Heap::remove(const int index){
	// we remove by a similar technique as delete_max by changing the priority of the last Element and deleting the last
    // priority.
    const int last_priority = data_array.back();
	data_array.pop_back();
	change_priority(index, last_priority);
}

int Heap::delete_max() {
	// Removes the Vertex with the highest priority and returns the Priority.
	// Then to repair the Heap-Order the last Element in the Heap has to be assigned to the root 
	// so that we can call repair_down on it.

	// We separate different cases of the vector.size() if there is more than one value the Heap-Structure and Order
	// must be restored again.
	if (data_array.size() > 1) {
        const int max = data_array[0];
		data_array[0] = data_array.back();
		repair_down(0);
		return max;

	// if there is only one value we don't need to repair anything.
	}
    if (data_array.size() == 1) {
        const int max = data_array[0];
        data_array.pop_back();
        return max;

        // In the last case the Heap has no values and nothing can be returned.
    }
    cout << "No values in the Heap" << endl;
    return 0;
}

int Heap::change_priority(const int index, const int new_priority) {
	// If the priority of one vertex changed we have to update the current priority to the new priority and repair the
    // Heap Order.
    const int old_priority = data_array[index];
	data_array[index] = new_priority;
	// We decide if repair_up or repair_down has to be called based on the value of the old_priority.
	if (new_priority < old_priority) {
		repair_down(index);
		return 1;
	}
    if (new_priority > old_priority) {
        repair_up(index);
        return 1;
    }
    return 0;
}  

void Heap::build_heap() {
	// To build the Heap from scratch in case an array was assigned to the Heap, we start at the last vertex that is not a Leaf
	// then we call repair_down on each vertex as with each level of depth that was repaired the Heap Order is
    // restored for this level and all levels below.
    const int end_index = data_array.size() - 1;
	int index = ((end_index + 1)/ 2) - 1;
	while (index >=0) {
		repair_down(index);
		index--;
	}
}
