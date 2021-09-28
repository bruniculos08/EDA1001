#include <stdio.h>
#include <math.h>

int main(void) {
    int valor, numeroNotas[7], resto, n;
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    do
    {
        scanf("%d", &valor);
    } while (valor > 1000000 || valor < 0);
    for (int i = 0; i < 7; i++)
    {
        //printf("%i\n", valor);
        resto =  floor(valor%notas[i]);
        numeroNotas[i] = floor((valor)/notas[i]);
        valor = resto;        
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d nota(s) de  R$ %d,00\n", numeroNotas[i], notas[i]);
    }
}