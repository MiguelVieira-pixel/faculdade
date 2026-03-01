#include <stdio.h>
#include <string.h>
// ENDEREÇO
typedef struct {
    char rua[40];
    int numero;
} Endereco;

void criaEndereco(Endereco * e){
    printf("Informe a rua: ");
    scanf("%[^\n]", e->rua);
    printf("Informe o numero: ");
    scanf("%d", & e->numero);
}

void mostraEndereco(Endereco * e) {
    printf("%s, %d\n", e ->rua, e->numero);
}

// PESSOA   
typedef struct {
    char nome[35];
    int idade;
    Endereco end;
} Pessoa;

void criaPessoa(Pessoa * p){
    printf("Informe o nome: ");
    scanf("%[^\n]", p->nome);
    printf("Informe a idade: ");
    scanf("%d", & p->idade);
    // Limpa o buffer de teclado
    fflush(stdin);
    criaEndereco(& p->end);
}

void mostraPessoa(Pessoa * p){
    printf("%s, %d\n", p->nome, p->idade);
    mostraEndereco(& p->end);
}

// main
int main(){
    Pessoa joao;
    criaPessoa(&joao);
    mostraPessoa(&joao);
}
