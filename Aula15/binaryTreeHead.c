#include <stdlib.h>
#include <stdio.h>
#include "binaryTreeHead.h"

void imprime(raiz *l){
    if(l == NULL) return;
    printf("%i\n", l->valor);    
    imprime(l->esq);
    imprime(l->dir);
}

int testeAVL(raiz *l){
    if(l == NULL) return 0;
    else if(abs(balanceamento(l)) > 1) return 1;
    else return (testeAVL(l->esq)+testeAVL(l->dir));
}

int altura(raiz *l){
    int h = 0;
    if(l == NULL) return -1;
    if(l->esq == NULL && l->dir == NULL) return 0;
    if(l->esq == NULL) h = h + 1 + altura(l->dir);
    else if(l->dir == NULL) h = h + 1 + altura(l->esq);
    else{
        if(altura(l->esq) < altura(l->dir)) h = h + 1 + altura(l->dir);
        else h = h + 1 + altura(l->esq);
    }
    return h;
}

int profundidade(raiz *l, int valor){
    int p = 0;
    while(l->valor != valor){
        if(l->valor < valor) l = l->dir;
        else l = l->dir;
        p++;
    }
    return p;
}

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
    l = balancear(l);
    return l;
}

int balanceamento(raiz *l){
    int i = altura(l->esq)-altura(l->dir);
    return i;
}

raiz *balancear(raiz *l){
    if(l == NULL) return l;
    else if(balanceamento(l) >= 2){
        if(l->esq != NULL && balanceamento(l->esq) >= 0) l = rotacionaDir(l);
        else{
            l->esq = rotacionaEsq(l->esq);
            l = rotacionaDir(l);
        }
    }
    else if(balanceamento(l) <= -2){
        if(l->dir != NULL && balanceamento(l->dir) <= 0) l = rotacionaEsq(l);
        else{
            l->dir = rotacionaDir(l->dir);
            l = rotacionaEsq(l);
        }
    }
    return l;
}

raiz *balancearArvore(raiz *l, int valor){
    //balancear de baixo pra cima
    if(l->valor == valor) return balancear(l);
    else if(l->valor < valor) l->esq = balancearArvore(l->esq, valor);
    else if(l->valor > valor) l->dir = balancearArvore(l->dir, valor);
    l = balancear(l);
    return l;
}

raiz *remover(raiz *l, int valor){
    raiz *f, *p;
    f = l;
    p = f;
    while(f->valor != valor && f != NULL){
        printf("Here.\n");
        p = f;
        if(f->valor > valor) f = f->esq;
        else f = f->dir;
    }
    if(f == NULL){
        printf("Valor nao encontrado.\n");
        return l;
    }
    if(p == f){
        l = removerNode(p);
        l = balancearArvore(l, l->valor);
    }
    else if(p->esq == f){
        p->esq = removerNode(f);
        if(p->esq != NULL) l = balancearArvore(l, p->esq->valor);
        else l = balancearArvore(l, p->valor);
    }
    else{
        p->dir = removerNode(f);
        if(p->dir != NULL) l = balancearArvore(l, p->dir->valor);
        else l = balancearArvore(l, p->valor);
    }
    // fazer um while indo até o novo nó e balanceando todos pelo caminho
    return l;
}

raiz *removerNode(raiz *node){
    raiz *f, *p; // o ponteiro *p aponta para o pai do nó que queremos mexer e *f para algum dos nós filhos de *node
    if(node->esq == NULL && node->dir == NULL){
        free(node);
        return NULL;
    }
    else if(node->dir == NULL){
        f = node->esq;
        free(node);
        return f;
    }
    else if(node->esq == NULL){
        f = node->dir;
        free(node);
        return f;
    }
    p = node;
    f = node->dir;
    while(f->esq != NULL){ // o ponteiro *f tem que apontar para o sucessor de *node, enquanto *p aponta para o pai desse sucessor
        p = f;
        f = f->esq;
    }
    if(p != node){
        p->esq = f->dir;
        f->dir = node->dir;
    }
    f->esq = node->esq;
    free(node);
    return f;
}

raiz *rotacionaEsq(raiz *x){
    if(x == NULL) return NULL;
    raiz *y = x->dir;
    x->dir = y->esq;
    y->esq = x;
    return y;
}

raiz *rotacionaDir(raiz *x){
    if(x == NULL) return NULL;
    raiz *y = x->esq;
    x->esq = y->dir;
    y->dir = x;
    return y;
}