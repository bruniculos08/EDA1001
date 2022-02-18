#include <stdio.h>
#include <string.h>
#include "headQ6.h"
#include <stdlib.h>


char *retira(pilha *a){
    if(a->topo == NULL) {
        return "\0";
    }
    node *anterior = a->topo;
    a->topo = a->topo->next;
    char r[8] = anterior->item;
    free(anterior);
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
        printf("%s ", start->item);
        start = start->next;
    }
    printf("\n");
} 

void sair(pilha *a, char dado[8]){
    pilha *M;
    M = (pilha *)malloc(sizeof(pilha));
    M->topo = NULL;
    int i = 0;
    char letter[8];
    while(a->topo != NULL){
        strcpy(letter, retira(a));
        if(strcmp(letter, dado) == 0) break;
        insere(M, letter);
        printf("%c saiu de G e entrou em M\n", letter);
    }
    printf("J saiu\n");
    while(M->topo != NULL){
        strcpy(letter, retira(a));
        insere(a, letter);
        printf("%c saiu de M e entrou em G\n", letter);
    }
}