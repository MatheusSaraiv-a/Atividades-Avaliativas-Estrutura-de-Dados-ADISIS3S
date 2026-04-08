#include <stdio.h>
#include "fila_clientes.h"

int main(void) {
    FilaClientes fila;
    int n;
    int id;
    int tempoAtendimento;
    int tempoEspera = 0;

    inicializarFilaClientes(&fila);

    printf("Digite a quantidade de clientes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Cliente %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Tempo de atendimento (minutos): ");
        scanf("%d", &tempoAtendimento);
        enqueueCliente(&fila, id, tempoAtendimento);
    }

    printf("\nSimulacao de atendimento:\n");
    while (dequeueCliente(&fila, &id, &tempoAtendimento)) {
        printf("Cliente ID %d atendido. Tempo de espera: %d minutos\n", id, tempoEspera);
        tempoEspera += tempoAtendimento;
    }

    return 0;
}
