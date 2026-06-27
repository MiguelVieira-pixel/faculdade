#include <stdio.h>

typedef struct {
    char cpf[30];
    char nome[40];
    struct Arvore * esq;
    struct Arvore * dir;
} Arvore;

