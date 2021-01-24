#include <iostream>
using namespace std;

//class min heap
class MinHeap{

//private fields
private:
	int capacity;
	int size;
	int* array;

//public methods
public:

	//constructor
	MinHeap(int capacity) {
		this->capacity = capacity;
		size = 0;
		array = new int[capacity + 1];
	}

	//method to return the minimum number
	int top() {
		if (!isEmpty()) {
			return array[1];
		}
		else {
			cout << "The heap is Empty!" << endl;
			return -1;
		}
	}

	//method to remove the minimum number
	int pop() {
		if (!isEmpty()) {
			int number = array[1];
			array[1] = array[size];
			size--;
			minHeapify(array, 1, size);
			return number;
		}
		else {
			cout << "Heap Underflow!" << endl;
			return -1;
		}
	}

	//method to insert an element and rearrange the heap
	void push(int n) {
		if (size < capacity) {
			array[++size] = n;
			int x = size;
			while (x > 0 && array[parent(x)] > array[x]) {
				swap(array[parent(x)], array[x]);
				x = parent(x);
			}
		}
		else {
			cout << "Heap is full!" << endl;
		}

		
	}

	//method to check if the heap is empty
	bool isEmpty() {
		return size == 0;
	}

	//method to get the size of the heap
	int getSize() {
		return size;
	}

	//method to get the height of the heap
	int height() {
		return floor(log2(size));
	}

	//method to return the parent of a node
	int parent(int n) {
		return floor(n / 2);
	}

	//method to get the left child
	int left(int n) {
		return 2 * n;
	}

	//method to get the right child
	int right(int n) {
		return 2 * n + 1;
	}

	//min heapify function
	void minHeapify(int* array, int index, int size) {
		int l = left(index);
		int r = right(index);
		int min;
		if (l <= size && array[index] > array[l]) {
			min = l;
		}
		else {
			min = index;
		}
		if (r <= size && array[min] > array[r]) {
			min = r;
		}
		if (min != index) {
			swap(array[min], array[index]);
			minHeapify(array, min, size);
		}
	}

	//build heap method
	void buildHeap(int* array, int size) {
		for (int i = size; i > 0; i--) {
			minHeapify(array, i, size);
		}
	}

	//print heap method
	void print() {
		for (int i = 1; i <= size; i++) {
			cout << array[i] << " ";
		}
	}
};
