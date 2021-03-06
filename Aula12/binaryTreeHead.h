typedef struct Raiz raiz;
struct Raiz{
    int valor;
    raiz *dir;
    raiz *esq;
};
raiz *insere(raiz *l, int valor);
raiz *remover(raiz *l, int valor);
raiz *remover_node(raiz *node);
raiz *buscar(raiz *l, int valor);
raiz *buscar_pai(raiz *l, int valor);
void imprime(raiz *l);