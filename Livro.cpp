#include <string>
#include <iostream>

class Livro{
     private:
          std::string titulo;
          std::string autor;
          bool disponivel;

     public:
          Livro(std::string titulo, std::string autor){
            this->titulo = titulo; 
            this->autor = autor;
            disponivel = true;
          }

     void emprestarLivro(){
          disponivel = false;
     } 
     
     void devolverLivro(){
          disponivel = true;
     } 
     
     bool estaDisponivel(){
          return disponivel;
     }

     std::string getTitulo(){
          return titulo;
     }

     std::string getAutor(){
          return autor;
     }

     void setTitulo(std::string titulo){
           this->titulo = titulo;
     }

     void setAutor(std::string autor){
           this->autor = autor;
     }

     void setAutor(bool disponivel){
           this->disponivel = disponivel;
     }



};