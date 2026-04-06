#ifndef FILA_CLIENTES_H
#define FILA_CLIENTES_H

typedef struct NoCliente {
    int id;
    int tempoAtendimento;
    struct NoCliente *proximo;
} NoCliente;

typedef struct {
    NoCliente *inicio;
    NoCliente *fim;
} FilaClientes;

void inicializarFilaClientes(FilaClientes *fila);
int filaClientesVazia(FilaClientes *fila);
void enqueueCliente(FilaClientes *fila, int id, int tempoAtendimento);
int dequeueCliente(FilaClientes *fila, int *id, int *tempoAtendimento);
void liberarFilaClientes(FilaClientes *fila);

#endif
