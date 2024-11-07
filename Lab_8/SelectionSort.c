#include <stdio.h>

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void selectionSort(int arr[], int n)
{
	int i, j, min_idx, temp;
	// One by one move boundary of unsorted subarray
	for(int i = 0; i < n-1; i++){
		printf("Iteration %d\n", i+1);
		min_idx = i;
		for(int j = i+1; j < n; j++){
			if(arr[j] < arr[min_idx]){
				min_idx = j;
			}
		}
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
		printArray(arr, n);
	}
}


int main()
{
    int arr[] = {6, 2, 8, 1, 3, 7, 5, 4};
    int n = 8; //size of the array

    

    selectionSort(arr, n);

    return 0;
}
