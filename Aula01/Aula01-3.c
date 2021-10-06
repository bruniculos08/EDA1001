#include <stdio.h>


typedef struct funcionario {
    double codigo, salario;
    char nome[40];
} Funcionario;

double maiorSalario(Funcionario vetor[]){
    double maior = 0;
    int n = sizeof(*vetor)/sizeof(Funcionario);
    for (int i = 0; i < n; i++)
    {
        if (maior < vetor[i].salario)
        {
            maior = vetor[i].salario;
        }
    }
    return maior;
}

int main(){
    Funcionario vetor[6];
}