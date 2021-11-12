#include <stdio.h>
#include <stdlib.h>
#include "poliHead.h"
#include <math.h>


void mostrar(polinomio *p){
    polinomio *l;
    l = p;
    if(l == NULL){
        printf("0\n");
        return;
    }
    while(l != NULL){
        printf("%d.x^%i ", l->a, l->b);
        l = l->prox;
        if(l != NULL) printf("+ ");
    }
    printf("\n");
}

float calcular(polinomio *p, float x){
    if (p == NULL) return 0;
    float resultado = 0;
    while(p != NULL){
        resultado = resultado + (p->a)*(pow(x, p->b));
        p = p->prox;
    }
    return resultado;
}