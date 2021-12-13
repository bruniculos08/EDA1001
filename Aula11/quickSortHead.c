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
    while(last->next != NULL) last = last->next;
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
    }
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
    return p;
}

node *merge(node *l1, node *l2){
    node *last;
    last = l1;
    while(last->next != NULL) last = last->next;
    last->next = l2;
    return l1;
}

node *half(node *l, node *r){
    node *p;
    p = split(l);
    node *a;
    a = l;
    node *b;
    node *last1;
    last1 = NULL;
    node *last2;
    while(a != NULL && a != p){
        if(a->number > p->number){
            b = a;
            a = a->next;
            l = moveFinal(l, b);
        }
        else a = a->next;
    }
    if(a == p) a = a->next;
    while(a != NULL){
        if(a->number < p->number){
            b = a;
            a = a->next;
            l = moveInicio(l, b);
        }
        else a = a->next;
    }
    b = NULL;
    b = p->next;
    p->next = NULL;
    *r = *l;
    free(l);
    if(b == NULL){
        last1 = r;
        while(last1 != p && last1->next != p){
            last1 = last1->next;
        }
        last1->next = NULL;
        return p;
    }
    return b;
}

node *quickSort(node *l){
    node *p;
    node *r;
    r = (node *)malloc(sizeof(node));
    r->next = NULL;
    if(l != NULL && l->next != NULL){
        p = half(l, r);
        //printf("l %i\n", l->number);
        l = r;
        imprime(r);
        imprime(p);
        l = quickSort(l);
        p = quickSort(p);
        //if(l->next == NULL) printf("l->next NULL.\n");
        //if(p->next == NULL) printf("p->next NULL.\n");
        //l = merge(l, p);
        //imprime(l);
        //imprime(p);
        l = merge(l, p);
    }
    //else printf("l ou l->next NULL.\n");
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