#include <stdio.h>


int num;
int func(int a, int b){
    a = (a+b)/2;
    num = num - a;
    return a;
}
int main() {    
    int first = 0, second = 1;
    num = 10;
    num = num + func(first, second); //& note, a função é chamada antes da soma (por que é necessário),
                                     //& logo num é alterado antes do final da soma.
    printf("%d\n", num);
}