#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro{
     private:
          std::string id;
          std::string titulo;
          std::string autor;
          bool disponivel;

     public:
          Livro(std::string id, std::string titulo, std::string autor);

     void emprestarLivro();
     
     void devolverLivro();
     
     bool estaDisponivel();

     std::string getTitulo();

     std::string getAutor();

     std::string getId();

     void setId(std::string id);

     void setTitulo(std::string titulo);

     void setAutor(std::string autor);

     void setAutor(bool disponivel);

};

#endif // LIVRO_H
