#ifndef PILHA_H
#define PILHA_H

typedef struct No {
    char dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializarPilha(Pilha *pilha);
int isEmpty(Pilha *pilha);
void push(Pilha *pilha, char valor);
char pop(Pilha *pilha);
char peek(Pilha *pilha);
void liberarPilha(Pilha *pilha);

#endif