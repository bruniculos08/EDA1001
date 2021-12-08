#include <stdio.h>
#include <string.h>

#include <stdlib.h>


typedef struct Node node;
struct Node {
    char item;
    node *next;
};

typedef struct Pilha pilha;
struct Pilha {
    node *topo;
};

char retira(pilha *a, int *status) {
    if(a->topo == NULL) {
        *status = 1;
        return '\0';
        //return;
    }
    node *anterior = a->topo;
    a->topo = a->topo->next;
    char r = anterior->item;
    free(anterior);
    *status = 0;
    return r;
}

int insere(pilha *a, char dado){
    //printf("inserindo...\n");
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->item = dado;
    newNode->next = a->topo;
    a->topo = newNode;
    //printf("inserido.\n");
    return 0;
}

void expressao(pilha *a, char string[]){
    int n = strlen(string);
    int status = 0;
    //printf("montando...\n");
    for(int i = 0; i < n; i++){
        if(string[i] == '(') insere(a, string[i]);
        if(string[i] == ')'){
            retira(a, &status);
            if(status == 1){
                printf("incorrect\n");
                return;
            }
        }
    }
    if(a->topo != NULL) printf("incorrect\n");
    else printf("correct\n");
}

void limpa(pilha *a){
    int status;
    while(a->topo != NULL){
        retira(a->topo, &status);
    }
}

int main(){
    int i, status;
    char string[1000], letter;
    pilha *a;
    a = malloc(sizeof(pilha));
    a->topo = NULL;
    //scanf("%i", &i);
    for(int j = 0; j < 1000; j++){
            a->topo = NULL;
            string[0] = '\0';
            fflush(stdin);
            gets(string);
            if(string[0] == '\0') break;
            expressao(a, string);
            lerPilha(a);
    }
}