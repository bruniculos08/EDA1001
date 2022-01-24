#include <stdlib.h>
#include <stdio.h>
#include <binaryTreeHead.h>

raiz *buscar(raiz *l, int valor){
    if(l == NULL) return NULL;
    else if(valor == l->valor){
        printf("Valor encontrado.\n");
        return l;
    }
    else if(valor < l->valor && l->esq != NULL) return buscar(l->esq, valor);
    else if(valor > l->valor && l->dir != NULL) return buscar(l->dir, valor);
    else printf("Valor nao encontrado.\n");
    return NULL;
}

raiz *buscar_pai(raiz *l, int valor){
    if(l == NULL) return NULL;
    else if(l->valor == valor) return l;
    else if(valor < l->valor && l->esq != NULL){
        if(l->esq->valor == valor) return l;
        else return buscar_pai(l->esq, valor);
    }
    else if(valor > l->valor && l->dir != NULL){
        if(l->dir->valor == valor) return l;
        else return buscar_pai(l->dir, valor);
    }
    else printf("Valor nao encontrado.\n");
    return NULL;
}

raiz *insere(raiz *l, int valor){
    if(l == NULL){
        l = malloc(sizeof(raiz));
        l->valor = valor;
        l->esq = NULL;
        l->dir = NULL;
    }
    else if(valor <= l->valor) l->esq = insere(l->esq, valor);
    else l->dir = insere(l->dir, valor);
}

raiz *remover(raiz *l, int valor){
    raiz *p = buscar_pai(l, valor);
    if(p == NULL) return NULL;
    else if(p->valor == valor) p = remover_node(p);
    else if(p->esq == valor) p->esq = remover_node(p->esq);
    else p->dir = remover_node(p->dir);
    return l;
}