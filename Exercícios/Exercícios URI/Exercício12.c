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
    //printf("inserindo...\n");
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->valor = h;
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
    int n = 1;
    int temp;
    pilha *a;
    a = (pilha *)malloc(sizeof(pilha));
    a->topo = NULL;
    pilha *b;
    b = (pilha *)malloc(sizeof(pilha));
    b->topo = NULL;
    pilha *resultado;
    resultado = (pilha *)malloc(sizeof(pilha));
    resultado->topo = NULL;
    do
    {
        limpa(a);
        limpa(b);
        limpa(resultado);
        scanf("%i", &n);
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            insere(a, n-i);
            fflush(stdin);
            scanf("%i", &temp);
            insere(resultado, temp);
        }
        for(int i = 0; i < n; i++){
            insere(b, resultado->topo->valor);
            retira(resultado);
        }
        imprime(a);
        imprime(b);
        limpa(resultado);
        for(int i = 0; i < 2*n; i++){
            if(a->topo != NULL && b->topo != NULL){
                if(resultado->topo != NULL && resultado->topo->valor == b->topo->valor){
                    //printf("R");
                    retira(resultado);
                    retira(b);
                }
                else if(a->topo->valor == b->topo->valor){
                    //printf("IR");
                    retira(a);
                    retira(b);
                }
                else if(a->topo->valor != b->topo->valor){
                    if(resultado->topo != NULL && resultado->topo->valor == b->topo->valor){
                        //printf("R");
                        retira(resultado);
                        retira(b);
                    }
                else{
                        //printf("I");
                        insere(resultado, a->topo->valor);
                        retira(a);
                    }
                }
            }
            else if(resultado->topo != NULL && b->topo != NULL){
                if(resultado->topo->valor == b->topo->valor){
                    //printf("R");
                    retira(resultado);
                    retira(b);
                }
            }
        }
        if(resultado->topo != NULL) printf("No");
        else printf("Yes");
        printf("\n");
    } while (n != 0);
}