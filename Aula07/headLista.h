typedef struct Node node;

struct Node{
    int value;
    node *next;
    node *before;
};
node *remover(node *l, int removedValue);
node *insereFim(node *l, int newValue);
node *insereOrdenado(node *l, int newValue);
node *atualizar(node *l, int newValue, int posiList);
void buscar(node *l, int value);