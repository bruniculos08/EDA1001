typedef struct Raiz raiz;
struct Raiz{
    int valor;
    int bal;
    raiz *dir;
    raiz *esq;
};
void imprime(raiz *l);
int altura(raiz *l);
int profundidade(raiz *l, int valor);
int testeAVL(raiz *l);
raiz *insere(raiz *l, int valor);
raiz *remover(raiz *l, int valor);
raiz *removerNode(raiz *node);
raiz *buscar(raiz *l, int valor);
raiz *buscarPai(raiz *l, int valor);
raiz *buscarDescendente(raiz *node);
raiz *rotacionaEsq(raiz *x);
raiz *rotacionaDir(raiz *x);
raiz *balancear(raiz *l, raiz *node);