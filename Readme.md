# Compilador para a Linguagem Goianinha

## 📝 Visão Geral

Este repositório contém o código-fonte de um compilador completo para a "Linguagem Goianinha", uma linguagem de programação didática. O compilador foi desenvolvido como um projeto para a disciplina de Compiladores e abrange todas as fases clássicas da compilação:

-   **Análise Léxica**: Reconhecimento de tokens e palavras-chave da linguagem.
-   **Análise Sintática**: Validação da estrutura gramatical do código-fonte.
-   **Geração da Árvore Sintática Abstrata (AST)**: Representação intermediária do código.
-   **Análise Semântica**: Verificação de tipos, escopo de variáveis e regras semânticas.
-   **Geração de Código**: Tradução do código-fonte para a linguagem Assembly do processador MIPS.

---

## 📂 Estrutura de Pastas

O projeto está organizado na seguinte estrutura de diretórios, separando cada componente principal do compilador:

-   `analisador_sintatico/`
    -   Contém os arquivos de especificação para as ferramentas de análise.
    -   `goianinha.l`: Arquivo de entrada para o Flex, definindo as regras para o reconhecimento de tokens (análise léxica).
    -   `goianinha.y`: Arquivo de entrada para o Bison, contendo a gramática da linguagem e as ações semânticas para a construção da AST (análise sintática).
    -   `main.c`: Ponto de entrada do compilador. Orquestra as chamadas para as fases de análise e geração de código.
-   `analisador_semantico/`
    -   `semantico.c`: Implementação do analisador semântico. Este módulo percorre a AST para realizar a checagem de tipos, análise de escopo e validação das regras semânticas da linguagem.
-   `ast/`
    -   `ast.c`: Implementação das funções para criar, percorrer e liberar os nós da Árvore Sintática Abstrata (AST).
-   `gerador_codigo/`
    -   `gerador.c`: Contém a lógica para percorrer a AST e traduzir sua estrutura em instruções Assembly para a arquitetura MIPS.
-   `includes/`
    -   Contém os arquivos de cabeçalho (`.h`) que definem as estruturas de dados e os protótipos de funções utilizados em todo o projeto.
-   `tabela_simbolos/`
    -   `tabela_simbolos.c`: Implementação da tabela de símbolos, que é usada para armazenar e consultar informações sobre variáveis, funções e seus respectivos escopos.
-   `saidas/`
    -   Diretório gerado ao executar `make test`.
    -   Contém arquivos `.txt` com os resultados da compilação para cada arquivo de teste.
-   `MIPS/`
    -   Diretório gerado ao executar `make test`.
    -   Armazena os arquivos `.asm` com o código Assembly MIPS gerado para cada arquivo de teste que foi compilado com sucesso.
-   `Especificacao do Trabalho/`
    -   Contém os documentos PDF com as especificações do projeto.

---

## 🚀 Como Executar

Para compilar e testar o compilador, você pode utilizar os comandos `make` a partir da raiz do diretório.

1.  **Compilar o Projeto**
    Este comando invoca o `Flex` e o `Bison` para gerar os analisadores, e em seguida compila todo o código-fonte C para criar o executável do compilador.
    ```bash
    make
    ```

2.  **Executar os Testes**
    Este comando executa o compilador para um conjunto predefinido de arquivos de teste. Ele cria os diretórios `saidas/` e `mips/` para armazenar os resultados.
    ```bash
    make test
    ```

3.  **Limpar o Projeto**
    Remove todos os arquivos gerados durante a compilação (arquivos objeto, executável e os diretórios de saída).
    ```bash
    make clean
    ```

---

## 📊 Geração de Saídas

Ao executar `make test`, o compilador processa múltiplos arquivos de entrada e gera os seguintes artefatos:

> ### **Pasta `saidas/`**
>
> Para cada arquivo de teste, um arquivo `.txt` correspondente é criado nesta pasta. Este arquivo contém:
>
> -   A confirmação de que a análise sintática foi concluída com sucesso.
> -   A representação completa da **Árvore Sintática Abstrata (AST)**, exibindo a estrutura hierárquica do código analisado.
> -   O resultado da análise semântica, indicando se o código está semanticamente correto ou se foi encontrado algum erro (de tipo, escopo, etc.).
> -   Uma mensagem final confirmando a geração do código MIPS, caso não haja erros.

> ### **Pasta `MIPS/`**
>
> Se um arquivo de teste passar por todas as fases de análise (léxica, sintática e semântica) sem erros, um arquivo `.asm` correspondente é gerado nesta pasta. Este arquivo contém o código Assembly MIPS que pode ser executado em um simulador como o SPIM.