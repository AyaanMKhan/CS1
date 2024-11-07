#include <stdio.h>




void swap(int *xp, int *yp){

    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void printArray(int arr[], int size){

    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

}

void bubbleSort(int arr[], int n){


    for(int i = 0;i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

}








int main(){

    int arr[] = {2, 8, 3, 6, 5, 1, 4, 7};
    int n = 8;

    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: \n");

    printArray(arr, n);

    return 0;

}