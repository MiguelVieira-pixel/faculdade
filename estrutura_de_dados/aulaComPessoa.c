#include<stdio.h>

typedef struct {
    char cpf[20];
    char nome[30];
    int idade;
    float salario;
} Pessoa;

void main(){
    Pessoa meganFox = {"123.456", "Megan Fox", 35, 35000.00};

    FILE * arqtexto = fopen("./Pessoas.txt", "w");
    fprintf(arqtexto, "%20s %30s %4d R$ %8.2f\n", meganFox.cpf, meganFox.nome, meganFox.idade, meganFox.salario);
    fclose(arqtexto);

    FILE * arqstru = fopen("./Pessoas.dat", "wb");
    fwrite(&meganFox, sizeof(Pessoa), 1, arqstru);
    fclose(arqstru);
}