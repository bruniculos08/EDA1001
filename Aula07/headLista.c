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
    if(lista == NULL){
        lista->value = valor;
        lista->before = NULL;
        lista->next = NULL;
        return lista;
    }
    while(lista != NULL){
        if(lista->value < valor && lista->next == NULL){
            
        }
    }
}