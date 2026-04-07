#include <stdio.h>
#include <stdlib.h>
#include "fila_impressao.h"

void inicializarFilaImpressao(FilaImpressao *fila) {
    fila->inicio = NULL;
}

int filaImpressaoVazia(FilaImpressao *fila) {
    return fila->inicio == NULL;
}

void inserirDocumento(FilaImpressao *fila, int id, int paginas, int prioridade) {
    NoDocumento *novo = (NoDocumento *)malloc(sizeof(NoDocumento));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para documento.\n");
        exit(1);
    }

    novo->id = id;
    novo->paginas = paginas;
    novo->prioridade = prioridade;
    novo->proximo = NULL;

    if (filaImpressaoVazia(fila) || prioridade < fila->inicio->prioridade) {
        novo->proximo = fila->inicio;
        fila->inicio = novo;
        return;
    }

    NoDocumento *atual = fila->inicio;
    while (atual->proximo != NULL && atual->proximo->prioridade <= prioridade) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

int removerDocumento(FilaImpressao *fila, int *id, int *paginas, int *prioridade) {
    if (filaImpressaoVazia(fila)) {
        return 0;
    }

    NoDocumento *removido = fila->inicio;
    *id = removido->id;
    *paginas = removido->paginas;
    *prioridade = removido->prioridade;
    fila->inicio = removido->proximo;
    free(removido);
    return 1;
}

void liberarFilaImpressao(FilaImpressao *fila) {
    int id, paginas, prioridade;
    while (removerDocumento(fila, &id, &paginas, &prioridade)) {
    }
}
