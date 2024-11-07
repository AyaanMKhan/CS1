#include <stdio.h>


/*int Power(int base, int exponent){

    long result = 1;
    while(exponent != 0){
        result *= base;
        --exponent;
    }
    return result;


}*/

int Power(int base, int exponent){

    if(exponent == 0){
        return 1;
    } else {
        return (base*Power(base, exponent-1));
    }

}

int main(){

    int x = Power(5,2);
    printf("%d ", x);

    return 0;
}