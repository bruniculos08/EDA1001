//* Listas simplemente encadeadas
#include <stdio.h>

typedef struct List {
    int number;       //^ o que a lista armazena
    list *next;       //^ ponteiro para o próximo elemento da lista 
} list;

list *newList(int n){ //^ retorna o endereço de um novo elemento da lista (new)
    list *new;
    new = (list *)malloc(sizeof(list)); //^ new se torna endereço de uma memória alocada
    new->number = n;
    new->next = NULL;
    return new;       //^ retorna o endereço de um novo elemento da lista (new)                                            
}   

list *addList(list *totalList, list *newList){ //^ iremos retornar o endereço da própria lista por garantia
    list *p;
    p = totalList;
    if (totalList != NULL)
    {
        while (p != NULL){
            p = totalList->next;
            //^ Note que há a atribuição entre uma varíavel que guarda um endereço (p)
            //^ e uma que "guarda" um conteúdo (totalList->next) que é possível
            //^ pois este conteúdo armazenado é um endereço (next é um endereço,...
            //^ ... o que é diferente de *next nesta situação).
        }; 
        p->next = newList; 
        //^ o ponteiro *next do penúltimo elemento da lista irá apontar para o mais
        //^ novo elemento da lista, ou seja, a variável (de endereço) next do
        //^ penúltimo elemento da lista recebe o endereço do último elemento da lista
    }
    else {
        totalList = newList;
        //? caso a lista passada esteja vazia ela então apontará para a nova lista
    }

    return totalList;
    //^ retorna o endereço da própria lista para garantia
}

int main(void) {

}