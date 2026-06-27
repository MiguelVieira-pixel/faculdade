#include <stdio.h>
#include <malloc.h>
#include <string.h>
 
typedef struct {
	char cpf[30];
	char nome[40];
	char apelido[30];
	char sexo; // M ou F
	struct Pessoa * esq;
	struct Pessoa * dir;
} Pessoa;
	
//	typedef struct {
//		Pessoa * raiz;
//	} Arvore;
	
	typedef Pessoa * Arvore;
	
void init(Arvore * a){
//		a->raiz = NULL;
	*a = NULL;
}
	
void inserir(Arvore * a, Pessoa p){
	if(*a == NULL){ // n� vazio
		*a = (Pessoa *)malloc(sizeof(Pessoa));
		p.esq = NULL;
		p.dir = NULL;
		**a = p;
//			mostra(**a);
	}
	else{ //n� ocupado
		if(strcmp((*a)->cpf, p.cpf) == 0)
			return -1; //ERRO, cpf j� cadastrado
			else if(strcmp((*a)->cpf, p.cpf) < 0)
				inserir((Arvore *) &(*a)->dir, p);
			else
				inserir((Arvore *) &(*a)->esq, p);
	}
}
	
void ordem(Arvore a){
	if(a != NULL){
		ordem((Arvore) a->esq);
		mostra((Pessoa) *a);
		ordem((Arvore) a->dir);
	}
}
	
void mostra(Pessoa p){
	printf("\n CPF[%s], %s, %s, %c\n", p.cpf, p.nome, p.apelido, p.sexo);
}



int main(){
//	este programa implementa uma �rvore bin�ria de PESSOAS, em que a chave de compara��o � o CPF. Teremos aqui as fun��es de inser��o,
//	visitas e busca
	int opcao;

	Arvore seringueira;
	init(&seringueira);
	Pessoa p1 = {"123", "Alano", "Feio", 'M'};
	Pessoa p2 = {"234", "Beltrano", "Bel", 'M'};
	Pessoa p3 = {"345", "Ciclana", "Ciclope", 'F'};
	Pessoa p4 = {"456", "Delano", "Delinho", 'M'};
	Pessoa p5 = {"567", "Elana", "Ela", 'F'};
	inserir(&seringueira, p3);
	inserir(&seringueira, p4);
	inserir(&seringueira, p1);
	inserir(&seringueira, p2);
	inserir(&seringueira, p5);
	do{
		switch(opcao){
			case 1:
			printf("\n Digite o cpf: ");
			
		}
	}
	ordem(seringueira);
	return 0;	
}
