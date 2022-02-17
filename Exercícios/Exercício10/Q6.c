#include <stdio.h>
#include <stdlib.h>

#include "headQ6.h"


int main(){
    node *lista;
    lista = NULL;
    int n, i;
    do
    {
        scanf("%i", &n);
        switch (n)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%i", &i);
            lista = insere(lista, i);
            break;
        case 2:
            lista = truque(lista);
            break;
        case 3:
            printf("Digite a posicao: ");
            scanf("%i", &i);
            lista = remover(lista, i);
            break;
        case 4:
            imprimir(lista);
            break;
        default:
            break;
        }
    } while (n != 0);
    
}