#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headQ6.h"


int main(){
    int i, status;
    char letter;
    pilha *a;
    a = malloc(sizeof(pilha));
    a->topo = NULL;
    do
    {   
        scanf("%i", &i);
        switch (i)
        {
        case 1:
            sair(a);
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