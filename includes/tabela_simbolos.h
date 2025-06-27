#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

#include "ast.h"

#define MAX_NAME 64
#define MAX_VARS 100
#define MAX_FUNCS 100
#define MAX_PILHA 100
#define MAX_PARAMS 10

typedef struct EntradaTabela {
    char nome[MAX_NAME];
    TipoDado tipo;
    int posicao;
    int is_param;
} EntradaTabela;

typedef struct EntradaFuncao {
    char nome[MAX_NAME];
    TipoDado tipo_retorno;
    int numero_parametros;
    TipoDado tipos_parametros[MAX_PARAMS];
} EntradaFuncao;

typedef struct TabelaSimbolos {
    EntradaTabela variaveis[MAX_VARS];
    int qtde_variaveis;
    int current_offset;

    EntradaFuncao funcoes[MAX_FUNCS];
    int qtde_funcoes;
} TabelaSimbolos;

typedef struct PilhaTabelas {
    TabelaSimbolos* pilha[MAX_PILHA];
    int topo;
} PilhaTabelas;

void tabela_inicializar(TabelaSimbolos* tabela);
void inserir_funcao(TabelaSimbolos* tabela, const char* nome, TipoDado tipo_retorno, int numero_parametros, TipoDado* tipos);
EntradaTabela* buscar_variavel(TabelaSimbolos* tabela, const char* nome);
EntradaFuncao* buscar_funcao(TabelaSimbolos* tabela, const char* nome);

void iniciar_pilha_tabela();
void eliminar_pilha_tabela();
void criar_escopo();
void remover_escopo();
void inserir_variavel(char* nome, TipoDado tipo, int is_param);
void inserir_funcao_em_escopo(char* nome, TipoDado tipo_retorno, int num_params, TipoDado* tipos_params);
EntradaTabela* buscar_simbolo(char* nome);
EntradaFuncao* buscar_funcao_em_escopo(char* nome);
EntradaTabela* buscar_variavel_no_escopo_atual(const char* nome);

extern PilhaTabelas pilha_global;

#endif
