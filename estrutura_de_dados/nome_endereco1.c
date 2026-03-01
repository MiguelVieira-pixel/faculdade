#include <stdio.h>
#include <string.h>

typedef struct {
        char nome [35];
        int idade;
    } Pessoa;

typedef struct {
        char rua[40];
        int numero;
    } Endereco;

int main (){
    Pessoa joao;
    Endereco endereco_do_joao;
    
    strcpy(joao.nome, "João da Silva");
    joao.idade = 33;
    strcpy(endereco_do_joao.rua, "Rua das couves");
    endereco_do_joao.numero = 847;
    printf("%s\n", joao.nome);
    printf("%s\n", endereco_do_joao.rua);
}