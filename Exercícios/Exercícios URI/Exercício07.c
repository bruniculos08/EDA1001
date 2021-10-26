#include <stdio.h>
#include <math.h>

int primo(int n) {
    if (n%2 == 0 && n !=2) {
        return 1;
    }
    else for (int i=1; i < sqrt(n); i = i + 2) {
        if (n%(i+2)==0 && n != 3) 
        {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int testes, n;
    scanf("%d", &testes);
    for (int j = 0; j < testes; j++) {
        scanf("%d", &n);
            if (primo(n) == 1)
            {
                printf("Not Prime\n");
            }   
            else {
                printf("Prime\n");
            }   
    }
}