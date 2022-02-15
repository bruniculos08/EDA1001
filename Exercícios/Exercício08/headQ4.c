#include <stdio.h>
#include <stdlib.h>

#include "headQ4.h"


voto *insere(voto *l, char candidato[], int valor){
    voto *p;
    voto *new;
    new = (voto *)malloc(sizeof(voto));
    p = l;
    new->hora = valor;
    new->candidato = candidato;
    new->next = NULL;
    if (p == NULL) return new;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = new;
    return l;
}

voto *split(voto *l){
    voto *p;
    voto *p1;
    voto *p2;
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

voto *merge(voto *l1, voto *l2){
    voto *sortedNew;
    voto *a;
    a = NULL;
    sortedNew = NULL;
    while(l1 != NULL && l2 != NULL){
        if(l1->hora <= l2->hora){
            sortedNew = insere(sortedNew, l1->hora);
            a = l1;
            l1 = l1->next;
            free(a);
        }
        else{
            sortedNew = insere(sortedNew, l2->hora);
            a = l2;
            l2 = l2->next;
            free(a);
        }
    }
    while(l1 != NULL){
        sortedNew = insere(sortedNew, l1->hora);
        l1 = l1->next;
    }
    while(l2 != NULL){
        sortedNew = insere(sortedNew, l2->hora);
        l2 = l2->next;
    }
    return sortedNew;
}

voto *mergeSort(voto *l){
    voto *l1;
    voto *l2;
    voto *middle;
    voto *sortedNew;
    if(l == NULL || l->next == NULL) return l;
    middle = split(l);
    l1 = mergeSort(l);
    l2 = mergeSort(middle);
    //imprimir(l1);
    //imprimir(l2);
    sortedNew = merge(l1, l2);
    return sortedNew;
}