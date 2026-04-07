#include <stdio.h>

int ordenarValores(int *a, int *b, int *c) {
    int temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }

    return (*a == *b && *b == *c) ? 1 : 0;
}

int main(void) {
    int x, y, z;
    int iguais;

    printf("Digite tres valores inteiros:\n");
    scanf("%d %d %d", &x, &y, &z);

    iguais = ordenarValores(&x, &y, &z);

    printf("Valores ordenados: %d %d %d\n", x, y, z);
    printf("Retorno da funcao: %d\n", iguais);

    return 0;
}
