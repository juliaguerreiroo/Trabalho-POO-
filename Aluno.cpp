#include <string>
#include <iostream>
#include "Pessoa.cpp"

class Aluno: public Pessoa{
    private:
        std::string curso;
        int livrosPegos;
        int matricula;

    public:
        Aluno(std::string nome, std::string cpf, std::string curso, int livrosPegos, int matricula):Pessoa(nome, cpf){
            this->curso = curso;
            this->livrosPegos = livrosPegos;
            this->matricula = matricula;
        }
        
        void exibirDados()override{
            Pessoa::exibirDados();
            std::cout << "\nCurso: " << curso << "\nLivros pegos: " << livrosPegos << "\nMatricula: " << matricula;
        }

        bool podePegar(){
            if (livrosPegos < 3){
                return true;
            }
            return false;
        }

        std::string getCurso(){
            return curso;
        }

        void setCurso(std::string curso){
            this->curso = curso;
        }

        int getLivrosPegos(){
            return livrosPegos;
        }

        void setLivrosPegos(int livrosPegos){
            this->livrosPegos = livrosPegos;
        }

        int getMatricula(){
            return matricula;
        }

        void setMatricula(int matricula){
            this->matricula = matricula;
        }


};