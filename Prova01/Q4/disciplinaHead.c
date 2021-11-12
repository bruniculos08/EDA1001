#include <stdio.h>
#include <stdlib.h>
#include "disciplinaHead.h"
#include <math.h>


aluno *insereOrdenado(aluno *l, aluno *novo){ //^ ordenado por nota
    aluno *lista;
    lista = l;
    if (lista == NULL){
        printf("Lista de alunos vazia.\n");
    }
    while (lista != NULL){
        if (lista->nota < novo->nota && lista->prox == NULL){
            lista->prox = novo;
            novo->ant = lista;
            return l;
        }
        else if(lista->nota > novo->nota && lista->ant == NULL){
            lista->ant = novo;
            novo->prox = lista;
            return novo;
        }
        else if(lista->nota > novo->nota && lista->ant->nota < lista->nota){
            novo->ant = lista->ant; 
            lista->ant->prox = novo;
            lista->ant = novo;
            novo->prox = lista;
            return l;
        }
        lista = lista->prox;
    }
    return l;
}


int tamanhoLista(aluno *l){
    if (l == NULL) return 0;
    int valor = 0;
    while (l != NULL){
        valor++;
        l = l->prox;
    }
    return valor;
}

double mediana(aluno *l){
    int tamanho = tamanhoLista(l);
    double resultado, termo1, termo2;
    aluno *listaOrdenada;
    while (l != NULL){
        listaOrdenada = insereOrdenado(listaOrdenada, l);
        l = l->prox;
    }
    if(tamanho%2 == 0){
        for(int i = 1; i <= (tamanho/2)+1; i++){
            if(i == tamanho/2) termo1 = listaOrdenada->nota;
            else if(i == (tamanho/2)+1) termo2 = listaOrdenada->nota;
            listaOrdenada = listaOrdenada->prox;
        }
        resultado = (termo1+termo2)/2;
        return resultado;
    }
    else{
        for(int i = 1; i <= 1+(tamanho-1)/2; i++){
            if(i == 1 + (tamanho-1)/2) return listaOrdenada->nota;
            listaOrdenada = listaOrdenada->prox;
        }
    }
}

void alunosPertoMediana(aluno *l){
    aluno *lista;
    lista = l;
    aluno *acima;
    aluno *abaixo;
    double notaAcima, notaAbaixo;
    notaAcima = 10; //^supondo que a nota máxima seja 10
    notaAbaixo = 0; //^supondo que a nota mínima seja 0
    double valorMediana = calcula_mediana_aluno(l);
    if(lista == NULL){
        printf("Lista de alunos vazia.\n");
    }
    while(lista != NULL){
        if(lista->nota < notaAcima && lista->nota > valorMediana){
            notaAcima = lista->nota;
            acima = lista;
        }
        if(lista->nota > notaAbaixo && lista->nota < valorMediana){
            notaAbaixo = lista->nota;
            abaixo = lista;
        }
    }



    printf("Primeiro aluno acima da mediana:\nnome: %s\nmatricula: %i\nnota: %lf\n", acima->nome, acima->matricula, acima->nota);
    printf("Primeiro aluno abaixo da mediana:\nnome: %s\nmatricula: %i\nnota: %lf\n", abaixo->nome, abaixo->matricula, abaixo->nota);
}

double calcula_mediana(aluno *l){
}