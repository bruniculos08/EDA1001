#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headAgenda.h"
#include <time.h>

tarefa *geraTarefa(tarefa *l){
    tarefa *lista = l;
    tarefa *newTarefa;
    newTarefa = (tarefa *)malloc(sizeof(tarefa));
    tempo *time;
    time = &newTarefa->dados.deadline;
    
    printf("Digite o a hora: ");
    scanf("%i", &time->hora);
    printf("Digite o minuto: ");
    scanf("%i", &time->minuto);
    printf("Digite o dia: ");
    scanf("%i", &time->dia);
    printf("Digite o mes: ");
    scanf("%i", &time->mes);
    printf("Digite o ano: ");
    scanf("%i", &time->ano);
    printf("Digite a duracao: ");
    scanf("%i", &newTarefa->dados.duracao);
    printf("Digite a prioridade: ");
    scanf("%i", &newTarefa->dados.prioridade);
    printf("Digite o nome: ");
    scanf("%i", &newTarefa->dados.nome);
    
    int randomNumber = rand();

    if (l != NULL){
        do{                                         //^ Verifica se há ID repetido
            if (randomNumber == lista->id){
                randomNumber = rand();
                lista = l;
            }
            lista = lista->next;
        } while (lista != NULL);
    }

    return newTarefa;
}

int dataAnterior(tempo a, tempo b){
    if (a.ano > b.ano) return 2;
    else if (a.ano < b.ano) return 1;
    else if (a.ano == b.ano){
        if (a.mes > b.mes) return 2;
        else if (a.mes < b.mes) return 1;
        else if (a.mes < b.mes){
            if (a.dia > b.dia) return 2;
            else if (a.dia < b.dia) return 1;
            else if (a.dia == b.dia){
                if (a.hora > b.hora) return 2;
                else if (a.hora < b.hora) return 1;
                else if (a.hora == b.hora){
                    if (a.minuto > b.minuto) return 2;
                    else if (a.minuto < b.minuto) return 1;
                    else if (a.minuto == b.minuto) return -1;
                }
            }
        }
    }
}

tarefa *insereTarefa(tarefa *l, tarefa *newTarefa){
    tarefa *lista;
    tarefa *a;
    lista = l;
    a = NULL;
    while(lista != NULL){
        if (dataAnterior(newTarefa->dados.deadline, lista->dados.deadline) == 2 && lista->next == NULL){
            lista->next = newTarefa;
            return l;
        }
        else if (dataAnterior(newTarefa->dados.deadline, lista->dados.deadline) == 2 && dataAnterior(newTarefa->dados.deadline, lista->next->dados.deadline) == 1){
            newTarefa->next = lista->next;
            lista->next = newTarefa;
            return l;
        }
        else if (dataAnterior(newTarefa->dados.deadline, lista->dados.deadline) == 1 && a == NULL){
            newTarefa->next = lista;
        }
        
        a = lista;
        lista = lista->next;
    };

    return newTarefa;
}

void verTarefas(tarefa *l){
    tarefa *lista;
    lista = l;
    if (lista == NULL){
        printf("Nao ha registro de tarefas.\n");
    }
    while (lista != NULL){
        printf("%s\n", lista->dados.nome);
        printf("ID: %i\n", lista->id);
        lista = lista->next;
    }
}

tarefa *removerTarefa(tarefa *l, int idRemover){
    tarefa *lista;
    lista = l;
    tarefa *anterior;
    anterior = NULL;
    if (lista == NULL){
        printf("Nao ha tarefas para serem removidas.\n");
        return l;
    }
    while (lista != NULL){
        if (lista->id == idRemover && lista->next != NULL && anterior == NULL)
        {
            anterior = lista->next;
            free(lista);
            return anterior;
        }
        else if(lista->id == idRemover && lista->next != NULL && anterior != NULL){
            anterior->next = lista->next;
            free(lista);
            return l;
        }
        else if(lista->id == idRemover && lista->next == NULL){
            anterior->next = NULL;
            free(lista);
            return l;
        }
        anterior = lista;
        lista = lista->next;
    }
    printf("A tarefa a ser removida nao foi encontrada.\n");
    return l;
}

tarefa *alterarTarefa(tarefa *l, int idAlterar){
    tarefa *lista;
    lista = l;
    int n;
    while (lista != NULL){
        if (lista->id == idAlterar){
            break;
        }
        lista = lista->next;
    }

    do
    {
        printf("Digite o elemento a ser alterado:\n1- Nome\n2- Duracao\n3- Deadline\n4- Prioridade\n0- Sair\n");
        scanf("%i", &n);
        char nome[50];
        int duracao;
        tempo deadline;
        int prioridade;

        switch (n){
            case 1:
                printf("Digite o novo nome: ");
                scanf("%s", &nome);
                strcpy(lista->dados.nome, nome);
                break;
            case 2:
                printf("Digite a nova duracao: ");
                scanf("%i", &duracao);
                lista->dados.duracao = duracao;
                break;
            case 3:
                printf("Digite o novo ano: ");
                scanf("%i", &deadline.ano);
                printf("Digite o novo mes: ");
                scanf("%i", &deadline.mes);
                printf("Digite o novo dia: ");
                scanf("%i", &deadline.dia);
                printf("Digite a nova hora: ");
                scanf("%i", &deadline.hora);
                printf("Digite o novo minuto: ");
                scanf("%i", &deadline.minuto);
                lista->dados.deadline = deadline;
                break;
            case 4:
                printf("Digite a nova prioridade: ");
                scanf("%i", &prioridade);
                lista->dados.prioridade = prioridade;
                break;
            case 0:
                return l;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (n != 0);
    return l;
}

void indicarTarefa(tarefa *l) {

}