#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*Este programa exemplifica a implementação de fila com ponteiros no caso, uma fila de músicas.*/

typedef struct{
    char titulo[40];
    char interprete[40];
    char caminho[60];
    struct Musica * anterior;
    struct Musica * proximo;
} Musica;

typedef struct{
    Musica * primeiro;
    Musica * ultimo;
} FilaMus;

void initFilaMus(FilaMus *f){
    f->primeira = NULL;
    f->ultimo = NULL;
}

filaVazia(FilaMus f){
    return f.primeira == 1;
}

int inserir(FilaMus *f, Musica m){
    Musica * aux =(Musica *)malloc(sizeof(Musica));
    if(aux == NULL)
        return -1; //erro. memória heap insuficiente.
    else{
        m.proxima = NULL;
        if(filaVazia(*f)){
            m.anterior = NULL;
            *aux = m;
            f->primeiro = aux;
        }
        else{
            m.anterior = (struc Musica *)f->ultimo;
            *aux = m;
            f->ultimo->proximo = (struct Musica *) aux;
        }
        f->ultimo = aux;
        return 0; //sucesso
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

void main(){


}