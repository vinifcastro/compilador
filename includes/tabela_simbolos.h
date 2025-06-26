#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

#include "ast.h" // Inclui a definição de TipoDado

#define MAX_NAME 64
#define MAX_VARS 100
#define MAX_FUNCS 100
#define MAX_PILHA 100

typedef struct EntradaTabela {
    char nome[MAX_NAME];
    TipoDado tipo; // Usa TipoDado
    int posicao;
    int is_param; // NOVO: Flag para indicar se é um parâmetro formal
} EntradaTabela;

typedef struct EntradaFuncao {
    char nome[MAX_NAME];
    TipoDado tipo_retorno; // Usa TipoDado
    int numero_parametros;
    // Poderia adicionar TipoDado* tipos_parametros; para armazenar os tipos dos parâmetros
    // e alocar dinamicamente, mas por enquanto vamos manter simples.
} EntradaFuncao;

typedef struct TabelaSimbolos {
    EntradaTabela variaveis[MAX_VARS];
    int qtde_variaveis;

    EntradaFuncao funcoes[MAX_FUNCS];
    int qtde_funcoes;
} TabelaSimbolos;

typedef struct PilhaTabelas {
    TabelaSimbolos* pilha[MAX_PILHA];
    int topo;
} PilhaTabelas;


void tabela_inicializar(TabelaSimbolos* tabela);
// NOVO: Adicionado is_param ao inserir_variavel_na_tabela
void inserir_variavel_na_tabela(TabelaSimbolos* tabela, const char* nome, TipoDado tipo, int posicao, int is_param);
void inserir_funcao(TabelaSimbolos* tabela, const char* nome, TipoDado tipo_retorno, int numero_parametros);
EntradaTabela* buscar_variavel(TabelaSimbolos* tabela, const char* nome);
EntradaFuncao* buscar_funcao(TabelaSimbolos* tabela, const char* nome);

void pilha_iniciar(PilhaTabelas* p);
void pilha_empilhar(PilhaTabelas* p, TabelaSimbolos* tabela);
void pilha_desempilhar(PilhaTabelas* p);
TabelaSimbolos* pilha_topo(PilhaTabelas* p);
EntradaTabela* pilha_buscar_variavel(PilhaTabelas* p, const char* nome);
EntradaFuncao* pilha_buscar_funcao(PilhaTabelas* p, const char* nome);

// NOVO: Funções para busca no escopo atual
EntradaTabela* buscar_variavel_no_escopo_atual(const char* nome);
EntradaFuncao* buscar_funcao_no_escopo_atual(const char* nome);


// Interface da Etapa 3
void iniciar_pilha_tabela();
void eliminar_pilha_tabela();
void criar_escopo();
void remover_escopo();
// NOVO: TipoDado ao invés de int, e is_param
void inserir_variavel(char* nome, TipoDado tipo, int posicao, int is_param);
void inserir_funcao_em_escopo(char* nome, TipoDado tipo_retorno, int num_parametros);
EntradaTabela* buscar_simbolo(char* nome);
EntradaFuncao* buscar_funcao_em_escopo(char* nome);

extern PilhaTabelas pilha_global;

#endif