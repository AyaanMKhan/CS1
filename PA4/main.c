#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} coordinates;

int x, y;
// Function to read data into the coordinates array
coordinates* readData(int n) {
    coordinates *arr = malloc(n * sizeof(coordinates));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    return arr;
}
// Function to merge two subarrays
void merge(coordinates *arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    coordinates *L = (coordinates *)malloc(n1 * sizeof(coordinates));
    coordinates *R = (coordinates *)malloc(n2 * sizeof(coordinates));

    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i].x < R[j].x || (L[i].x == R[j].x && L[i].y <= R[j].y)) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Function to perform insertion sort on a subarray
void insertionSort(coordinates *arr, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        coordinates key = arr[i];
        int j = i - 1;
        while (j >= start && (arr[j].x > key.x || (arr[j].x == key.x && arr[j].y > key.y))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform merge sort with a threshold for insertion sort
void mergeSort(coordinates *arr, int start, int end, int t) {
    if (start < end) {
        if ((end - start + 1) <= t) {
            insertionSort(arr, start, end);
        } else {
            int mid = start + (end - start) / 2; // avoiding out of bounds
            mergeSort(arr, start, mid, t);
            mergeSort(arr, mid + 1, end, t);
            merge(arr, start, mid, end);
        }
    }
}

// Wrapper function for merge sort
void wrapperSort(coordinates *arr, int n, int t) {
    mergeSort(arr, 0, n - 1, t);
}



// Function to perform binary search
int binarySearch(coordinates *arr, int n, coordinates target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].x == target.x && arr[mid].y == target.y) {
            return mid;
        } else if (arr[mid].x < target.x || (arr[mid].x == target.x && arr[mid].y < target.y)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int x, y, n, s, t;
    scanf("%d %d %d %d %d", &x, &y, &n, &s, &t);

    coordinates* p1 = readData(n);

    wrapperSort(p1, n, t);

    // Print sorted coordinates
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", p1[i].x, p1[i].y);
    }

    // Read query points
    coordinates queries[s];
    for (int i = 0; i < s; i++) {
        scanf("%d %d", &queries[i].x, &queries[i].y);
    }

    // Perform binary search for each query point
    for (int i = 0; i < s; i++) {
        int result = binarySearch(p1, n, queries[i]);
        if (result != -1) {
            printf("%d %d garage found at position %d in the order\n", queries[i].x, queries[i].y, result + 1);
        } else {
            printf("%d %d no garage found\n", queries[i].x, queries[i].y);
        }
    }

    free(p1);
    return 0;
}