#include <stdio.h>
#include <stdlib.h>

main(){
    int pessoas, entraram, andar, sairam, limitePessoas = 0;

    printf("\n Quantos andares tem esse predio: ");
    scanf("%d", &andar);

    for(int i=1;i <= andar; i++){
        printf("\n Estamos no %d.0 andar", i);
        printf("\n Tem %d pessoas no elevador", pessoas);

        if(i == 1){  //primeiro andar não sai
            printf("\n Quantas pessoas entraram: ");
            scanf("%d", &pessoas);
            system("cls");
        }
        else if(i != andar){  //restante dos andares
            printf("\n Quantas pessoas entraram: ");  //entraram
            scanf("%d", &entraram);
            pessoas += entraram;
            printf("\n Quantas pessoas sairam: ");  //sairam
            scanf("%d", &sairam);
            system("cls");

            while(sairam > pessoas){  //não pode sair mais do que existe no elevador
                printf("\n Nao pode sair mais pessoas do que tem no elevador.");
                printf("\n Quantas pessoas sairam: ");
                scanf("%d", &sairam);
                system("cls");
            }

            pessoas -= sairam;
            if(pessoas > 15){ //limite 15 pessoas
                printf("\n Limite de pessoas excedido!");
                limitePessoas = pessoas - 15;
                pessoas -= limitePessoas;
                printf("\n Sairam %d pessoas", limitePessoas);
                printf("\n Pressione Enter para continuar.");
                system("pause>null");
            }
        }
        else{
            printf("\n Descam todas as %d pessoas", pessoas);  //ultimo andar
            system("pause>null");  
        }
    }
}
