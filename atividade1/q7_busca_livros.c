#include <stdio.h>
#include <string.h>

#define TOTAL_LIVROS 5

typedef struct {
    char titulo[31];
    char autor[16];
    int ano;
} Livro;

int main(void) {
    Livro livros[TOTAL_LIVROS];
    char busca[31];
    int encontrou = 0;

    for (int i = 0; i < TOTAL_LIVROS; i++) {
        printf("Livro %d\n", i + 1);
        printf("Titulo: ");
        scanf(" %30[^\n]", livros[i].titulo);
        printf("Autor: ");
        scanf(" %15[^\n]", livros[i].autor);
        printf("Ano: ");
        scanf("%d", &livros[i].ano);
    }

    printf("\nDigite o titulo que deseja buscar: ");
    scanf(" %30[^\n]", busca);

    printf("\nLivros encontrados:\n");
    for (int i = 0; i < TOTAL_LIVROS; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            printf("Titulo: %s | Autor: %s | Ano: %d\n",
                   livros[i].titulo, livros[i].autor, livros[i].ano);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum livro encontrado com esse titulo.\n");
    }

    return 0;
}
