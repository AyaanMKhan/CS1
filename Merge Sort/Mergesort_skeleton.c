/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>


/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r){

    int lSize = (m - l) + 1;
    int rSize = r - m;

    int *leftArray = malloc(sizeof(int) * lSize);
    int *rightArray = malloc(sizeof(int) * sizeof(rSize));

    for(int i = 0; i < lSize; i++){
        leftArray[i] = arr[l + i];
    }

    for(int i = 0; i < rSize; i++){
        rightArray[i] = arr[m+i+1];
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < lSize && j < rSize){

        if(leftArray[i] < rightArray[j]){
            arr[k] = leftArray[i];
            k++;
            i++;
        } else {
            arr[k] = rightArray[j];
            k++;
            j++;
        }
    }

    while(i < lSize){

        arr[k] = leftArray[i];
        k++;
        i++;

    }

    while(j < rSize){

        arr[k] = rightArray[j];
        k++;
        j++;

    }
    printArray(arr, 6);

    free(rightArray);
    free(leftArray); 
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){

    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);

    }

}



/* Driver program to test above functions */
int main()
{
    int arr[] = {3, 6, 8, 1, 7, 4 , 5, 2};
    int arr_size = 8;

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
