#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct{
    char titulo[40];
    char interprete[40];
    char caminho[60];
} Musica;

typedef struct{
    Musica vetMus[MAX];
    int inicial;
    int final;
    int tamanho;
} FilaMus;

int filaVazia(FilaMus f){
    return f.inicial == f.final;
}

int filaCheia(FilaMus f){
    return f.final > MAX - 1;
}

int inserir(FilaMus *f, Musica m){
    if(filaCheia(*f))
        return -1;
    else{
        f->vetMus[f->final]=m;
        f->final = f->final + 1;
        return 0;
    }
}

int retirar(FilaMus *f, Musica m){
    if(filaVazia)
        return -1;
    else{
        f->vetMus[f->inicial]=m;
        f->inicial = f->inicial + 1;
        return 0;
    }
}

void imprimir_musica(FilaMus f, Musica m){
    if(filaVazia(f)){
        printf("\nPlaylist está vazia.");
    }
    else{
        for(int i = f.inicial; i < f.final; i++){
            printf("\n titulo: %s \n interprete: %s", f.vetMus[i].titulo, f.vetMus[i].interprete);
            // printf("-" * 15);
        }
    }
    printf("\n");
    system("pause");
}

int main(){
    //final:onde vai ser armazenada a proxima música (se fila não cheia) / inicio = 0
    //incial: onde está a próxima música a ser retirada (se fila não vazia) inicio = 0
    FilaMus fila;
    Musica m;
    fila.inicial = 0;
    fila.final = 0;
    int opcao;


    do{
        printf("\n--- MENU PLAYLIST ---\n");
        printf("\n Digite a opcao [1] para inserir uma musica na playlist.");
        printf("\n Digite a opcao [2] para remover uma musica na playlist.");
        printf("\n Digite a opcao [3] para mostrar as musica(s) na playlist.");
        printf("\n Digite a opcao [4] para sair.");
        printf("\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\n Digite o titulo da musica: ");
                scanf(" %[^\n]", &m.titulo);
                printf("\n Digite o interprete da musica: ");
                scanf(" %[^\n]", &m.interprete);
                if(inserir(&fila, m) == 0)
                    printf("\n musica adicionada.");
                break;

            case 2:
                if(retirar(&fila, m) == 0)
                    printf("\n Musica removida.");
                break;

            case 3:
                imprimir_musica(fila, m);
                break;
            
            case 4:
                printf("\n Adios.");
                break;

            default:
                printf("\n Opcao nao identificado.");
                break;
        }


    } while(opcao != 4);
    
    return 0;
}