#include "SimpleSortingAlgorithms.h"

//---------------------------- Bubble Sort --------------------------------------------
void bubbleSort(int Ar[], long size) {
    int temp;
    for (long i = 0; i < size - 1; i++)
        //for ( int j = 0; j < size-1; j++){
        for (long j = 0; j < size - i - 1; j++) {

            if (Ar[j] > Ar[j + 1]) {
                temp = Ar[j];
                Ar[j] = Ar[j + 1];
                Ar[j + 1] = temp;
            } /* end if */
        }
   
}

//---------------------------- Selection Sort --------------------------------------------
void SelectionSort(int Ar[], long size) {
    int currentMin;
    unsigned long currentMinIndex;
    for (long i = 0; i < size - 1; i++) {
        currentMin = Ar[i];    // Find the minimum in the list[i..list.length-1]
        currentMinIndex = i;
        for (long j = i + 1; j < size; j++) {
            
            if (currentMin > Ar[j]) {
                currentMin = Ar[j];
                currentMinIndex = j;
            }
        }
        if (currentMinIndex != i) {
            Ar[currentMinIndex] = Ar[i];
            Ar[i] = currentMin;
        }
    }

}

//---------------------------- Insertion Sort --------------------------------------------
void insertionSort(int arr[],long size) {

    int i, j;
    for (i = 0;i <size;i++) {
        j = i;

        //j is less than j-1 , swap them and decrement j
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}