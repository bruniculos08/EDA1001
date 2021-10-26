typedef struct Lista lista;
struct Lista {
    int number;         //^ o que a lista armazena
    lista *next;        //^ ponteiro para o próximo elemento da lista 
};

lista *removeLista(lista *totalList, int n);
lista *newList(int n);
lista *insertEnd(lista *totalList, lista *newList);
lista *insertOrder(lista *totalList, lista *newList);
lista *insertStart(lista *totalList, lista *newList);
int posiList (lista *totalList, int n);
void printAllList(lista *totalList);
int tamanhoLista(lista *totalList);
//^ foi necessário fazer toda a declarações da estrutura lista em HeadListaEncadeada.h para
//^ evitar erros