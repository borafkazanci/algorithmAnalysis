/**
* Title : Algorithm Efficiency and Sorting
* Author : Bora Fatih Kazancý
* ID: 21801753
* Section : 1
* Assignment : 1
* Description : This file consists function of sorting as header file
*/

#ifndef __SORTING_H
#define __SORTING_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

class Sorting {
public:
	void quickSort(int* arr, int f, int l, int& compCount, int& moveCount);
	void insertionSort(int* arr, int size, int& compCount, int& moveCount);
	void hybridSort(int* arr, int f, int l, int& compCount, int& moveCount);
	void printArray(int* arr, int size, string type);
	void performanceAnalysis(int startSize);
private:
	void partition(int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount);
};
#endif