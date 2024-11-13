#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int isHeap_recursive(int arr[], int i, int n)
{
    //if statement for checking if it is out of bounds
    if(n <= 0 || i > (n - 2) / 2){
        return 1;
    }
    //if statement for left child
    if(arr[2 * i + 1] < arr[i]){
        return 0;
    }
    //if statements for right child
    if(2 * i + 2 < n){
        if(arr[2 * i + 2] < arr[i]){
            return 0;
        }
    }

    //recursive call
    return isHeap_recursive(arr, 2 * i + 1, n) && isHeap_recursive(arr, 2 * i + 2, n);
}

int isHeap_iter(int arr[], int n){

    for(int i = 0; i <= (n-2)/2; ++i){
        //left child
        if(arr[2 * i + 1] < arr[i]){
            return 0;
        }
        //check the right child
        if(2 * i + 2 < n && arr[2 * i + 2] < arr[i]){
            return 0;
        }
    }

    return 1;
}

int main(){
    int n;
    int * arr;

    printf("How many entries? ");
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);

    printf("Enter %d entries: ", n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    isHeap_recursive(arr, 0, n) ? printf("Recursive says Yes!\n"): printf("Recursive says No!\n");

    isHeap_iter(arr, n) ? printf("Iterative says Yes!\n"): printf("Iterative says No!\n");

    free(arr);

    return 0;
}