#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilizadores.h"
#include "uteis/ficheiros.h"

#define TAMANHO_MAXIMO 999

// Funcao para carregar um administrador
void carregarFicheiros(FILE *ficheiroAdministradores, FILE *ficheiroMedicos, FILE *ficheiroPacientes,
                       Utilizador *utilizadores, int *numeroUtilizadores,
                       Medico *medicos, int *numeroMedicos,
                       Paciente *pacientes, int *numeroPacientes) {
    int i = 0, n = 0;
    int index = 0;
    char item[TAMANHO_MAXIMO];
    char tmp[TAMANHO_MAXIMO];

    // preenche o array de estruturas Utilizador com os administradores
    while (fgets(item, TAMANHO_MAXIMO, ficheiroAdministradores)) {
        desfazerLinha(&index, utilizadores[i].nome, item);
        desfazerLinha(&index, utilizadores[i].password, item);

        utilizadores[i].tipo = ADMIN;
        i++;
    }

    // preenche o array de estruturas Medico e Utilizadores com os medicos
    while (fgets(item, TAMANHO_MAXIMO, ficheiroMedicos)) {
        desfazerLinha(&index, utilizadores[i].nome, item);
        desfazerLinha(&index, utilizadores[i].password, item);
        utilizadores[i].tipo = MEDICO;

        desfazerLinha(&index, tmp, item);
        medicos[n].numInternoProf = atol(tmp);

        desfazerLinha(&index, medicos[n].nomeM, item);

        desfazerLinha(&index, tmp, item);
        medicos[n].idade = atol(tmp);

        desfazerLinha(&index, tmp, item);
        medicos[n].espMedica = atol(tmp);

        desfazerLinha(&index, tmp, item);
        medicos[n].anosExp = atol(tmp);

        desfazerLinha(&index, medicos[n].localidade, item);

        desfazerLinha(&index, tmp, item);
        medicos[n].telefone = atol(tmp);

        desfazerLinha(&index, tmp, item);
        medicos[n].salario = atof(tmp);

        desfazerLinha(&index, medicos[n].horario, item);

        n++;
        i++;
    }
    *numeroUtilizadores = i;
    *numeroMedicos = n;

    // preenche o array de estruturas Paciente com os pacientes
    i = 0;
    index = 0;
    while (fgets(item, TAMANHO_MAXIMO, ficheiroPacientes)) {

        desfazerLinha(&index, tmp, item);

        pacientes[i].numInterno = atoi(tmp);
        printf("%d\n", pacientes[i].numInterno);

        desfazerLinha(&index, pacientes[i].nomeP, item);

        desfazerLinha(&index, tmp, item);
        pacientes[i].idade = atoi(tmp);

        desfazerLinha(&index, pacientes[i].sexo, item);
        desfazerLinha(&index, pacientes[i].localidade, item);

        desfazerLinha(&index, tmp, item);
        pacientes[i].telefone = atoi(tmp);

        desfazerLinha(&index, pacientes[i].problemaSaude, item);
        desfazerLinha(&index, pacientes[i].dtPrimConsulta, item);
        desfazerLinha(&index, pacientes[i].dtProxConsulta, item);
        desfazerLinha(&index, pacientes[i].sitClinica, item);
        desfazerLinha(&index, pacientes[i].nomeM, item);

        i++;
    }
    *numeroPacientes = i;
}

void atualizarMedicos(FILE *ficheiroMedicos, Utilizador utilizadores[], int numUtilizadores, Medico medicos[], int numeroMedicos) {
    int i;
    char texto[TAMANHO_MAXIMO];
    char linha[TAMANHO_MAXIMO];
    printf("numeroMedicos %d: \n", numeroMedicos);


    strcpy(texto, "");
    for (i = 0; i < numeroMedicos; i++) {
        sprintf(linha, "%s;%s;%d;%s;%d;%d;%d;%s;%d;%f;%s\n",
                utilizadores[i+numUtilizadores-numeroMedicos].nome,
                utilizadores[i+numUtilizadores-numeroMedicos].password,
                medicos[i].numInternoProf,
                medicos[i].nomeM,
                medicos[i].idade,
                medicos[i].espMedica,
                medicos[i].anosExp,
                medicos[i].localidade,
                medicos[i].telefone,
                medicos[i].salario,
                medicos[i].horario
        );
        strcat(texto, linha);
    }
    fputs(linha, ficheiroMedicos);
}

void atualizarPacientes(FILE * ficheiroPacientes, Paciente pacientes[], int numPacientes) {
    int i;
    char texto[TAMANHO_MAXIMO];
    char linha[TAMANHO_MAXIMO];
    printf("numeroMedicos %d: \n", numPacientes);


    strcpy(texto, "");
    for (i = 0; i < numPacientes; i++) {
        sprintf(linha, "%d;%s;%d;%c;%s;%d;%s;%s;%s;%s;%s;%s\n",
                pacientes[i].numInterno,
                pacientes[i].nomeP,
                pacientes[i].idade,
                pacientes[i].sexo,
                pacientes[i].localidade,
                pacientes[i].telefone,
                pacientes[i].problemaSaude,
                pacientes[i].dtPrimConsulta,
                pacientes[i].dtProxConsulta,
                pacientes[i].sitClinica,
                pacientes[i].nomeM,
                pacientes[i].espMedica
        );
        strcat(texto, linha);
    }
    fputs(linha, ficheiroPacientes);
}