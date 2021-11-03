#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headAgenda.h"
#include <time.h>

tarefa *geraTarefa(tarefa *l){
    tarefa *lista;
    lista = l;
    tarefa *newTarefa;
    newTarefa = (tarefa *)malloc(sizeof(tarefa));
    do
    {
        printf("Digite a hora: ");
        scanf("%i", &newTarefa->dados.deadline.hora);
        if (newTarefa->dados.deadline.hora < 0)
        {
            printf("Valor de hora invalido.\n");
        }
        
    } while (newTarefa->dados.deadline.hora < 0);

        do
    {
        printf("Digite o minuto: ");
        scanf("%i", &newTarefa->dados.deadline.minuto);
        if (newTarefa->dados.deadline.minuto < 0 || newTarefa->dados.deadline.minuto > 59)
        {
            printf("Valor de minuto invalido.\n");
        }
        
    } while (newTarefa->dados.deadline.minuto < 0 || newTarefa->dados.deadline.minuto > 59);
    
        do
    {
        printf("Digite o dia: ");
        scanf("%i", &newTarefa->dados.deadline.dia);
        if (newTarefa->dados.deadline.dia < 0 || newTarefa->dados.deadline.dia > 30)
        {
            printf("Valor de dia invalido.\n");
        }
        
    } while (newTarefa->dados.deadline.dia < 0 || newTarefa->dados.deadline.dia > 30);
    
        do
    {
        printf("Digite o mes: ");
        scanf("%i", &newTarefa->dados.deadline.mes);

        if (newTarefa->dados.deadline.mes < 0 || newTarefa->dados.deadline.mes > 12)
        {
            printf("Valor de mes invalido.\n");
        }
        
    } while (newTarefa->dados.deadline.mes < 0 || newTarefa->dados.deadline.mes > 12);

        do
    {
        printf("Digite o ano: ");
        scanf("%i", &newTarefa->dados.deadline.ano);
        if (newTarefa->dados.deadline.ano < 0)
        {
            printf("Valor de ano invalido.\n");
        }
    } while (newTarefa->dados.deadline.ano < 0);

        do
    {
        printf("Digite a duracao: ");
        scanf("%i", &newTarefa->dados.duracao);
        if (newTarefa->dados.duracao < 0)
        {
            printf("Valor de duracao invalido.\n");
        }    
    } while (newTarefa->dados.duracao < 0);

    printf("Digite a prioridade: ");
    scanf("%i", &newTarefa->dados.prioridade);
    printf("Digite o nome: ");
    scanf("%s", &newTarefa->dados.nome);
    
    int randomNumber = rand() % 1000000;
    
    if (lista != NULL){
        printf("Verificando ID\n"); 
        do{                                         //^ Verifica se há ID repetido
            if (randomNumber == lista->id){
                randomNumber = rand() % 1000000;
                lista = l;
            }
            lista = lista->next; 
        } while (lista != NULL);
    }
    //^ Perguntar por que quando não há essa atribuição (linha 43) os ID's são repetidos de 2 em 2 a partir do segundo item da lista
    newTarefa->id = randomNumber;
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
    if (lista == NULL){
        printf("Inserindo tarefa em lista vazia\n");
        newTarefa->next = NULL;
        return newTarefa;
    }
    while(lista != NULL){
        printf("Inserindo tarefa\n");
        if (dataAnterior(newTarefa->dados.deadline, lista->dados.deadline) == 2 && lista->next == NULL){
            printf("Inserindo tarefa 1\n");
            lista->next = newTarefa;
            newTarefa->next = NULL;
            return l;
        }
        else if (dataAnterior(newTarefa->dados.deadline, lista->dados.deadline) == 1 && lista->next == NULL){
            printf("Inserindo tarefa 2\n");
            newTarefa->next = lista;
            return newTarefa;
        }
        else if (dataAnterior(newTarefa->dados.deadline, lista->dados.deadline) == 2 && dataAnterior(newTarefa->dados.deadline, lista->next->dados.deadline) == 1){
            printf("Inserindo tarefa 3\n");
            newTarefa->next = lista->next;
            lista->next = newTarefa;
            return l;
        }
        else if (dataAnterior(newTarefa->dados.deadline, lista->dados.deadline) == 1 && a == NULL){
           printf("Inserindo tarefa 4 \n");
           newTarefa->next = lista;
            return newTarefa;
        }
        
        if (lista->next == NULL){
            printf("Inserindo tarefa 5\n");
           lista->next = newTarefa;
           return l;
        }
        a = lista;
        lista = lista->next;
    }
    printf("Inserindo tarefa return\n");
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
        else if (lista->id == idRemover && lista->next == NULL && anterior == NULL){
            free(lista);
            return NULL;
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
        if (lista->next == NULL)
        {
            printf("Item nao encontrado.\n");
            return l;
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
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (n != 0);
    tarefa *newTarefa;
    newTarefa = (tarefa*)malloc(sizeof(tarefa));
    *newTarefa = *lista;
    l = removerTarefa(l, idAlterar);
    l = insereTarefa(l, newTarefa);
    return l;
}

void indicarTarefa(tarefa *l) {

}