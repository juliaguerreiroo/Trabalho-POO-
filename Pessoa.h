#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {

    private:
        std::string nome;
        std::string cpf;

    public:
        Pessoa(std::string nome, std::string cpf);

        // virtual para que a classe possa ser substituida (override)
        virtual void exibirDados();

        std::string getNome();

        std::string getCpf();

        void setNome(std::string nome);

        void setCpf(std::string cpf);

};

#endif 
