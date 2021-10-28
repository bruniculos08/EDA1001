typedef struct Node node;

struct Node{
    int value;
    node *next;
    node *before;
};
node *insere(node *l, int newValue);
node *buscar(node *l, int newValue);
node *remover(node *l, int removedValue);
//^ resto...