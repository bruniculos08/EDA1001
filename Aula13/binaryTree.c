#include <stdlib.h>
#include <stdio.h>

#include "binaryTreeHead.h"


int main(){
    raiz *l;
    l = NULL;
    int n, i;
    do
    {
        printf("Digite a opcao desejada:\n1- inserir\n2- remover\n3- buscar\n4- imprimir\n5- altura\n6- profundidade\n7- verificar AVL\n");
        scanf("%i", &n);
        switch(n)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%i", &i);
            l = insere(l, i);
            break;
        case 2:
            l = remover(l, i);
            break;
        case 3:
            printf("Digite o valor: ");
            scanf("%i", &i);
            buscar(l, i);
        case 4:
            imprime(l);
            break;
        case 5:
            printf("Digite o valor: ");
            scanf("%i", &i);
            raiz *node = buscar(l, i);
            printf("Altura: %i\n", altura(node));
            break;
        case 6:
            printf("Digite o valor: ");
            scanf("%i", &i);
            printf("Profundidade: %i\n", profundidade(l, i));
            break;
        default:
            break;
        }
    } while (n != 0);
}