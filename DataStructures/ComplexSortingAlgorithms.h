/*-- ComplexSortingAlgorithms.h --------------------------------------------------------------

 This header file defines multiple complex sorting algorithms.

 sorting algorithms included:
 QuickSort
 HeapSort
 RadixSort 
 MergeSort
 --------------------------------------------------------------------------*/

#ifndef ComplexSortingAlgorithms_h
#define ComplexSortingAlgorithms_h
#include <queue>
#include <list>
#include <iostream>
#include <iomanip>
using namespace std;
typedef int ElementType;


 //---------------------------- Quick Sort --------------------------------------------
void quickSort(int arr[], int s);
void quickSortAux(int arr[], int low, int high);

//---------------------------- Heap Sort --------------------------------------------
void heapify(int* arr, int iParent, int size);
void buildHeap(int* arr, int size);
void heapSort(int* arr, int size);

//---------------------------- Radix Sort --------------------------------------------
void radixSort(list<ElementType>& x, int numDigits, int base);

//---------------------------- Merge Sort --------------------------------------------
void mergesort(int* a, int* b, int low, int high);
void merge(int* a, int* b, int low, int Mid, int high);

#endif