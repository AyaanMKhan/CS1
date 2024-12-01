#include <stdio.h>


/* Function to print an array */
void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



void insertionSort(int arr[], int n){

    int i, j, item;
    // Average: O(n^2), Best: O(n), Worst: O(n^2)


    for(i = 1; i < n; i++){
        item = arr[i];
        for(j = i-1; j >= 0; j--){
            if(arr[j] > item){
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = item;
    }

}






// Driver program to test above functions
int main(){


    int arr[] = {2, 8, 3, 6, 5, 1, 4, 7};
    int n = 8;

    

    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
