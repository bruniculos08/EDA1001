#include "mergeSortHead.h"
#include <stdio.h>
#include <stdlib.h>

node *insere_fim(node *l, int valor){
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

node *insere_ordenado(node *l, int valor){
    node *p;
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    p = l;
    newNode->number = valor;
    newNode->next = NULL;
    if (p == NULL) return newNode;
    if (p->number >= newNode->number){
        newNode->next = p;
        return newNode;
    }
    while(p->next != NULL){
        if(p->number <= newNode->number && p->next->number >= newNode->number){
            newNode->next = p->next;
            p->next = newNode;
            return l;
        }
        p = p->next;
    }
    p->next = newNode;
    return l;
}

int profundidade(node *l, int valor){
    node *p;
    int size = 0;
    p = l;
    if (p == NULL) return -1;                           //^ lista vazia
    while(p->next != NULL && valor != p->number){         //^ percorre lista
        p = p->next;
        size += 1;
    }
    if (p->next == NULL && valor != p->number) return -1; //^ não há o elemento na lista
    return size+1;
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

node *inicializa(){
    node *p;
    p = NULL;
    //p = (node *)malloc(sizeof(node));
    //printf("\nDigite o number do primeiro node: ");
    //scanf("%i", &p->number);
    //p->next = NULL;
    return p;
}

int conta_nos(node *l){
    node *p;
    p = l;
    if (p == NULL) return 0;
    int n = 0;
    while (p->next != NULL) {
        n += 1;
        p = p->next;
    }
    return n;
}

node *liberar(node *l){
    node *p;
    node *a;
    p = l;
    if (p == NULL) return NULL;
    while (p->next != NULL) {
        a = p;
        p = p->next;
        free(a);
    }
    free(p);
    return NULL;
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

node *ponteiro(node *l, int position){
    node *lista;
    lista = l;
    for (int i = 1; i < position; i++){
        if (lista == NULL){
            printf("Lista vazia ou sem tamanho para posicao inserida.\n");
            return l;
        }
        lista = lista->next;
    }
    return lista;
}

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
        p = p1->next;
    }
    p1->next = NULL;
    return p;
}

node *merge(node *lista1, node *lista2){
    node *l;
    node *new;
    node *a;
    l = (node *)malloc(sizeof(node));
    new = l;
    while(lista1 != NULL && lista2 != NULL){
        if(lista1->number <= lista2->number){
            new->number = lista1->number;
            a = lista1;
            lista1 = lista1->next;
            free(a);
        }
        else{
            new->number = lista2->number;
            a = lista2;
            lista2 = lista2->next;
            free(a);
        }
        new = new->next;
    }
    if(lista1 == NULL) new = lista2;
    else new = lista1;
    return l;
}

node *mergeSort(node *l){
    node *l1;
    node *l2;
    node *sortedNew;
    if(l == NULL || l->next == NULL) return l;
    l1 = l;
    l2 = split(l);
    sortedNew = merge(l1, l2);
    return sortedNew;
}