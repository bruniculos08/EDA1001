#include <stdio.h>
#include <string.h>
#include "headQ3.h"
#include <stdlib.h>


number *end(number *n) {
    if (n == NULL) return n;
    while(n->next != NULL){
        n = n->next;
    }
    return n;
}

int numberSize(number *n) {
    number *l;
    l = n;
    if(l == NULL) return 0;
    int i = 0;
    while(l != NULL) {
        i++;
        l = l->next;
    }
    return i;
}

int numberSizeDot(number *n){
    number *l;
    if(l == NULL) return 0;
    int i = 0, h = 0;
    while(l != NULL) {
        if(h == 1){
            i++;
        }
        if(l->digit == 20) {
            h = 1;
        }
        l = l->next;
    }
    return i;
}
//^ ir até o final da lista e ir somando andando devolta para o início.
head *soma(head *n1, head *n2){
    int aux;
    int size;
}