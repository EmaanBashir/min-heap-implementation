#include "MinHeap.h"

//main method to test the class min heap
int main() {

	//declaring variables
	int number, capacity, noOfValues, counter = 0;

	//input the capacity of the heap
	cout << "Enter the capacity of the heap: ";
	cin >> capacity;

	//create the heap
	MinHeap heap(capacity);

	//input the number of values to be inserted
	cout << "Enter the number of values to be inserted: ";
	cin >> noOfValues;

	//input the values to be inserted
	while (counter < capacity && counter < noOfValues) {
		cout << "Value " << ++counter << ": ";
		cin >> number;
		heap.push(number);
	}

	//print the heap
	cout << "\nHeap: ";
	heap.print();

	//return the minimum element
	cout <<"\nTop: " << heap.top();

	//remove the minimum element
	cout << "\nPop...";
	heap.pop();

	//print the heap
	cout << "\nHeap: ";
	heap.print();

	//is the heap empty
	string empty = "No";
	if (heap.isEmpty()) empty = "Yes";
	cout << "\nis Empty? " <<empty;

	//size of the heap
	cout << "\nSize of heap: " << heap.getSize();

	//height of the heap
	cout << "\nHeight of heap: " << heap.height();

	//build a heap from an array
	cout << "\n\n'''Build Heap from an array'''";
	int array[] = {NULL, 1, 5, 3, 7, 2, 4, 8};
	

	//print the original array
	cout << "\n\nArray: ";
	for (int i = 1; i < 8; i++) {
		cout << array[i] << " ";
	}

	//call the build heap method
	heap.buildHeap(array, 7);

	//print the array after build heap method
	cout << "\nAfter build heap: ";
	for (int i = 1; i < 8; i++) {
		cout << array[i] << " ";
	}
	return 0;
}
