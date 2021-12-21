typedef struct Raiz raiz;
struct Raiz{
    int valor;
    raiz *dir;
    raiz *esq;
};
raiz *insere(raiz *l, int valor);
raiz *remover(raiz *l, int valor);
int altura(raiz *l);
int profundidade(raiz *l, raiz *v);