#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ra[50];
    char nome[50];
} Aluno;

Aluno* criarAluno(char* _ra, char* _nome) {
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(aluno->ra, _ra);
    strcpy(aluno->nome, _nome);
    return aluno;
}

void destruirAluno(Aluno* aluno) {
    printf("Destruindo\n");
    free(aluno);
}

char* getRa(Aluno* aluno) {
    return aluno->ra;
}

void setRa(Aluno* aluno, char* ra) {
    strcpy(aluno->ra, ra);
}

char* getNome(Aluno* aluno) {
    return aluno->nome;
}

void setNome(Aluno* aluno, char* nome) {
    strcpy(aluno->nome, nome);
}

void imprimirAluno(Aluno* aluno) {
    printf("(%s, %s)\n", aluno->ra, aluno->nome);
}
