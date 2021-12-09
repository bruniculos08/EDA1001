#include <stdio.h>
#include <stdlib.h>

#include "quickSortHead.h"


node *trocanode(node *l, node *l1, node *l2){
    node *aux;
    aux = l;
    node *a1;
    a1 = NULL;
    node *a2;
    a2 = NULL;
    node *a;
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
        if (aux->next == l1){
            printf("1");
            a1 = aux;
        }
        else if (aux->next == l2){
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
        aux = aux->next;
    }

    aux = l1->next;
    if(a1 != NULL && a1 != l2) a1->next = l2;
    if (l2->next != l1) l1->next = l2->next;
    else l1->next = l2;
    if(a2 != NULL && a2 != l1) a2->next = l1;
    if (aux != l2) l2->next = aux;
    else l2->next = l1;
    if(a1 == NULL) return l2;
    if(a2 == NULL) return l1;
    return l;
}

void imprime(node *l){
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

node *moveInicio(node *l, node *v){
    
}