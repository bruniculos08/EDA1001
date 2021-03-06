#include <stdio.h>
#include <stdlib.h>
#include "HeadListaEncadeada.h"



lista *newList(int n){ //^ retorna o endereço de um novo elemento da lista (new)
    lista *new;
    new = (lista *)malloc(sizeof(lista)); //^ new se torna endereço de uma memória alocada
    new->number = n;
    new->next = NULL;
    return new;       //^ retorna o endereço de um novo elemento da lista (new)                                            
} 

lista *insertEnd(lista *totalList, lista *newList){ //^ iremos retornar o endereço da própria lista por garantia
    lista *p;
    lista *a;
    p = totalList;
    if (totalList != NULL)
    {
        while (p->next != NULL){    //todo: perguntar por que quando usa-se p != NULL e após o while
                                    //todo: usa-se p = newList há erro
            p = p->next;
            //^ Note que há a atribuição entre uma varíavel que guarda um endereço (p)
            //^ e uma que "guarda" um conteúdo (totalList->next) que é possível
            //^ pois este conteúdo armazenado é um endereço (next é um endereço,...
            //^ ... o que é diferente de *next nesta situação).
        }; 
        p->next = newList; 
        //^ o ponteiro *next do penúltimo elemento da lista irá apontar para o mais
        //^ novo elemento da lista, ou seja, a variável (de endereço) next do
        //^ penúltimo elemento da lista recebe o endereço do último elemento da lista
    }
    else {
        totalList = newList;
        //? caso a lista passada esteja vazia ela então apontará para a nova lista
    }

    return totalList;
    //^ retorna o endereço da própria lista para garantia
}

lista *insertOrder(lista *totalList, lista *newList) {
    lista *p1;
    lista *a;
    p1 = totalList;
    a = NULL;

    while (p1 != NULL){
        if (p1->number <= newList->number && p1->next == NULL){ //^ fim da lista

            p1->next = newList;
            return totalList;
        }
        else if (p1->number <= newList->number && p1->next->number >= newList->number){ //^ entre dois termos
            newList->next = p1->next;
            p1->next = newList;
            return totalList;
        }
        else if (p1->number >= newList->number && a == NULL){ 
            newList->next = p1;
        }
        a = p1;
        p1 = p1->next; 
    };

    return newList; //^ se a lista estiver vazia irá retornar uma lista com apenas o novo elemento
}

lista *insertStart(lista *totalList, lista *newList) {
    newList->next = totalList;
    return newList;
}

lista *removeLista(lista *totalList, int n){
    lista *p = totalList;
    lista *a;
    a = NULL;
    while(p->next != NULL && p->number != n){
        a = p;
        p = p->next;
    }
    if (a == NULL){
        a = p;
        p = p->next;
        free(a);
        return p;
    }
    else {
        a->next = p->next;
        free(p);
        return totalList;
    }
}

int posiList (lista *totalList, int n){
    lista *p = totalList;
    int position = 0;
    while(p->next != NULL && p->number != n){
        position = position + 1;
        p = p->next;
    }
    if (p->next == NULL && p->number != n) return -1; //^ número não encontrado
    
    return position+1;
}

void printAllList(lista *totalList) {
    lista *p;
    p = totalList;
    while (p != NULL) {
        printf("%d-", p->number);
        p = p->next;
    };
}

int tamanhoLista(lista *totalList) {
    int n = 0;
    lista *p;
    p = totalList;
    while (p != NULL) {
        n = n + 1;
        p = p->next;
    }
    return n;
}