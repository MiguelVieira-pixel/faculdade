#include <stdio.h>
#include <string.h>

// ============================================
// STRUCT + BUBBLE SORT + RECURSÃO - INTEGRADO
// ============================================

// Estrutura para armazenar dados de uma Pessoa
typedef struct {
    char nome[30];
    int idade;
    float nota;
} Pessoa;

// ===== FUNÇÕES COM RECURSÃO =====

// Conta recursivamente quantas pessoas têm idade >= minAge
int contaPessoasRecursivo(Pessoa pessoas[], int tamanho, int indice, int minAge) {
    // CASO BASE - chegou ao final do array
    if (indice == tamanho) {
        return 0;
    }
    
    // Se a pessoa atual tem idade >= minAge, conta 1 + o resto
    int contador = (pessoas[indice].idade >= minAge) ? 1 : 0;
    
    // CASO RECURSIVO - chama para o próximo índice
    return contador + contaPessoasRecursivo(pessoas, tamanho, indice + 1, minAge);
}

// Calcula recursivamente a média das notas
float mediaRecursiva(Pessoa pessoas[], int tamanho, int indice) {
    // CASO BASE - chegou ao final
    if (indice == tamanho) {
        return 0;
    }
    
    // Se é o último elemento, retorna apenas a nota dele
    if (indice == tamanho - 1) {
        return pessoas[indice].nota / tamanho;
    }
    
    // CASO RECURSIVO
    return (pessoas[indice].nota / tamanho) + mediaRecursiva(pessoas, tamanho, indice + 1);
}

// ===== FUNÇÕES COM BUBBLE SORT =====

// Ordena pessoas por idade usando Bubble Sort
void bubbleSortIdade(Pessoa pessoas[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (pessoas[j].idade > pessoas[j + 1].idade) {
                // Troca a struct inteira
                Pessoa temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }
}

// Ordena pessoas por nota usando Bubble Sort
void bubbleSortNota(Pessoa pessoas[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int trocou = 0;
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (pessoas[j].nota < pessoas[j + 1].nota) { // Ordem decrescente
                Pessoa temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

// ===== FUNÇÕES AUXILIARES =====

void mostraPessoas(Pessoa pessoas[], int tamanho) {
    printf("%-15s | %-7s | %-6s\n", "Nome", "Idade", "Nota");
    printf("-----------------------------------------\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%-15s | %7d | %6.2f\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].nota);
    }
    printf("\n");
}

int main() {
    // Array de estruturas (Struct)
    Pessoa pessoas[] = {
        {"Alice", 20, 8.5},
        {"Bruno", 19, 7.2},
        {"Carlos", 22, 9.1},
        {"Diana", 18, 8.8},
        {"Eduardo", 21, 6.9}
    };
    int tamanho = sizeof(pessoas) / sizeof(pessoas[0]);
    
    printf("===== DADOS ORIGINAIS =====\n");
    mostraPessoas(pessoas, tamanho);
    
    // ===== USANDO RECURSÃO =====
    printf("===== EXEMPLOS COM RECURSÃO =====\n");
    
    int maiores20 = contaPessoasRecursivo(pessoas, tamanho, 0, 20);
    printf("Pessoas com idade >= 20: %d\n", maiores20);
    
    float media = mediaRecursiva(pessoas, tamanho, 0);
    printf("Média de notas: %.2f\n\n", media);
    
    // ===== USANDO BUBBLE SORT =====
    printf("===== ORDENADO POR IDADE (Bubble Sort) =====\n");
    bubbleSortIdade(pessoas, tamanho);
    mostraPessoas(pessoas, tamanho);
    
    printf("===== ORDENADO POR NOTA (Bubble Sort - Decrescente) =====\n");
    bubbleSortNota(pessoas, tamanho);
    mostraPessoas(pessoas, tamanho);
    
    printf("Pressione ENTER para finalizar...");
    getchar();
    return 0;
}
