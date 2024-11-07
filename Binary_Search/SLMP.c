#include <stdio.h>

// Binary search function
int binarySearch(int arr[], int target, int size) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Target not found
}

void slmp_linear(int arr[], int arr2[], int n, int m){

    int i = 0;
    int j = 0;

    while(i < n && j < m){

        if(arr[i] < arr2[j]){
            i++;
        } else if (arr2[j] < arr[i]){
            j++;
        } else {
            printf("%d ", arr[i]);
            i++;
            j++;
        }


    }


}

int main() {
    int arr[] = { 2, 3, 4, 10, 15, 40, 45 };
    int arr2[] = { 1, 3, 6, 11, 15, 47, 50 };


   
    for (int i = 0; i < 7; i++) {
        int result = binarySearch(arr2, arr[i], 7);
        if (result != -1) {
            printf("%d ", arr[i]);
        }
    }

    



    return 0;
}