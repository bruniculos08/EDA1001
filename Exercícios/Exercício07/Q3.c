#include <stdlib.h>
#include <stdio.h>

#include "binaryTreeHead.h"


int main(){
    raiz *l;
    l = NULL;
    int n, i;
    do
    {
        scanf("%i", &n);
        switch(n)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%i", &i);
            l = insere(l, i);
            break;
        case 2:
            imprime(l);
            break;
        case 3:
            deitaArvore(l);
            break;
        default:
            break;
        }
    } while (n != 0);
}