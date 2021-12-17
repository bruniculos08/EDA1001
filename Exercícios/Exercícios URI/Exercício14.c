#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node{
    int valor;
    node *next;
};

typedef struct Pilha pilha;
struct Pilha {
    node *topo;
};

void insere(pilha *a, int h){
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->valor = h;
    newNode->next = a->topo;
    a->topo = newNode;
}

int retira(pilha *a){
    if(a->topo == NULL) return -1;
    int r;
    if(a->topo->next == NULL){
        r = a->topo->valor;
        free(a->topo);
        a->topo = NULL;
        return r;
    }
    node *anterior = a->topo;
    a->topo = a->topo->next;
    r = anterior->valor;
    free(anterior);
    return r;
}

void imprime(pilha *a){
    if(a->topo == NULL) printf("Lista vazia.\n");
    node *l;
    l = a->topo;
    while(l != NULL){
        printf("%i ", l->valor);
        l = l->next;
    }
    printf("\n");
}

void limpa(pilha *a){
    while(a->topo != NULL) retira(a);
}

void moveBase(pilha *a){
    if(a->topo == NULL || a->topo->next == NULL) return;
    node *l;
    l = a->topo->next;
    node *b;
    b = a->topo;
    a->topo = a->topo->next;
    while(l->next != NULL) l = l->next;
    l->next = b;
    b->next = NULL;
}

int main(){
    pilha *a;
    a = (pilha *)malloc(sizeof(pilha));
    a->topo = NULL;
    pilha *b;
    b = (pilha *)malloc(sizeof(pilha));
    b->topo = NULL;
    node *l;
    int k;
    int n = 1;
    do
    {
        scanf("%i", &n);
        if(n == 0) break;
        for(int i = 0; i < n; i++) insere(a, n-i);
        l = a->topo;
        while(a->topo->next != NULL){
            //imprime(a);
            k = retira(a);
            insere(b, k);
            moveBase(b);
            moveBase(a);
            //imprime(a);
        }
        l = b->topo;
        printf("Discarded cards: ");
        while(l->next != NULL){
            printf("%i, ", l->valor);
            l = l->next;
        }
        printf("%i\n", l->valor);
        printf("Remaining card: %i\n", a->topo->valor);
        limpa(a);
        limpa(b);
    } while (n != 0);
    
}