#include <stdio.h>

// ============================================
// EXERCÍCIOS PRÁTICOS PARA A PROVA
// ============================================

// EXERCÍCIO 1: Struct com Recursão
// Cria uma struct e usa recursão para buscar o maior valor

typedef struct {
    char produto[20];
    float preco;
} Produto;

// Função recursiva para encontrar o maior preço
float maiorPrecoRecursivo(Produto produtos[], int tamanho, int indice, float maior) {
    // CASO BASE
    if (indice == tamanho) {
        return maior;
    }
    
    // Atualiza maior se encontrou algo maior
    if (produtos[indice].preco > maior) {
        maior = produtos[indice].preco;
    }
    
    // CASO RECURSIVO
    return maiorPrecoRecursivo(produtos, tamanho, indice + 1, maior);
}

// EXERCÍCIO 2: Bubble Sort com Struct
// Ordena produtos por preço

void bubbleSortProdutos(Produto produtos[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (produtos[j].preco > produtos[j + 1].preco) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

// EXERCÍCIO 3: Recursão com array
// Conta recursivamente quantos números são pares

int contaParesRecursivo(int arr[], int tamanho, int indice) {
    // CASO BASE
    if (indice == tamanho) {
        return 0;
    }
    
    // Se é par, conta 1, senão 0
    int ehPar = (arr[indice] % 2 == 0) ? 1 : 0;
    
    // CASO RECURSIVO
    return ehPar + contaParesRecursivo(arr, tamanho, indice + 1);
}

// EXERCÍCIO 4: Bubble Sort - Decrescente
// Ordena array em ordem DECRESCENTE

void bubbleSortDecrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) { // Inverte a comparação!
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// EXERCÍCIO 5: Recursão - Potência personalizada
// Calcula a^b de forma recursiva

int potencia(int base, int exp) {
    // CASO BASE
    if (exp == 0) return 1;
    
    // CASO RECURSIVO
    return base * potencia(base, exp - 1);
}

// EXERCÍCIO 6: Struct + Recursão
// Encontra o aluno com maior nota recursivamente

typedef struct {
    char nome[20];
    float nota;
} Aluno;

int encontraMelhorAlunoIndice(Aluno alunos[], int tamanho, int indice, 
                               int melhorIndice, float melhorNota) {
    // CASO BASE
    if (indice == tamanho) {
        return melhorIndice;
    }
    
    // Se achou uma nota melhor, atualiza
    if (alunos[indice].nota > melhorNota) {
        melhorNota = alunos[indice].nota;
        melhorIndice = indice;
    }
    
    // CASO RECURSIVO
    return encontraMelhorAlunoIndice(alunos, tamanho, indice + 1, 
                                      melhorIndice, melhorNota);
}

// Funções auxiliares
void mostraArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mostraProdutos(Produto produtos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("  %s: R$ %.2f\n", produtos[i].produto, produtos[i].preco);
    }
}

void mostraAlunos(Aluno alunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("  %s: %.1f\n", alunos[i].nome, alunos[i].nota);
    }
}

int main() {
    printf("===== EXERCÍCIO 1: MAIOR PREÇO (RECURSÃO) =====\n");
    Produto produtos[] = {
        {"Notebook", 2500.00},
        {"Mouse", 50.00},
        {"Teclado", 150.00},
        {"Monitor", 800.00},
        {"Webcam", 200.00}
    };
    int qtdProd = sizeof(produtos) / sizeof(produtos[0]);
    printf("Produtos:\n");
    mostraProdutos(produtos, qtdProd);
    float maior = maiorPrecoRecursivo(produtos, qtdProd, 0, 0);
    printf("Maior preço: R$ %.2f\n\n", maior);
    
    printf("===== EXERCÍCIO 2: ORDENAR PRODUTOS (BUBBLE SORT) =====\n");
    bubbleSortProdutos(produtos, qtdProd);
    printf("Produtos ordenados por preço:\n");
    mostraProdutos(produtos, qtdProd);
    printf("\n");
    
    printf("===== EXERCÍCIO 3: CONTAR PARES (RECURSÃO) =====\n");
    int numeros[] = {2, 5, 8, 3, 10, 7, 4, 6};
    int qtdNum = sizeof(numeros) / sizeof(numeros[0]);
    printf("Array: ");
    mostraArray(numeros, qtdNum);
    int pares = contaParesRecursivo(numeros, qtdNum, 0);
    printf("Total de números pares: %d\n\n", pares);
    
    printf("===== EXERCÍCIO 4: ORDENAR DECRESCENTE (BUBBLE SORT) =====\n");
    int arr[] = {45, 12, 89, 23, 56, 34, 78, 11};
    int qtdArr = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: ");
    mostraArray(arr, qtdArr);
    bubbleSortDecrescente(arr, qtdArr);
    printf("Array decrescente: ");
    mostraArray(arr, qtdArr);
    printf("\n");
    
    printf("===== EXERCÍCIO 5: POTÊNCIA (RECURSÃO) =====\n");
    printf("2^5 = %d\n", potencia(2, 5));
    printf("3^4 = %d\n", potencia(3, 4));
    printf("5^3 = %d\n\n", potencia(5, 3));
    
    printf("===== EXERCÍCIO 6: MELHOR ALUNO (STRUCT + RECURSÃO) =====\n");
    Aluno alunos[] = {
        {"Alice", 8.5},
        {"Bruno", 7.2},
        {"Carlos", 9.1},
        {"Diana", 6.8},
        {"Eduardo", 8.9}
    };
    int qtdAlunos = sizeof(alunos) / sizeof(alunos[0]);
    printf("Alunos:\n");
    mostraAlunos(alunos, qtdAlunos);
    int melhorIdx = encontraMelhorAlunoIndice(alunos, qtdAlunos, 0, 0, 0);
    printf("Melhor aluno: %s com nota %.1f\n\n", alunos[melhorIdx].nome, alunos[melhorIdx].nota);
    
    printf("Pressione ENTER para finalizar...");
    getchar();
    return 0;
}
