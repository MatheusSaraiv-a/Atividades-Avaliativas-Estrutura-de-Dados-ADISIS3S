#include <stdio.h>

int main(void) {
    char palavra1[50], palavra2[50], palavra3[50];

    printf("Digite tres palavras:\n");
    scanf("%49s %49s %49s", palavra1, palavra2, palavra3);

    printf("Ordem inversa: %s %s %s\n", palavra3, palavra2, palavra1);
    return 0;
}
