#include <stdio.h>
#include <stdlib.h>

#include "listaHead.h"
void imprime(node *l);

int main(){
    int k, n;
    node *l;
    l = NULL;
    do
    {
        scanf("%i", &k);
        switch (k)
        {
        case 1:
            printf("Type the new value: ");
            scanf("%i", &n);
            l = insere(l, n);
            break;
        case 2:
            printf("Removing...\n");
            l = remover(l);
            break;
        default:
            if (k != 0) imprime(l);
            break;
        }
    } while (k != 0);
    
}

void imprime(node *l){
    node *list;
    list = l;
    if (list == NULL){
        printf("Empty list.\n");
        return;
    }
    while(list != NULL){
        printf("%i ", list->value);
        list = list->next;
    }
    printf("\n");
}