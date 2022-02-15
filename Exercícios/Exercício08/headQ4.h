typedef struct Voto voto;
struct Voto{
    int hora;
    char *candidato;
    voto *next;
};
voto *insere(voto *lista);
voto *split(voto *lista);
voto *merge(voto *a, voto *b);
voto *mergeSort(voto *lista);