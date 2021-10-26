#include <stdio.h>


int main(void) {
    int valores[10], maior;
    for (int i = 0; i < 100; i++) {
        scanf("%d\n", &valores[i]);
    }

    maior = 0;
    for (int i = 0; i < 101; i++) {
        if (maior < valores[i]) maior = valores[i];
    }
    printf("%d", maior);
    printf("\n");
}