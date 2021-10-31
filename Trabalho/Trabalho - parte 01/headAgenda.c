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
    printf("")
}
