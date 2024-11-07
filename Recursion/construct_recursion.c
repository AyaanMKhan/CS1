#include <stdio.h>

int Triangle_Number(int n){

    int index, sum = 0;
    for(index = 1; index <= n; index++){
        sum += index;
    }

    return sum;

}

int main(){

    int x = Triangle_Number(5);
    printf("%d ", x);

    return 0;
}