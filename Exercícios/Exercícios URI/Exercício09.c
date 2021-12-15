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
    }
    node *anterior = a->topo;
    a->topo = a->topo->next;
    char r = anterior->item;
    free(anterior);
    *status = 0;
    return r;
}

void limpa(pilha *a){
    int status;
    while(a->topo != NULL) retira(a, &status);
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
    char temp = '\0', barra = '\0';
    //printf("montando...\n");
    for(int i = 0; i < n; i++){
        if(string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '^' || string[i] == '/'){
            if(string[i] == '/' && temp != '\0'){
                insere(a, temp);
                if(barra != '\0') insere(a, barra);
                barra = string[i];
                temp = '\0';
            }
            else if(string[i] == '/' && temp == '\0') barra = string[i];
            else if(barra == '/' && temp != '\0'){
                insere(a, temp);
                insere(a, barra);
                barra = '\0';
                temp = string[i];
            }
            else if(temp == '\0') temp = string[i];
            else if(temp != '\0' && barra != '\0'){
                insere(a, temp);
                insere(a, barra);
                barra = '\0';
                temp = string[i];
            }
            else if(temp != '\0' && barra == '\0'){
                insere(a, temp);
                temp = string[i];
            }
            else temp = string[i];
        }
        //else if(string[i] == '/') barra = string[i];
        else if(string[i] != '(' && string[i] != ')') status = insere(a, string[i]);
        //else status = insere(a, string[i]);
    }
    pilha *b;
    b = (pilha *)malloc(sizeof(pilha));
    b->topo = NULL;
    if(temp != '\0') insere(a, temp);
    if(barra != '\0') insere(a, barra);
    while(a->topo != NULL) status = insere(b, retira(a, &status));
    while(b->topo != NULL) printf("%c", retira(b, &status));
    printf("\n");
    limpa(b);
}

int main(){
    int n, status;
    char string[1000], letter;
    pilha *a;
    a = malloc(sizeof(pilha));
    a->topo = NULL;
    scanf("%i", &n);
    for(int j = 0; j < n; j++){
            limpa(a);
            a->topo = NULL;
            string[0] = '\0';
            fflush(stdin);
            gets(string);
            if(string[0] == '\0') break;
            expressao(a, string);
    }
}