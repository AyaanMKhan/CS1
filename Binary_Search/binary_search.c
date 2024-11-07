#include <stdio.h>


int binarySearchIter(int list[], int item, int len){
    printf("Iterative function not implemented yet\n");
    return -1;
}
int binarySearchRec(int list[], int left, int right, int item){
    printf("Recursive function not implemented yet\n");
    return -1;
}
void displayArray(int a[], int size){

    printf("Array:\n");
    for(int i=0; i<size; i++)
    printf("%d ", a[i]);
    printf("\n");

}

int binarySearch(int list[], int item, int len){

    int l = 0, r = len - 1;
    int mid;
    while(l <= r){

        // Check if item is present at mid
        mid = (l+r) / 2;

        
        // If item is greater, ignore the left half
        if(list[mid] < item){
            l = mid + 1;
        } else {
            // If item is smaller, ignore the right half
            r = mid - 1;
        }

    }

    // if we reach here then element was not present
    return -1;

}

int main(void){

    int arr[] = { 2, 3, 4, 10, 15, 40, 45 };
    displayArray(arr, 7);
    int keysToSearch[] = {4, 12, 70, 1, 3, 45, 40};
    for(int i=0; i<7; i++){
        printf("Searching for %d\n", keysToSearch[i]);
        printf("Result from iterative Binary Search\n");

        int result = binarySearchIter(arr, keysToSearch[i], 7);
        (result == -1) ? printf("Not found\n") : printf("Found\n");
        printf("Result from recursive Binary Search\n");

        result = binarySearchRec(arr, 0, 6, keysToSearch[i]);
        (result == -1) ? printf("Not found\n") : printf("Found\n");
        printf("\n====\n");
    }

    int res = binarySearch(arr, 10, 7);
    printf("%d ", res);

    return 0;
}