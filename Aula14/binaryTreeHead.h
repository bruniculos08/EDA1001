typedef struct Raiz raiz;
struct Raiz{
    int valor;
    int bal;
    raiz *dir;
    raiz *esq;
};
raiz *insere(raiz *l, int valor);
raiz *remover(raiz *l, int valor);
raiz *remover_node(raiz *node);
raiz *buscar(raiz *l, int valor);
raiz *buscar_pai(raiz *l, int valor);
int altura(raiz *l);
int profundidade(raiz *l, int valor);
int teste_AVL(raiz *l);
void imprime(raiz *l);
raiz *rotaciona_esq(raiz *x);
raiz *rotaciona_dir(raiz *x);
raiz *balancear(raiz *l, raiz *node);