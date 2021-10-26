#include "lse.h"
#include <stdio.h>
#include <stdlib.h>

nodo * insere_fim(nodo *l, int valor){
    nodo *p;
    nodo *new;
    p = l;
    new->dado = valor;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = new;
    return l;
}

int profundidade(nodo *l, int valor){
    nodo *p;
    int size = 0;
    p = l;
    if (p == NULL) return -1;                           //^ lista vazia
    while(p->prox != NULL && valor != p->dado){         //^ percorre lista
        p = p->prox;
        size += 1;
    }
    if (p->prox == NULL && valor != p->dado) return -1; //^ não há o elemento na lista
    else return size+1;
}

void imprime_lista(nodo *l){
    nodo *p;
    p = l;
    while(p != NULL){
        printf("%i ", p->dado);
        p = p->prox;
    }
}