#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int *heaparray;
    int size;
    int capacity;
}heap;

heap *init(){

    heap *temp;
    temp = malloc(sizeof(heap));
    temp->size = 0;
    temp->capacity = 10;
    temp->heaparray = malloc(sizeof(int) * temp->capacity);

    return temp;

}

heap *insert(heap *h, int data){

    if(h->size == h->capacity){
        
        h->heaparray = realloc(h->heaparray, sizeof(int) * (2*h->capacity+1));

        h->capacity *= 2;
    }

    h->heaparray[h->size] = data;
    h->size++;

    int i = h->size - 1;
    while(i > 0 && h->heaparray[i] > h->heaparray[(i - 1) / 2]){
        int temp = h->heaparray[i];
        h->heaparray[i] = h->heaparray[(i - 1) / 2];
        h->heaparray[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }

    return h;

}



int main(){




    return 0;
}