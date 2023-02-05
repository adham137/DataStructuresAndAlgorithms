#include "ComplexSortingAlgorithms.h"


//---------------------------- Quick Sort --------------------------------------------
void quickSort(int arr[], int s) {
	quickSortAux(arr, 0, s - 1);
}

void quickSortAux(int arr[], int low, int high) {
	//the function does not split the array explicilty , instead it passes 
	//the lower (low) and upper (high) indicies of the sublist we are going to work on
	//thus working on a single array instead of creating multiple and using too much memory

	int size = (high - low) + 1;
	if (size <= 1 ) {
		return;
	}

	int pivotindex = low;
	int leftPtr = low + 1;
	int rightPtr = high;

	//place the pivot in the correct index
	while (true) {

		//if the value of the left pointer is not greater than the value of pivot , increment left pointer by 1
		if (!(arr[leftPtr] > arr[pivotindex])) leftPtr++;

		//if the value of the right pointer is not less than or equal the value of pivot , decrement left pointer by 1
		if (!(arr[rightPtr] <= arr[pivotindex])) rightPtr--;

		//break condition : if left pointer passes the right pointer 
		if (leftPtr > rightPtr) break;

		//swap the values of the left and right pointers
		if ((arr[leftPtr] > arr[pivotindex]) && (arr[rightPtr] <= arr[pivotindex])) {
			int temp = arr[rightPtr];
			arr[rightPtr] = arr[leftPtr];
			arr[leftPtr] = temp;
		}
	}

	//swap the values of the right pointer and the pivot
	int temp = arr[rightPtr];
	arr[rightPtr] = arr[pivotindex];
	arr[pivotindex] = temp;

	//set the index of the pivot to the index of right pointer
	pivotindex = rightPtr;

	//call the function on the sublist before the pivot
	quickSortAux(arr, low, pivotindex - 1);

	//call the function on the sublist after the pivot
	quickSortAux(arr, pivotindex + 1, high);

}



//---------------------------- Heap Sort --------------------------------------------
void heapify(int* arr, int iParent, int size) {
	int temp = 0;

	//calculate index of first child
	int iFirstChild = (2 * (iParent + 1)) - 1;

	//calculate index of second child
	int iSecChild = (2 * (iParent + 1) + 1) - 1;

	//if first child exists and > parent , swap
	if ((arr[iParent] < arr[iFirstChild]) && (iFirstChild < size)) {

		temp = arr[iParent];
		arr[iParent] = arr[iFirstChild];
		arr[iFirstChild] = temp;

	}

	//if second child exists and > parent , swap
	if ((arr[iParent] < arr[iSecChild]) && (iSecChild < size)) {

		temp = arr[iParent];
		arr[iParent] = arr[iSecChild];
		arr[iSecChild] = temp;

	}
}

//call the heapify function multiple times to build the Max-heap 
void buildHeap(int* arr, int size) {
	int i, j;
	//calculate the number of levels of the heap 
	int nHeapLevels = log2(size);

	//calculate number of parents
	int nParents = size / 2;

	//repeat (number of heap levels) times to build the heap
	for (i = 0;i < nHeapLevels;i++) {

		//call heapify function to build the sub-Heap for each parent
		for (j = 0; j < nParents; j++) {
			heapify(arr, j, size);
		}

	}

}

//sort the array descending using the Max-heap and a queue
void heapSort(int* arr, int size) {
	queue<int> q;
	int i = 0;

	//if size is zero , then there is nothing to sort
	//if size is one , then it's already sorted
	if (size == 0 || size == 1) return;

	while (size > 0) {

		buildHeap(arr, size);

		//push the top of the heap into queue
		q.push(arr[0]);

		//replace the the top of heap with the last element
		arr[0] = arr[size - 1];

		size--;
	}

	//push the queue sorted contents into the array
	while (!q.empty()) {
		arr[i] = q.front();
		q.pop();
		i++;
	}



}



//---------------------------- Radix Sort --------------------------------------------
void radixSort(list<ElementType>& x, int numDigits, int base) {
	list<ElementType>* bucket = new list<ElementType>[base];
	int basePower = 1;
	ElementType value;
	for (int pass = 1; pass <= numDigits; pass++) {
		while (!x.empty()) {
			value = x.front();
			x.pop_front();
			int digit = value % (base * basePower) / basePower;
			//int digit = value % base;
			bucket[digit].push_back(value);
		}
		for (int i = 0; i < base; i++)
			while (!bucket[i].empty()) {
				value = bucket[i].front();
				x.push_back(value);
				bucket[i].pop_front();
			}
		basePower *= base;
		cout << pass << ": ";
		for (list<ElementType>::iterator it = x.begin(); it != x.end(); it++)
			cout << setfill('0') << setw(numDigits) << *it << ", ";
		cout << endl;
	}
}

//---------------------------- Merge Sort --------------------------------------------
void mergesort(int* a, int* b, int low, int high) {
	int Mid;
	if (low < high) {
		Mid = (low + high) / 2;
		mergesort(a, b, low, Mid);
		mergesort(a, b, Mid + 1, high);
		merge(a, b, low, Mid, high);
	}
}
void merge(int* a, int* b, int low, int Mid, int high) {
	int i, x, y, k;
	i = low;
	x = low;
	y = Mid + 1;

	while ((x <= Mid) && (y <= high)) {
		if (a[x] <= a[y]) {
			b[i] = a[x];
			x++;
		}
		else {
			b[i] = a[y];
			y++;
		}
		i++;
	}
	if (x > Mid) {
		for (k = y; k <= high; k++) {
			b[i] = a[k];
			i++;
		}
	}
	else {
		for (k = x; k <= Mid; k++) {
			b[i] = a[k];
			i++;
		}
	}
	for (k = low; k <= high; k++)
		a[k] = b[k];
}