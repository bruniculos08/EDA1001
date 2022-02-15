typedef struct Raiz raiz;
struct Raiz{
    int valor;
    raiz *dir;
    raiz *esq;
};
void imprime(raiz *l);
void deitaArvore(raiz *l);
raiz *insere(raiz *l, int valor);
