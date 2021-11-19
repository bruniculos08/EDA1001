#include <stdio.h>
#include "listaHead.h"

void *insere(fila *l, int newValue){
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->value = newValue;
    newNode->next = NULL;
    if(l->start == NULL){
        l->start = newNode;
    }
    if(l->end != NULL){
        l->end->next = newNode;
    }
    l->end = newNode;
    
}

int remove(fila *l){
    int oldValue;
    node *oldNode;
    if(l->start == NULL){
        printf("Empty list.\n");
        return 0;
    }
    else{
        oldValue = l->start->value;
        oldNode = l->start;
        l->start = l->start->next;
        free(oldNode);
        return oldValue;
    }
}