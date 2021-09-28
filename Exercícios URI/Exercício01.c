#include <stdio.h>


int main(void) {
    double A, B;
    //do
    //{
    scanf("%lf %lf", &A, &B);
    //} while (A < 0 || B < 0 || A > 10 || B > 10); 
    
    A = A * 3.5;
    B = B * 7.5;
    double M;
    M = (A+B)/11;

    printf("MEDIA = %.5lf", M);
    printf("\n");
}