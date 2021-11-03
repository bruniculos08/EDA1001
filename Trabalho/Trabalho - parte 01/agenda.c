#include "headAgenda.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


int main(void) {
    int n, j;
    tarefa *lista;
    lista = NULL;
    //lista = (tarefa*)malloc(sizeof(tarefa));
    lista = lerTarefasSalvas(lista);

    do
    {
        //system("cls");
        printf("|-------------------------------------|\n");
        printf("|    CADASTRO DE TAREFA               |\n");
        printf("|-------------------------------------|\n");
        printf("|     MENU DE OPCOES                  |\n");
        printf("|-------------------------------------|\n");
        printf("| 1 - Incluir nova tarefa             |\n");
        printf("| 2 - Visualizar tarefas cadastradas  |\n");
        printf("| 3 - Excluir tarefas                 |\n");
        printf("| 4 - Editar tarefa                   |\n");
        printf("| 5 - Indicar a tarefa do momento     |\n");
        printf("| 0 - Sair                            |\n");
        printf("|-------------------------------------|\n");
        scanf("%i", &n);

        switch (n) {
            case 1:
                lista = insereTarefa(lista, geraTarefa(lista));
                fflush(stdin);
                break;
            case 2:
                verTarefas(lista);
                break;
            case 3:
                if (lista == NULL) {
                    printf("Nao ha itens para serem removidos.\n");
                    break;
                }
                printf("Digite o ID da tarefa a ser removida: ");
                scanf("%i", &j);
                lista = removerTarefa(lista, j);
                break;
            case 4:
                if (lista == NULL)
                {
                    printf("Nao ha itens para serem alterados.\n");
                    break;
                }
                printf("Digite o ID da tarefa a ser editada: ");
                scanf("%i", &j);
                lista = alterarTarefa(lista, j);
                fflush(stdin);
                break;
            case 5:
                indicarTarefa(lista);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (n!=0);


    salvarTarefas(lista);
}