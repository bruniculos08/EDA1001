//* Aqui é o header (cabeçalho) onde são colocadas as declarações
typedef struct ponto Ponto;

Ponto* cria (float x, float y);
void libera (Ponto* p);
void acessa (Ponto* p, float* x, float* y);
void atribui (Ponto* p, float x, float y);
float distancia (Ponto* p1, Ponto* p2);