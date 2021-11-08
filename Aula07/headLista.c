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
        else if(lista->value > valor && lista->before == NULL){
            lista->before = newNode;
            newNode->next = lista;
            return newNode;
        }
        else if(lista->value > valor && lista->before->value < valor){
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