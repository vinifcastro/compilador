#include "../includes/tabela_simbolos.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

PilhaTabelas pilha_global;

void tabela_inicializar(TabelaSimbolos* tabela) {
    tabela->qtde_variaveis = 0;
    tabela->qtde_funcoes = 0;
}

// NOVO: Adicionado is_param
void inserir_variavel_na_tabela(TabelaSimbolos* tabela, const char* nome, TipoDado tipo, int posicao, int is_param) {
    if (tabela->qtde_variaveis < MAX_VARS) {
        strncpy(tabela->variaveis[tabela->qtde_variaveis].nome, nome, MAX_NAME - 1);
        tabela->variaveis[tabela->qtde_variaveis].nome[MAX_NAME - 1] = '\0'; // Garantir null termination
        tabela->variaveis[tabela->qtde_variaveis].tipo = tipo;
        tabela->variaveis[tabela->qtde_variaveis].posicao = posicao;
        tabela->variaveis[tabela->qtde_variaveis].is_param = is_param; // NOVO
        tabela->qtde_variaveis++;
    } else {
        fprintf(stderr, "Erro: Limite de variáveis na tabela de símbolos atingido.\n");
    }
}

void inserir_funcao(TabelaSimbolos* tabela, const char* nome, TipoDado tipo_retorno, int numero_parametros) {
    if (tabela->qtde_funcoes < MAX_FUNCS) {
        strncpy(tabela->funcoes[tabela->qtde_funcoes].nome, nome, MAX_NAME - 1);
        tabela->funcoes[tabela->qtde_funcoes].nome[MAX_NAME - 1] = '\0'; // Garantir null termination
        tabela->funcoes[tabela->qtde_funcoes].tipo_retorno = tipo_retorno;
        tabela->funcoes[tabela->qtde_funcoes].numero_parametros = numero_parametros;
        tabela->qtde_funcoes++;
    } else {
        fprintf(stderr, "Erro: Limite de funções na tabela de símbolos atingido.\n");
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
    } else {
        fprintf(stderr, "Erro: Limite da pilha de tabelas de símbolos atingido.\n");
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
    // Funções são sempre buscadas no escopo global (primeiro elemento da pilha)
    if (p->topo >= 0 && p->pilha[0]) { // Assume que a tabela global está sempre na base da pilha
        return buscar_funcao(p->pilha[0], nome);
    }
    return NULL;
}

// NOVO: Implementação da busca no escopo atual
EntradaTabela* buscar_variavel_no_escopo_atual(const char* nome) {
    TabelaSimbolos* topo = pilha_topo(&pilha_global);
    if (topo) {
        return buscar_variavel(topo, nome);
    }
    return NULL;
}

// NOVO: Implementação da busca de função no escopo atual (global)
EntradaFuncao* buscar_funcao_no_escopo_atual(const char* nome) {
     TabelaSimbolos* global = pilha_global.pilha[0]; // Funções sempre no escopo global
     if (global) {
         return buscar_funcao(global, nome);
     }
     return NULL;
}


void iniciar_pilha_tabela() {
    pilha_iniciar(&pilha_global);
    criar_escopo(); // Cria o escopo global
}

void eliminar_pilha_tabela() {
    while (pilha_global.topo >= 0)
        remover_escopo();
}

void criar_escopo() {
    TabelaSimbolos* novo = malloc(sizeof(TabelaSimbolos));
    if (!novo) {
        perror("Erro ao alocar TabelaSimbolos para novo escopo");
        exit(1);
    }
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

// NOVO: Adicionado is_param
void inserir_variavel(char* nome, TipoDado tipo, int posicao, int is_param) {
    TabelaSimbolos* topo = pilha_topo(&pilha_global);
    if (topo) {
        // Antes de inserir, verificar se já existe uma variável com o mesmo nome NO ESCOPO ATUAL
        // para evitar duplicação (e para a regra de parâmetro/local)
        if (buscar_variavel_no_escopo_atual(nome) != NULL) {
            // Este caso é um erro de variável já declarada no mesmo escopo
            // A mensagem de erro específica para o parâmetro vs. variável local será em semantico.c
            // pois lá temos o contexto da linha. Aqui apenas evita a inserção.
            return;
        }
        inserir_variavel_na_tabela(topo, nome, tipo, posicao, is_param);
    }
}

// NOVO: tipo_retorno usa TipoDado
void inserir_funcao_em_escopo(char* nome, TipoDado tipo_retorno, int num_parametros) {
    // printf("DEBUG: Chamando inserir_funcao_em_escopo('%s')\n", nome);
    if (pilha_global.topo >= 0) {
        TabelaSimbolos* global = pilha_global.pilha[0]; // Funções são sempre no escopo global
        // printf("DEBUG: pilha_global.pilha[0] = %p\n", (void*)global);
        if (global) {
            // Verificar se a função já foi declarada (evitar duplicação)
            if (buscar_funcao(global, nome) != NULL) {
                // Erro: Função já declarada. A checagem de linha e erro fica no semantico.c
                return;
            }
            inserir_funcao(global, nome, tipo_retorno, num_parametros);
        }
    }
}

EntradaTabela* buscar_simbolo(char* nome) {
    return pilha_buscar_variavel(&pilha_global, nome);
}

EntradaFuncao* buscar_funcao_em_escopo(char* nome) {
    return pilha_buscar_funcao(&pilha_global, nome);
}