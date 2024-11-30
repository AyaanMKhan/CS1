#include <stdio.h>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform insertion sort on a subarray
void insertionMergeSort(int arr[], int l, int r) {
    int i, item, j;
    for (i = l + 1; i <= r; i++) {
        item = arr[i];
        /* Move elements of arr[l..i-1], that are
        greater than key, to one position ahead
        of their current position */
        for (j = i - 1; j >= l; j--) {
            if (arr[j] > item) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = item;
    }
}

// Function to merge two subarrays of arr[]
void merge(int arr[], int l, int m, int r) {
    int lSize = m - l + 1;
    int rSize = r - m;

    // Create temporary arrays
    int left[lSize], right[rSize];

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < lSize; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < rSize; i++) {
        right[i] = arr[m + 1 + i];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < lSize && j < rSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < lSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < rSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform merge sort with insertion sort for small subarrays
void mergeInsertionSort(int arr[], int l, int r) {
    if (l < r) {
        if (r - l + 1 <= 25) {
            insertionMergeSort(arr, l, r);
            return;
        }
        // Get the mid point
        int m = (l + r) / 2;
        // Sort first and second halves
        mergeInsertionSort(arr, l, m);
        mergeInsertionSort(arr, m + 1, r);
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 3, 1, 9, 8, 2, 4, 10, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeInsertionSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}