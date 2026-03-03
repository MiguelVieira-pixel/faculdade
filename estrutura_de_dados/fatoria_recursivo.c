#include <stdio.h>

long fatorial(long x){
    if(x<1)
        return 1;
    else
        return x * fatorial(x-1);
}

void main(){
    long num;
    printf("\n sizeof(int) = %ld\n", sizeof(int));
    printf("\n Informe um número natural > 0: ");
    scanf("ld", &num);
    printf("\n\n O fatorial(%d) é %d\n", num, fatorial(num));
}