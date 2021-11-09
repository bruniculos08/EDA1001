typedef struct Ponto ponto;
struct Ponto {
    double x, y;
};


typedef struct Personagem Personagem;
struct Personagem {
    char nome[50];
    ponto position;
    double life;
};