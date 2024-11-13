#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashNode;

HashNode **arr;
HashNode *dummy;
const int capacity = 10;
int size = 0;


// Hash Table

void insert(int key, int V){

    HashNode *temp = (HashNode*)malloc(sizeof(HashNode));
    temp->key = key;
    temp->value = V;

    int hashIndex = key % capacity;

    // Find the next free space
    while(arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1){
        hashIndex++;
        hashIndex %= capacity;
    }

    // If the key is inserted or updated then increase the size
    if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1){
        size++;
    }

    arr[hashIndex] = temp;

}


int delete(int key){

    int hashIndex = key % capacity;

    while(arr[hashIndex] != NULL){
        if(arr[hashIndex]->key == key){

            arr[hashIndex] = dummy;

            size--;

            return 1;
        }

        hashIndex++;
        hashIndex %= capacity;
    }

    return 0;


}



int find(int key){

    int hashIndex = key % capacity;
    int counter = 0;

    while(arr[hashIndex] != NULL){

        if(counter > capacity){
            break;
        }

        counter++;

        if(arr[hashIndex]->key == key){
            return arr[hashIndex]->value;
        }

        hashIndex++;
        hashIndex %= capacity;
    }

    return -1;


}


int main() {

    arr = (HashNode**)malloc(sizeof(HashNode*) * capacity);

    for(int i = 0; i < capacity; i++){
        arr[i] = NULL;
    }

    dummy = (HashNode*)malloc(sizeof(HashNode));

}