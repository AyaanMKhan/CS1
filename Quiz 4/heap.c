#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100
#define NUM_TEST_INSERTS 150
//#define NUM_TEST_INSERTS 1000000
#define NUM_TOTAL_OPS 10000000
#define PRINT 0

struct heapStruct {
    int* heaparray;
    int capacity;
    int size;
};


// Initialize an empty heap with a capacity of SIZE.
struct heapStruct* initHeap() {

    struct heapStruct* h;

    // Allocate space for the heap and set the size for an empty heap.
    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    h->capacity = SIZE;
    h->heaparray = (int*)malloc(sizeof(int)*(SIZE+1));
    h->size = 0;
    return h;
}

// Frees the struct pointed to by h.
void freeHeap(struct heapStruct *h) {
     free(h->heaparray);
     free(h);
}

// Initializes the heap using the first length number of items in the array
// values.
struct heapStruct * initHeapfromArray(int* values, int length) {

    int i;
    struct heapStruct* h;

    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    // We allocate one extra slot, since slot 0 stays unused.
    h->heaparray = (int*)malloc(sizeof(int)*(length+1));

    // Just copy the values into our array.
    for (i=1; i<=length; i++)
        h->heaparray[i] = values[i-1];

    // This is the number of values we copied.
    h->size = length;

    // This takes our random values and rearranges them into a heap.
    heapify(h);
    return h;
}

// h points to a heap structure that has values inside of it, but isn't yet
// organized into a heap and does exactly that.
void heapify(struct heapStruct *h) {

    int i;

    // We form a heap by just running percolateDown on the first half of the
    // elements, in reverse order.
    for(i = h->size/2; i > 0; i--){
        percolateDown(h, i);
    }

    for(i = 1; i <= h->size; i++){
        percolateUp(h, i);
    }

}

// Runs percolate down on the heap pointed to by h on the node stored in index.
void percolateDown(struct heapStruct *h, int index) {

    int min;

    // Only try to percolate down internal nodes.
    if ((2*index+1) <= h->size) {

        // Find the minimum value of the two children of this node.
        min = minimum(h->heaparray[2*index], 2*index, h->heaparray[2*index+1], 2*index+1);

      // If this value is less than the current value, then we need to move
      // our current value down the heap.
        if (h->heaparray[index] > h->heaparray[min]) {
            swap(h, index, min);

            // This part is recursive and allows us to continue percolating
            // down the element in question.
            percolateDown(h, min);
        }
    }

    // Case where our current element has exactly one child, a left child.
    else if (h->size == 2*index) {

        // Here we only compare the current item to its only child.
        // Clearly, no recursive call is needed since the child of this node
        // is a leaf.
        if (h->heaparray[index] > h->heaparray[2*index]){
            swap(h, index, 2*index);
        }
    }
}

// Runs percolate up on the heap pointed to by h on the node stored in index.
void percolateUp(struct heapStruct *h, int index) {

    // Can only percolate up if the node isn't the root.
    if (index > 1) {

        // See if our current node is smaller in value than its parent.
        if (h->heaparray[index/2] > h->heaparray[index]) {

            // Move our node up one level.
            swap(h, index, index/2);

            // See if it needs to be done again.
            percolateUp(h, index/2);
        }
    }
}

// Inserts value into the heap pointed to by h. Returns 1 if the insert was
// successful, 0 otherwise.
int insert(struct heapStruct *h, int value) {

    

    // Our array is full, we need to allocate some new space!
    if (h->size == h->capacity) {

        // Allocate new space for an array.
        h->heaparray = (int*)realloc(h->heaparray, sizeof(int)*(2*h->capacity+1));

        // Realloc failed so we quit.
        if (h->heaparray == NULL) return 0;

        // Double the capacity.
        h->capacity *= 2;
    }

    // Adjust all the necessary components of h, and then move the inserted
    // item into its appropriate location.
    h->size++;
    h->heaparray[h->size] = value;
    percolateUp(h, h->size);
}

// heap sort
void heapsort(int values[], int length) {

    struct heapStruct* h;
    int i;

    // Initialize the heap with the values.
    h = initHeapfromArray(values, length);

    // Pull them out in sorted order.
    for (i=0; h->size>0; i++)
        values[i] = removeMin(h);

    // Free the heap.
    freeHeap(h);
}