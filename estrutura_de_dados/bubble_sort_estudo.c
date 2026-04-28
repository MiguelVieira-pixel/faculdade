#include <stdio.h>

// ============================================
// BUBBLE SORT - Algoritmo de Ordenação
// ============================================

void mostraArray(int arr[], int tamanho) {
    printf("Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort Simples
void bubbleSort(int arr[], int tamanho) {
    // Passa externa - controla quantas vezes vai passar pelo array
    for (int i = 0; i < tamanho - 1; i++) {
        // Passa interna - compara elementos adjacentes
        for (int j = 0; j < tamanho - 1 - i; j++) {
            // Se um elemento é maior que o próximo, troca
            if (arr[j] > arr[j + 1]) {
                // Troca
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Passo %d: ", i + 1);
        mostraArray(arr, tamanho);
    }
}

// Bubble Sort com Flag (otimizado)
void bubbleSortOtimizado(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int trocou = 0; // Flag para detectar se houve troca
        
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        
        // Se não trocou nada, array já está ordenado
        if (!trocou) {
            printf("Array já ordenado no passo %d\n", i + 1);
            break;
        }
        printf("Passo %d: ", i + 1);
        mostraArray(arr, tamanho);
    }
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("===== BUBBLE SORT SIMPLES =====\n");
    printf("Array original: ");
    mostraArray(arr1, tamanho);
    printf("\n");
    bubbleSort(arr1, tamanho);
    printf("Final ordenado: ");
    mostraArray(arr1, tamanho);
    
    printf("\n===== BUBBLE SORT OTIMIZADO =====\n");
    int arr2[] = {5, 2, 8, 1, 9, 3};
    tamanho = sizeof(arr2) / sizeof(arr2[0]);
    printf("Array original: ");
    mostraArray(arr2, tamanho);
    printf("\n");
    bubbleSortOtimizado(arr2, tamanho);
    printf("Final ordenado: ");
    mostraArray(arr2, tamanho);
    
    printf("\nPressione ENTER para finalizar...");
    getchar();
    return 0;
}
