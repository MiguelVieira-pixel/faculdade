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
        f->vetMus[f->final] = m;
        f->final = f->final + 1;
        f->tamanho++;
        return 0;
    }
}

// CORREÇÃO: era filaVazia sem (), e a cópia estava invertida
int retirar(FilaMus *f, Musica *m){
    if(filaVazia(*f))
        return -1;
    else{
        *m = f->vetMus[f->inicial];  // copia a música retirada para *m
        f->inicial = f->inicial + 1;
        f->tamanho--;
        return 0;
    }
}

void imprimir_musica(FilaMus f){
    if(filaVazia(f)){
        printf("\nPlaylist esta vazia.\n");
    }
    else{
        printf("\n--- Playlist (%d musica(s)) ---\n", f.tamanho);
        for(int i = f.inicial; i < f.final; i++){
            printf("\n[%d] Titulo:     %s", i - f.inicial + 1, f.vetMus[i].titulo);
            printf("\n    Interprete: %s", f.vetMus[i].interprete);
            printf("\n    Caminho:    %s", f.vetMus[i].caminho);  // ADICIONADO
            printf("\n    ----------------------------------------");
        }
    }
    printf("\n");
    system("pause");
}

int main(){
    FilaMus fila;
    Musica m;
    fila.inicial = 0;
    fila.final = 0;
    fila.tamanho = 0;  // CORREÇÃO: inicializar tamanho
    int opcao;

    do{
        printf("\n--- MENU PLAYLIST ---\n");
        printf("\n [1] Inserir musica");
        printf("\n [2] Remover musica");
        printf("\n [3] Mostrar playlist");
        printf("\n [4] Sair");
        printf("\n\n Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\n Digite o titulo da musica: ");
                scanf(" %[^\n]", m.titulo);
                printf("\n Digite o interprete da musica: ");
                scanf(" %[^\n]", m.interprete);
                printf("\n Digite o caminho do arquivo: ");  // ADICIONADO
                scanf(" %[^\n]", m.caminho);                // ADICIONADO
                if(inserir(&fila, m) == 0)
                    printf("\n Musica adicionada com sucesso!");
                else
                    printf("\n Playlist cheia!");
                break;

            case 2:
                if(retirar(&fila, &m) == 0)  // CORREÇÃO: passa &m
                    printf("\n Musica removida: %s", m.titulo);
                else
                    printf("\n Playlist vazia!");
                break;

            case 3:
                imprimir_musica(fila);
                break;
            
            case 4:
                printf("\n Adios.\n");
                break;

            default:
                printf("\n Opcao nao identificada.");
                break;
        }
        printf("\n");
        system("pause");
        system("cls");

    } while(opcao != 4);
    
    return 0;
}