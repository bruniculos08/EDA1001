#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *vector;

void aumentaVetor(int *vetor){
    int n = sizeof(*vetor)/sizeof(int) + 1;
    vetor = realloc(vetor, n*sizeof(int));
    scanf("%d", &vetor[n]);
}

void diminuiVetor(int *vetor, int position){

}

void imprimeVetor(int *vetor){
    for (int i = 0; i < sizeof(*vetor); i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    
    int tamanhoInicial, option, position = 0;
    printf("Type the inicial size: ");
    scanf("%d", &tamanhoInicial);
    int vetor[tamanhoInicial];

    for (int i = 0; i < tamanhoInicial; i++){
        scanf("%d", &vetor[i]);
    }

    do { 
        printf("Choose an option:\n[1] plus 1 number in the vector\n[2] less 1 number in the vector\n[3] print all\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                aumentaVetor(vetor);
                continue;
            case 2:
                diminuiVetor(vetor, position);
                continue;
            case 3:
                imprimeVetor(vetor);
                continue;
            case 0:
                break;
            default:
                printf("Type a valid option\n");
                continue; 
        }
    } while (option != 0);
}