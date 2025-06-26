#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/semantico.h"
#include "../includes/tabela_simbolos.h"

int contar_argumentos(ASTNode* no) {
    if (!no) return 0;
    if (no->kind == NODE_LISTA) {
        int soma = 0;
        for (int i = 0; i < no->n_filhos; i++) {
            soma += contar_argumentos(no->filhos[i]);
        }
        return soma;
    }
    if (no->kind == NODE_ID || no->kind == NODE_CONST) return 1;
    return 0;
}

ASTNode* extrair_parametros(ASTNode* func) {
    if (func && func->n_filhos > 0 && func->filhos[0] && func->filhos[0]->kind == NODE_FUNCAO) {
        ASTNode* filhoFunc = func->filhos[0];
        if (filhoFunc->n_filhos > 0)
            return filhoFunc->filhos[0]; 
        return NULL;
    }
    return NULL;
}

void inserir_parametros_formais(ASTNode* parametros) {
    if (!parametros) return;
    if (parametros->kind == NODE_LISTA) {
        for (int i = 0; i < parametros->n_filhos; i++) {
            inserir_parametros_formais(parametros->filhos[i]);
        }
    } else if (parametros->kind == NODE_ID) {
        inserir_variavel(parametros->valor_str, 1, 0);
    }
}

void percorrer_ast_semantica(ASTNode* raiz);

void analisar_semantica(ASTNode* raiz) {
    iniciar_pilha_tabela();   
    percorrer_ast_semantica(raiz);
    eliminar_pilha_tabela();
}

void percorrer_ast_semantica(ASTNode* raiz) {
    if (!raiz) return;

    switch (raiz->kind) {
        case NODE_PROGRAMA:
            for (int i = 0; i < raiz->n_filhos; i++) {
                if (raiz->filhos[i] && raiz->filhos[i]->kind == NODE_FUNCAO) {
                    ASTNode* func = raiz->filhos[i];
                    if (func->valor_str) {
                        char* nome = func->valor_str;
                        ASTNode* parametros = extrair_parametros(func);
                        int num_param = contar_argumentos(parametros);
                        inserir_funcao_em_escopo(nome, 1, num_param);
                    }
                }
            }

            for (int i = 0; i < raiz->n_filhos; i++) {
                if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]);
            }
            break;

        case NODE_BLOCO:
            criar_escopo();
            for (int i = 0; i < raiz->n_filhos; i++)
                if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]);
            remover_escopo();
            break;

        case NODE_LISTA:
            for (int i = 0; i < raiz->n_filhos; i++)
                if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]);
            break;

        case NODE_DECLVAR:
            if (raiz->n_filhos >= 1 && raiz->filhos[0] && raiz->filhos[0]->kind == NODE_ID) {
                char* nome = raiz->filhos[0]->valor_str;
                inserir_variavel(nome, 1, 0);
            }
            for (int i = 0; i < raiz->n_filhos; i++)
                if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]);
            break;

        case NODE_FUNCAO:
            criar_escopo();
            {
                ASTNode* parametros = extrair_parametros(raiz);
                inserir_parametros_formais(parametros);
            }
            for (int i = 0; i < raiz->n_filhos; i++)
                if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]);
            remover_escopo();
            break;

        case NODE_ID: {
            EntradaTabela* entrada = buscar_simbolo(raiz->valor_str);
            EntradaFuncao* func = buscar_funcao_em_escopo(raiz->valor_str);
            if (!entrada && !func) {
                printf("ERRO SEMÂNTICO: identificador '%s' não declarado (linha %d)\n", raiz->valor_str, raiz->linha);
                exit(1);
            }
            break;
        }


        case NODE_EXPR:
            if (raiz->valor_str && strcmp(raiz->valor_str, "call") == 0) {
                if (raiz->n_filhos >= 1 && raiz->filhos[0]) {
                    ASTNode* idNode = raiz->filhos[0];
                    EntradaFuncao* func = buscar_funcao_em_escopo(idNode->valor_str);
                    if (!func) {
                        printf("ERRO SEMÂNTICO: chamada para função '%s' não declarada (linha %d)\n", idNode->valor_str, raiz->linha);
                        exit(1);
                    }
                    int fornecidos = (raiz->n_filhos == 2 && raiz->filhos[1]) ? contar_argumentos(raiz->filhos[1]) : 0;
                    if (fornecidos != func->numero_parametros) {
                        printf("ERRO SEMÂNTICO: função '%s' espera %d argumento(s), mas %d fornecido(s) (linha %d)\n",
                               idNode->valor_str, func->numero_parametros, fornecidos, raiz->linha);
                        exit(1);
                    }
                }
            }
            for (int i = 0; i < raiz->n_filhos; i++)
                if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]);
            break;

        default:
            for (int i = 0; i < raiz->n_filhos; i++)
                if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]);
            break;
    }
}
