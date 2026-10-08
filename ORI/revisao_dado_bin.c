#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	float temperatura;
} Registro;

int main(){
	
	Registro dado_entrada;
	Registro dado_saida = {1, 36.5};
	
	FILE *ficheiro = fopen("dados.bin", "wb");
	if(ficheiro == NULL){
		printf("\n Erro ao abrir o ficheiro.");
		return 1;
	}
	
	fwrite(&dado_saida, sizeof(Registro), 1, ficheiro);
	fclose(ficheiro);
	
    ficheiro = fopen("dados.bin", "rb");
    if(ficheiro == NULL){
    	printf("\n Erro ao ler o ficheiro.");
    	return 1;
	}
	
	fread(&dado_entrada, sizeof(Registro), 1, ficheiro);
	fclose(ficheiro);
	printf("\n ID: %d --- Temperatura: %.1f", dado_entrada.id, dado_entrada.temperatura);
	
	return 0;
}
