# Estudo de caso para um software orientado a objetos em C++
Nomes: Julia D.Guerreiro(208414)  e Julia Holz(207977).

## 1. Estudo de caso: Sistema de biblioteca

O sistema escolhido para ser desenvolvido será um sistema de biblioteca. O funcionamento do nosso sistema ocorre através da interação entre as classes Pessoa, Aluno, Livro, Emprestimo e Biblioteca.

### 1.1 Problema a ser resolvido

O sistema tem como objetivo controlar o empréstimo de livros de uma biblioteca universitária, permitindo cadastrar livros, registrar alunos e realizar empréstimos de forma organizada.

A biblioteca universitária enfrenta dificuldades no controle dos empréstimos de livros, principalmente quando esse processo é realizado manualmente ou sem organização adequada. Isso pode gerar problemas como empréstimos duplicados, dificuldade em saber quais livros estão disponíveis, falta de controle sobre os alunos que possuem livros emprestados e ausência de acompanhamento de atrasos na devolução.

Além disso, torna-se difícil garantir regras básicas da biblioteca, como limitar a quantidade de livros que cada aluno pode pegar e aplicar multas em casos de atraso.

Dessa forma, o sistema proposto busca automatizar o gerenciamento dos empréstimos da biblioteca, permitindo controlar a disponibilidade dos livros, registrar alunos, validar regras de empréstimo e calcular multas por atraso, tornando o processo mais organizado e eficiente.

O sistema resolverá o problema através do:
* Controle a disponibilidade dos livros, evitando empréstimos duplicados;
* Registro os alunos que possuem livros emprestados;
* Limite de quantidade de livros por aluno, seguindo as regras da biblioteca;
* Registro empréstimos e devoluções de forma organizada;
* Identificação de atrasos e cálculo automático de multas;
* Visualização facilitada dos livros cadastrados na biblioteca.

## 1.2 Principais Funcionalidades

**1. Cadastro de livros**

Permite adicionar livros ao sistema com: título, autor e disponibilidade. Está relacionada à classe Livro e relacionado ao método: adicionarLivro()

**2. Cadastro e gerenciamento de alunos**

São armazenados: nome, CPF, matrícula, curso e quantidade de livros emprestados, que estão relacionados às classes: Pessoa e Aluno.

**3. Verificação de disponibilidade do livro**

O sistema verifica se o livro está disponível antes de permitir o empréstimo. Isso evita que o mesmo livro seja emprestado para mais de um aluno ao mesmo tempo. Relacionada a classe: Livro e ao Método: estaDisponivel()

**4. Realização de empréstimos**

Permite emprestar um livro para um aluno. O sistema deve: verificar se o livro está disponível, verificar se o aluno ainda pode pegar livros, atualiza a disponibilidade do livro e 
registra o empréstimo. Essas ações estão relacionadas a classe: Biblioteca e ao método: ao realizarEmprestimo().

**5. Controle do limite de livros por aluno**

O sistema impede que um aluno ultrapasse o número máximo permitido de livros. Exemplo:
máximo de 3 livros por aluno, está relacionado a classe: Aluno e ao método: podePegar().

**6. Devolução de livro**

Permite registrar e realizar a devolução do livro, tornando-o disponível novamente para novos empréstimos. (Relacionada à classe: Biblioteca e ao método: devolver())

**7. Cálculo de multa**

Caso haja atraso, o sistema calcula automaticamente a multa, esse comportamento está relacionado à classe: Emprestimo e ao método: calcularMulta().

**8. Listagem de livros**

Permite visualizar todos os livros cadastrados no sistema. A funcionalidade exibir informações como: título, autor e disponibilidade do livro.

Exemplo de saída:

Livro: Java Orientado a Objetos

Autor: Fulano de Tal

Disponível: Sim

Livro: Estruturas de Dados

Autor: Ciclano de Tal

Disponível: Não

Essa funcionalidade está relacionada à classe: Biblioteca e ao método: listarLivros(), que percorre a lista: ArrayList<Livro> e mostra os dados de cada livro.

## 2. Descrição da linguagem escolhida

A linguagem de programação C++ é uma linguagem de propósito geral criada como uma evolução da linguagem C, incorporando recursos mais avançados para o desenvolvimento de software. Ela é amplamente utilizada no desenvolvimento de sistemas operacionais, jogos, sistemas embarcados, aplicações de alto desempenho e programas que exigem maior controle sobre hardware e gerenciamento de memória.

A relação do C++ com a Programação Orientada a Objetos (POO) está no fato de que a linguagem oferece suporte completo a esse paradigma. Em C++, é possível organizar o programa em classes e objetos, permitindo representar elementos do mundo real dentro do sistema.

A orientação a objetos em C++ utiliza conceitos fundamentais como:
* Encapsulamento: protege os dados da classe, controlando o acesso por meio de métodos.
* Herança: permite criar novas classes baseadas em classes já existentes, reaproveitando código.
* Polimorfismo: possibilita que métodos tenham diferentes comportamentos dependendo do objeto utilizado.
* Abstração: representa apenas as características essenciais de um objeto, ignorando detalhes desnecessários.

Por exemplo, em um sistema de biblioteca, uma classe Livro pode possuir atributos como título e autor, além de métodos como emprestar() e devolver(). Assim, o C++ facilita a modelagem de sistemas de forma mais organizada, reutilizável e próxima da realidade.

Para organizar melhor o programa, o C++ utiliza arquivos .h e .cpp. O arquivo .h contém a declaração da classe, mostrando quais atributos e métodos ela possui, enquanto o arquivo .cpp contém a implementação desses métodos, ou seja, o código que define seu funcionamento. Essa separação deixa o projeto mais organizado, facilita a manutenção e permite reutilizar as classes em outras partes do sistema sem precisar reescrever o código.

Em C++, arquivos .h (header files) são usados para declarar funções, classes, structs, variáveis e constantes que serão utilizadas em outros arquivos do projeto.

A ideia principal é separar:

* Declaração => o que existe (.h)
* Implementação => como funciona (.cpp)

### Como realizar a execução e compilação do código desse programa: ###

**Para compilar todos os arquivos:**
```
g++ *.cpp -o Biblioteca
```
**Para executar o binário:**
```
.\Biblioteca
```
## 3. Implementações realizadas

**1. Classe Pessoa**

A classe Pessoa é a superclasse do sistema, responsável por armazenar informações básicas comuns aos usuários.


**Atributos:**

nome : String => armazena o nome da pessoa.

cpf : String => armazena o CPF do usuário.


**Método:**

exibirDados() : void => Exibe as informações da pessoa cadastrada.


**Exemplo:**

Nome: Julia

CPF: 123.456.789-00

**Trecho do código de Pessoa.h:**

```
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

```

**2. Classe Aluno**

A classe Aluno representa o usuário que poderá pegar livros emprestados, e  herda os atributos e métodos da classe Pessoa.


**Atributos:**

curso : String => Armazena o curso do aluno.

livrosPegos : int =>Controla quantos livros o aluno possui emprestados.

matricula : int => Identifica o aluno na universidade.


**Métodos:**

podePegar() : boolean => Verifica se o aluno ainda pode pegar livros emprestados.

Regra de negócio:

O aluno pode possuir no máximo 3 livros emprestados.

Exemplo de funcionamento:

livrosPegos = 2

Resultado: true

Ou seja, o aluno ainda pode realizar empréstimos.

Se: livrosPegos = 3

Resultado: false

E assim o sistema impede novos empréstimos.

exibirDados() : void => Sobrescreve(override/substitui) o método da classe Pessoa, exibindo informações específicas do aluno. 


**Exemplo:**

Nome: Julia

Curso: Ciência da Computação

Matrícula: 1001

Livros Pegos: 2

**Trecho do código de Aluno.h:**

```
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
```

**3. Classe Livro**

A classe Livro representa os livros cadastrados na biblioteca.


**Atributos:**

titulo : String = > Armazena o título do livro.

id: String = > Armazena o id do livro.

autor : String = > Armazena o autor do livro.

disponivel : boolean =>  O atributo disponível controla se o livro está livre para empréstimo.


**Métodos:**

estaDisponivel() : boolean => Verifica se o livro pode ser emprestado.

**Exemplo:**

disponivel = true

Resultado: true

Livro disponível para empréstimo.

emprestarLivro() : void => Quando um empréstimo é realizado, esse método altera o atributo: disponivel = false

Assim, o livro não poderá ser emprestado novamente até sua devolução.

devolverLivro() : void => Quando o aluno devolve o livro, o método altera: disponivel = true

Permitindo um novo empréstimo.


**Trecho do código de Livro.h:**

```
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

```

**4. Classe Emprestimoo**

A classe Emprestimo é responsável por controlar as regras do empréstimo.


**Atributos:**

aluno : Aluno => Armazena o aluno responsável pelo empréstimo.

livro : Livro => Armazena o livro emprestado.

diasAtraso : int => Usado para calcular multa.

devolvido : boolean => Informa se o livro foi devolvido.


**Métodos:**

calcularMulta() : double => Calcula multa caso haja atraso.

Regra de negócio:

multa = diasAtraso × 2

**Exemplo:**

diasAtraso = 4

Resultado: multa = 8.0


**Trecho do código de Emprestimo.h:**

```
class Emprestimo {
     private:
          Aluno aluno;
          Livro livro;
          int diasAtraso;
          bool devolvido;

     public:
          Emprestimo(Aluno aluno, Livro livro);

          double calcularMulta();

          int getDiasAtraso();

          bool getDevolvido();

          void setDiasAtraso(int diasAtraso);

          void setDevolvido(bool devolvido);
};

```

**5. Classe Biblioteca**

A classe Biblioteca gerencia os livros e empréstimos do sistema.


**Atributos:**

livros : ArrayList<Livro> => Armazena os livros cadastrados.

emprestimos : ArrayList<Emprestimo> =>Armazena os empréstimos realizados.

**Métodos:**

adicionarLivro() : void => Adiciona livros ao sistema.

**Exemplo:**

Livro Java adicionado

listarLivros() : void => Exibe todos os livros cadastrados.

realizarEmprestimo() : void => Esse método executa a principal regra do sistema.

Ele realiza as seguintes verificações, como regra de negócio:


**Passo 1 — Verificar disponibilidade do livro**

Utiliza: livro.estaDisponivel()

Se o livro não estiver disponível: Livro indisponível e o processo é encerrado.


**Passo 2 — Verificar limite do aluno**

Utiliza: aluno.podePegar()

Se o aluno já possuir 3 livros: Aluno atingiu o limite e o empréstimo é negado.


**Passo 3 — Realizar empréstimo**

Caso tudo esteja correto:

O método: livro.emprestarLivro() torna o livro indisponível.

Depois: livrosPegos +1 

Atualiza a quantidade de livros do aluno.

Por fim: devolvido = false

Marca que o livro ainda está emprestado.

devolver() : void => Esse método localiza o empréstimo de um livro, calcula a multa caso haja atraso, torna o livro disponível novamente, remove o empréstimo dos registros ativos e atualiza a quantidade de livros emprestados pelo aluno. 


**Trecho do código de Biblioteca.h:**

```
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


```
