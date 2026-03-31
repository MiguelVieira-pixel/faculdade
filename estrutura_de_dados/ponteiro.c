#include <stdio.h>
#include <malloc.h>

typedef struct{
    int codigo;
    char nome[35];
} Pessoa;

void main(){
    Pessoa joao = {123, "João Pessoa"};
    Pessoa * pp = (Pessoa *) malloc(sizeof(Pessoa));
    // *pp = joao;

    Pessoa vPessoa[] = {
        {123, "João Pessoa"},
        {456, "Maria Silva"},
        {789, "Carlos Oliveira"}
    };
    pp = vPessoa+2;

    printf("\n%s \n", pp->nome);
}