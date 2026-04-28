#include <stdio.h>

// ============================================
// RECURSÃO - Funções Recursivas
// ============================================

// 1. FATORIAL - Exemplo clássico de recursão
// Fatorial de n = n * (n-1)!
// Base: 0! = 1, 1! = 1
int fatorial(int n) {
    printf("Chamada: fatorial(%d)\n", n);
    
    // CASO BASE - MUITO IMPORTANTE!
    if (n <= 1) {
        printf("  Retorna 1 (caso base)\n");
        return 1;
    }
    
    // CASO RECURSIVO
    int resultado = n * fatorial(n - 1);
    printf("  fatorial(%d) = %d * fatorial(%d) = %d\n", n, n, n - 1, resultado);
    return resultado;
}

// 2. FIBONACCI - Sequência: 1, 1, 2, 3, 5, 8, 13...
// fib(n) = fib(n-1) + fib(n-2)
// Base: fib(1) = 1, fib(2) = 1
int fibonacci(int n) {
    printf("fib(%d) ", n);
    
    // CASO BASE
    if (n <= 2) {
        return 1;
    }
    
    // CASO RECURSIVO
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. SOMA DE NÚMEROS - 1+2+3+...+n
int soma(int n) {
    printf("soma(%d) ", n);
    
    // CASO BASE
    if (n == 0) {
        return 0;
    }
    
    // CASO RECURSIVO
    return n + soma(n - 1);
}

// 4. POTÊNCIA - calcular a^b recursivamente
int potencia(int base, int expoente) {
    printf("potencia(%d, %d) ", base, expoente);
    
    // CASO BASE
    if (expoente == 0) {
        return 1;
    }
    
    // CASO RECURSIVO
    return base * potencia(base, expoente - 1);
}

// 5. BUSCA BINÁRIA - busca em array ordenado (divide e conquista)
int buscaBinaria(int arr[], int esquerda, int direita, int alvo) {
    printf("Procurando %d entre índices [%d, %d]\n", alvo, esquerda, direita);
    
    // CASO BASE - não encontrado
    if (esquerda > direita) {
        printf("  Não encontrado!\n");
        return -1;
    }
    
    int meio = (esquerda + direita) / 2;
    printf("  Elemento do meio: arr[%d] = %d\n", meio, arr[meio]);
    
    // Encontrou!
    if (arr[meio] == alvo) {
        printf("  Encontrado em índice %d!\n", meio);
        return meio;
    }
    
    // Se alvo é menor, busca na metade esquerda
    if (alvo < arr[meio]) {
        return buscaBinaria(arr, esquerda, meio - 1, alvo);
    }
    
    // Caso contrário, busca na metade direita
    return buscaBinaria(arr, meio + 1, direita, alvo);
}

// 6. CONTAGEM REGRESSIVA - exemplo simples
void contagemRegressiva(int n) {
    printf("%d ", n);
    
    // CASO BASE
    if (n == 0) {
        printf("\nFim!\n");
        return;
    }
    
    // CASO RECURSIVO
    contagemRegressiva(n - 1);
}

int main() {
    printf("===== 1. FATORIAL =====\n");
    printf("fatorial(5) = %d\n\n", fatorial(5));
    
    printf("===== 2. FIBONACCI =====\n");
    printf("fib(6) = %d\n\n", fibonacci(6));
    
    printf("===== 3. SOMA =====\n");
    printf("soma(5) = %d\n\n", soma(5));
    
    printf("===== 4. POTÊNCIA =====\n");
    printf("2^5 = %d\n\n", potencia(2, 5));
    
    printf("===== 5. BUSCA BINÁRIA =====\n");
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    printf("Array: ");
    for (int i = 0; i < tamanho; i++) printf("%d ", arr[i]);
    printf("\n");
    int resultado = buscaBinaria(arr, 0, tamanho - 1, 23);
    printf("Resultado: índice %d\n\n", resultado);
    
    printf("===== 6. CONTAGEM REGRESSIVA =====\n");
    contagemRegressiva(5);
    
    printf("\nPressione ENTER para finalizar...");
    getchar();
    return 0;
}
