#include <stdio.h>
#include <stdlib.h>
#include "headLista.h"

node *insereOrdenado(node *l, int valor){
    node *lista;
    lista = l;
    node *anterior;
    anterior = lista->before;
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->value = valor;
    newNode->before = NULL;
    newNode->next = NULL;

    if(lista == NULL){
        lista = newNode;
        return lista;
    }

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
    }
    while(lista != NULL){
        if (lista->value == value){
            printf("O item está na posicao %i\n", index+1);
            break;
        }
        else if (lista->value != value && lista->next == NULL){
            printf("O item nao esta na lista.\n");
            break;
        }
        index++;
        lista = lista->next;
    }
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
}