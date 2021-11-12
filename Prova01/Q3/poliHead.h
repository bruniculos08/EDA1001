typedef struct Polinomio polinomio;
struct Polinomio{ //^ polinômio na forma ax^b supondo que sejam apenas expoentes inteiros
    float a;
    int b;
    polinomio *prox;
};
void mostrar(polinomio *p);
float calcular(polinomio *p, float x);