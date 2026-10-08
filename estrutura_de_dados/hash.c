#include <stdio.h>
#include <malloc.h>
#define TABELA 10

typedef struct No{
    int chave;
    int valor;
    struct No* proximo; 
} No;


No* tabelaHash[TABELA] = {NULL}; 

// CÓDIGO DE INSERÇÃO
void insert(int chave, int valor) {
    int index = chave % TABELA; 
    
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->valor = valor;
    
    novoNo->proximo = tabelaHash[index]; 
    tabelaHash[index] = novoNo;
}

//  CÓDIGO DE BUSCA
int search(int chave) {
    int index = chave % TABELA;
    
    // Inicia a busca a partir do primeiro nó no índice calculado
    No* atual = tabelaHash[index];
    
    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual->valor; 
        }
        atual = atual->proximo;
    }
    return -1; 
}