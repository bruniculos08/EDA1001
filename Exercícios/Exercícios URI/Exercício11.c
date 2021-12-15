#include <stdlib.h>
#include <stdio.h>

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
        printf("%i ", l->nome);
        l = l->next;
    }
    printf("\n");
}

void limpa(pilha *a){
    while(a->topo != NULL) retira(a);
}

int main(){
    int n = 1;
    char temp;
    pilha *a;
    a = (pilha *)malloc(sizeof(pilha));
    do
    {
        limpa(a);
        scanf("%i", &n);
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            scanf("%c", &temp);
            insere(a, temp);
        }
    } while (n != 0);
    
}