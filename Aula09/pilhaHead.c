#include <stdio.h>
#include <string.h>
#include "pilhaHead.h"
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

void expressao(pilha *a, char string[]){
    int n = strlen(string);
    printf("montando...\n");
    for(int i = 0; i < n; i++){
        insere(a, string[i]);
    }
}

int lerPilha(pilha *a){
    int n, status;
    n = 0;
    printf("lendo...\n");
    while(a->topo != NULL){
        char s = retira(a, &status);
        if(s == ')') n = n+1;
        else if(s == '(') n = n-1;
        if(n < 0){
            printf("Expressao invalida.\n");
            return 1;
        }
    }
    if(n != 0){
        printf("Expressao invalida.\n");
        return 1;
    }
    printf("Expressao valida.\n");
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