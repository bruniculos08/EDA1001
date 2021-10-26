//* Listas simplemente encadeadas
#include <stdio.h>
#include <stdlib.h>
#include "HeadListaEncadeada.h"


int main() {
    lista *totalList;
    totalList = (lista *)malloc(sizeof(lista));
    totalList->number = 2;
    totalList->next = NULL;

    totalList = insertEnd(totalList, newList(3));
    printAllList(totalList);
    printf("\ntamanho da lista = %i\n", tamanhoLista(totalList));

    totalList = insertStart(totalList, newList(1));
    printAllList(totalList);
    printf("\ntamanho da lista = %i\n", tamanhoLista(totalList));

    totalList = insertOrder(totalList, newList(2));
    printAllList(totalList);
    printf("\ntamanho da lista = %i\nposition number 5 = %i\n", tamanhoLista(totalList), posiList(totalList,5));

    totalList = insertOrder(totalList, newList(0));
    printf("remove 1 e insere 0\n");
    totalList = removeLista(totalList, 1);
    printAllList(totalList);
    printf("\ntamanho da lista = %i\nposition number 5 = %i", tamanhoLista(totalList), posiList(totalList,5));
}