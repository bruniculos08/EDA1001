#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

int main(void){

    int option, n;
    nodo *lista;
    lista = NULL;
    do{
        printf("Digite a opcao desejada:\n[1]inicializar lista\n[2]inserir em ordem na lista\n[3]inserir no final da lista\n[4]verificar a profundidade de um elemento na lista\n[5]imprimir lista\n[6]contar nos\n[7]liberar lista\n[8]remover elemento da lista\n");
        scanf("%i", &option);
        switch(option){
            case 1:
                free(lista);
                lista = inicializa();
                break;
            case 2:
                printf("\nDigite o valor a ser inserido na lista: ");
                scanf("%i", &n);
                lista = insere_ordenado(lista, n);
                break;
            case 3:
                printf("\nDigite o valor a ser inserido na lista: ");
                scanf("%i", &n);
                lista = insere_fim(lista, n);
                break;
            case 4:
                printf("\nDigite o valor a ser verificada a profundidade: ");
                scanf("%i", &n);
                printf("profundidade do valor %i: %i\n", n, profundidade(lista, n));
                break;
            case 5:
                imprime_lista(lista);
                break;
            case 6:
                printf("\nExistem %i nos na lista.\n", conta_nos(lista));
                break;
            case 7:
                lista = libera_lst(lista);
                break;
            case 8:
                printf("\nDigite o valor a ser removido da lista: ");
                scanf("%i", &n);
                lista = busca_rmv(lista, n);
                break;
            case 0:
                break;
            default:
                printf("Essa opcao nao existe.\n");
                break;
        }
    } while (option != 0);
}