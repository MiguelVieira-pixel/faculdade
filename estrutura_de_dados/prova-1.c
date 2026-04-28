#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    char cpf[12];
    int contribuicao;
} Contribuinte;

Contribuinte c[8] = {
    {"João Silva", "12345678901", 500},
    {"Maria Oliveira", "98765432100", 300},
    {"Carlos Pereira", "19283746500", 700},
    {"Ana Souza", "56473829100", 400},
    {"Pedro Santos", "10293847500", 600},
    {"Lucia Costa", "01928374650", 200},
    {"Rafael Lima", "56473829101", 800},
    {"Largatixq", "01928374651", 100}
};

void bubleSort(Contribuinte arr[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - 1 - i; j++) {
            if(strcmp(arr[j].cpf, arr[j + 1].cpf) > 0) {
                Contribuinte temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int tamanho = sizeof(c) / sizeof(c[0]);
    bubleSort(c, tamanho);
    printf("Contribuintes ordenados por CPF:\n");
    printf("CPF        Nome         Contribuicao\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%s   %s         %d\n", c[i].cpf, c[i].nome, c[i].contribuicao);
    }
    system("pause");
    return 0;
}