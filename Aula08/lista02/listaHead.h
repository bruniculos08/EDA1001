typedef struct Fila fila;
struct Fila{
    node *start;
    node *end;
};

typedef struct Node node;
struct Node{
    int value;
    node *next;
};

void *insere(fila *l, int newValue);
int remover(fila *l);