#include <stdio.h>
#include <string.h>

void mostra01(char * s){
    int tamanho = strlen(s);
    int i;
    printf("\n nome tem %d letras\n", tamanho);
    for(i = 0; i < tamanho; i++)
        printf("\n%c", s[i]);
    printf("\n\n");
}
void mostra02(char * s){
    if(s[0] != '\0'){
        printf("\n%c", s[0]);
        mostra02(s+1);
    }
    printf("\n%c", s[0]);
}


void main(){
    char nome[] = "sabado";
    mostra01(nome);
    printf("\n --------------------------------\n");
    mostra02(nome);
    printf("\n---------------------------------\n");
}