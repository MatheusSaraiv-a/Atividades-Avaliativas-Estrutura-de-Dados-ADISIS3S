#include <stdio.h>

#define TOTAL_ALUNOS 10

typedef struct {
    char nome[100];
    int matricula;
    float mediaFinal;
} Aluno;

int main(void) {
    Aluno alunos[TOTAL_ALUNOS];
    Aluno aprovados[TOTAL_ALUNOS];
    Aluno reprovados[TOTAL_ALUNOS];
    int qtdAprovados = 0;
    int qtdReprovados = 0;

    for (int i = 0; i < TOTAL_ALUNOS; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" %99[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Media final: ");
        scanf("%f", &alunos[i].mediaFinal);

        if (alunos[i].mediaFinal >= 5.0f) {
            aprovados[qtdAprovados++] = alunos[i];
        } else {
            reprovados[qtdReprovados++] = alunos[i];
        }
    }

    printf("\nAlunos aprovados:\n");
    for (int i = 0; i < qtdAprovados; i++) {
        printf("Nome: %s | Matricula: %d | Media: %.2f\n",
               aprovados[i].nome, aprovados[i].matricula, aprovados[i].mediaFinal);
    }

    printf("\nAlunos reprovados:\n");
    for (int i = 0; i < qtdReprovados; i++) {
        printf("Nome: %s | Matricula: %d | Media: %.2f\n",
               reprovados[i].nome, reprovados[i].matricula, reprovados[i].mediaFinal);
    }

    return 0;
}
