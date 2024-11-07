#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n){
    int i, j, temp;
    
    for(int i = 0; i < n-1; i++){
        
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                printf("Iteration #%d\n", i+1);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printArray(arr, n);
    }

}


// Driver program to test above functions
int main()
{
    int arr[] = {4, 2, 6, 5, 7, 1, 8, 3};



    int n = 8;
    printf("Before Sorting: ");
    printArray(arr, n);
    printf("\n");

    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
