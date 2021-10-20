#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "header.h"


int main(){
	setlocale(LC_ALL, "Portuguese");
	int op,i,tmp;
	do{
		mostraMenu();
		scanf("%d",&op);
		switch(op){
			case 1:
                system("cls"); //isso vai limpar a tela
                printf("Digite o tamanho do vetor:");
                scanf("%i", &N);
                vetor = malloc(N*sizeof(funcionario));
				for(i=0;i<N;i++){
					system("cls"); //isso vai limpar a tela
					printf("Pos %i:\n",i);
					printf("Digite o codigo:\n");
					scanf("%d",&vetor[i].cod);
					printf("Digite o nome:\n");
					scanf("%s",&vetor[i].nome);
					printf("Digite o salario:\n");
					scanf("%f",&vetor[i].salario);
				}
				break;
			case 2:
				system("cls"); //limpa a tela
				imprimeTodos(vetor);
				system("pause"); //mensagem que espera o "enter"
				break;
			case 3:
				printf("Qual posicao quer imprimir?\n");
				scanf("%d",&tmp);
				imprimePos(vetor,tmp);
				system("pause");
				break;
			case 4:
				printf("O maior salario esta na posicao %d\n",maiorSalario(vetor));  
				system("pause");
				break;
			case 5:
				printf("O menor salario esta na posicao %d\n",menorSalario(vetor));  
				system("pause");
				break;
			case 6:
				printf("A media dos salarios %.2f\n",mediaSalarios(vetor));  
				system("pause");
				break;
            case 7:
                incluiFuncionario();
                system("pause");
                break;
            case 8:
                removeFuncionario();
                system("pause");
                break;
			case 0:
				printf("Obrigado por usar o nosso programa!\n");  
				break;
			default:
				system("cls");
				printf("OPCAO NAO CADASTRADA!\n");  
				system("pause");
				break;

		}
	}while(op!=0);
}