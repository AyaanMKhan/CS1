#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Partition function
int partition(int *arr, int low, int high) {
    

    int lowpos = low;
    low++;

    while(low <= high){

        if(arr[low] <= arr[lowpos]){
            low++;
        } else if(arr[high] > arr[lowpos]){
            high--;
        } else {
            swap(&arr[low], &arr[high]);
        }
    }

    swap(&arr[high], &arr[lowpos]);
    printArray(arr, 8);
    return high;
}

// QuickSort function
void quickSort(int* numbers, int low, int high) {
    // Average, Best: O(n log n), Worst: O(n^2)
    // Space: O(log n), O(n)
    if(low < high){
        int pivot = partition(numbers, low, high);
        quickSort(numbers, low, pivot-1);
        quickSort(numbers, pivot+1, high);
    }
}



// Main function to test QuickSort
int main() {
    int arr[] = {6, 2, 8, 1, 3, 7, 5, 4};
    int n = 8;
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}