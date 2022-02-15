#include <stdlib.h>
#include <stdio.h>
#include "headQ3.h"

void deitaArvore(raiz *l){
    while(l != NULL){
        printf("%i\n", l->valor);
        l = l->esq;
    }
}

void imprime(raiz *l){
    if(l == NULL) return;
    printf("%i\n", l->valor);    
    imprime(l->esq);
    imprime(l->dir);
}

raiz *insere(raiz *l, int valor){
    if(l == NULL){
        l = malloc(sizeof(raiz));
        l->valor = valor;
        l->esq = NULL;
        l->dir = NULL;
        return l;
    }
    else if(valor <= l->valor) l->esq = insere(l->esq, valor);
    else l->dir = insere(l->dir, valor);
    return l;
}