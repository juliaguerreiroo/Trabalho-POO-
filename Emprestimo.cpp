#include <string>
#include <iostream>
#include "Aluno.cpp"
#include "Livro.cpp"

class Emprestimo {
     private:
          Aluno aluno;
          Livro livro;
          int diasAtraso;
          bool devolvido;

     public:
          Emprestimo(Aluno aluno, Livro livro) : aluno(aluno), livro(livro) {
               //inicializa os atributos antes do construtor executar.Porque o emprestimo precisa de Livro e Aluno para existir
               this->diasAtraso = 0;
               this->devolvido = false;
          }

          void realizarEmprestimo(){
               if (livro.estaDisponivel()){
                    if (aluno.podePegar()){
                         livro.emprestarLivro();
                         devolvido = false;
                         aluno.setLivrosPegos(aluno.getLivrosPegos() + 1);
                         std::cout << "Livro emprestado!" << std::endl;
                    }else{
                         std::cout << "O aluno já atingiu o limite de livros para emprestimo!" << std::endl;
                    }
               }else{
                    std::cout << "O livro não está disponivel" << std::endl;
               }
          }

          double calcularMulta(){
               double valorPorDia = 2.0;

               if (diasAtraso > 0) {
                    return diasAtraso * valorPorDia;
               }

               return 0.0;
          }

          int getDiasAtraso(){
               return diasAtraso;
          }

          bool getDevolvido(){
               return devolvido;
          }

          void setDiasAtraso(int diasAtraso){
               this->diasAtraso = diasAtraso;
          }

          void setDevolvido(bool devolvido){
               this->devolvido = devolvido;
          }
};
