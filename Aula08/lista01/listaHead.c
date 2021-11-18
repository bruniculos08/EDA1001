#include <stdio.h>
#include <stdlib.h>

#include "listaHead.h"


node *insere(node *l, int newValue){
    node *newItem;
    newItem = malloc(sizeof(node));
    newItem->value = newValue;
    newItem->next = NULL;
    if(l == NULL) return newItem;
    node *list;
    list = l;
    while(list->next != NULL){
        list = list->next;
    }
    list->next = newItem;
    return l;
}

node *remover(node *l){
    if(l == NULL){
        printf("Empty list.\n");
        return NULL;
    }
    node *start;
    start = l->next;
    free(l);
    return start;
}