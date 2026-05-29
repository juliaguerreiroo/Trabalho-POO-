#include <string>
#include <iostream>

class Pessoa {

    private:
        std::string nome;
        std::string cpf;

    public:
        Pessoa(std::string nome, std::string cpf){
            this->nome = nome; 
            this->cpf = cpf;
        }

        // virtual para que a classe possa ser substituida (override)
        virtual void exibirDados(){
            std::cout << "Nome: " << nome << "\nCPF: " << cpf;
        }

        std::string getNome(){
            return nome;
        }

        std::string getCpf(){
            return cpf;
        }

        void setNome(std::string nome){
            this->nome = nome;
        }

        void setCpf(std::string cpf){
            this->cpf = cpf;
        }

};