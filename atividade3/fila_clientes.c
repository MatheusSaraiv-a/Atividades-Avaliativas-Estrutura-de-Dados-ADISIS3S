#include <stdio.h>
#include <stdlib.h>
#include "fila_clientes.h"

void inicializarFilaClientes(FilaClientes *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaClientesVazia(FilaClientes *fila) {
    return fila->inicio == NULL;
}

void enqueueCliente(FilaClientes *fila, int id, int tempoAtendimento) {
    NoCliente *novo = (NoCliente *)malloc(sizeof(NoCliente));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para cliente.\n");
        exit(1);
    }

    novo->id = id;
    novo->tempoAtendimento = tempoAtendimento;
    novo->proximo = NULL;

    if (filaClientesVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

int dequeueCliente(FilaClientes *fila, int *id, int *tempoAtendimento) {
    if (filaClientesVazia(fila)) {
        return 0;
    }

    NoCliente *removido = fila->inicio;
    *id = removido->id;
    *tempoAtendimento = removido->tempoAtendimento;
    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);
    return 1;
}

void liberarFilaClientes(FilaClientes *fila) {
    int id, tempoAtendimento;
    while (dequeueCliente(fila, &id, &tempoAtendimento)) {
    }
}