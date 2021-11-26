#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaHead.h"


int main(){
    int i, status;
    char string[50], letter;
    pilha *a;
    do
    {   
        printf("Digite a opcao desejada:\n1- inserir expressao\n2- inserir na pilha\n3- retirar da pilha\n4- imprimir pilha\n");
        scanf("%i", &i);
        switch (i)
        {
        case 1:
            printf("Digite a expressao: ");
            scanf("%s", string);
            expressao(a, string);
            lerPilha(a);
            break;
        case 2:
            printf("Digite o item a ser inserido: ");
            fflush(stdin);
            scanf("%c", &letter);
            insere(a, letter);
            break;
        case 3:
            letter = retira(a, &status);
            printf("Item retirado: %c\n", letter);
            break;
        case 4:
            imprimePilha(a);
            break;        
        default:
            break;
        }
    } while (i != 0);
    
}