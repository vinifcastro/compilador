#include "../includes/tabela_simbolos.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

PilhaTabelas pilha_global;

void tabela_inicializar(TabelaSimbolos* tabela) {
    tabela->qtde_variaveis = 0;
    tabela->qtde_funcoes = 0;
}

void inserir_variavel_na_tabela(TabelaSimbolos* tabela, const char* nome, int tipo, int posicao) {
    if (tabela->qtde_variaveis < MAX_VARS) {
        strncpy(tabela->variaveis[tabela->qtde_variaveis].nome, nome, MAX_NAME);
        tabela->variaveis[tabela->qtde_variaveis].tipo = tipo;
        tabela->variaveis[tabela->qtde_variaveis].posicao = posicao;
        tabela->qtde_variaveis++;
    }
}

void inserir_funcao(TabelaSimbolos* tabela, const char* nome, int tipo_retorno, int numero_parametros) {
    if (tabela->qtde_funcoes < MAX_FUNCS) {
        strncpy(tabela->funcoes[tabela->qtde_funcoes].nome, nome, MAX_NAME);
        tabela->funcoes[tabela->qtde_funcoes].tipo_retorno = tipo_retorno;
        tabela->funcoes[tabela->qtde_funcoes].numero_parametros = numero_parametros;
        tabela->qtde_funcoes++;
    }
}

EntradaTabela* buscar_variavel(TabelaSimbolos* tabela, const char* nome) {
    for (int i = 0; i < tabela->qtde_variaveis; i++) {
        if (strcmp(tabela->variaveis[i].nome, nome) == 0) {
            return &tabela->variaveis[i];
        }
    }
    return NULL;
}

EntradaFuncao* buscar_funcao(TabelaSimbolos* tabela, const char* nome) {
    for (int i = 0; i < tabela->qtde_funcoes; i++) {
        if (strcmp(tabela->funcoes[i].nome, nome) == 0) {
            return &tabela->funcoes[i];
        }
    }
    return NULL;
}

void pilha_iniciar(PilhaTabelas* p) {
    p->topo = -1;
}

void pilha_empilhar(PilhaTabelas* p, TabelaSimbolos* tabela) {
    if (p->topo < MAX_PILHA - 1) {
        p->pilha[++(p->topo)] = tabela;
    }
}

void pilha_desempilhar(PilhaTabelas* p) {
    if (p->topo >= 0) {
        p->topo--;
    }
}

TabelaSimbolos* pilha_topo(PilhaTabelas* p) {
    if (p->topo >= 0) {
        return p->pilha[p->topo];
    }
    return NULL;
}

EntradaTabela* pilha_buscar_variavel(PilhaTabelas* p, const char* nome) {
    for (int i = p->topo; i >= 0; i--) {
        EntradaTabela* resultado = buscar_variavel(p->pilha[i], nome);
        if (resultado != NULL) {
            return resultado;
        }
    }
    return NULL;
}

EntradaFuncao* pilha_buscar_funcao(PilhaTabelas* p, const char* nome) {
    for (int i = p->topo; i >= 0; i--) {
        EntradaFuncao* resultado = buscar_funcao(p->pilha[i], nome);
        if (resultado != NULL) {
            return resultado;
        }
    }
    return NULL;
}

void iniciar_pilha_tabela() {
    pilha_iniciar(&pilha_global);
    criar_escopo(); 
}

void eliminar_pilha_tabela() {
    while (pilha_global.topo >= 0)
        remover_escopo();
}

void criar_escopo() {
    TabelaSimbolos* novo = malloc(sizeof(TabelaSimbolos));
    tabela_inicializar(novo);
    pilha_empilhar(&pilha_global, novo);
}

void remover_escopo() {
    if (pilha_global.topo >= 0) {
        TabelaSimbolos* topo = pilha_topo(&pilha_global);
        free(topo);
        pilha_desempilhar(&pilha_global);
    }
}

void inserir_variavel(char* nome, int tipo, int posicao) {
    TabelaSimbolos* topo = pilha_topo(&pilha_global);
    if (topo)
        inserir_variavel_na_tabela(topo, nome, tipo, posicao);
}

void inserir_funcao_em_escopo(char* nome, int tipo, int num_parametros) {
    printf("DEBUG: Chamando inserir_funcao_em_escopo('%s')\n", nome);
    if (pilha_global.topo >= 0) {
        TabelaSimbolos* global = pilha_global.pilha[0];
        printf("DEBUG: pilha_global.pilha[0] = %p\n", (void*)global);
        if (global)
            inserir_funcao(global, nome, tipo, num_parametros);
    }
}



EntradaTabela* buscar_simbolo(char* nome) {
    return pilha_buscar_variavel(&pilha_global, nome);
}

EntradaFuncao* buscar_funcao_em_escopo(char* nome) {
    return pilha_buscar_funcao(&pilha_global, nome);
}
