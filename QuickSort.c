/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Swap the value of 2 elements
 *
 * PARAMETERS
 * a    The first element
 * b    The second element
 * ------------------------------------------------------------------------- */
static void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* ------------------------------------------------------------------------- *
 * Divide an array into 2 parts: one for the elements <= to the pivot and one
 * for the elements > to the pivot (= last element) and move the pivot between these two parts
 * of the array
 *
 * PARAMETERS
 * array    The array to partition
 * p        The position of the first element
 * r        The position of the last element
 *
 * RETURN
 * i    The new position of the pivot
 * ------------------------------------------------------------------------- */
static int partition(int *array, int p, int r){
    assert(array != NULL && p >= 0 && r > 0);
    
	int pivot = array[r];
	int i = p;
	for(int j = p; j < r; j++){
		if (array[j] <= pivot){
            swap(&array[i], &array[j]); //Move the elements <= to the pivot
                                        //on the left side of the array
            i++;
		}
	}
    swap(&array[i], &array[r]);
	return i;
}

/* ------------------------------------------------------------------------- *
 * Choose a pivot randomly before calling partition
 *
 * PARAMETERS
 * array    The array to partition
 * p        The position of the first element
 * r        The position of the last element
 *
 * RETURN
 * The value returned by partition
 * ------------------------------------------------------------------------- */
static int randomizedPartition(int *array, int p, int r){
    int i = rand() % (r - p + 1) + p;
    swap(&array[r], &array[i]);
    return partition(array, p, r);
}

/* ------------------------------------------------------------------------- *
 * Perform the QuickSort algorithm (recursively)
 *
 * PARAMETERS
 * array    The array to sort
 * p        The position of the first element
 * r        The position of the last element
 * ------------------------------------------------------------------------- */
static void quickSort(int *array, int p, int r){
    assert(array != NULL && p >= 0);  // r can be < 0
    
	if (p < r) {
        int q = randomizedPartition(array, p, r);
        quickSort(array, p, q - 1); //Sort the left part of the array
        quickSort(array, q + 1, r); //Sort the right part of the array
	}

}

void sort(int *array, size_t length){
    if(!array || length == 0)
        return;
    
	quickSort(array, 0, length-1);

}
