#include <stdio.h>

#define SIZE 6
#define EMPTY -1
#define FULL 0

typedef struct  stack{
    int items[SIZE];
    int top;
}stack;

void initialize(stack* stackPtr);
int full(stack* stackPtr);
int push(stack* stackPtr, int value);
int empty(stack* stackPtr);

int empty(stack *stackPtr){

    if(stackPtr->top < 0){
        return 1;
    } else {
        return 0;
    }

}

void initialize(stack* stackPtr){

    stackPtr->top = -1;

}

int full(stack* stackPtr){
    
    if(stackPtr->top >= SIZE-1){
        return 1;
    } else {
        return 0;
    }

}


int push(stack* stackPtr, int value){

    if(full(stackPtr)){
        return FULL;
    }
    stackPtr->items[stackPtr->top+1] = value;
    stackPtr->top += 1;
}


int pop(stack* stackPtr){

    if(!empty(stackPtr)){
        int save = stackPtr->items[stackPtr->top];

        stackPtr->top -= 1;

        return save;
    }

    return EMPTY;
}   


int main(){

    int i;

    stack st1;

    initialize(&st1);

    stack st2;

    initialize(&st2);


    stack st[10];

    for(int i = 0; i < 10; i++){
        initialize(&st[i]);
    }
    
    return 0;
}