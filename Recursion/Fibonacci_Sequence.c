#include <stdio.h>

int fib(int n){

    if(n <= 1){
        return n;
    } else {
        return fib(n-1) + fib(n-2);
    }


}


int main(){

    int x = fib(5);
    printf("%d ", x);

    return 0;
}