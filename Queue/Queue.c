#include <stdio.h>
#include <stdlib.h>
#define EMPTY -1

typedef struct node{

    int data;
    struct node* next;

}node;

typedef struct queue {
    struct node* front;
    struct node* back;

}queue;


int enqueue(struct queue* qPtr, int x){

    node* temp = malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;


    if(qPtr->back == NULL){
        qPtr->front = temp;
        qPtr->back = temp;

        return 1; 
    } else {
        qPtr->back->next = temp;
        qPtr->back = temp;

        return 1;
    }
    return 0;
}


int dequeue(struct queue* qPtr, int x){

    struct node* temp = qPtr->front;
    qPtr->front = qPtr->front->next;
    int retval = temp->data;
    free(temp);

    if(empty(qPtr)){
        return EMPTY;
    }

    return retval;

}





int main(){


    return 0;
}