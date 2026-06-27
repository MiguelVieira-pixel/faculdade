#include<stdio.h>

typedef struct {
    char cpf[20];
    char nome[30];
    int idade;
    float salario;
} Pessoa;

void mostra(Pessoa p){
	printf("\n%20s %30s %4d R$ %8.2f\n", p.cpf, p.nome, p.idade, p.salario);
}

int main(){
    Pessoa Paola;

    FILE * arqstru = fopen("./Pessoas.dat", "rb");
    fread(&Paola, sizeof(Pessoa), 1, arqstru);
    fclose(arqstru);
    
    mostra(Paola);
    return 0;
}
