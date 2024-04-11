#include <iostream>
#include <string>

#include "turma.h"


int main() {
    Turma* t1 = new Turma("2024-1", 100);
    Turma* t2 = new Turma("2023-2", 20);

    Aluno* a1 = new Aluno("1", "Joao");
    Aluno a2("2", "Maria");

    t1->matricula(a1);
    t1->matricula(&a2);
    t1->matricula(new Aluno("3", "Jose"));

    t1->imprime();

    t1->cancelaMatricula("1");
    t1->imprime();

    delete t1;
    delete a1;
    return 0;
}