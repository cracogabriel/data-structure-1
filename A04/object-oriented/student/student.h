#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

class Aluno {
   private:
    string ra;
    string nome;

   public:
    Aluno() {
        this->ra = "0";
        this->nome = "undefined";
    }

    Aluno(string _ra, string _nome) {
        this->ra = _ra;
        this->nome = _nome;
    }

    ~Aluno() { cout << "Destruindo" << endl; }

    string getRa() { return this->ra; }
    void setRa(string ra) { this->ra = ra; }
    string getNome() { return this->nome; }
    void setNome(string nome) { this->nome = nome; }

    void imprimir() {
        cout << "(" << this->ra << ", " << this->nome << ")" << endl;
    }
};
