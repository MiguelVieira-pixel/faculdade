#include <stdio.h>
#include <stdlib.h>

//duplamente ligada
typedef struct No{
	int valor;
	struct No* prox;
	struct No* ant; //novo ponteiro apontando para o nó de trás
}No;

typedef struct Lista{
	No* inicio;
	No* fim;
}Lista;

//função adaptada para inserir no inicio da lista duplamente ligada
void inserirFinal(Lista* lis, int novo_valor){
	No* noNovo = (No*)malloc(sizeof(No));
	
	noNovo->valor = novo_valor;
	noNovo->prox = NULL; //como é o ultimo o proximo é o null
	noNovo->ant = lis->fim // o anterior ao novo nó é o antigo ultimo nó
	if(lis* inicio == NULL)
		lis->inicio = noNovo; // se a lista estava vazia o novo nó é o inicio e o fim
	else
		lis->fim->prox = noNovo; // se já tinha elementos o antigo passa a apontar para o novo
	lis->fim = noNovo;	//atualiza o ponteiro de fim da lista
}
