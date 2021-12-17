#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node node;
struct node{
    char nome;
    node *next;
};

typedef struct Pilha pilha;
struct Pilha {
    node *topo;
};

void insere(pilha *a, char h){
    //printf("inserindo...\n");
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->nome = h;
    newNode->next = a->topo;
    a->topo = newNode;
}

void retira(pilha *a){
    //printf("retirando...\n");
    if(a == NULL) return;
    if(a->topo == NULL) return;
    if(a->topo->next == NULL){
        free(a->topo);
        a->topo = NULL;
        return;
    }
    node *anterior = a->topo;
    a->topo = a->topo->next;
    int r = anterior->nome;
    free(anterior);
}

void imprime(pilha *a){
    if(a->topo == NULL) printf("Lista vazia.\n");
    node *l;
    l = a->topo;
    while(l != NULL){
        printf("%c ", l->nome);
        l = l->next;
    }
    printf("\n");
}

void limpa(pilha *a){
    while(a->topo != NULL) retira(a);
}

int main(){
    int n;
    pilha *a;
    a = (pilha*)malloc(sizeof(pilha));
    a->topo = NULL;
    char *string;
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        int k = 0;
        limpa(a);
        string = (char*)malloc(sizeof(char)*1000);
        fflush(stdin);
        scanf("%s", string);
        int h = strlen(string);
        for(int j = 0; j < h; j++){
            if(a->topo != NULL){
                if(string[j] == '>' && a->topo->nome == '<'){
                    retira(a);
                    k++;
                }
                else if(string[j] == '<' || string[j] == '>') insere(a, string[j]);
            }
            else if(string[j] == '<' || string[j] == '>') insere(a, string[j]);
        }
        printf("%i\n", k);
    }
}