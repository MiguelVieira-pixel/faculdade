#include <stdio.h>

int main ( void ) {
    char linha[80];
    FILE * arq = fopen ( "arquivo.txt", "w+") ;
    printf("\n... Criando o arquivo e gravando nele trÃªs linhas ...\n");
    fprintf(arq, "%s\n", "001 Porca 1.20");
    fprintf(arq, "%s\n", "002 Arruela 1.30");
    fprintf(arq, "%s\n", "003 Parafuso 0.90");
    fclose(arq);
    
    printf("\n... Lendo arquivo ...\n");
	arq = fopen ( "arquivo.txt", "r") ;
	while ( fscanf(arq, "%s", linha) != EOF ) 
		printf("Palavra lida = [%s]\n", linha) ;
	fclose(arq);
	
	printf("\n... Incluindo mais dois ítens ...\n");
	arq = fopen ( "arquivo.txt", "a") ;
	fprintf(arq, "%s\n", "004 Abracadeira 1.00");
	fprintf(arq, "%s\n", "005 Esticador 3.60");
	fclose(arq);
	
	printf("\n... Lendo arquivo novamente ...\n");
	arq = fopen ( "arquivo.txt", "r") ;
	while ( fgets(linha, 80, arq) != NULL ) {
		printf("Linha lida = [%s]\n", linha ) ;
	}
	fclose(arq);
	return 0 ;
}
