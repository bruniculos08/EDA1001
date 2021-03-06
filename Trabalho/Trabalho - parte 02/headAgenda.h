typedef struct Tarefa tarefa;
typedef struct Reg reg;
typedef struct Tempo tempo;
struct Tempo {
    int minuto, hora, ano, dia, mes;
};
struct Reg {
    char nome[50];
    tempo duracao; //^ trocar depois de int para tempo (quantidade de minutos, horas, dias, meses e anos)
    tempo deadline;
    int prioridade;
};
struct Tarefa {
    int id;
    reg dados;
    tarefa *next;
};
tarefa *atualizarTarefas(tarefa *l);
tarefa *geraTarefa(tarefa *l);
tarefa *insereTarefa(tarefa *l, tarefa *novaTarefa);
tarefa *removerTarefa(tarefa *l, int idRemover);
tarefa *alterarTarefa(tarefa *l, int idAlterar);
void verTarefas(tarefa *l);
int dataAnterior(tempo a, tempo b);
int dataPassada(tempo a);
long tempoRank(tempo *a); 
int tamanhoTarefas(tarefa *l);
tarefa *mergeSort(tarefa *l);
tarefa *split(tarefa *l);
tarefa *indicarTarefa(tarefa *l);