#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "aluno-estruturado.h"

typedef struct {
    char codDisciplina[50];
    char codTurma[50];
    char semestre[50];

    Aluno** alunos;
    int tamVetor;
    int qtde;
} Turma;

Turma* criarTurma(char* semestre, int tamVetor) {
    Turma* turma = (Turma*)malloc(sizeof(Turma));
    strcpy(turma->semestre, semestre);
    turma->codTurma[0] = '\0';
    turma->codDisciplina[0] = '\0';

    turma->alunos = (Aluno**)malloc(tamVetor * sizeof(Aluno*));
    turma->tamVetor = tamVetor;
    turma->qtde = 0;

    return turma;
}

int matricula(Turma* turma, Aluno* a) {
    if (turma->qtde + 1 > turma->tamVetor) return 0;

    turma->alunos[turma->qtde] = a;
    turma->qtde++;
    return 1;
}

int cancelaMatricula(Turma* turma, char* ra) {
    int alunoFindedAtIndex = -1;

    for (int i = 0; i < turma->qtde; i++) {
        char raFinded[50];
        strcpy(raFinded, turma->alunos[i]->getRa());
        if (strcmp(raFinded, ra) == 0) {
            alunoFindedAtIndex = i;
            break;
        }
    }

    if (alunoFindedAtIndex != -1) {
        for (int i = alunoFindedAtIndex; i < turma->qtde - 1; i++) {
            turma->alunos[i] = turma->alunos[i + 1];
        }
        turma->qtde--;
    }

    return alunoFindedAtIndex; // -1 case not finded
}

void imprimeTurma(Turma* turma) {
    printf("\n\n");
    printf("Código da Disciplina: %s\n", turma->codDisciplina);
    printf("Código da Turma: %s\n", turma->codTurma);
    printf("Semestre: %s\n", turma->semestre);
    printf("Tamanho do Vetor de Alunos: %d\n", turma->tamVetor);
    printf("Quantidade de Alunos: %d\n", turma->qtde);
    for (int i = 0; i < turma->qtde; i++) {
        printf("Aluno %d: %s - %s\n", i + 1, turma->alunos[i]->getRa(), turma->alunos[i]->getNome());
    }
    printf("\n\n");
}

void destruirTurma(Turma* turma) {
    free(turma);
}