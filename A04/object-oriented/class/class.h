#include <stdlib.h>

#include <iostream>
#include <string>

#include "student.h"

using namespace std;

class Turma {
   private:
    string codDisciplina;
    string codTurma;
    string semestre;

    Aluno** alunos;
    int tamVetor;
    int qtde;

   public:
    Turma(string semestre, int tamVetor) {
        this->semestre = semestre;
        this->codTurma = "";
        this->codDisciplina = "";

        this->alunos = new Aluno*[tamVetor];
        this->tamVetor = tamVetor;
        this->qtde = 0;
    }

    bool matricula(Aluno* a) {
        if (qtde + 1 > tamVetor) return false;

        this->alunos[qtde] = a;
        qtde++;
        return true;
    };

    int cancelaMatricula(string ra) {
        int alunoFindedAtIndex;

        for (int i = 0; i < qtde; i++) {
            string raFinded = this->alunos[i]->getRa();
            if (raFinded == ra) {
                alunoFindedAtIndex = i;
                break;
            }
        }

        if (alunoFindedAtIndex != -1) {
            for (int i = alunoFindedAtIndex; i < qtde - 1; i++) {
                this->alunos[i] = this->alunos[i + 1];
            }
            qtde--;
        }

        return alunoFindedAtIndex;  // -1 case not finded
    };

    void imprime() {
        std::cout << "Código da Disciplina: " << codDisciplina << std::endl;
        std::cout << "Código da Turma: " << codTurma << std::endl;
        std::cout << "Semestre: " << semestre << std::endl;
        std::cout << "Tamanho do Vetor de Alunos: " << tamVetor << std::endl;
        std::cout << "Quantidade de Alunos: " << qtde << std::endl;
        for (int i = 0; i < qtde; i++) {
            std::cout << "Aluno " << i + 1 << ": " << alunos[i]->getRa()
                      << " - " << alunos[i]->getNome() << std::endl;
        }
    }
};