#include <stdio.h>
#include <stdlib.h>

#include "mergeSortHead.h"


int main(){
    node *lista;
    lista = NULL;
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
            lista = insere_fim(lista, i);
            break;
        case 2:
            lista = liberar(lista);
            break;
        case 3:
            printf("Digite a posicao: ");
            scanf("%i", &i);
            lista = remover(lista, i);
            break;
        case 4:
            imprimir(lista);
            break;
        case 5:
            lista = mergeSort(lista);
            break;
        default:
            break;
        }
    } while (n != 0);
    
}