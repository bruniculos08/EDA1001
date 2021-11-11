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
    if (p == NULL) return new;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = new;
    return l;
}

nodo * insere_ordenado(nodo *l, int valor){
    nodo *p;
    nodo *newNode;
    newNode = (nodo *)malloc(sizeof(nodo));
    p = l;
    newNode->dado = valor;
    newNode->prox = NULL;
    if (p == NULL) return newNode;
    if (p->dado >= newNode->dado){
        newNode->prox = p;
        return newNode;
    }
    while(p->prox != NULL){
        if(p->dado <= newNode->dado && p->prox->dado >= newNode->dado){
            newNode->prox = p->prox;
            p->prox = newNode;
            return l;
        }
        p = p->prox;
    }
    p->prox = newNode;
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
    p = NULL;
    //p = (nodo *)malloc(sizeof(nodo));
    //printf("\nDigite o dado do primeiro nodo: ");
    //scanf("%i", &p->dado);
    //p->prox = NULL;
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
    if (p == NULL){
        printf("Lista vazia.\n");
        return l;
    }
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

nodo *ponteiro(nodo *l, int position){
    nodo *lista;
    lista = l;
    for (int i = 1; i < position; i++){
        if (lista == NULL){
            printf("Lista vazia ou sem tamanho para posicao inserida.\n");
            return l;
        }
        lista = lista->prox;
    }
    return lista;
}

nodo *troca(nodo *l, nodo *trocaNodo) {
    printf("11\n");
    nodo *lista;
    nodo *anterior;
    nodo *aux;
    lista = l;
    anterior = NULL;
    aux = NULL;
    if (lista == NULL){
        printf("Lista vazia.\n");
        return NULL;
    }
    while (lista != NULL){
        if (lista == trocaNodo && anterior == NULL) {
            printf("1\n");
            aux = lista->prox->prox;
            anterior = lista->prox;
            lista->prox->prox = lista;
            lista->prox = aux;
            return anterior;
        }
        else if (lista == trocaNodo && lista->prox == NULL){
            printf("2\n");
            anterior->prox = NULL;
            free(lista);
            return l;
        }
        else if (lista == trocaNodo){
            printf("3\n");
            anterior->prox = lista->prox;       //^ anterior aponta pra quem está na frente
            lista->prox = lista->prox->prox;    //^ lista aponta para o proximo do que esta na frente
            anterior->prox->prox = lista;       //^ o que estava na frente agora aponta para lista
            return l;
        }
        anterior = lista;
        lista = lista->prox;
    }
}