#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do Nó
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Função para inserir um elemento no início da lista
void inserirInicio(No** cabeca, int novo_valor) {
    // Alocação dinâmica de memória para o novo nó
    No* novo_no = (No*)malloc(sizeof(No));
    
    // Atribuição do valor e do ponteiro
    novo_no->valor = novo_valor;
    novo_no->proximo = *cabeca;
    
    // Atualiza a cabeça da lista para apontar para o novo nó
    *cabeca = novo_no;
}

// Função para percorrer e imprimir a lista
void imprimirLista(No* no) {
    while (no != NULL) {
        printf("%d -> ", no->valor);
        no = no->proximo;
    }
    printf("NULL\n");
}

int main() {
    No* cabeca = NULL; // Inicializa a lista vazia

    inserirInicio(&cabeca, 10);
    inserirInicio(&cabeca, 20);
    inserirInicio(&cabeca, 30);

    // O resultado será: 30 -> 20 -> 10 -> NULL
    imprimirLista(cabeca);

    return 0;
}
