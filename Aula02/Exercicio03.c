#include <stdio.h>


int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%i",&n);
    int v[n];

    for (int i = 0; i < n; i++)
    {
        if(i%2 == 0) v[i] = 0;
        else v[i] = 1;
    }
    
    for (int i = 0; i < n; i++) printf("v[%i] = %i\n", i, v[i]);
}