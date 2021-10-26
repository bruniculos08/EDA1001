#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

int main(void){

    int option, n;
    nodo *lista;
    lista = NULL;
    do{
        printf("Digite a opcao desejada:\n[1]inicializar lista\n[2]inserir no final da lista\n[3]verificar a profundidade de um elemento na lista\n[4]imprimir lista\n[5]liberar lista\n[6]contar nos\n[7]remover elemento da lista\n");
        scanf("%i", &option);
        switch(option){
            case 1:
                free(lista);
                lista = inicializa();
                break;
            case 2:
                printf("\nDigite o valor a ser inserido na lista: ");
                scanf("%i", &n);
                lista = insere_fim(lista, n);
                break;
            case 3:
                printf("\nDigite o valor a ser verificada a profundidade: ");
                scanf("%i", &n);
                printf("profundidade do valor %i: %i\n", n, profundidade(lista, n));
                break;
            case 4:
                imprime_lista(lista);
                break;
            case 5:
                lista = libera_lst(lista);
                break;
            case 6:
                printf("\nExistem %i nos na lista.\n", conta_nos(lista));
                break;
            case 7:
                printf("\nDigite o valor a ser removido da lista: ");
                scanf("%i", &n);
                lista = busca_rmv(lista, n);
                break;
            default:
                printf("Essa opcao não existe.\n");
                break;
        }
    } while (option != 0);
}