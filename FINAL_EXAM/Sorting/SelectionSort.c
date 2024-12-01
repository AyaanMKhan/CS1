#include <stdio.h>




void printArray(int arr[], int size){

    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

}


void selectionSort(int arr[], int n){

    int i, j, min_idx, temp;
    // Average, Best, Worst: O(n^2)

    for(i = 0; i < n-1; i++){
        min_idx = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }


}





int main(){

    int arr[8] = {6, 2, 8, 1, 3, 7, 5, 4};

    int n = 8;

    printArray(arr, n);
    printf("\n");

    selectionSort(arr, n);
    printArray(arr, n);
    

}