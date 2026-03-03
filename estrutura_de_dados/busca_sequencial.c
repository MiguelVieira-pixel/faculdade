#include <stdio.h>
// este program mostra como realizar
// uma busca linear em um vertor de estruturas
// completar em casa

typedef struct{
    char codigo[2];
    char extenso[40];
    int populacao;
    float rpc; //renda per capita
} Estado;

Estado e[] = {
    {"AC", "ACRE", 56, 10.00},
    {"AL", "ALAGOAS", 57, 11.00},
    {"MT", "MATO GROSSO", 58, 12.00},
    {"SP", "SAO PAULO", 59, 13.00},
    {"SP", "SAO PAULO", 59, 13.00},
    {"TO", "TOCATINS", 60, 14.00}
};

void mostraEstado( Estado e){
    printf("\n     %s Pop=%d habitantes RPC=%d\n\n", e.codigo, e.extenso, e.populacao, e.rpc);
}

// retorna a posição do vetor
int buscaEstado(char siglaProcurada[3]){
    if(buscaEstado() == )
}

void main(){
    char desejado[3];
    int posicao = buscaEstado(desejado);
    printf("Informe a sigla do estado desejado: ");
    scanf("%s", desejado);
    if(posicao == -1)
        printf("\nSigla não encontrada\n");
    else
        mostraEstado(e[posicao]);
}