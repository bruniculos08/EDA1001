typedef struct Node node;
struct Node {
    char item;
    node *next;
};

typedef struct Pilha pilha;
struct Pilha {
    node *topo;
};
void imprimePilha(pilha *a);
void sair(pilha *a);
char retira(pilha *a, int *status);
int insere(pilha *a, char dado);