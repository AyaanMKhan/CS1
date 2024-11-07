#include <stdio.h>

#define MAX 5
#define EMPTY -999


typedef struct Queue {

    int queue_array[MAX];
    int *front;
    int *rear;

}Queue;

void initQ(Queue *q){

    q->front = 0;
    q->rear = 0;

}


void enQueue(Queue *q, int item){

    if(q->rear < MAX){
        q->queue_array[q->rear] = item;
        q->rear++;
    } else {
        printf("Queue is full\n");
    }

}


void deQueue(Queue *q){

    if(q->front == q->rear){
        printf("Queue is empty\n");

        return EMPTY;
    }

    int retval = q->queue_array[q->front];
    q->front++;
    
    return retval;

}



int main(){

    int choice;
    int data;
    

    Queue myQ;

    initQ(&myQ);

}