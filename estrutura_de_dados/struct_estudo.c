#include <stdio.h>

typedef struct{
    char nome[30];
    int cpf;
    int idade;
} Pessoa;

Pessoa p[]={{"Largatixq", 123456789, 18}, {"Miguel", 987543210, 19}, {"Felix", 192827364, 23}};

void mostraPessoa(){
    int i, tamanho = sizeof(p)/sizeof(p[0]);
    for (i=0; i<tamanho; i++){
        printf("\n Nome: %s  CPF: %d    Idade: %d", p[i].nome, p[i].cpf, p[i].idade);
    }
}

int main() {
    mostraPessoa();
    printf("\nPressione ENTER para encerrar...");
    getchar();
    return 0;
    
}