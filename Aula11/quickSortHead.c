#include <stdio.h>
#include <stdlib.h>

#include "quickSortHead.h"


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
    if(l == NULL || v == NULL) return l;
    node *a;
    a = l;
    while(a != v && a->next != v) a = a->next;
    if(a->next == v){
        a->next = v->next;
        v->next = l;
        return v;
    }
    return l;
}

node *moveFinal(node *l, node *v){
    if(l == NULL || v == NULL) return l;
    node *a;
    node *last;
    a = l;
    last = l;
    while(l->next != NULL) l = l->next;
    while(a != v && a->next != v) a = a->next;
    if(a == v){
        l = l->next;
        v->next = NULL;
        last->next = v;
    }
    if(a->next == v){
        a->next = v->next;
        last->next = v;
        v->next = NULL;
        return l;
    }
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
    node *last;
    last = l1;
    while(last->next != NULL) last = last->next;
    last->next = l2;
    return l1;
}

node *quickSort(node *l, node *p){
    //p->next = NULL;
    if(l->next == NULL) return l;
    node *v;
    node *vNew;
    node * newL;
    v = l;
    vNew = NULL;
    printf("%i\n", p->number);
    while(v != NULL && v != p){
        if(v->number > p->number){
            printf("Movendo para o final.\n");
            vNew = v->next;
            l = moveFinal(l, v);
            v = vNew;
        }
        if(v != p) v = v->next;
    }
    if(v == p) v = v->next;
    vNew = p;
    while(v != NULL){
        if(v->number < p->number){
            printf("Movendo para o inicio.\n");
            l = moveInicio(l, v);
            v = vNew->next;
        }
        vNew = v;
        v = v->next;
    }
    printf("Fim de quick sort.\n");
    newL = p->next;
    p->next = NULL;
    l = quickSort(l, split(l));
    newL = quickSort(newL, split(newL));
    l = merge(l, newL);
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

node *limpar(node *l){
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