typedef struct Aluno aluno;
struct Aluno{
    int matricula;
    char nome[50];
    double nota;
    aluno *prox;
    aluno *ant;
};
double mediana(aluno *l);
int tamanhoLista(aluno *l);
void alunosPertoMediana(aluno *l);
double calcula_mediana(aluno *l);