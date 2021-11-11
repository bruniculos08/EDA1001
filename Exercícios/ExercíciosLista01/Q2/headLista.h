typedef struct Node node;

struct Node{
    int value;
    node *next;
    node *before;
};
node *remover(node *l, int removedValue);
void imprime(node *l);
node *insereOrdenado(node *l, int newValue);
node *atualizar(node *l, int newValue, int posiList);
void buscar(node *l, int value);
node *ponteiro(node *l, int position);
node *troca(node *l, node *trocaNodo);