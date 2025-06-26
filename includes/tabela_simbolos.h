#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

#define MAX_NAME 64
#define MAX_VARS 100
#define MAX_FUNCS 100
#define MAX_PILHA 100

typedef struct EntradaTabela {
    char nome[MAX_NAME];
    int tipo;
    int posicao;
} EntradaTabela;

typedef struct EntradaFuncao {
    char nome[MAX_NAME];
    int tipo_retorno;
    int numero_parametros;
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
void inserir_variavel_na_tabela(TabelaSimbolos* tabela, const char* nome, int tipo, int posicao);
void inserir_funcao(TabelaSimbolos* tabela, const char* nome, int tipo_retorno, int numero_parametros);
EntradaTabela* buscar_variavel(TabelaSimbolos* tabela, const char* nome);
EntradaFuncao* buscar_funcao(TabelaSimbolos* tabela, const char* nome);

void pilha_iniciar(PilhaTabelas* p);
void pilha_empilhar(PilhaTabelas* p, TabelaSimbolos* tabela);
void pilha_desempilhar(PilhaTabelas* p);
TabelaSimbolos* pilha_topo(PilhaTabelas* p);
EntradaTabela* pilha_buscar_variavel(PilhaTabelas* p, const char* nome);
EntradaFuncao* pilha_buscar_funcao(PilhaTabelas* p, const char* nome);

// Interface da Etapa 3
void iniciar_pilha_tabela();
void eliminar_pilha_tabela();
void criar_escopo();
void remover_escopo();
void inserir_variavel(char* nome, int tipo, int posicao);
void inserir_funcao_em_escopo(char* nome, int tipo, int num_parametros);
EntradaTabela* buscar_simbolo(char* nome);
EntradaFuncao* buscar_funcao_em_escopo(char* nome);

extern PilhaTabelas pilha_global;

#endif
