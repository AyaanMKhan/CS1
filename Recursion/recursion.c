#include <stdio.h>

void rec2(int x){

    if (x == 0){
        return;
    }

    rec2(x-1);
    printf("%d ", x);

}

void rec1(int x){

    if(x == 0){
        return;
    }

    printf("%d ", x);
    rec1(x-1);
    

}


int main(){

    printf("Calling rec1: ");
    rec1(10);    

    printf("\nCalling rec2: ");
    rec2(10);

    return 0;
}