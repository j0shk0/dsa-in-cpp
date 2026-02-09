#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

using namespace std;

class Heap {
	
	// Declaring the typical vector to store the values of the Heap.
	vector<int> data_array;
	void repair_up(int index);
	void repair_down(int index);

	public:

	Heap(const vector<int>& start_vector);
	~Heap();
	Heap(const Heap& other);
	Heap&  operator=(const Heap& other);
	Heap(Heap&& other) noexcept;
	Heap& operator=(Heap&& other) noexcept;
	vector<int> read() const;
	void add(int element);
	void remove(int index);
	int delete_max();
	int change_priority(int index, int new_priority);
	void build_heap();
};

#endif
