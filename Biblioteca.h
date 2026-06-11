#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "Livro.h"
#include "Emprestimo.h"

class Biblioteca{
    private:
        std::vector<Livro> livros;
        std::vector<Emprestimo> emprestimos;

    public:
        void adicionarLivro(Livro l);

        void listarLivros();

        void realizarEmprestimo(Aluno &a, std::string id);

        void devolver(Aluno &a, std::string id, int diasAtraso);

};

#endif // BIBLIOTECA_H
