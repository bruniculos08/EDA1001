#include <stdlib.h>
#include <stdio.h>
typedef struct Raiz raiz;
struct Raiz{
    int valor;
    raiz *dir;
    raiz *esq;
};
void imprime(raiz *l);
int balanceamento(raiz *l);
int altura(raiz *l);
int contaRoots(raiz *l);
raiz *insere(raiz *l, int valor);
raiz *remover(raiz *l, int valor);
raiz *removerNode(raiz *node);

void imprime(raiz *l){
    if(l == NULL) return;
    printf("%i\n", l->valor);    
    imprime(l->esq);
    imprime(l->dir);
}

int altura(raiz *l){
    int h = 0;
    if(l == NULL) return -1;
    if(l->esq == NULL && l->dir == NULL) return 0;
    if(l->esq == NULL) h = h + 1 + altura(l->dir);
    else if(l->dir == NULL) h = h + 1 + altura(l->esq);
    else{
        if(altura(l->esq) < altura(l->dir)) h = h + 1 + altura(l->dir);
        else h = h + 1 + altura(l->esq);
    }
    return h;
}

int balanceamento(raiz *l){
    int i = altura(l->esq)-altura(l->dir);
    return i;
}

int contaRoots(raiz *l){
    if(l == NULL) return 0;
    else if(l->dir == NULL && l->esq == NULL) return 0;
    int r = 0;
    if(balanceamento(l) >= 2){
        if(l->esq != NULL && balanceamento(l->esq) >= 0) r++;
        else r = r + 2;
    }
    else if(balanceamento(l) <= -2){
        if(l->dir != NULL && balanceamento(l->dir) >= 0) r++;
        else r = r + 2;
    }
    return r + contaRoots(l->esq) + contaRoots(l->dir);
}

raiz *insere(raiz *l, int valor){
    if(l == NULL){
        l = malloc(sizeof(raiz));
        l->valor = valor;
        l->esq = NULL;
        l->dir = NULL;
        return l;
    }
    else if(valor <= l->valor) l->esq = insere(l->esq, valor);
    else l->dir = insere(l->dir, valor);
    return l;
}

raiz *remover(raiz *l, int valor){
    raiz *f, *p;
    f = l;
    p = f;
    while(f->valor != valor && f != NULL){
        p = f;
        if(f->valor > valor) f = f->esq;
        else f = f->dir;
    }
    if(f == NULL){
        printf("Valor nao encontrado.\n");
        return l;
    }
    if(p == f){
        l = removerNode(p);
    }
    else if(p->esq == f) p->esq = removerNode(f);
    else p->dir = removerNode(f);
    return l;
}

raiz *removerNode(raiz *node){
    raiz *f, *p; // o ponteiro *p aponta para o pai do nó que queremos mexer e *f para algum dos nós filhos de *node
    if(node->esq == NULL && node->dir == NULL){
        free(node);
        return NULL;
    }
    else if(node->dir == NULL){
        f = node->esq;
        free(node);
        return f;
    }
    else if(node->esq == NULL){
        f = node->dir;
        free(node);
        return f;
    }
    p = node;
    f = node->dir;
    while(f->esq != NULL){ // o ponteiro *f tem que apontar para o sucessor de *node, enquanto *p aponta para o pai desse sucessor
        p = f;
        f = f->esq;
    }
    if(p != node){
        p->esq = f->dir;
        f->dir = node->dir;
    }
    f->esq = node->esq;
    free(node);
    return f;
}

int main(){
    raiz *l;
    l = NULL;
    int n, i;
    do
    {
        scanf("%i", &n);
        switch(n)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%i", &i);
            l = insere(l, i);
            break;
        case 2:
            printf("Digite o valor: ");
            scanf("%i", &i);
            l = remover(l, i);
            break;
        case 3:
            printf("%i\n", contaRoots(l));
            break;
        case 4:
            imprime(l);
            break;
        default:
            break;
        }
    } while (n != 0);
}