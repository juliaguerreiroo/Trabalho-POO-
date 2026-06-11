#include <iostream>
#include <vector>
#include "Biblioteca.h"
#include "Aluno.h"
#include "Livro.h"
#include "Emprestimo.h"

#include <iostream>

void Biblioteca::adicionarLivro(Livro l){
    livros.push_back(l);
}

void Biblioteca::listarLivros(){
    for(Livro l : livros){
        std::cout << "Id: " << l.getId() << "\nTitulo: " << l.getTitulo() << "\nAutor: " << l.getAutor() << std::endl;
    }
}

void Biblioteca::realizarEmprestimo(Aluno &a, std::string id){
    for(Livro &l : livros){
        if(l.getId() == id){
            if(l.estaDisponivel()){
                if(a.podePegar()){
                    l.emprestarLivro();
                    a.setLivrosPegos(a.getLivrosPegos() + 1);
                    Emprestimo e(a, l);
                    emprestimos.push_back(e);
                    std::cout << "Livro emprestado!" << std::endl;
                } else {
                    std::cout << "O aluno já atingiu o limite de livros para emprestimo!" << std::endl;
                }
            } else {
                std::cout << "O livro não está disponivel" << std::endl;
            }
            return;
        }
    }
    std::cout << "Livro não existe" << std::endl;

}

void Biblioteca::devolver(Aluno &a, std::string id, int diasAtraso){
    for(auto it = emprestimos.begin(); it != emprestimos.end(); ++it){
        if(it->getLivro().getId() == id){
            if(diasAtraso > 0){
                it->setDiasAtraso(diasAtraso);
                std::cout << "Multa de: R$" << it->calcularMulta() << std::endl;
            }
            for(Livro &l : livros){
                if(l.getId() == id){
                    l.devolverLivro();
                    break;
                }
            }
            emprestimos.erase(it);
            a.setLivrosPegos(a.getLivrosPegos() - 1);
            std::cout << "Livro devolvido" << std::endl;
            return;
        }
    }

}

int main(){

    Aluno a1("Maria", "390403490", "Ciência da Computação", 0, 3984);
    Livro l1("12903", "1984", "George Orwell");
    Livro l2("20392", "Harry Potter", "J.K Rowling");
    Livro l3("84932", "O Principe Cruel", "Holly Black");
    Livro l4("43321", "Crepusculo", "Stephenie Meyer");
    Biblioteca b;

    b.adicionarLivro(l1);
    b.adicionarLivro(l2);
    b.adicionarLivro(l3);
    b.adicionarLivro(l4);
    b.listarLivros();

    // realiza o empréstimo do livro de id "12903" para o aluno a1
    b.realizarEmprestimo(a1, "12903");

    // tentativa de emprestar o mesmo livro novamente — agora deverá falhar
    b.realizarEmprestimo(a1, "12903");

    // devolver livro
    b.devolver(a1, "12903", 10);

    // tentativa de emprestar mais de 3 livros para o mesmo aluno
    b.realizarEmprestimo(a1, "12903");
    b.realizarEmprestimo(a1, "20392");
    b.realizarEmprestimo(a1, "84932");
    b.realizarEmprestimo(a1, "43321");

    return 0;
}