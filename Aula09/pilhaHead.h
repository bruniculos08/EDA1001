typedef struct Pilha pilha;
struct Pilha {
    node *topo;
};
typedef struct Node node;
struct Node {
    char item;
    node *next;
};
char retira(pilha *a, int *status);
int insere(pilha *a, char dado);