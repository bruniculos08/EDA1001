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
    printf("inserindo...\n");
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
    int n;
    if(a->topo == NULL) return;
    n = a->topo->nome;
    for(int i = 0; i < k; i++) insere(a, string[i]);
}

void retiraN(pilha *a, int k){
    for(int i = 0; i < k && a->topo != NULL; i++) retira(a);
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
    char string[4];
    pilha *a;
    node *b;
    a = (pilha*)malloc(sizeof(pilha));
    a->topo = NULL;
    insere(a, 'F');
    insere(a, 'A');
    insere(a, 'C');
    insere(a, 'E');
    imprime(a);
    for(int i = 0; i < n; i++){
        fflush(stdin);
        for(int j = 0; j < 4; j++) scanf("%c", string[j]);
        //scanf("%s", string);
        if(a->topo != NULL){
            b = a->topo;
            for(int j = 0; j < 4; j++){
                if(b->nome != string[j]){
                    insereN(a, 4, string);
                    break;
                }
                if(b != NULL) b = b->next;
                if(j == 3){
                    k++;
                    retiraN(a, 4);
                }
            }
        }
    }
    printf("%i\n", k);
}