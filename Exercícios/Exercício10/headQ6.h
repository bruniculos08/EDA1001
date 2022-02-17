typedef struct Node node;
struct Node{
	int number;
	node * next;
};

node *insere(node *l, int valor);
node *remover(node *l, int position);
node *merge(node *l1, node *l2);
node *split(node *l);
node *truque(node *l);
void imprimir(node *l);