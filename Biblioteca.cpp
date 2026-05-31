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
        std::cout << "Titulo: " << l.getTitulo() << "\nAutor: " << l.getAutor() << std::endl;
    }
}

void Biblioteca::realizarEmprestimo(Aluno &a, size_t livroIndex){
    if (livroIndex >= livros.size()){
        std::cout << "Indice de livro invalido" << std::endl;
        return;
    }

    Livro &l = livros[livroIndex];

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
}

int main(){

    Aluno a1("Maria", "390403490", "Ciência da Computação", 1, 3984);
    Livro l1("1984", "George Orwell");
    Biblioteca b;

    b.adicionarLivro(l1);
    b.listarLivros();

    // realiza o empréstimo do livro de índice 0 para o aluno a1
    b.realizarEmprestimo(a1, 0);

    // tentativa de emprestar o mesmo livro novamente — agora deverá falhar
    b.realizarEmprestimo(a1, 0);

    return 0;
}