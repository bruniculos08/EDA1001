typedef struct Node node;
struct Node {
    int value;
    node *next;
};

node *insere(node *l, int newValue);
node *remover(node *l);