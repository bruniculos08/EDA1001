#include <stdio.h>


struct hora {
    int horas;
    int minutos;
} Hora;

void numero_horas(int minutos) {
    int h = minutos/60;
    int m = minutos%60;
    Hora.horas = h;
    Hora.minutos = m;
}

int main(){
    int minutos;
    scanf("%d", &minutos);
    numero_horas(minutos);
    printf("%d:%d\n", Hora.horas, Hora.minutos);
}
