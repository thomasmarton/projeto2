#define TAMANHO_MAXIMO 999

// Librarias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Headers
#include "utilizadores.h"
#include "uteis/ficheiros.h"
#include "uteis/password.h"


// Funcao para imprimir o menu
void menu() {
    printf("\n\n");
    printf("\t------------------------\n");
    printf("\t|  Unidade Hospitalar  |\n");
    printf("\t------------------------\n");
    printf("\t| 1 - Opcao ???        |\n");
    printf("\t| 2 - Opcao ???        |\n");
    printf("\t| 3 - Opcao ???        |\n");
    printf("\t| 4 - Opcao ???        |\n");
    printf("\t| 5 - Opcao ???        |\n");
    printf("\t| 0 - Sair do Programa |\n");
    printf("\t------------------------\n");
    printf("\n");
}

// Funcao para realizar o login
int login (Utilizador utilizadores[], int numUtilizadores) {
    char nome[20], password[20];
    int i = 0;
    int x = 0;

    do {
        printf("\n\t-------------------------\n");
        printf("\t          Login          \n");
        printf("\t-------------------------\n");
        printf("\t| Username: ");
        gets(nome);
        printf("\n\t| Palavra-passe: ");
        gets(password);
        printf("\t-------------------------\n");

        codificar(password, password);
        for (i = 0 ; i < numUtilizadores ; i++) {
            if(strcmp(nome, utilizadores[i].nome) == 0 && strcmp(password, utilizadores[i].password) == 0) {
                x = 1;
            }
        }

        if (x == 0) {
            printf("\n\t| Nome do Utilizador ou palavra-passe incorretos!");
        } else {
            printf("\n\t| Bem-vindo de volta!");
        }
    } while(x == 0);
    return utilizadores[i].tipo; // 1 --> Administrador ou 2 --> Cliente
}


// Funcao principal do programa
int main() {
    // UTF-8
    setlocale(LC_ALL, "Portuguese");

    // Dados dos ficheiros
    Utilizador utilizadores[TAMANHO_MAXIMO];
    Medico medicos[TAMANHO_MAXIMO];
    Paciente pacientes[TAMANHO_MAXIMO];
    int numUtilizadores = 0, numMedicos = 0, numPacientes = 0;

    // Variaveis dos ficheiros
    FILE *ficheiroAdministradores, *ficheiroMedicos, *ficheiroPacientes;

    int opcao;
    int i;


    // Código
    ficheiroAdministradores = fopen("../data/utilizadores.txt", "r");
    if (ficheiroAdministradores == NULL) {
        printf("Ficheiro utilizadores.txt não existe");
    }
    ficheiroMedicos = fopen("../data/medicos.txt", "r");
    if (ficheiroMedicos == NULL) {
        printf("Ficheiro medicos.txt não existe");
    }
    ficheiroPacientes = fopen("../data/pacientes.txt", "r");
    if (ficheiroPacientes == NULL) {
        printf("Ficheiro pacientes.txt não existe");
    }
    carregarFicheiros(
            ficheiroAdministradores, ficheiroMedicos, ficheiroPacientes,
            utilizadores, &numUtilizadores,
            medicos, &numMedicos,
            pacientes, &numPacientes);

    fclose(ficheiroAdministradores);
    fclose(ficheiroMedicos);
    fclose(ficheiroPacientes);

    printf("Utilizadores %d\n", numUtilizadores);
    printf("Medicos %d\n", numMedicos);
    printf("Pacientes %d\n", numPacientes);

    ficheiroMedicos = fopen("../data/medicos.txt", "w");
    ficheiroPacientes = fopen("../data/pacientes.txt", "w");

    atualizarMedicos(ficheiroMedicos, utilizadores, numUtilizadores, medicos, numMedicos);
    fclose(ficheiroAdministradores);
    fclose(ficheiroMedicos);
    fclose(ficheiroPacientes);


    printf("\n\tProjeto realizado pelos alunos:\n");
    printf("\t\tAndré Matos de Sousa\n");
    printf("\t\tLuís Diogo Silva Carreira\n");
    printf("\t\tHugo Abel Rodrigues Félix Vieira\n");

    login(utilizadores, numUtilizadores);

    do {
        // Imprimir menu
        menu();

        // Perguntar ao utilizador qual a opcao que deseja
        printf("\n\tOpcao? ");
        scanf("%i", &opcao);
    
        // Switch
        switch (opcao) {
            // Opcao ???
            case 0:
                printf("\n\n\tFim do Programa!");
                break;

            // Opcao ???
            case 1:
                printf("\n\n\tOpcao 1 selecionada!");
                break;

            // Opcao ???
            case 2:
                printf("\n\n\tOpcao 2 selecionada!");
                break;

            // Opcao ???
            case 3:
                printf("\n\n\tOpcao 3 selecionada!");
                break;

            // Opcao ???
            case 4:
                printf("\n\n\tOpcao 4 selecionada!");
                break;

            // Opcao ???
            case 5:
                printf("\n\n\tOpcao 5 selecionada!");
                break;

            // Opcao ???
            default:
                printf("\n\n\tOpcao Invalida!");
                break;
        }
    } while (opcao != 0);

    return 1;
}