#include <stdio.h>
#define SIZE 3


void print(int *A, int n){

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
        printf("\n");
    }
}

void printperms(int *perm, int* used, int k, int n){

    if(k == n){
        print(perm, n);
        return;
    }
    int i;
    for(int i = 0; i < n; i++){
        if(!used[i]){
            used[i] = 1;
            perm[k] = i;
            printperms(perm, used, k+1, n);
            used[i] = 0;
        }
    }

}

int main(){

    int perm[SIZE] = {0};
    int used[SIZE] = {0};

    printperms(perm, used, 0, SIZE);

}