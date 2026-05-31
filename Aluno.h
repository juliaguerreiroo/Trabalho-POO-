#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include "Pessoa.h"

class Aluno: public Pessoa{
    private:
        std::string curso;
        int livrosPegos;
        int matricula;

    public:
        Aluno(std::string nome, std::string cpf, std::string curso, int livrosPegos, int matricula);
        
        void exibirDados() override;

        bool podePegar();

        std::string getCurso();

        void setCurso(std::string curso);

        int getLivrosPegos();

        void setLivrosPegos(int livrosPegos);

        int getMatricula();

        void setMatricula(int matricula);

};

#endif 
