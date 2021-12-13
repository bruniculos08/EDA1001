typedef struct Node node;
struct Node{
	int number;
	node * next;
};
node *limpar(node *l);
node *insere(node *l, int valor);
node *moveInicio(node *l, node *v);
node *moveFinal(node *l, node *v);
node *split(node *l);
node *merge(node *l1, node *l2);
node *quickSort(node *l);
node *half(node *l, node *r);
node *remover(node *l, int position);
void imprime(node *l);