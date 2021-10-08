#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *vetor;
int n;

void aumentaVetor(){
    n = n+1;
    vetor = realloc(vetor, n*sizeof(int));
    scanf("%d", &vetor[n-1]);
}

void diminuiVetor(int position){

}

void imprimeVetor(){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int tamanhoInicial, option, position = 0;
    printf("Type the inicial size: ");
    scanf("%d", &tamanhoInicial);
    n = tamanhoInicial;
    vetor = malloc(tamanhoInicial*sizeof(int));

    for (int i = 0; i < tamanhoInicial; i++){
        scanf("%d", &vetor[i]);
    }

    do { 
        printf("Choose an option:\n[1] plus 1 number in the vector\n[2] less 1 number in the vector\n[3] print all\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                aumentaVetor();
                continue;
            case 2:
                diminuiVetor(position);
                continue;
            case 3:
                imprimeVetor();
                continue;
            case 0:
                break;
            default:
                printf("Type a valid option\n");
                continue; 
        }
    } while (option != 0);
}