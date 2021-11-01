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

    do{                                         //^ Verifica se há ID repetido
        if (randomNumber == lista->id){
            randomNumber = rand();
            lista = l;
        }
        lista = lista->next;
    } while (lista != NULL);

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