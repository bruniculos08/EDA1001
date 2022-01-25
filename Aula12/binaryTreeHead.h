typedef struct Raiz raiz;
struct Raiz{
    int valor;
    raiz *dir;
    raiz *esq;
};
raiz *buscar(raiz *l, int valor);
raiz *buscar_pai(raiz *l, int valor);
raiz *insere(raiz *l, int valor);
raiz *remover(raiz *l, int valor);
raiz *remover_node(raiz *node);
void imprime(raiz *l);