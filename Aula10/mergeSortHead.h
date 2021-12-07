typedef struct Node node;

struct Node{
	int number;
	node * next;
};
node *insere_fim(node *l, int valor);
node *insere_ordenado(node *l, int valor);
int profundidade(node *l, int valor);
void imprimir(node *l);
node *inicializa();
int conta_nos(node *l);
node *liberar(node *l);
node *remover(node *l, int position);
node *trocanode(node *l, node *l1, node *l2);
node *ponteiro(node *l, int position);
node *mergeSort(node *l);
node *split(node *l);