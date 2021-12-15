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

void insere(pilha *a, int j){
    //printf("inserindo...\n");
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->valor = j;
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
    int r = anterior->valor;
    free(anterior);
}

void insereN(pilha *a, int k){
    int n;
    if(a->topo == NULL) return;
    n = a->topo->valor;
    for(int i = 0; i < k; i++){
        n = n-1;
        insere(a, n);
    }
}

void retiraN(pilha *a, int k){
    for(int i = 0; i < k && a->topo != NULL; i++) retira(a);
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

int main(){
    int m, n;
    pilha *a;
    a = (pilha *)malloc(sizeof(pilha));
    a->topo = NULL;
    for(int i = 0; i < 2000; i++){
        limpa(a);
        a->topo = NULL;
        fflush(stdin);
        scanf("%i %i", &n, &m);
        if(m == 0 && n == 0) break;
        for(int j = n+1; j >= 0; j--) insere(a, j);
        for(int j = 1; j <= n+1; j++){
            //imprime(a);
            if(a->topo == NULL){
                printf("Don't make fun of me!\n");
                break;
            }
            else if(a->topo->valor == n+1){
                printf("Don't make fun of me!\n");
                break;
            }
            else if(a->topo->valor == m){
                printf("Let me try!\n");
                break;
            }
            else if(a->topo->valor < m && a->topo->valor+2*j-1 < n+1) retiraN(a, 2*j-1);
            else if(a->topo->valor < m && a->topo->valor-2*j+1 >= 0) insereN(a, 2*j-1);
            else if(a->topo->valor > m && a->topo->valor-2*j+1 >= 0) insereN(a, 2*j-1);
            else if(a->topo->valor > m && a->topo->valor+2*j-1 < n+1) retiraN(a, 2*j-1);
            else{
                printf("Don't make fun of me!\n");
                break;
            }
        }
        if(a->topo == NULL) printf("Don't make fun of me!\n");
        //else if(a->topo->valor != m) printf("Don't make fun of me!\n");
    }
}