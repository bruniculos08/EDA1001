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

nodo *trocaNodo(nodo *l, nodo *l1, nodo *l2){
    nodo *aux;
    aux = l;
    nodo *a1;
    a1 = NULL;
    nodo *a2;
    a2 = NULL;
    nodo *a;
    a = NULL;
    if (l1 == NULL || l2 == NULL){
        printf("Ponteiros inválidos.\n");
        return l;
    }
    else if (l1 == l2) {
        printf("Ponteiros iguais.\n");
        return l;
    }
    while(aux != NULL){
        if (aux->prox == l1){
            printf("1");
            a1 = aux;
        }
        else if (aux->prox == l2){
            printf("2");
            a2 = aux;
        }
        else if (aux == l1 && a == NULL){
            printf("3");
            a1 = NULL;
        }
        else if (aux == l2 && a == NULL){
            printf("4");
            a2 = NULL;
        }
        a = aux;
        aux = aux->prox;
    }
    aux = l1->prox;
    if(a1 != NULL && a1 != l2) a1->prox = l2;
    if (l2->prox != l1) l1->prox = l2->prox;
    else l1->prox = l2;
    if(a2 != NULL && a2 != l1) a2->prox = l1;
    if (aux != l2) l2->prox = aux;
    else l2->prox = l1;
    
    if(a1 == NULL) return l2;
    if(a2 == NULL) return l1;
    return l;
}