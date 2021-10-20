#include <stdio.h>
#include "ponto.h"

//* Tipos de dados abstratos

int main(void){
	Ponto *p1,*p2;
	p1=cria(2.0,3.0);
	p2=cria(2.5,-1.0);
	printf("Distancia: %f", distancia(p1,p2));
}