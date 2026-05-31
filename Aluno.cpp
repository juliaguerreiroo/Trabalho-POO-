#include "Aluno.h"
#include <iostream>

Aluno::Aluno(std::string nome, std::string cpf, std::string curso, int livrosPegos, int matricula)
    : Pessoa(nome, cpf), curso(curso), livrosPegos(livrosPegos), matricula(matricula) {}

void Aluno::exibirDados(){
    Pessoa::exibirDados();
    std::cout << "\nCurso: " << curso << "\nLivros pegos: " << livrosPegos << "\nMatricula: " << matricula;
}

bool Aluno::podePegar(){
    return livrosPegos < 3;
}

std::string Aluno::getCurso(){
    return curso;
}

void Aluno::setCurso(std::string curso){
    this->curso = curso;
}

int Aluno::getLivrosPegos(){
    return livrosPegos;
}

void Aluno::setLivrosPegos(int livrosPegos){
    this->livrosPegos = livrosPegos;
}

int Aluno::getMatricula(){
    return matricula;
}

void Aluno::setMatricula(int matricula){
    this->matricula = matricula;
}