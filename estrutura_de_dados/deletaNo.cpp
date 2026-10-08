#include <stdio.h>
#include <stdlib.h>

#define fim 8
#define INSERIR 1
#define PESQUISAR 2
//outras define para fazer

typedef struct{
	char cpf[30];
	char nome[35];
	int altura;
	int nivel;
	struct Pessoa *esq;
	struct Pessoa *dir;
	struct Pessoa *pai;
} Pessoa;

typedef Pessoa * Arvore;

//typedef struct No{
//	struct No *esq;
//	struct No *dir;
//} No;

void initArvore(Arvore *a){
	
}

void inserir(){
	printf("\nEstou na inserir ( a fazer ) \n");
}

void pesquisar(){
	printf("\nEstou pesquisando ( a fazer ) \n");
}

int menu(){
	int opcao;
	printf("\n1.Inserir pesssoa");
	printf("\n2.Pesquisar pessoa");
	printf("\n3.Calcular custo total");
	printf("\n4.Pesquisar sucessor");
	printf("\n5.Pesquisar predecessor");
	printf("\n6.Mostrar em ordem");
	printf("\n7.Calcular o numero de nos");
	printf("\nDigite numero da opcao ou 8 para terminar\n");
	scanf("%d", &opcao);
	return opcao;
}

int main(){
	int opc;
	Arvore a;
	
	initArvore(&a);
	do{
		opc = menu();
		switch(opc){
			case INSERIR:
				inserir();
				break;
			case PESQUISAR:
				pesquisar();
				break;
			default:
				printf("\n opcao invalida");
		}
			
		
	}while(opc != fim);
	return 0;
}
