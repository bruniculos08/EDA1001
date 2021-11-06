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
    }
}