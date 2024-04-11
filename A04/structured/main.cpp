#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "turma-estruturado.h"
#include "aluno-estruturado.h"

int main() {
    Turma* t1 = criarTurma("2024-1", 100);
    Turma* t2 = criarTurma("2023-2", 20);

    Aluno* a1 = criarAluno("1", "Joao");
    Aluno* a2 = criarAluno("2", "Maria");

    matricula(t1, a1);
    matricula(t1, a2);
    Aluno* a3 = criarAluno("3", "Jose");
    matricula(t1, a3);

    imprimeTurma(t1);

    cancelaMatricula(t1, "1");
    imprimeTurma(t1);

    destruirAluno(a1);
    destruirAluno(a2);
    destruirAluno(a3);
    destruirTurma(t1);
    destruirTurma(t2);
    return 0;
}
