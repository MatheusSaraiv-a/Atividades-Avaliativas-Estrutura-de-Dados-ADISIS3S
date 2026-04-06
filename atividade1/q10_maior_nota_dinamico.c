#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    float nota;
} Aluno;

Aluno *maiorNota(Aluno *alunos, int quantidade) {
    Aluno *maior = alunos;

    for (int i = 1; i < quantidade; i++) {
        if ((alunos + i)->nota > maior->nota) {
            maior = alunos + i;
        }
    }

    return maior;
}

int main(void) {
    int n;
    Aluno *alunos;
    Aluno *melhorAluno;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    alunos = (Aluno *)malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" %99[^\n]", (alunos + i)->nome);
        printf("Nota: ");
        scanf("%f", &(alunos + i)->nota);
    }

    melhorAluno = maiorNota(alunos, n);
    printf("\nAluno com maior nota:\n");
    printf("Nome: %s\n", melhorAluno->nome);
    printf("Nota: %.2f\n", melhorAluno->nota);

    free(alunos);
    return 0;
}
