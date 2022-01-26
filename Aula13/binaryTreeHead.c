#include <stdlib.h>
#include <stdio.h>
#include <binaryTreeHead.h>

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
        return l;
    }
    else if(valor <= l->valor) l->esq = insere(l->esq, valor);
    else l->dir = insere(l->dir, valor);
    return l;
}

raiz *remover(raiz *l, int valor){
    raiz *p = buscar_pai(l, valor);
    if(p == NULL) return NULL;
    else if(p->valor == valor) p = remover_node(p);
    else if(p->esq->valor == valor) p->esq = remover_node(p->esq);
    else p->dir = remover_node(p->dir);
    return l;
}

raiz *remover_node(raiz *node){
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
    while(f != NULL){ // o ponteiro *f tem que apontar para o sucessor de *node, enquanto *p aponta para o pai desse sucessor
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

void imprime(raiz *l){
    if(l == NULL) return;
    imprime(l->esq);
    printf("%i\n", l->valor);
    imprime(l->dir);
}

int teste_AVL(raiz *l){}