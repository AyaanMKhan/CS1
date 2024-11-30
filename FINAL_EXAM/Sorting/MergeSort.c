/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r){

    int lSize = (m-l)+1;
    int rSize = r-m;

    int *left = malloc(sizeof(int)*lSize);
    int *right = malloc(sizeof(int)*rSize);

    for(int i = 0; i < lSize; i++){
        left[i] = arr[l+i];
    }

    for(int i = 0; i < rSize; i++){
        right[i] = arr[m+1+i];
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < lSize && j < rSize){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            k++;
            i++;
        }else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }


    while(i < lSize){
        arr[k] = left[i];
        k++;
        i++;
    }

    while(j < rSize){
        arr[k] = right[j];
        k++;
        j++;
    }


    free(left);
    free(right);

}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){

    if(l < r){
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }


}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = 6;

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}