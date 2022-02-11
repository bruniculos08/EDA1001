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
    else if(abs(altura(l->esq)-altura(l->dir)) > 1) return 1;
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

raiz *buscarPai(raiz *l, int valor){ 
    if(l == NULL) return NULL;
    else if(l->valor == valor) return l;
    else if(valor < l->valor && l->esq != NULL){
        if(l->esq->valor == valor) return l;
        else return buscarPai(l->esq, valor);
    }
    else if(valor > l->valor && l->dir != NULL){
        if(l->dir->valor == valor) return l;
        else return buscarPai(l->dir, valor);
    }
    return NULL;
}

raiz *buscarDescendente(raiz *node){
    while(node->esq != NULL || node->dir != NULL){
        node->bal = altura(node->esq)-altura(node->dir);
        if(node->bal == 0) break;
        else if(node->bal > 0) node = node->esq;
        else node = node->dir;
    }
    return node;
}

raiz *insere(raiz *l, int valor){
    if(l == NULL){
        l = malloc(sizeof(raiz));
        l->valor = valor;
        l->esq = NULL;
        l->dir = NULL;
        l->bal = altura(l->esq)-altura(l->dir);
        return l;
    }
    else if(valor <= l->valor){
        l->esq = insere(l->esq, valor);
        l->bal = altura(l->esq)-altura(l->dir);
    }
    else{
        l->dir = insere(l->dir, valor);
        l->bal = altura(l->esq)-altura(l->dir);
    }
    return l;
}

raiz *balancear(raiz *l, raiz *node){
    node->bal = altura(node->esq)-altura(node->dir);
    node = buscarPai(l, node->valor);
    raiz *p = buscarPai(l, node->valor);
    //É necessário se percorrer a àrvore a partir do pai do nó qual se deseja rotacionar
    //pois quando houver rotação o nó pai terá que apontar para seu novo nó filho
    while(1){
        node->bal = altura(node->esq)-altura(node->dir);
        if(node->bal >= 2){
            if(node->esq != NULL){
                if(node->esq->bal >= 0){
                    if(p == node) p = rotacionaDir(node);
                    else if(p->esq == node) p->esq = rotacionaDir(node);
                    else p->dir = rotacionaDir(node);
                }
                else{
                    node->esq = rotacionaEsq(node->esq);
                    if(p == node) p = rotacionaDir(node);
                    else if(p->esq == node) p->esq = rotacionaDir(node);
                    else p->dir = rotacionaDir(node);
                }
            }
            else node->esq = rotacionaDir(node->esq);
        }
        else if(node->bal <= -2){
            if(node->dir != NULL){
                if(node->dir->bal <= 0){
                    if(p == node) p = rotacionaEsq(node);
                    else if(p->esq == node) p->esq = rotacionaEsq(node);
                    else p->dir = rotacionaEsq(node);
                }
                else{
                    node->dir = rotacionaDir(node->dir);
                    if(p == node) p = rotacionaEsq(node);
                    else if(p->esq == node) p->esq = rotacionaEsq(node);
                    else p->dir = rotacionaEsq(node);
                }
            }
            else node->esq = rotacionaDir(node->esq);
        }
        if(node == l) break;
        node = p;
        p = buscarPai(l, p->valor);
    }
    return p;
}

raiz *remover(raiz *l, int valor){
    raiz *p = buscarPai(l, valor);
    if(p == NULL) return NULL;
    else if(p->valor == valor) l = removerNode(p);
    else if(p->esq->valor == valor) p->esq = removerNode(p->esq);
    else p->dir = removerNode(p->dir);
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
        p->bal = altura(p->esq)-altura(p->dir);
    }
    f->esq = node->esq;
    f->bal = altura(f->esq)-altura(f->dir);
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