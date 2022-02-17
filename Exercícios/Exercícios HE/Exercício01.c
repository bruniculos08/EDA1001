#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree tree;
struct Tree {
    int number;
    tree *left;
    tree *right;
};
tree *insert(tree *G, int old, int new);
tree *find(tree *G, int old);
int height(tree *G);
void biggestWay(tree *G);

tree *insert(tree *G, int old, int new){
    tree *A;
    tree *B;
    A = find(G, old);
    B = (tree *)malloc(sizeof(tree));
    B->left = NULL;
    B->right = NULL;
    if(G == NULL && A == NULL){
        A = (tree *)malloc(sizeof(tree));
        A->left = NULL;
        A->right = NULL;
        A->number = old;
        G = A;
    }
    else if(A == NULL) free(B);
    else if(A->left != NULL) A->left = B;
    else if(A->right != NULL) A->right = A;
    else free(B);
    return G;
}

tree *find(tree *G, int old){
    if(G == NULL) return NULL;
    else if(G->number = old) return G;
    else if(G->left == NULL && G->right == NULL) return NULL;
    else if(find(G->left, old) != NULL) return find(G->left, old);
    else if(find(G->right, old) != NULL) return find(G->right, old);
    else return NULL;
}

int height(tree *G){
    if(G == NULL) return -1;
    if(G->left == NULL && G->right == NULL) return 0;
    if(G->left == NULL) return 1 + height(G->right);
    else if(G->right == NULL) return 1 + height(G->left);
    else{
        if(height(G->left) >= height(G->right)) return 1 + height(G->left);
        else return 1 + height(G->right);
    }
}

void biggestWay(tree *G){
    tree *A;
    tree *B;
    if(G == NULL) return;
    if(G->left != NULL) A = G->left;
    else A = G;
    if(G->right != NULL) B = G->right;
    else B = G;
    while((A->left != NULL || A->right != NULL) && A != G){
        if(height(A->left) >= height(A->right)) A = A->left;
        else A = A->right;
    }
    while((B->left != NULL || B->right != NULL) && B != G){
        if(height(B->left) >= height(B->right)) B = B->left;
        else B = B->right;
    }
    printf("%i %i", A->number, B->number);
}

int main(){
    int n;
    do
    {
        scanf("%i", &n);
    } while (n < 1 || n > 100000);
    int a, b;
    tree *G;
    G = NULL;
    for(int i = 0; i < n-1; i++){
        scanf("%i %i", &a, &b);
        G = insert(G, a, b);
    }
    biggestWay(G);
}