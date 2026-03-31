#include <stdio.h>
#include <string.h>

typedef char codigo[20];

typedef struct{
    codigo ismn;
    char titulo[30];
    char interprete[30];
    int ano;
} Musica;

void troca(Musica m[], int a, int b){
    Musica aux = m[a];
    m[a] = m[b];
    m[b] = aux;
}

void divide( Musica n[ ], int start, int end, int * newfirst, int * newlast ) {
codigo ref;
int meio, begin1, final1 ;
meio = ( start + end ) / 2 ;
strcpy(ref, n[meio].ismn) ;
begin1 = start ;
final1 = end ;
while ( begin1 < final1 ) {
while (strcmp(n[begin1].ismn, ref) < 0) begin1++ ;
while (strcmp(n[final1].ismn, ref) > 0) final1-- ;
if ( begin1 <= final1 ) {
troca(n, begin1, final1) ;
begin1++ ;
final1-- ;
}
}
*newfirst = begin1 ;
*newlast = final1 ;
}

void quicksort ( Musica n[ ], int start, int end ) {
    int newfirst, newlast ;
    if ( start < end ) {
        divide ( n, start, end, &newfirst, &newlast ) ;
        quicksort ( n, start, newlast ) ;
        quicksort ( n, newfirst, end ) ;
    }
}

void mostra ( Musica n[ ], int size ) {
    printf("\n----------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %s - %s - %d\n", n[i].ismn, n[i].titulo, n[i].interprete, n[i].ano);
    }
}


int main(){
    Musica m[] = {
               {"123", "Let it be", "The Beatles", 1970},
               {"456", "Bohemian Rhapsody", "Queen", 1975},
               {"789", "Stairway to Heaven", "Led Zeppelin", 1971},
               {"101", "Hotel California", "Eagles", 1976},
               {"112", "Imagine", "John Lennon", 1971},
               {"131", "Smells Like Teen Spirit", "Nirvana", 1991},
               {"415", "Like a Rolling Stone", "Bob Dylan", 1965},
               {"161", "What's Going On", "Marvin Gaye", 1971},
                };
    int size = sizeof(m) / sizeof(m[0]);
    mostra(m, size);
    printf("\nOrdenando...\n\n");
    quicksort(m, 0, size - 1);
    mostra(m, size);

    return 0;
}