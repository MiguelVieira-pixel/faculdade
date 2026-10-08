#include <stdio.h>
#include <stdlib.h> // A biblioteca padrão recomendada para o malloc()

#define TABELA 10

// 1. Estrutura do nó
typedef struct No {
    int chave;
    int valor;
    struct No* proximo;
} No;

// Inicializando a tabela hash globalmente
No* tabelaHash[TABELA] = {NULL};

// 2. Função de Inserção (A que está no seu slide)
void insert(int chave, int valor) {
    int index = chave % TABELA;
    
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->valor = valor;
    
    // O novo nó aponta para o que já estava na cabeça da lista
    novoNo->proximo = tabelaHash[index];
    // O índice da tabela passa a apontar para o novo nó
    tabelaHash[index] = novoNo;
}

// 3. Função de Busca (Para o seu próximo slide)
int search(int chave) {
    int index = chave % TABELA;
    No* atual = tabelaHash[index]; // Começa a procurar pelo início da lista
    
    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual->valor; // Encontrou e devolve o valor
        }
        atual = atual->proximo;  // Pula para o próximo nó da lista ligada
    }
    return -1; // Não encontrou
}

// Função Principal apenas para testar a lógica
int main() {
    printf("--- Testando a Tabela Hash com Encadeamento ---\n\n");
    
    // Inserindo chaves que vão colidir propositadamente
    // Ambas resultarão no índice 2 (pois 42 % 10 = 2 e 12 % 10 = 2)
    insert(42, 100); 
    insert(12, 200); 
    
    // Inserindo numa posição sem colisão
    insert(5, 300);  
    
    // Testando as buscas
    printf("Valor da chave 42: %d\n", search(42));
    printf("Valor da chave 12 (que colidiu na mesma lista): %d\n", search(12));
    printf("Valor da chave 5: %d\n", search(5));
    printf("Buscando uma chave inexistente (99): %d\n", search(99));
    
    return 0;
}
