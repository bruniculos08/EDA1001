#include <stdio.h>
#include <stdlib.h>
#include "headLista.h"

int main(){

    node *lista;
    lista = NULL;
    int i, v, n;
    do
    {
        printf("Digite a sua opcao:\n1- Inserir\n2- Buscar\n3- Atualizar\n4- Remover\n0- Sair\n");
        scanf("%i", &i);
        switch (i)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &n);
            lista = insereOrdenado(lista, n);
            imprime(lista);
            break;
        case 2:
            printf("Digite o valor a ser buscado: ");
            scanf("%i", &n);
            buscar(lista, n);
            break;
        case 3:
            printf("Digite a posicao do valor a ser atualizado: ");
            scanf("%i", &n);
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &v);
            lista = atualizar(lista, v, n);
            break;
        case 4:
            printf("Digite o valor a ser removido: ");
            scanf("%i", &n);
            lista = remover(lista, n);
            break;
        case 5:
            printf("Digite a posicao do valor(1) a ser trocado: ");
            scanf("%i", &n);
            printf("Digite a posicao do valor(2) a ser trocado: ");
            scanf("%i", &v);
            lista = trocaNodo(lista, ponteiro(lista, n), ponteiro(lista, v));
            break;
        case 11:
            imprime(lista);
            break;        
        default:
            if (i == 0) break;
            printf("Opcao invalida, digite novamente.\n");
            break;
        }
    } while (i != 0);
}