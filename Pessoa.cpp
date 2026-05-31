#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa(std::string nome, std::string cpf) : nome(nome), cpf(cpf) {}

void Pessoa::exibirDados(){
    std::cout << "Nome: " << nome << "\nCPF: " << cpf;
}

std::string Pessoa::getNome(){
    return nome;
}

std::string Pessoa::getCpf(){
    return cpf;
}

void Pessoa::setNome(std::string nome){
    this->nome = nome;
}

void Pessoa::setCpf(std::string cpf){
    this->cpf = cpf;
}