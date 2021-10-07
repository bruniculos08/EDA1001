#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct funcionario {
    double salario;
    int codigo;
    char nome[40];
} Funcionario;

int maiorSalario(Funcionario vetor[]){
    double maior = 0;
    int position = 0;
    int n = sizeof(*vetor)/sizeof(Funcionario);
    for (int i = 0; i < n; i++)
    {
        if (maior < vetor[i].salario)
        {
            position = i;
        }
    }
    return position;
}

int menorSalario(Funcionario vetor[]){
    double menor = vetor[0].salario;
    int position = 0;
    int n = sizeof(*vetor)/sizeof(Funcionario);
    for (int i = 0; i < n; i++)
    {
        if (menor > vetor[i].salario)
        {
            position = i;
        }
    }
    return position;
}

double mediaSalario(Funcionario vetor[]){
    double media = 0;
    int n = sizeof(*vetor)/sizeof(Funcionario);
    for (int i = 0; i < n; i++)
    {
        media += (vetor[i].salario/n);
    }
    return media;
}

void imprimeDados(Funcionario vetor[]){
    int n;
    printf("Type the position of the employee: ");
    scanf("%i", &n);
    printf("Name: %s\n", vetor[n].nome);
    printf("Wage: %lf\n", vetor[n].salario);
    printf("Code: %i\n", vetor[n].codigo);
}

void imprimeTodos(Funcionario vetor[]){
    int n = sizeof(*vetor)/sizeof(Funcionario);
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", vetor[i].nome);
        printf("Wage: %lf\n", vetor[i].salario);
        printf("Code: %i\n", vetor[i].codigo);
    }
}

Funcionario incluiFuncionario(Funcionario vetor[]){
    Funcionario novoFuncionario;
    printf("Type the name of the new employee: ");
    scanf("%s", &novoFuncionario.nome);
    printf("Type the wage of the new employee %i: ");
    scanf("%lf", &novoFuncionario.salario);
    printf("Type the code of the new employee %i: ");
    scanf("%i", &novoFuncionario.codigo);
}

int main(){
    Funcionario *vetor;
    int option, flag = 1, position;
    double average;
    do {
        printf("Choose an option:\n[0] Exit\n[1] return the vector position of the employee with the biggest wage\n[2] return the vector position of the employee with the smallest wage\n[3] print the date of the employee acording to his position in the vector\n[4] return the average wage of the employees\n[5] print the data of all the employees\n[6] include new employee\n[7] insert employees into the vector\n");
        scanf("%d", &option);
        
        switch(option) {
            case 0: 
                break;
            case 1: 
                printf("%d\n", maiorSalario(vetor));
                continue;
            case 2: 
                printf("%d\n", menorSalario(vetor));
                continue;
            case 3: 
                imprimeDados(vetor);
                continue;
            case 4: 
                printf("%lf\n", mediaSalario(vetor));
                continue;
            case 5: 
                imprimeTodos(vetor);
                continue;
            case 6:
                incluiFuncionario(vetor);
                continue;
            case 7:
                if (flag == 0)
                {
                    printf("You already have typed the vector");
                    continue;
                }
                int N; 
                printf("Type the number of employees in the vector\n");
                scanf("%i", &N);
                vetor = malloc(N*sizeof(Funcionario));
                for (int i = 0; i < N; i++){
                    printf("Type the wage of the employee %i: ", i);
                    scanf("%lf", &(vetor+i)->salario);
                    printf("Type the code of the employee %i: ", i);
                    scanf("%i", &(vetor+i)->codigo);
                    printf("Type the name of the employee %i: ", i);
                    //fflush(stdin);                                      //* limpa o buffer do teclado(stdin)
                    //fgets(vetor[i].nome, sizeof(vetor[i].nome), stdin); //* fgets(ponteiro da variável, tamanho máximo, origem)
                    scanf("%s", &(vetor+i)->nome);                        //* stdin se refere ao teclado
                }
                flag = 0;
            case 8:
                
            default:
                printf("This option does not exist. Type a valid option.\n");
                break;
        }
    } while(option != 0);
}