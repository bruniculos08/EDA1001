#include <stdlib.h>
#include <stdio.h>

#include "quickSortHead.h"


int main(){
    node *l;
    l = NULL;
    int n, i;
    do
    {
        printf("Digite a opcao desejada:\n1- inserir\n2- liberar\n3- remover\n4- imprimir\n5- ordenar\n");
        scanf("%i", &n);
        switch (n)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%i", &i);
            l = insere(l, i);
            break;
        case 2:
            l = limpar(l);
            break;
        case 3:
            printf("Digite a posicao: ");
            scanf("%i", &i);
            l = remover(l, i);
            break;
        case 4:
            imprime(l);
            break;
        case 5:
            l = quickSort(l, split(l));
            break;
        default:
            break;
        }
    } while (n != 0);
    
}