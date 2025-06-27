#include "../includes/tabela_simbolos.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

PilhaTabelas pilha_global;

void tabela_inicializar(TabelaSimbolos* tabela) {
    if(!tabela) return;
    tabela->qtde_variaveis = 0;
    tabela->qtde_funcoes = 0;
    tabela->current_offset = -8;
}

void inserir_variavel_na_tabela(TabelaSimbolos* tabela, const char* nome, TipoDado tipo, int is_param) {
    if (tabela->qtde_variaveis < MAX_VARS) {
        strncpy(tabela->variaveis[tabela->qtde_variaveis].nome, nome, MAX_NAME - 1);
        tabela->variaveis[tabela->qtde_variaveis].nome[MAX_NAME - 1] = '\0';
        tabela->variaveis[tabela->qtde_variaveis].tipo = tipo;
        tabela->variaveis[tabela->qtde_variaveis].is_param = is_param;
        tabela->current_offset -= 4;
        tabela->variaveis[tabela->qtde_variaveis].posicao = tabela->current_offset;
        tabela->qtde_variaveis++;
    }
}

void inserir_funcao(TabelaSimbolos* tabela, const char* nome, TipoDado tipo_retorno, int numero_parametros, TipoDado* tipos) {
    if (tabela->qtde_funcoes < MAX_FUNCS) {
        int idx = tabela->qtde_funcoes;
        strncpy(tabela->funcoes[idx].nome, nome, MAX_NAME - 1);
        tabela->funcoes[idx].nome[MAX_NAME - 1] = '\0';
        tabela->funcoes[idx].tipo_retorno = tipo_retorno;
        tabela->funcoes[idx].numero_parametros = numero_parametros;
        for (int i = 0; i < numero_parametros; i++) {
            if (i < MAX_PARAMS) {
                tabela->funcoes[idx].tipos_parametros[i] = tipos[i];
            }
        }
        tabela->qtde_funcoes++;
    }
}

EntradaTabela* buscar_variavel(TabelaSimbolos* tabela, const char* nome) {
    for (int i = 0; i < tabela->qtde_variaveis; i++) {
        if (strcmp(tabela->variaveis[i].nome, nome) == 0) return &tabela->variaveis[i];
    }
    return NULL;
}

EntradaFuncao* buscar_funcao(TabelaSimbolos* tabela, const char* nome) {
    for (int i = 0; i < tabela->qtde_funcoes; i++) {
        if (strcmp(tabela->funcoes[i].nome, nome) == 0) return &tabela->funcoes[i];
    }
    return NULL;
}

void pilha_iniciar(PilhaTabelas* p) { p->topo = -1; }

void pilha_empilhar(PilhaTabelas* p, TabelaSimbolos* tabela) {
    if (p->topo < MAX_PILHA - 1) p->pilha[++(p->topo)] = tabela;
}

void pilha_desempilhar(PilhaTabelas* p) {
    if (p->topo >= 0) p->topo--;
}

TabelaSimbolos* pilha_topo(PilhaTabelas* p) {
    return (p->topo >= 0) ? p->pilha[p->topo] : NULL;
}

EntradaTabela* pilha_buscar_variavel(PilhaTabelas* p, const char* nome) {
    for (int i = p->topo; i >= 0; i--) {
        EntradaTabela* r = buscar_variavel(p->pilha[i], nome);
        if (r) return r;
    }
    return NULL;
}

EntradaFuncao* pilha_buscar_funcao(PilhaTabelas* p, const char* nome) {
    return (p->topo >= 0) ? buscar_funcao(p->pilha[0], nome) : NULL;
}

EntradaTabela* buscar_variavel_no_escopo_atual(const char* nome) {
    TabelaSimbolos* t = pilha_topo(&pilha_global);
    return t ? buscar_variavel(t, nome) : NULL;
}

void iniciar_pilha_tabela() {
    pilha_iniciar(&pilha_global);
    criar_escopo();
}

void eliminar_pilha_tabela() {
    while (pilha_global.topo >= 0) remover_escopo();
}

void criar_escopo() {
    TabelaSimbolos* n = malloc(sizeof(TabelaSimbolos));
    if (!n) exit(1);
    tabela_inicializar(n);
    pilha_empilhar(&pilha_global, n);
}

void remover_escopo() {
    TabelaSimbolos* t = pilha_topo(&pilha_global);
    if (t) free(t);
    pilha_desempilhar(&pilha_global);
}

void inserir_variavel(char* nome, TipoDado tipo, int is_param) {
    TabelaSimbolos* t = pilha_topo(&pilha_global);
    if (t) inserir_variavel_na_tabela(t, nome, tipo, is_param);
}

void inserir_funcao_em_escopo(char* nome, TipoDado tipo_retorno, int num_params, TipoDado* tipos_params) {
    if (pilha_global.topo >= 0) {
        TabelaSimbolos* global = pilha_global.pilha[0];
        if (global) {
            inserir_funcao(global, nome, tipo_retorno, num_params, tipos_params);
        }
    }
}

EntradaTabela* buscar_simbolo(char* nome) {
    return pilha_buscar_variavel(&pilha_global, nome);
}

EntradaFuncao* buscar_funcao_em_escopo(char* nome) {
    return pilha_buscar_funcao(&pilha_global, nome);
}
