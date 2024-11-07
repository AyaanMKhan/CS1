// C program for insertion sort
#include <math.h>
#include <stdio.h>

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, j, item;

    for(int i = 1; i < n; i++){
        printf("Iteration #%d\n", i);
        item = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > item){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = item;
        printArray(arr, n);
    }
}



/* Driver program to test insertion sort */
int main()
{
    int arr[] = {2, 8, 3, 6, 5, 1, 4, 7};
    int n = 8; //size of the array
    
    insertionSort(arr, n);
    printf("\nAfter sorting: ");
    printArray(arr, n);

    return 0;
}
