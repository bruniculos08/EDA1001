#include <stdio.h>
#include <stdlib.h>
#include "headLista.h"

node *insereOrdenado(node *l, int valor){
    node *lista;
    lista = l;
    node *anterior;
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->value = valor;
    newNode->before = NULL;
    newNode->next = NULL;

    if(lista == NULL){
        lista = newNode;
        return lista;
    }
    anterior = lista->before;
    while(lista != NULL){
        if(lista->value < valor && lista->next == NULL){
            lista->next = newNode;
            newNode->before = lista;
            return l;
        }
        else if(lista->value >= valor && lista->before == NULL){
            newNode->next = lista;
            lista->before = newNode;
            return newNode;
        }
        else if(lista->value > valor && lista->before == NULL){
            lista->before = newNode;
            newNode->next = lista;
            return newNode;
        }
        else if(lista->value >= valor && lista->before->value <= valor){
            newNode->before = lista->before; 
            lista->before->next = newNode;
            lista->before = newNode;
            newNode->next = lista;
            return l;
        }
        lista = lista->next;
    }
    return l;
}

void buscar(node *l, int value){
    node *lista;
    int index = 0;
    lista = l;
    if (lista == NULL){
        printf("Lista vazia.\n");
        return;
    }
    while(lista != NULL){
        if (lista->value == value){
            printf("O item esta na posicao %i\n", index+1);
            break;
        }
        else if (lista->value != value && lista->next == NULL){
            printf("Item nao encontrado.\n");
            break;
        }
        index++;
        lista = lista->next;
    }
    imprime(l);
}

node *atualizar(node *l, int newValue, int posiList){
    node *lista;
    lista = l;
    if (lista == NULL){
        printf("Lista vazia.\n");
        return l;
    }
    for(int i=1; i < posiList; i++){
        lista = lista->next;
        if (lista == NULL){
            printf("Posicao inexistente.\n");
            return l;
        }
    }
    l = remover(l, lista->value);
    l = insereOrdenado(l, newValue);
    return l;
}

node *remover(node *l, int removedValue){
    node *lista;
    lista = l;
    if (lista == NULL){
        printf("Lista vazia.\n");
        return l;
    }
    while(lista != NULL){
        if (lista->value == removedValue && lista->before == NULL && lista->next == NULL){
            return NULL;
        }
        else if (lista->value == removedValue && lista->before == NULL){
            lista = lista->next;
            free(lista->before);
            lista->before = NULL;
            return lista;
        }
        else if(lista->value == removedValue && lista->next == NULL){
            lista = lista->before;
            free(lista->next);
            lista->next = NULL;
            return l;
        }
        else if(lista->value == removedValue){
            lista = lista->before;
            lista->next = lista->next->next;
            free(lista->next->before);
            lista->next->before = lista;
            return l;
        }
        lista = lista->next;
    }
    printf("Item não encontrado.\n");
    return l;
}

void imprime(node *l){
    node *lista;
    lista = l;
    if(lista == NULL){
        printf("Lista vazia.\n");
        return;
    }
    while(lista != NULL){
        printf("%i ", lista->value);
        lista = lista->next;
    }
    printf("\n");
}

node *ponteiro(node *l, int position){
    node *lista;
    lista = l;
    for(int i = 1; i < position; i++){
        if(lista == NULL){
            printf("Lista vazia ou sem tamanho para a posicao inserida.\n");
            return l;
        }
        lista = lista->next;
    }
    return lista;
}

node *trocaNodo(node *l, node *l1, node *l2){
    node *aux;
    aux = (node *)malloc(sizeof(node));
    aux->next = l1->next;
    aux->before = l1->before;
    if(l1 == l2) return l;
    else if(l1->next != l2 && l2->next != l1){
        l1->before = l2->before;
        l1->next = l2->next;
        if(l1->before != NULL) l1->before->next = l1;
        if(l1->next != NULL) l1->next->before = l1; 
        l2->before = aux->before;
        l2->next = aux->next;
        if(l2->before != NULL) l2->before->next = l2;
        if(l2->next != NULL) l2->next->before = l2;
    }
    else if(l1->next == l2){
        l1->before = l2;
        l1->next = l2->next;
        if(l1->before != NULL) l1->before->next = l1;
        if(l1->next != NULL) l1->next->before = l1;
        l2->before = aux->before;
        l2->next = l1;
        if(l2->before != NULL) l2->before->next = l2;
        if(l2->next != NULL) l2->next->before = l2;
    }
    else if(l2->next == l1){
        l1->before = l2->before;
        l1->next = l2;
        if(l1->before != NULL) l1->before->next = l1;
        if(l1->next != NULL) l1->next->before = l1;
        l2->before = l1;
        l2->next = aux->next;
        if(l2->before != NULL) l2->before->next = l2;
        if(l2->next != NULL) l2->next->before = l2;
    }
    if(l1->before == NULL) return l1;
    if(l2->before == NULL) return l2;
    return l;
}