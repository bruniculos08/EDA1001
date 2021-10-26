#include <stdio.h>
#include <math.h>

int main(void) {
    int testes, n;
    scanf("%d", &testes);
    for (int j = 0; j < testes; j++) {
        scanf("%d", &n);
    if (n%2 == 0 && n !=2) {
        printf("Not Prime\n");
        return 0;
    }
    else for (int i=1; i < n; i += 2) {
        if (n%(i+2))
        {
            printf("Not Prime\n");
            return 0;
        }
    }
    printf("Prime\n");
    }
}