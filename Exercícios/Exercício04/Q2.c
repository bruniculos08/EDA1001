#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Lista lista;
struct Lista {
    char letra;
    lista *next;
};

int vogal(char a);
int vogal(char a){
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
        return 0;
    }
    return 1;
}

lista *insere(lista *l, char a){
    lista *palavra;
    palavra = l;
    if (palavra == NULL){
        palavra = (lista *) malloc(sizeof(lista));
        palavra->letra = a;
        palavra->next = NULL;
        return palavra;
    }
    while (palavra->next != NULL){
        palavra = palavra->next;
    }
    palavra->next->letra = a;
    return l;
}

int main(){
    lista *nome;
    nome = NULL;
    int n;
    scanf("%i", &n);
    char sobre[n];
    scanf("%s", sobre);
    for(int i = 0; i < n; i++){
        printf("letra");
        nome = insere(nome, sobre[i]);
    }

    if (nome == NULL || nome->next == NULL){
        printf("Sobrenome facil 1.\n");
        return 0;
    }
    while(nome->next != NULL){
        if(vogal(nome->letra) == vogal(nome->next->letra)){
            printf("Sobrenome dificil.\n");
            return 1;
        }
        nome = nome->next;
    }
    printf("Sobrenome facil.\n");
    return 1;
}