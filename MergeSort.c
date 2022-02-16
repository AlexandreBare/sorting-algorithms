/* ========================================================================= *
 * MergeSort
 * Implementation of the MergeSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <limits.h>
#include <assert.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Merge the left (from position p to q) and right (from position q+1 to r)
 * parts of the array in a sorted sequence
 *
 * PARAMETERS
 * array    The array
 * p        The position of the first element
 * q        The position of the middle element (bottom rounded)
 * r        The position of the last element
 * ------------------------------------------------------------------------- */
static void merge(int* array, size_t p, size_t q, size_t r){
    assert(array != NULL && p <= q && q < r);
    
	size_t l_length = q - p + 1;
	size_t r_length = r - q;
	size_t leftArray[l_length + 1];
	size_t rightArray[r_length + 1];

	for(size_t i = 0; i < l_length; i++)
		leftArray[i] = array[p + i];
	for(size_t j = 0; j < r_length; j++)
		rightArray[j] = array[q + j + 1];
    
    leftArray[l_length] = INT_MAX;
    rightArray[r_length] = INT_MAX;

	size_t i = 0;
	size_t j = 0;
    
    //For all the elements to merge, place them in the right order
    //in the studied part of the array
    for(size_t k = p; k <= r; k++){
        
		if(leftArray[i] <= rightArray[j]){
			array[k] = leftArray[i];
			i++;
		}else{
			array[k] = rightArray[j];
			j++;
		}
        
	}
}

/* ------------------------------------------------------------------------- *
 * Perform the MergeSort algorithm (recursively)
 *
 * PARAMETERS
 * array    The array to sort
 * p        The position of the first element
 * r        The position of the last element
 * ------------------------------------------------------------------------- */
static void mergeSort(int *array, size_t p, size_t r){
    assert(array != NULL && p >= 0);
    
	if(p < r){
		size_t q = (p + r) / 2; //Find the position of the middle element
                                //(bottom rounded) of the array
		mergeSort(array, p, q); //Sort the left part of the array
		mergeSort(array, q + 1, r); //Sort the rigth part of the array
		merge(array, p, q, r); //Merge the 2 parts of the array
	}
}

void sort(int* array, size_t length){
    if(!array || length == 0)
        return;
    
	mergeSort(array, 0, length-1);
}

