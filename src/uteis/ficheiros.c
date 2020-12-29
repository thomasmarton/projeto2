#include "ficheiros.h"


// Funcao para
void desfazerLinha(int *i, char *var, const char *texto) {
    int n = 0;
    while (texto[*i] != '\n' && texto[*i] != ';') {
        var[n] = texto[*i];
        n++;
        (*i)++;
    }
    // adicionar o final da string
    var[n] = '\0';

    if (texto[*i] == '\n') {
        (*i) = 0;
    } else {
        (*i)++;
    }
}
