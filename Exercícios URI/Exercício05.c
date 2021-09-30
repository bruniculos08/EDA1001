#include <stdio.h>
#include <math.h>

int main(void) {
    double vetor[100];
    scanf("%lf", &vetor[0]);
    printf("N[0] = %.4f\n",vetor[0]);
    for (int i = 1; i < 100; i++) {
        vetor[i] = vetor[i-1]/2;
        printf("N[%d] = %.4lf\n", i, vetor[i]);
    }
}