#ifndef FILA_IMPRESSAO_H
#define FILA_IMPRESSAO_H

typedef struct NoDocumento {
    int id;
    int paginas;
    int prioridade;
    struct NoDocumento *proximo;
} NoDocumento;

typedef struct {
    NoDocumento *inicio;
} FilaImpressao;

void inicializarFilaImpressao(FilaImpressao *fila);
int filaImpressaoVazia(FilaImpressao *fila);
void inserirDocumento(FilaImpressao *fila, int id, int paginas, int prioridade);
int removerDocumento(FilaImpressao *fila, int *id, int *paginas, int *prioridade);
void liberarFilaImpressao(FilaImpressao *fila);

#endif
