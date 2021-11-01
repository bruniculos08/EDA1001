typedef struct Tarefa tarefa;
typedef struct Reg reg;
typedef struct Tempo tempo;
struct Tempo {
    int minuto, hora, ano, dia, mes;
};
struct Reg {
    char nome[50];
    int duracao;
    tempo deadline;
    int prioridade;
};
struct Tarefa {
    int id;
    reg dados;
    tarefa *next;
};
tarefa *geraTarefa(tarefa *l);
tarefa *insereTarefa(tarefa *l, tarefa *novaTarefa);
tarefa *removerTarefa(tarefa *l, int idRemover);
tarefa *alterarTarefa(tarefa *l, int idAlterar);
tarefa *verTarefas(tarefa *l);
int dataAnterior(tempo a, tempo b);
void indicarTarefa(tarefa *l);