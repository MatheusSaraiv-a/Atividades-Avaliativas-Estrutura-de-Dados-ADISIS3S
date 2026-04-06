#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int isEmpty(Pilha *pilha) {
    return pilha->topo == NULL;
}

void push(Pilha *pilha, char valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para a pilha.\n");
        exit(1);
    }

    novo->dado = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

char pop(Pilha *pilha) {
    if (isEmpty(pilha)) {
        return '\0';
    }

    No *removido = pilha->topo;
    char valor = removido->dado;
    pilha->topo = removido->proximo;
    free(removido);
    return valor;
}

char peek(Pilha *pilha) {
    if (isEmpty(pilha)) {
        return '\0';
    }
    return pilha->topo->dado;
}

void liberarPilha(Pilha *pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}