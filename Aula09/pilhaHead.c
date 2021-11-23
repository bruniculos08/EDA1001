#include <stdio.h>
#include <string.h>
#include "pilhaHead.h"

char retira(pilha *a, int *status) {
    if(a->topo == NULL) {
        *status = 1;
        return NULL;
    }
    node *anterior = a->topo;
    a->topo = a->topo->next;
    char r = anterior->item;
    free(anterior);
    *status = 0;
    return r;
}

int insere(pilha *a, char dado){
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->item = dado;
    newNode->next = NULL;
    if(a->topo == NULL) {
        a->topo = newNode;
        return 0;
    }
    newNode->next = a->topo;
    a->topo = newNode;
    return 0;
}

void expressao(pilha *a, char string[]){
    int n = sizeof(string)/sizeof(char);
    for(int i = 0; i < n; i++){
        insere(a, string[i]);
    }
}