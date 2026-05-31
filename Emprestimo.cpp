#include "Emprestimo.h"
#include <iostream>

Emprestimo::Emprestimo(Aluno aluno, Livro livro) : aluno(aluno), livro(livro) {
     this->diasAtraso = 0;
     this->devolvido = false;
}

double Emprestimo::calcularMulta(){
     double valorPorDia = 2.0;

     if (diasAtraso > 0) {
          return diasAtraso * valorPorDia;
     }

     return 0.0;
}

int Emprestimo::getDiasAtraso(){
     return diasAtraso;
}

bool Emprestimo::getDevolvido(){
     return devolvido;
}

void Emprestimo::setDiasAtraso(int diasAtraso){
     this->diasAtraso = diasAtraso;
}

void Emprestimo::setDevolvido(bool devolvido){
     this->devolvido = devolvido;
}
