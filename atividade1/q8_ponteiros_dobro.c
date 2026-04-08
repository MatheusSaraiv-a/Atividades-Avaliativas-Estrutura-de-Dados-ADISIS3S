#include <stdio.h>

int main(void) {
    int array[5];
    int *ptr = array;

    printf("Digite 5 numeros inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", ptr + i);
    }

    printf("Dobro dos valores:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i) * 2);
    }
    printf("\n");

    return 0;
}
