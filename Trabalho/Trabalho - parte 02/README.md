# Trabalho de EDA 01
**Aluno:** Bruno Rafael dos Santos


## Tutorial de utilização do software de agendamento de tarefas
1. Insira os arquivos agenda.c, headAgenda.c e headAgenda.h em uma pasta e inicie o código a partir de um terminal utilizando o seguinte comando:
```
cd "Diretório" ; if ($?) { gcc *.c -o agenda } ; if ($?) { .\agenda }
```
2. Insira um dos números presentes no seguinte menu:
```
|-------------------------------------|
|    CADASTRO DE TAREFA               |
|-------------------------------------|
|     MENU DE OPCOES                  |
|-------------------------------------|
| 1 - Incluir nova tarefa             |
| 2 - Visualizar tarefas cadastradas  |
| 3 - Excluir tarefas                 |
| 4 - Editar tarefa                   |
| 5 - Indicar a tarefa do momento     |
| 0 - Sair                            |
|-------------------------------------|
```
3. Escolhendo a opção '1' o programa irá solicitar a data, duração, prioridade e nome da tarefa a ser inserida, assim se terá o seguinte no terminal:
```
Digite a hora: (exemplo)
Digite o minuto: (exemplo)
Digite o dia: (exemplo)
Digite o dia: (exemplo)
Digite o mes: (exemplo)
Digite o ano: (exemplo)
Digite a quantidade de minutos de duracao: (exemplo)
Digite a quantidade de horas de duracao: (exemplo)
Digite a quantidade de dias de duracao: (exemplo)
Digite a quantidade de meses de duracao: (exemplo)
Digite a quantidade de anos de duracao: (exemplo)
Digite a prioridade: (exemplo)
Digite o nome: (exemplo)
```
4. Escolhendo a opção '2' o programa irá apresentar todos os dados de cada uma das tarefas, incluindo o ID qual é gerado aleatóriamente, da seguinte maneira:
```
exemplo
ID: 11398
Duracao: 5 minutos, 0 horas, 0 dias, 0 meses e 0 anos.
Data: 10/10/2222 20:0
Prioridade: 5
```
5. Escolhendo a opção '3' o programa irá solicitar o ID da tarefa qual se deseja excluir, assim se tal ID existir o programa não irá imprimir no terminal, caso contrário será apresentada a seguinte mensagem no terminal:
```
A tarefa a ser removida nao foi encontrada.
```
6. Escolhendo a opção '4' será solicitado pelo programa o ID da tarefa a ser editada e após isso, caso o ID seja válido, será apresentado o seguinte menu do qual o usuário deverá inserir um dos números presentes no terminal:
```
Digite o elemento a ser alterado:
1- Nome
2- Duracao
3- Deadline
4- Prioridade
0- Sair
```
7. Escolhendo a opção '5' o programa irá apresentar o nome da tarefa atualmente indicada pelo mesmo de acordo com os critérios de diferença de tempo em relação a tarefa seguinte, duração e prioridade, assim haverá a seguinte mensagem no terminal (supondo que a lista de tarefas não esteja vazia):
```
Tarefa indicada: exemplo
```
8. Escolhendo a opção '0' o programa irá encerrar e assim a lista de tarefas será perdida (não é salva).
