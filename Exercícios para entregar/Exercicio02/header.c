#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "header.h"


void mostraMenu(){
	system("cls");//limpa a tela
	printf("|      CADASTRO DE FUNCIONARIOS      |\n");
	printf("|____________________________________|\n");
	printf("|           MENU DE OPCOES           |\n");
	printf("|------------------------------------|\n");
	printf("| 1 - INSERIR VALORES NO VETOR       |\n");
	printf("| 2 - IMPRIMIR TODOS OS FUNCIONARIOS |\n");
	printf("| 3 - IMPRIMIR FUNCIONARIO DA POSICAO|\n");	
	printf("| 4 - RETORNAR POS. DO MAIOR SALARIO |\n");
	printf("| 5 - RETORNAR POS. DO MENOR SALARIO |\n");
	printf("| 6 - RETORNAR A MEDIA DOS SALARIOS  |\n");
	printf("| 7 - INCLUIR FUNCIONARIO            |\n");
	printf("| 8 - REMOVER UM FUNCIONARIO         |\n");
    printf("| 0 - SAIR                           |\n");
	printf("|------------------------------------|\n");
}

void imprimeTodos(funcionario v[]){
	int i;
	for(i=0;i<N;i++){
		printf("Pos %i:\n",i);
		printf("Codigo: %d\n",v[i].cod);
		printf("Nome: %s\n",v[i].nome);
		printf("Salario: %.2f\n",v[i].salario); //%.2f fara imprimir duas casas decimais depois da virgula
	}
}

void imprimePos(funcionario v[], int pos){
	printf("Pos %i:\n",pos);
	printf("Codigo: %d\n",v[pos].cod);
	printf("Nome: %s\n",v[pos].nome);
	printf("Salario: %.2f\n",v[pos].salario); 
}

int maiorSalario(funcionario v[]){
	int i,maior;
	maior=0;
	for(i=0;i<N;i++){
		if(v[i].salario>v[maior].salario){
			maior=i;
		}
	}
	return(maior);
}

int menorSalario(funcionario v[]){
	int i,menor;
	menor=0;
	for(i=0;i<N;i++){
		if(v[i].salario<v[menor].salario){
			menor=i;
		}
	}
	return(menor);
}

float mediaSalarios(funcionario v[]){
	int i;
	float soma;
	soma=0.0;
	for(i=0;i<N;i++){
		soma+=v[i].salario;
	}
	return(soma/N);
}

void incluiFuncionario(){
    N = N+1;
    vetor = realloc(vetor, N*sizeof(funcionario));
    printf("Pos %i (novo funcionario):\n", N-1);
	printf("Digite o codigo:\n");
	scanf("%d",&vetor[N-1].cod);
	printf("Digite o nome:\n");
	scanf("%s",&vetor[N-1].nome);
	printf("Digite o salario:\n");
	scanf("%f",&vetor[N-1].salario);
}

void removeFuncionario(){
    int pos;
    printf("Digite a posicao em que se encontra o funcionario qual se deseja remover: ");
    scanf("%d",&pos);
    funcionario *novoVetor;
    novoVetor = malloc((N-1)*sizeof(funcionario));
    for (int i=0, j=0; i < N; i++){
        if (i != pos){
            *(novoVetor + j) = *(vetor + i);
            j++;
        }
    }
    free(vetor);
    N = N-1;
    vetor = malloc((N)*sizeof(funcionario));
    *vetor = *novoVetor;
}