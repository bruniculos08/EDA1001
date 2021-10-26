typedef struct reg funcionario;
struct reg{
	int cod;
	char nome[60];
	float salario;
};
int N;
funcionario *vetor;
void mostraMenu();
void imprimeTodos(funcionario v[]);
void imprimePos(funcionario v[], int pos);
int maiorSalario(funcionario v[]);
int menorSalario(funcionario v[]);
float mediaSalarios(funcionario v[]);
void incluiFuncionario();
void removeFuncionario();