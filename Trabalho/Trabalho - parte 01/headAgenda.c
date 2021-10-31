#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headAgenda.h"


tarefa *geraTarefa(){
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
    printf("Digite o nome: ");
    scanf("%i", &newTarefa->dados.nome);
}
