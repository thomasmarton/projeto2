#include "string.h"
#include "password.h"

void codificar(char password[], char password2[]) {
    int len = strlen(password);

    strcpy(password2, password);
    for(int k = 0; k < len; k++) {
        password2[k] += SALTO;
    }
}

void descodificar(char password[], char password2[]) {
    int len = strlen(password);

    strcpy(password2, password);
    for(int k = 0; k < len; k++) {
        password2[k] -= SALTO;
    }
}