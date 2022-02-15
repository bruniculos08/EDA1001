#include <stdio.h>
#include <string.h>
#include "headQ5.h"
#include <stdlib.h>


char retira(pilha *a, int *status) {
    if(a->topo == NULL) {
        *status = 1;
        return '\0';
    }
    node *anterior = a->topo;
    a->topo = a->topo->next;
    char r = anterior->item;
    free(anterior);
    *status = 0;
    return r;
}

int insere(pilha *a, char dado){
    printf("inserindo...\n");
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->item = dado;
    newNode->next = a->topo;
    a->topo = newNode;
    printf("inserido.\n");
    return 0;
}

void imprimePilha(pilha *a){
    node *start;
    start = a->topo;
    while(start != NULL){
        printf("%c ", start->item);
        start = start->next;
    }
    printf("\n");
} 

void sair(pilha *a){
    pilha *M;
    M = NULL;
    int i;
    char letter;
    while(a != NULL){
        letter = retira(a, &i);
        if(letter == 'J') break;
        printf("%c saiu de G e entrou em M\n", letter);
        insere(a, letter);
    }
    printf("J saiu\n");
    while(M != NULL){ }
}