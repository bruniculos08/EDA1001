#include <stdio.h>


void trocaVariavel(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    trocaVariavel(&a, &b);
    printf("a = %d, b = %d", a, b);
}