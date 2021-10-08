#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct funcionario {
    double salario;
    int codigo;
    char nome[40];
} Funcionario;

Funcionario *vetor;
int n;

int maiorSalario(){
    double maior = 0;
    int position = 0;
    for (int i = 0; i < n; i++)
    {
        if (maior < vetor[i].salario)
        {
            position = i;
        }
    }
    return position;
}

int menorSalario(){
    double menor = vetor[0].salario;
    int position = 0;
    for (int i = 0; i < n; i++)
    {
        if (menor > vetor[i].salario)
        {
            position = i;
        }
    }
    return position;
}

double mediaSalario(){
    double media = 0;
    for (int i = 0; i < n; i++)
    {
        media += (vetor[i].salario/n);
    }
    return media;
}

void imprimeDados(){
    int position;
    printf("Type the position of the employee: ");
    scanf("%i", &position);
    printf("Name: %s\n", vetor[position].nome);
    printf("Wage: %lf\n", vetor[position].salario);
    printf("Code: %i\n", vetor[position].codigo);
}

void imprimeTodos(){
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", (vetor+i)->nome);
        printf("Wage: %lf\n", vetor[i].salario);
        printf("Code: %i\n", vetor[i].codigo);
    }
}

void inserirFuncionario() {
    n = n+1;
    vetor = realloc(vetor, n*sizeof(int));
    printf("New employee\n");
    printf("Type the wage of the employee %i: ", n-1);
    scanf("%lf", &(vetor+n-1)->salario);
    printf("Type the code of the employee %i: ", n-1);
    scanf("%i", &(vetor+n-1)->codigo);
    printf("Type the name of the employee %i: ", n-1);
    scanf("%s", (vetor+n-1)->nome); 
}

int main(){    
    int option, flag = 1, position;
    double average;
    
    do {
        printf("Choose an option:\n[0] Exit\n[1] return the vector position of the employee with the biggest wage\n[2] return the vector position of the employee with the smallest wage\n[3] print the date of the employee acording to his position in the vector\n[4] return the average wage of the employees\n[5] print the data of all the employees\n[6] include new employee\n[7] insert employees into the vector\n");
        scanf("%d", &option);
        
        switch(option) {
            case 0: 
                break;
            case 1: 
                printf("%d\n", maiorSalario());
                continue;
            case 2: 
                printf("%d\n", menorSalario());
                continue;
            case 3: 
                imprimeDados();
                continue;
            case 4: 
                printf("%lf\n", mediaSalario());
                continue;
            case 5: 
                imprimeTodos();
                continue;
            case 6:
                inserirFuncionario();
                continue;
            case 7:
                if (flag == 0)
                {
                    printf("You already have created the vector. To include or remove choose the options 6 and 8 respectively.\n");
                    continue;
                }
                printf("Type the number of employees in the vector\n");
                scanf("%i", &n);
                vetor = malloc(n*sizeof(Funcionario));
                for (int i = 0; i < n; i++){
                    printf("Type the wage of the employee %i: ", i);
                    scanf("%lf", &(vetor+i)->salario);
                    printf("Type the code of the employee %i: ", i);
                    scanf("%i", &(vetor+i)->codigo);
                    printf("Type the name of the employee %i: ", i);
                    //fflush(stdin);                                      //* limpa o buffer do teclado(stdin)
                    //fgets(vetor[i].nome, sizeof(vetor[i].nome), stdin); //* fgets(ponteiro da variável, tamanho máximo, origem)
                    scanf("%s", (vetor+i)->nome);                        //* stdin se refere ao teclado
                }
                flag = 0;
            case 8:

            default:
                printf("This option does not exist. Type a valid option.\n");
                break;
        }
    } while(option != 0);
}