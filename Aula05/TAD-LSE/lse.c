#include "lse.h"
#include <stdio.h>
#include <stdlib.h>

nodo * insere_fim(nodo *l, int valor){
    nodo *p;
    nodo *new;
    new = (nodo *)malloc(sizeof(nodo));
    p = l;
    new->dado = valor;
    new->prox = NULL;
    if (p == NULL)
    {
        p = new;
        return p;
    }
    
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
    return size+1;
}

void imprime_lista(nodo *l){
    nodo *p;
    p = l;
    if (p == NULL){
        printf("Lista vazia.\n");
        return;
    }
    while(p != NULL){
        printf("%i ", p->dado);
        p = p->prox;
    };
    printf("\n");
}

nodo * inicializa(){
    nodo *p;
    p = (nodo *)malloc(sizeof(nodo));
    printf("\nDigite o dado do primeiro nodo: ");
    scanf("%i", &p->dado);
    p->prox = NULL;
    return p;
}

int conta_nos(nodo *l){
    nodo *p;
    p = l;
    if (p == NULL) return 0;
    int n = 0;
    while (p->prox != NULL) {
        n += 1;
        p = p->prox;
    }
    return n;
}

nodo * libera_lst(nodo *l){
    nodo *p;
    nodo *a;
    p = l;
    if (p == NULL) return NULL;
    while (p->prox != NULL) {
        a = p;
        p = p->prox;
        free(a);
    }
    free(p);
    return NULL;
}

nodo * busca_rmv(nodo *l, int valor){
    nodo *p;
    nodo *a;
    a = NULL;
    p = l;
    while (p->prox != NULL && valor != p->dado){
        a = p;
        p = p->prox;
    }
    if (p->prox == NULL && valor != p->dado){
        printf("Valor nao encontrado.\n");
        return l;
    }
    if (a == NULL){
        a = p;
        p = p->prox;
        free(a);
        return p;
    }
    a->prox = p->prox;
    free(p);
    return l;
}