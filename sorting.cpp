/**
* Title : Algorithm Efficiency and Sorting
* Author : Bora Fatih Kazancý
* ID: 21801753
* Section : 1
* Assignment : 1
* Description : This file consists sorting algorithm
* funtions to calculate their efficiency	
*/

#include "sorting.h"

void Sorting::partition(int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount) {
	int pivot = arr[first];

	int lastS1 = first;
	int firstUnknown = first + 1;

	for (; firstUnknown <= last; ++firstUnknown) {
		if (arr[firstUnknown] < pivot) {  	// belongs to S1
			compCount++;	// key comparison ++
			lastS1++;
			swap(arr[firstUnknown], arr[lastS1]);
			moveCount += 3;	// 3 times item moved
		}
		// else belongs to S2
	}
	// place pivot in proper position and mark its location
	swap(arr[first], arr[lastS1]);
	moveCount += 3;	// 3 times item moved
	pivotIndex = lastS1;
}

void Sorting::quickSort(int* arr, int f, int l, int& compCount, int& moveCount) {
	int pivotIndex;

	if (f < l) {
		// create the partition: s1, pivot, s2
		partition(arr, f, l, pivotIndex, compCount, moveCount);

		// sort regions s1 and s2 recursively
		quickSort(arr, f, pivotIndex, compCount, moveCount);
		quickSort(arr, pivotIndex + 1, l, compCount, moveCount);
	}
}

void Sorting::insertionSort(int* arr, int size, int& compCount, int& moveCount) {
	for (int unsorted = 1; unsorted < size; unsorted++) {
		int nextItem = arr[unsorted];	// key
		int loc = unsorted;
		
		for (; (loc > 0) && (arr[loc - 1] > nextItem); loc--) {	// key comparison
			compCount++;
			arr[loc] = arr[loc - 1];	// data moves
			moveCount++;	// when data moves moveCount++
		}
		arr[loc] = nextItem;	// data moves
		moveCount++;	// key item moves
	}
}

void Sorting::hybridSort(int* arr, int f, int l, int& compCount, int& moveCount) {
	int size = l - f + 1;

	if (f < l) {
		// when partition size is less than or eual to 10 it osrts with insertion sort
		if (size <= 10) {
			insertionSort(arr, size, compCount, moveCount);
		}
		else {
			int pivotIndex;
			partition(arr, f, l, pivotIndex, compCount, moveCount);

			hybridSort(arr, f, pivotIndex - 1, compCount, moveCount);
			hybridSort(arr, pivotIndex + 1, l, compCount, moveCount);
		}
	}
}

void Sorting::printArray(int* arr, int size, string type) {
	cout << "By " << type << ": ";

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Sorting::performanceAnalysis(int startSize) {
	// I went with the loop. I know that it does not look like the list2. However, takiing data and reading of it seemed easier.

	for (; startSize <= 20000; startSize += 2000) {
		srand(time(0));
		int* array = new int[startSize];
		int* array1 = new int[startSize];
		int* array2 = new int[startSize];
		
		int f = 0;
		int l = startSize - 1;
		double duration1, duration2, duration3;
		int compCount, moveCount;

		for (int i = 0; i < startSize; i++) {
			int random = (rand());
			array[i] = random;
			array1[i] = random;
			array2[i] = random;
		}

		// quickSort ---------------------------------------------------------------------------------------------------
		compCount = 0, moveCount = 0;
		clock_t startTime1 = clock();

		quickSort(array, f, l, compCount, moveCount);

		duration1 = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;
		cout << "Part a - Time analysis of Quick Sort" << endl;
		cout << "Array Size " << "	" << "Time Elapsed" << "	" << "compCount" << "		" << "moveCount" << endl;
		cout << startSize << "		" << duration1 << " ms" << "		" << compCount << "			" << moveCount << endl;
		cout << "--------------------------------------------------------------------------" << endl;

		// insertionSort ---------------------------------------------------------------------------------------------------
		compCount = 0, moveCount = 0;
		clock_t startTime2 = clock();

		insertionSort(array1, startSize, compCount, moveCount);

		duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;
		cout << "Part b - Time analysis of Insertion Sort" << endl;
		cout << "Array Size " << "	" << "Time Elapsed" << "	" << "compCount" << "		" << "moveCount" << endl;
		cout << startSize << "		" << duration2 << " ms" << "		" << compCount << "		" << moveCount << endl;
		cout << "--------------------------------------------------------------------------" << endl;

		// hybridSort ---------------------------------------------------------------------------------------------------
		compCount = 0, moveCount = 0;
		clock_t startTime3 = clock();

		hybridSort(array2, f, l, compCount, moveCount);

		duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;
		cout << "Part c - Time analysis of Hybrid Sort" << endl;
		cout << "Array Size " << "	" << "Time Elapsed" << "	" << "compCount" << "		" << "moveCount" << endl;
		cout << startSize << "		" << duration3 << " ms" << "		" << compCount << "			" << moveCount << endl;
		cout << "--------------------------------------------------------------------------" << endl;

		cout << endl;
		cout << endl;
		cout << endl;

		delete[] array;
		delete[] array1;
		delete[] array2;
	}
}
