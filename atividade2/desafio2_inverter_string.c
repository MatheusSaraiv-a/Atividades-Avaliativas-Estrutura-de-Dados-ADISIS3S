#include <stdio.h>
#include "pilha.h"

void inverterString(char *texto) {
    Pilha pilha;
    inicializarPilha(&pilha);

    int i = 0;

    while (texto[i] != '\0') {
        push(&pilha, texto[i]);
        i++;
    }

    i = 0;

    while (!isEmpty(&pilha)) {
        texto[i] = pop(&pilha);
        i++;
    }

    texto[i] = '\0';
}

int main(void) {
    char texto[300];

    printf("Digite uma string: ");
    scanf(" %299[^\n]", texto);

    inverterString(texto);

    printf("String invertida: %s\n", texto);

    return 0;
}
