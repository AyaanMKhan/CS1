#include <stdio.h>
#include <stdlib.h>

typedef struct bigInt{

    int *digits;
    int size;

}bigInt;

int main(){


    bigInt *p1 = malloc(sizeof(bigInt));

    p1->digits = malloc(sizeof(int) * 10); 
    
    p1->digits[numDigits -1];
    
    
    

    free(p1->digits);
    free(p1);

    return 0;
}


