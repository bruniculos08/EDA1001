#include <stdio.h>
#include <stdlib.h>
#include "headLista.h"

int main(){

    node *lista;
    lista = (node *)malloc(sizeof(node));
    lista->before = NULL;
    lista->next = NULL;
    int i, n;
    do
    {
        printf("Digite a sua opção:\n1- Inserir\n2- Buscar\n3- Atualizar\n4- Remover\n0- Sair\n");
        scanf("%i", &i);
        switch (i)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &n);
            lista = insereOrdenado(lista, n);
            break;
        case 2:
        
        default:
            break;
        }
    } while (i != 0);
    
}