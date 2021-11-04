typedef struct Node node;

struct Node{
    int value;
    node *next;
    node *before;
};
node *buscar(node *l, int newValue);
node *remover(node *l, int removedValue);
node *insereFim(node *l, int newValue);
node *insereOrdenado(node *l, int newValue);