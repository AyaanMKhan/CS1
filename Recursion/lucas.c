#include <stdio.h>

int lucas(int n){

    if (n == 1){
        return 1;
    } else if (n == 2){
        return 3;
    } else {
        return lucas(n-1) + lucas(n-2);
    }


}


int main(){

    int n = 9;
    printf("%d ", lucas(n));
    return 0;
}