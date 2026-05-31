#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Aluno.h"
#include "Livro.h"

class Emprestimo {
     private:
          Aluno aluno;
          Livro livro;
          int diasAtraso;
          bool devolvido;

     public:
          Emprestimo(Aluno aluno, Livro livro);

          double calcularMulta();

          int getDiasAtraso();

          bool getDevolvido();

          void setDiasAtraso(int diasAtraso);

          void setDevolvido(bool devolvido);
};

#endif // EMPRESTIMO_H
