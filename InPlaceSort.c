/* ========================================================================= *
 * InPlaceSort
 * Implementation of the InPlaceMergeSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <assert.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Merge in place the left (from position p to q) and
 * right (from position q+1 to r) parts of the array in a sorted sequence
 *
 * PARAMETERS
 * array    The array
 * p        The position of the first element
 * q        The position of the middle element (bottom rounded)
 * r        The position of the last element
 * ------------------------------------------------------------------------- */
static void inPlaceMerge(int *array, size_t p, size_t q, size_t r){
    assert(array != NULL && p <= q && q < r && p >= 0);
    
    size_t i_left = p;
    size_t i_right = q + 1;
    
    while(i_left < r && i_right <= r && array[i_right - 1] > array[i_right]){
        if(array[i_left] <= array[i_right])
            i_left++;
        else{
            int tmp = array[i_right];
            size_t i;
            for(i = i_right; i > i_left; i--){
                array[i] = array[i - 1];
            }
            array[i] = tmp;
            i_right++;
        }
    }
}

/* ------------------------------------------------------------------------- *
 * Perform the InPlaceMergeSort algorithm (recursively)
 *
 * PARAMETERS
 * array    The array to sort
 * p        The position of the first element
 * r        The position of the last element
 * ------------------------------------------------------------------------- */
static void mergeSort(int *array, size_t p, size_t r){
    assert(array != NULL);
    
    if(p < r){
        size_t q = (p + r) / 2; //Find the position of the middle element
        //(bottom rounded) of the array
        mergeSort(array, p, q); //Sort the left part of the array
        mergeSort(array, q + 1, r); //Sort the rigth part of the array
        inPlaceMerge(array, p, q, r); //Merge the 2 parts of the array
    }
}

void sort(int* array, size_t length){
    if(!array || length == 0)
        return;
    
    mergeSort(array, 0, length-1);
    
}
