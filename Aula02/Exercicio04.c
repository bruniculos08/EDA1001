#include <stdio.h>


void valores(int vetor[], int *max, int *min, int n){
    int a = vetor[0], b = vetor[0];
    for(int i = 1; i < n; i++){
        if (a < vetor[i]) a = vetor[i];
        if (b > vetor[i]) b = vetor[i];
    }
    *max = a;
    *min = b;
}

int main(){
    int max, min, n;
    printf("Digite o tamanho do vetor: ");
    scanf("%i",&n);
    int vetor[n];
    for(int i = 0; i < n; i++) {
        printf("Digite o valor da posicao %i: ", i);
        scanf("%i",&vetor[i]);
    }
    valores(vetor, &max, &min, n);
    printf("Valor maximo = %i\nValor minimo = %i\n", max, min);
}