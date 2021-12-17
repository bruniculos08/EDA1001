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

void insereN(pilha *a, int k, char *string){
    for(int i = 0; i < k; i++) insere(a, string[i]);
}

void retiraN(pilha *a, int k){
    for(int i = 0; i < k && a->topo != NULL; i++) retira(a);
}

int verifica(pilha *a, char string[]){
    if(a->topo == NULL) return 1;
    node *b;
    b = a->topo;
    int r = 0;
    for(int i = 0; i < 4; i++){
        if(string[i] != b->nome){
            r = 1;
            break;
        }
        b = b->next;
    }
    return r;
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
    int k, n;
    k = 0;
    do
    {
        scanf("%i", &n);
    } while (n < 0 || n > 100);
    char *string;
    string = (char *)malloc(4*sizeof(char));
    pilha *a;
    node *b;
    a = (pilha*)malloc(sizeof(pilha));
    a->topo = NULL;
    insereN(a, 4, "FACE");
    for(int i = 0; i < n; i++){
        fflush(stdin);
        scanf("%c %c %c %c", &string[0], &string[1], &string[2], &string[3]);
        if(verifica(a, string) == 0){
            k++;
            retiraN(a, 4);
            if(a->topo == NULL) insereN(a, 4, "FACE");
        }
        else insereN(a, 4, string);
        //printf("Lista: ");
        //imprime(a);
    }
    printf("%i\n", k);
}