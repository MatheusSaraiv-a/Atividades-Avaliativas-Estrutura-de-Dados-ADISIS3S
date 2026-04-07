#include <stdio.h>
#include "pilha.h"

int ehAbertura(char c) {
    return c == '(' || c == '[' || c == '{';
}

int ehFechamento(char c) {
    return c == ')' || c == ']' || c == '}';
}

int corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

int expressaoValida(const char *expressao) {
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        char atual = expressao[i];

        if (ehAbertura(atual)) {
            push(&pilha, atual);
        } else if (ehFechamento(atual)) {
            if (isEmpty(&pilha)) {
                liberarPilha(&pilha);
                return 0;
            }

            char topo = pop(&pilha);
            if (!corresponde(topo, atual)) {
                liberarPilha(&pilha);
                return 0;
            }
        }
    }

    int valida = isEmpty(&pilha);
    liberarPilha(&pilha);
    return valida;
}

int main(void) {
    char expressao[300];

    printf("Digite a expressao: ");
    scanf(" %299[^\n]", expressao);

    if (expressaoValida(expressao)) {
        printf("Expressao valida.\n");
    } else {
        printf("Expressao invalida.\n");
    }

    return 0;
}