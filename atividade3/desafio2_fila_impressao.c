#include <stdio.h>
#include "fila_impressao.h"

int main(void) {
    FilaImpressao fila;
    int n;
    int id;
    int paginas;
    int prioridade;

    inicializarFilaImpressao(&fila);

    printf("Digite a quantidade de documentos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Documento %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Numero de paginas: ");
        scanf("%d", &paginas);
        printf("Prioridade (menor valor = maior prioridade): ");
        scanf("%d", &prioridade);
        inserirDocumento(&fila, id, paginas, prioridade);
    }

    printf("\nOrdem de impressao:\n");
    while (removerDocumento(&fila, &id, &paginas, &prioridade)) {
        printf("Documento ID %d | Paginas: %d | Prioridade: %d\n", id, paginas, prioridade);
    }

    return 0;
}
