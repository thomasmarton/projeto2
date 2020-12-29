#include <stdio.h>

#define ADMIN 1                                                 // 1 --> Administrador
#define MEDICO 2                                                // 2 --> Cliente

typedef struct {
    char nome[20];
    char password[20];
    int tipo;
} Utilizador;

typedef struct {
    int numInternoProf;
    char nomeM[90];
    int idade;
    int espMedica;
    int anosExp;
    char localidade[30];
    int telefone;
    double salario;
    char horario[20];
} Medico;

typedef struct {
    int numInterno;
    char nomeP[90];
    int idade;
    char sexo;
    char localidade[50];
    int telefone;
    char problemaSaude[50];
    char dtPrimConsulta[10];
    char dtProxConsulta[10];
    char sitClinica[255];
    char nomeM[90];
    char espMedica[30];
} Paciente;

void carregarFicheiros(FILE *ficheiroAdministradores, FILE *ficheiroMedicos, FILE *ficheiroPacientes,
                       Utilizador *utilizadores, int *numeroUtilizadores,
                       Medico *medicos, int *numeroMedicos,
                       Paciente *pacientes, int *numeroPacientes);

void atualizarMedicos(FILE *ficheiroMedicos, Utilizador utilizadores[], int numUtilizadores, Medico medicos[], int numeroMedicos);