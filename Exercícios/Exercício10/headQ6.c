#include <stdio.h>
#include <stdlib.h>

#include "headQ6.h"


node *insere(node *l, int valor){
    node *p;
    node *new;
    new = (node *)malloc(sizeof(node));
    p = l;
    new->number = valor;
    new->next = NULL;
    if (p == NULL) return new;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = new;
    return l;
}

node *remover(node *l, int position){
    node *p;
    node *a;
    p = l;
    if (p == NULL){
        printf("Lista vazia.\n");
        return l;
    }
    for (int i = 0; i < position; i++)
    {
        if(p->next == NULL){
            printf("Posicao inexistente.\n");
            return l;
        }
        a = p;
        p = p->next;
    }
    a->next = p->next;
    free(p);
    return l;
}

node *split(node *l){
    node *p;
    node *p1;
    node *p2;
    if(l != NULL && l->next == NULL) return l;
    p1 = l;
    p = l;
    if(l != NULL) p2 = l->next;
    else p2 = NULL;
    while(p2 != NULL && p2->next != NULL){
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p = p1->next;
    p1->next = NULL;
    return p;
}

node *merge(node *l1, node *l2){
    if(l1 == NULL && l2 == NULL) return NULL;
    else if(l1 == NULL) return l2;
    else if(l2 == NULL) return l1;
    node *lista;
    lista = l1;
    while(lista->next != NULL) lista = lista->next;
    lista->next = l2;
    return l1;
}

node *truque(node *l){
    int resposta;
    node *lista;
    lista = l;
    while(lista->next != NULL) lista = lista->next;
    resposta = lista->number;
    node *l1;
    node *l2;
    l1 = l;
    l2 = split(l);
    l = merge(l2, l1);
    node *l3;
    node *l4;
    l1 = l;
    l3 = split(l);
    l2 = split(l1);
    l4 = split(l3);
    node *newList;
    newList = merge(merge(l4, l3), merge(l2, l1));
    lista = newList;
    l1 = newList;
    l2 = split(l1);
    while(lista->next != NULL) lista = lista->next;
    int k = lista->number;
    newList = merge(l1, l2);
    lista = newList;
    for(int i = 0; i < k; i++) lista = lista->next;
    printf("%i, ", lista->number);
    if(lista->number == resposta) printf("acertou.\n");
    else printf("errou.\n");
    return newList;
}

void imprimir(node *l){
    node *p;
    p = l;
    if (p == NULL){
        printf("Lista vazia.\n");
        return;
    }
    while(p != NULL){
        printf("%i ", p->number);
        p = p->next;
    };
    printf("\n");
}