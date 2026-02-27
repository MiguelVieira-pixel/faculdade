#include <stdio.h>

// passagem por valor
int dobro(int x) {
    return 2*x;
}

void dobrar(int *px){ //px é um ponteiro para inteiro
    *px = 2 * *px;
}

void main() {
    int y = 7;
    printf("\ny antes do dobro(y) = %d \n", y);
    printf("\n O dobro de %d é: %d\n ", y, dobro(y));
    printf("\ny deprois de dobro(y) = %d\n ", y);
    printf("\nAgora vou dobrar o y .......... \n");
    dobrar(&y);
}