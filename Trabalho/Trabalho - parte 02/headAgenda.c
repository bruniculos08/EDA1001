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
    newTarefa->next = NULL;
    do
    {
        printf("Digite a hora: ");
        scanf("%i", &newTarefa->dados.deadline.hora);
        if (newTarefa->dados.deadline.hora < 0 && newTarefa->dados.deadline.hora > 23)
        {
            printf("Valor de hora invalido.\n");
        }
        
    } while (newTarefa->dados.deadline.hora < 0 && newTarefa->dados.deadline.hora > 23);

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
        
    } while (newTarefa->dados.deadline.dia <= 0 || newTarefa->dados.deadline.dia > 30);
    
        do
    {
        printf("Digite o mes: ");
        scanf("%i", &newTarefa->dados.deadline.mes);

        if (newTarefa->dados.deadline.mes < 0 || newTarefa->dados.deadline.mes > 12)
        {
            printf("Valor de mes invalido.\n");
        }
        
    } while (newTarefa->dados.deadline.mes <= 0 || newTarefa->dados.deadline.mes > 12);

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
    } while (newTarefa->dados.duracao <= 0);

    printf("Digite a prioridade: ");
    scanf("%i", &newTarefa->dados.prioridade);
    printf("Digite o nome: ");
    scanf("%s", &newTarefa->dados.nome);    //^ usar gets()
    
    int randomNumber = rand() % 1000000;
    //^ usar srand(time(NULL)) depois
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
    else {
        if (a.mes > b.mes) return 2;
        else if (a.mes < b.mes) return 1;
        else {
            if (a.dia > b.dia) return 2;
            else if (a.dia < b.dia) return 1;
            else {
                if (a.hora > b.hora) return 2;
                else if (a.hora < b.hora) return 1;
                else {
                    if (a.minuto > b.minuto) return 2;
                    else if (a.minuto < b.minuto) return 1;
                    else return 0;
                }
            }
        }
    }
}
//^função valida tarefa e exibir dados tanto verTarefas quanto em alterarTarefa
tarefa *insereTarefa(tarefa *l, tarefa *newTarefa){
    tarefa *lista;
    lista = l;
    if(l == NULL) return newTarefa;
    while(lista->next != NULL) lista = lista->next;
    lista->next = newTarefa;
    return l;
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
        printf("Duracao: %i\n", lista->dados.duracao);
        printf("Data: %i/%i/%i %i:%i\n", lista->dados.deadline.dia, lista->dados.deadline.mes, lista->dados.deadline.ano, lista->dados.deadline.hora, lista->dados.deadline.minuto);
        printf("Prioridade: %i\n", lista->dados.prioridade);
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

        switch (n){ //^ é necessário haver restrições aqui
            case 1: 
                printf("Digite o novo nome: ");
                scanf("%s", &nome);
                strcpy(lista->dados.nome, nome);
                break;
            case 2:
                do
                {
                    printf("Digite a nova duracao: ");
                    scanf("%i", &duracao);
                } while (duracao <= 0);
                
                lista->dados.duracao = duracao;
                break;
            case 3:
                do
                {
                    printf("Digite o novo ano: ");
                    scanf("%i", &deadline.ano);
                } while (deadline.ano < 0);
                
                do
                {
                    printf("Digite o novo mes: ");
                    scanf("%i", &deadline.mes);
                } while (deadline.mes <= 0 || deadline.mes > 12);
                
                do
                {
                    printf("Digite o novo dia: ");
                    scanf("%i", &deadline.dia);
                } while (deadline.dia <= 0 || deadline.dia > 30);
                
                do
                {
                    printf("Digite a nova hora: ");
                    scanf("%i", &deadline.hora);
                } while (deadline.hora < 0 || deadline.hora > 23);
                
                do
                {
                    printf("Digite o novo minuto: ");
                    scanf("%i", &deadline.minuto);
                } while (deadline.minuto < 0 || deadline.minuto > 59);
                
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
    printf("%s\n", lista->dados.nome);
    printf("ID: %i\n", lista->id);
    printf("Duracao: %i\n", lista->dados.duracao);
    printf("Data: %i/%i/%i %i:%i\n", lista->dados.deadline.dia, lista->dados.deadline.mes, lista->dados.deadline.ano, lista->dados.deadline.hora, lista->dados.deadline.minuto);
    printf("Prioridade: %i\n", lista->dados.prioridade);
    l = removerTarefa(l, idAlterar);
    newTarefa->next = NULL;
    l = insereTarefa(l, newTarefa);
    return l;
}

void indicarTarefa(tarefa *l) {

}

int tamanhoTarefas(tarefa *l) {
    tarefa *lista;
    lista = l;
    int n = 0;
    if (lista == NULL) return 0;
    while (lista != NULL) {
        n++;
        lista = lista->next;
    }
    return n;
}

tarefa *split(tarefa *l){
    tarefa *p;
    tarefa *p1;
    tarefa *p2;
    if(l != NULL && l->next == NULL) return l;
    p1 = l;
    p = l;
    if(l != NULL) p2 = l->next;
    else p2 = NULL;
    while(p2 != NULL && p2->next != NULL){
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p = p1->next;
    p1->next = NULL;
    return p;
}

tarefa *merge(tarefa *l1, tarefa *l2){
    tarefa *sortedNew;
    tarefa *a;
    a = NULL;
    sortedNew = NULL;
    while(l1 != NULL && l2 != NULL){
        printf("While 01.\n");
        if(dataAnterior(l1->dados.deadline, l2->dados.deadline) <= 1){
            a = l1->next;
            l1->next = NULL;
            sortedNew = insereTarefa(sortedNew, l1);
            l1 = a;
            //free(a);
        }
        else{
            a = l2->next;
            l2->next = NULL;
            sortedNew = insereTarefa(sortedNew, l2);
            l2 = a;
            //free(a);
        }
    }
    while(l1 != NULL){
        a = l1->next;
        l1->next = NULL;
        sortedNew = insereTarefa(sortedNew, l1);
        l1 = a;
    }
    while(l2 != NULL){
        a = l2->next;
        l2->next = NULL;
        sortedNew = insereTarefa(sortedNew, l2);
        l2 = a;
    }
    return sortedNew;
}

tarefa *mergeSort(tarefa *l){
    tarefa *l1;
    tarefa *l2;
    tarefa *middle;
    tarefa *sortedNew;
    //verTarefas(l);
    if(l == NULL || l->next == NULL) return l;
    middle = split(l);
    l1 = mergeSort(l);
    l2 = mergeSort(middle);
    //verTarefas(l1);
    //verTarefas(l2);
    sortedNew = merge(l1, l2);
    return sortedNew;
}

int dataPassada(tempo a){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    if(tm.tm_year > a.ano) return 1;
    else if(tm.tm_year < a.ano) return 0;
    else if(tm.tm_mon > a.mes) return 1;
}