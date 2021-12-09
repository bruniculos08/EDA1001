typedef struct Node node;
struct Node{
	int number;
	node * next;
};
node *trocanode(node *l, node *l1, node *l2);
void imprimir(node *l);
node *insereInicio(node *l);
node *insereFinal(node *l);
node *split(node *l);
node *quickSort(node *l);