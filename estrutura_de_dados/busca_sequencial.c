#include <stdio.h>
#include <string.h>
#include <ctype.h>
// este program mostra como realizar
// uma busca linear em um vertor de estruturas
// completar em casa

typedef struct{
    char codigo[3];
    char extenso[40];
    int populacao;
    float rpc; //renda per capita
} Estado;

Estado e[] = {
    {"AC", "ACRE", 56, 10.00},
    {"AL", "ALAGOAS", 57, 11.00},
    {"MT", "MATO GROSSO", 58, 12.00},
    {"SP", "SAO PAULO", 59, 13.00},
    {"MG", "MINAS GERAIS", 60, 14.00},
    {"TO", "TOCATINS", 61, 15.00}
};

void mostraEstado( Estado pe){
    printf("\n     %s | Pop = %d habitantes | RPC= R$ %.2f\n\n", pe.codigo, pe.extenso, pe.populacao, pe.rpc);
}

// retorna a posicao do vetor ou -1 se não encontrar
int buscaEstado(char sp[3]){	//Sigla procurada = sp
    int pos = 0;	//posicao no vetor
    int retorno, i = 0;
	int qtdEstado =  sizeof(e) / sizeof(Estado);
	
	for (i = 0; sp[i]; i++) { //Converte as letras em maiuscula
        sp[i] = toupper(sp[i]);
    }
	
	while(pos < qtdEstado && strcmp(sp, e[pos].codigo))
		pos++;
	if(pos >= qtdEstado)
		retorno = -1;
	else
		retorno = pos;
	return retorno;
}

void main(){
    char desejado[3];
    printf("Informe a sigla do estado desejado: ");
    scanf("%s", desejado);
    int posicao = buscaEstado(desejado);
    if(posicao == -1)
        printf("\nSigla nao encontrada\n");
    else
        mostraEstado(e[posicao]);
}
