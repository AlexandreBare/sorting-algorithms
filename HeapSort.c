/* ========================================================================= *
 * HeapSort
 * Implementation of the HeapSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <assert.h>
#include "Sort.h"

#define LEFT_CHILD(X) (2*X + 1)
#define RIGHT_CHILD(X) (2*(X + 1))

/* ------------------------------------------------------------------------- *
 * Swap the value of 2 elements
 *
 * PARAMETERS
 * a    A pointer to the first element
 * b    A pointer to the second element
 * ------------------------------------------------------------------------- */
static void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* ------------------------------------------------------------------------- *
 * Move (recursively) the element i so that the oder property
 * (A[parent] >= A[chil] for all children) of the heap is respected
 *
 * PARAMETERS
 * array        The array containing the heap
 * heapSize     The size of the heap
 * i            The position of the current element (= parent)
 * ------------------------------------------------------------------------- */
static void maxHeapify(int *array, size_t heapSize, size_t i){
    assert(array != NULL);
    
    size_t leftChild = LEFT_CHILD(i);
    size_t rightChild = RIGHT_CHILD(i);
    size_t max;    //Save the max value between the parent and its 2 children
                   //(in the heap)
    
    if(leftChild <= heapSize && array[leftChild] > array[i])
        max = leftChild;
    else
        max = i;
    if(rightChild <= heapSize && array[rightChild] > array[max])
        max = rightChild;
    
    if(max != i){
        swap(&array[max], &array[i]);
        maxHeapify(array, heapSize, max);
    }
        
}

/* ------------------------------------------------------------------------- *
 * Build a heap respecting the order property
 * (A[parent] >= A[chil] for all children)
 *
 * PARAMETERS
 * array    The initial array interpreted as a complete binary tree
 * length   The length of the array
 * ------------------------------------------------------------------------- */
static void buildMaxHeap(int *array, size_t length){
    assert(array != NULL);
    
    for(size_t i = length / 2 + 1; i > 0; i--) //length / 2 = the position of
                                               //the last element that has at
                                               //least a child
        maxHeapify(array, length, i - 1);
}

/* ------------------------------------------------------------------------- *
 * Perform the HeapSort algorithm
 *
 * PARAMETERS
 * array    The array to sort
 * length   The length of the array
 * ------------------------------------------------------------------------- */
static void heapSort(int *array, size_t length){
    assert(array != NULL);
    
    buildMaxHeap(array, length);
    
    for(size_t i = length; i > 0; i--){
        swap(&array[i], &array[0]); //Swap the first element (= the root)
                                    //with the last element of the heap
        maxHeapify(array, --length, 0); //Re-establish the order property of
                                        //the heap (that is one element shorter)
    }
}

void sort(int* array, size_t length){
    if(!array || length == 0)
        return;
    
    heapSort(array, length-1);
    
}
