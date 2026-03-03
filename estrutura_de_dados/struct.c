#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30];
    int idade;
    float salario;
} Pessoa;

void apresentaPessoa(Pessoa p){
    printf("\n----------------------------------------------------------");
    printf("\n|%30s    %5d    R$ %6.2f   |", p.nome, p.idade, p.salario);
    printf("\n----------------------------------------------------------");
}

void criaPessoa(Pessoa *p){
    printf("\n Informe o nome: ");
    scanf("%s", p->nome);
    printf("\n Informe a idade: ");
    scanf("%d", &p->idade);
    printf("\n Informe o salário: ");
    scanf("%f", &p->salario);
}

void dobrarSalario(Pessoa * p){  //recebe o endereço de uma pessoa
    p->salario= 2 * p->salario;  //note o uso do operador ->
    // (*p).salario = 2 * (*p).salario;  tambem funciona!!!
}

void main(){
    Pessoa maria = {"Maria Quiteria", 34, 5600.56};
    Pessoa pedro, joao;
    strcpy(pedro.nome, "Pedro Malazarte");
    pedro.idade = 36;
    pedro.salario = 4500.00;
    apresentaPessoa(pedro);
    apresentaPessoa(maria);
    criaPessoa(&joao);
    dobrarSalario(&joao); //passa o endereço do joao
    apresentaPessoa(joao);  //alterou o salário !!!
}