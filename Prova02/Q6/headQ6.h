typedef struct Node node;
struct Node {
    char item[8];
    node *next;
};

typedef struct Pilha pilha;
struct Pilha {
    node *topo;
};
void imprimePilha(pilha *a);
void sair(pilha *a, char dado[8]);
char *retira(pilha *a);
int insere(pilha *a, char dado[8]);