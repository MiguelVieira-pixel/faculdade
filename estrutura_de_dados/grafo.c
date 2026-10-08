#include <stdio.h>
#include <malloc.h>
#define QTD 5

typedef struct {
	int numero;
	struct NoLisViz * prox; //proximo
} NoLisViz;

typedef NoLisViz * grafo[QTD + 1];

void initGrafo(grafo g){
	int i;
	for(i = 1; i <= QTD; i++)
		g[i] = NULL;
}

//insere vizinho na posição onde do grafo g
void insertViz(grafo g, int onde, int viz){
	NoLisViz * vizinho = (NoLisViz *) malloc(sizeof(NoLisViz));
	vizinho->numero = viz;
	vizinho->prox = NULL;
	
	if(g[onde] == NULL)
		g[onde] = vizinho;
	else{
		NoLisViz * ultimo = (NoLisViz *)g[onde]->prox;
		while(ultimo->prox != NULL)
			ultimo = (NoLisViz *)ultimo->prox;
		ultimo->prox = (struct NoLisViz *)vizinho;
	}
}

void showGrafo(grafo g){
	for(int i = 0; i <= QTD; i++){
		printf("\n Vertice %d : ", i);
		NoLisViz * v = g[i];
		while(v != NULL){
			printf("\t %d", g[i]->numero);
			v = (NoLisViz *)v->prox;
		}
	}
	printf("\n");
}

int main(){
	grafo jombalaya;
	initGrafo(jombalaya);
	insertViz(jombalaya, 1, 2);
	insertViz(jombalaya, 1, 5);
	showGrafo(jombalaya);
	return 0;
}
