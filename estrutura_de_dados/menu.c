#include <stdio.h>
#define CADCLI 1
#define CADPRO 2
#define VENDPRO 3
#define SAIR 4

void cadCli(){
    char c;
    printf("\n Estou no cadastro de clientes\n");
    printf("\n <ENTER> para voltar ao menu");
    scanf("%c", &c);
}

void cadPro(){
    char c;
    printf("\n Estou no cadastro de produtos\n");
    printf("\n <ENTER> para voltar ao menu");
    scanf("%c", &c);
}

void vendPro(){
    char c;
    printf("\n Estou na venda de produtos\n");
    printf("\n <ENTER> para voltar ao menu");
    scanf("%c", &c);
}

int menu(){
    int escolha;
    printf("\n --- Sistema Mata ---\n");
    printf("\n1, Cadatro de clientes");
    printf("\n2, Cadatro de produtos");
    printf("\n3, Venda de produto");
    printf("\n4, Relatório de vendas");
    printf("\n5, Sair");
    printf("\n Digite a opção desejada: ");
    scanf("%d", &escolha);
    return escolha;
}
    
int main(){
    int escolha = menu();
    while(escolha != SAIR){
        switch (escolha){
            case CADCLI:
                cadCli();
                break;
            case CADPRO:
                cadPro();
                break;
            case VENDPRO:
                vendPro();
                break;
        }
        escolha = menu();
    }
    return 0;
}