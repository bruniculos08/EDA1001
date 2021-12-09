typedef struct Node node;
struct Node{
	int number;
	node * next;
};

node *trocaNode(node *l, node *l1, node *l2);
node *insere(node *l, int valor);
node *moveInicio(node *l, node *v);
node *moveFinal(node *l, node *v);
node *split(node *l);
node *quickSort(node *l);
void imprime(node *l);