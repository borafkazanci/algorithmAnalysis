/**
* Title : Algorithm Efficiency and Sorting
* Author : Bora Fatih Kazancý
* ID: 21801753
* Section : 1
* Assignment : 1
* Description : Main code to run the sorting algorithms and test them
*/

#include "sorting.h"

int main() {
	Sorting s;
	// part a - c
	s.performanceAnalysis(2000);


	// part d
	int* array1 = new int[10];
	int* array2 = new int[10];
	int* array3 = new int[10];
	int aSize = 10;
	int first = 0;
	int last = 9;
	int compCount, moveCount;

	// 20, 1, 100, 57, 92, 43, 99, 93, 17, 58
	array1[0] = 20, array1[1] = 1, array1[2] = 100, array1[3] = 57, array1[4] = 92, array1[5] = 43, array1[6] = 99, array1[7] = 93, array1[8] = 17, array1[9] = 58;
	array2[0] = 20, array2[1] = 1, array2[2] = 100, array2[3] = 57, array2[4] = 92, array2[5] = 43, array2[6] = 99, array2[7] = 93, array2[8] = 17, array2[9] = 58;
	array3[0] = 20, array3[1] = 1, array3[2] = 100, array3[3] = 57, array3[4] = 92, array3[5] = 43, array3[6] = 99, array3[7] = 93, array3[8] = 17, array3[9] = 58;

	// quickSort
	compCount = 0, moveCount = 0;
	s.quickSort(array1, first, last, compCount, moveCount);
	s.printArray(array1, aSize, "quicksort");

	// insertitionSort
	compCount = 0, moveCount = 0;
	s.insertionSort(array2, aSize, compCount, moveCount);
	s.printArray(array2, aSize, "insertion sort");

	// hybridSort
	compCount = 0, moveCount = 0;
	s.hybridSort(array3, first, last, compCount, moveCount);
	s.printArray(array3, aSize, "hybrid sort");

	delete[] array1;
	delete[] array2;
	delete[] array3;
	return 1;
}