#include "Livro.h"

#include <iostream>

Livro::Livro(std::string id, std::string titulo, std::string autor) : id(id), titulo(titulo), autor(autor), disponivel(true) {}

void Livro::emprestarLivro(){
     disponivel = false;
}

void Livro::devolverLivro(){
     disponivel = true;
}

bool Livro::estaDisponivel(){
     return disponivel;
}

std::string Livro::getTitulo(){
     return titulo;
}

std::string Livro::getId(){
     return id;
}

std::string Livro::getAutor(){
     return autor;
}

void Livro::setTitulo(std::string titulo){
      this->titulo = titulo;
}

void Livro::setId(std::string id){
      this->id = id;
}

void Livro::setAutor(std::string autor){
      this->autor = autor;
}

void Livro::setAutor(bool disponivel){
      this->disponivel = disponivel;
}