#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/semantico.h"
#include "../includes/tabela_simbolos.h"

static TipoDado tipo_retorno_funcao_atual = TIPO_UNKNOWN;
static char *nome_funcao_atual = NULL;

TipoDado percorrer_ast_semantica(ASTNode *raiz);

void coletar_tipos_parametros(ASTNode* params_node, TipoDado* tipos_array, int* count) {
    if (!params_node || *count >= MAX_PARAMS) return;
    if (params_node->kind == NODE_LISTA) {
        for (int i = 0; i < params_node->n_filhos; i++) {
            coletar_tipos_parametros(params_node->filhos[i], tipos_array, count);
        }
    } else if (params_node->kind == NODE_ID) {
        tipos_array[*count] = params_node->tipo_dado;
        (*count)++;
    }
}

void verificar_tipos_argumentos(ASTNode* arg_node, EntradaFuncao* func_info, int arg_idx) {
    if (!arg_node) return;
    if (arg_node->kind == NODE_LISTA) {
        for (int i = 0; i < arg_node->n_filhos; i++) {
            verificar_tipos_argumentos(arg_node->filhos[i], func_info, arg_idx);
            if(arg_node->filhos[i]->kind != NODE_LISTA) arg_idx++;
        }
    } else {
        TipoDado tipo_argumento = percorrer_ast_semantica(arg_node);
        if (arg_idx < func_info->numero_parametros) {
            TipoDado tipo_esperado = func_info->tipos_parametros[arg_idx];
            if (tipo_argumento != tipo_esperado) {
                printf("ERRO SEMÂNTICO: Incompatibilidade no argumento %d da chamada da função '%s'. Esperado tipo %d, mas foi fornecido tipo %d (linha %d)\n",
                       arg_idx + 1, func_info->nome, tipo_esperado, tipo_argumento, arg_node->linha);
                exit(1);
            }
        }
    }
}

void processar_lista_ids_declaracao(ASTNode *lista_node, TipoDado tipo_herdado) { if (!lista_node) return; if (lista_node->kind == NODE_ID) { char *nome = lista_node->valor_str; if (nome && buscar_variavel_no_escopo_atual(nome) == NULL) { inserir_variavel(nome, tipo_herdado, 0); lista_node->tipo_dado = tipo_herdado; } else if (nome) { printf("ERRO SEMÂNTICO: Variável '%s' já declarada (linha %d)\n", nome, lista_node->linha); exit(1); } } else if (lista_node->kind == NODE_LISTA) { for (int i = 0; i < lista_node->n_filhos; i++) { if (lista_node->filhos[i]) processar_lista_ids_declaracao(lista_node->filhos[i], tipo_herdado); } } }
int contar_argumentos(ASTNode *no) { if (!no) return 0; if (no->kind == NODE_LISTA) { int soma = 0; for (int i = 0; i < no->n_filhos; i++) soma += contar_argumentos(no->filhos[i]); return soma; } if (no->kind == NODE_ID || no->kind == NODE_CONST || no->kind == NODE_EXPR) return 1; return 0; }
ASTNode *extrair_parametros_node(ASTNode *func_node) { if (func_node && func_node->n_filhos > 0 && func_node->filhos[0] && func_node->filhos[0]->kind == NODE_FUNCAO) { ASTNode *inner_func = func_node->filhos[0]; if (inner_func->n_filhos > 0 && inner_func->filhos[0] && inner_func->filhos[0]->kind == NODE_LISTA) { return inner_func->filhos[0]; } } return NULL; }
void inserir_parametros_formais(ASTNode *params_node) { if (!params_node || params_node->kind != NODE_LISTA) return; for (int i = 0; i < params_node->n_filhos; i++) { ASTNode *param = params_node->filhos[i]; if (param && param->kind == NODE_ID && param->valor_str) { inserir_variavel(param->valor_str, param->tipo_dado, 1); } else if (param && param->kind == NODE_LISTA) { inserir_parametros_formais(param); } } }
void analisar_semantica(ASTNode *raiz) { iniciar_pilha_tabela(); percorrer_ast_semantica(raiz); eliminar_pilha_tabela(); }

TipoDado percorrer_ast_semantica(ASTNode *raiz) {
    if (!raiz) return TIPO_UNKNOWN;
    TipoDado tipo_resultante = TIPO_UNKNOWN;

    switch (raiz->kind) {
        case NODE_PROGRAMA:
            for (int i = 0; i < raiz->n_filhos; i++) {
                ASTNode *child = raiz->filhos[i];
                if (child && child->kind == NODE_FUNCAO && child->valor_str) {
                    if (buscar_funcao_em_escopo(child->valor_str) != NULL) {
                        printf("ERRO SEMÂNTICO: Função '%s' redeclarada (linha %d)\n", child->valor_str, child->linha);
                        exit(1);
                    }
                    ASTNode* params_node = extrair_parametros_node(child);
                    TipoDado tipos_params[MAX_PARAMS];
                    int num_params = 0;
                    if(params_node) {
                        coletar_tipos_parametros(params_node, tipos_params, &num_params);
                    }
                    inserir_funcao_em_escopo(child->valor_str, child->tipo_dado, num_params, tipos_params);
                } else if (child && child->kind == NODE_DECLVAR) {
                    percorrer_ast_semantica(child);
                }
            }
            for (int i = 0; i < raiz->n_filhos; i++) {
                 if (raiz->filhos[i] && raiz->filhos[i]->kind != NODE_DECLVAR) {
                    percorrer_ast_semantica(raiz->filhos[i]);
                 }
            }
            break;
        case NODE_BLOCO: criar_escopo(); for (int i = 0; i < raiz->n_filhos; i++) { if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]); } remover_escopo(); break;
        case NODE_DECLVAR: if (raiz->valor_str) { if (buscar_variavel_no_escopo_atual(raiz->valor_str) != NULL) { printf("ERRO SEMÂNTICO: Variável '%s' já declarada (linha %d)\n", raiz->valor_str, raiz->linha); exit(1); } inserir_variavel(raiz->valor_str, raiz->tipo_dado, 0); } for (int i = 0; i < raiz->n_filhos; i++) { if(raiz->filhos[i]) processar_lista_ids_declaracao(raiz->filhos[i], raiz->tipo_dado); } break;
        case NODE_FUNCAO: if (raiz->valor_str) { criar_escopo(); nome_funcao_atual = raiz->valor_str; tipo_retorno_funcao_atual = raiz->tipo_dado; inserir_parametros_formais(extrair_parametros_node(raiz)); for (int i = 0; i < raiz->n_filhos; i++) { if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]); } remover_escopo(); nome_funcao_atual = NULL; tipo_retorno_funcao_atual = TIPO_UNKNOWN; } else { for (int i = 0; i < raiz->n_filhos; i++) { if (raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]); } } break;
        case NODE_ID: if (!raiz->valor_str) return TIPO_UNKNOWN; EntradaTabela* var = buscar_simbolo(raiz->valor_str); if (var) tipo_resultante = var->tipo; else { EntradaFuncao* func = buscar_funcao_em_escopo(raiz->valor_str); if (func) tipo_resultante = func->tipo_retorno; else { printf("ERRO SEMÂNTICO: '%s' não foi declarado (linha %d)\n", raiz->valor_str, raiz->linha); exit(1); } } raiz->tipo_dado = tipo_resultante; break;
        case NODE_CONST: tipo_resultante = raiz->tipo_dado; break;
        case NODE_CMD: if (!raiz->valor_str) break; if (strcmp(raiz->valor_str, "retorne") == 0) { TipoDado tr = TIPO_VOID; if (raiz->n_filhos > 0 && raiz->filhos[0]) { tr = percorrer_ast_semantica(raiz->filhos[0]); } if (tipo_retorno_funcao_atual != TIPO_UNKNOWN && tr != tipo_retorno_funcao_atual) { printf("ERRO SEMÂNTICO: Retorno incompatível na função '%s' (linha %d)\n", nome_funcao_atual, raiz->linha); exit(1); } } else { for(int i=0; i < raiz->n_filhos; ++i) if(raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]); } break;
        case NODE_EXPR:
            if (!raiz->valor_str) { tipo_resultante = TIPO_UNKNOWN; break; }
            if (strcmp(raiz->valor_str, "call") == 0) {
                if (raiz->n_filhos < 1 || !raiz->filhos[0] || !raiz->filhos[0]->valor_str) {
                    printf("ERRO SEMÂNTICO: Chamada de função malformada (linha %d)\n", raiz->linha);
                    exit(1);
                }
                EntradaFuncao* func_info = buscar_funcao_em_escopo(raiz->filhos[0]->valor_str);
                if (!func_info) {
                    printf("ERRO SEMÂNTICO: Função '%s' não declarada (linha %d)\n", raiz->filhos[0]->valor_str, raiz->linha);
                    exit(1);
                }
                ASTNode* args_node = (raiz->n_filhos > 1) ? raiz->filhos[1] : NULL;
                int args_fornecidos = contar_argumentos(args_node);
                if (args_fornecidos != func_info->numero_parametros) {
                    printf("ERRO SEMÂNTICO: Função '%s' espera %d argumento(s), mas recebeu %d (linha %d)\n",
                           func_info->nome, func_info->numero_parametros, args_fornecidos, raiz->linha);
                    exit(1);
                }
                if (args_node) {
                    verificar_tipos_argumentos(args_node, func_info, 0);
                }
                tipo_resultante = func_info->tipo_retorno;
            } else if (strcmp(raiz->valor_str, "=") == 0) {
                if (raiz->n_filhos < 2 || !raiz->filhos[0] || !raiz->filhos[1] || raiz->filhos[0]->kind != NODE_ID) {
                    printf("ERRO SEMÂNTICO: Atribuição inválida (linha %d)\n", raiz->linha); exit(1);
                }
                TipoDado tipo_lhs = percorrer_ast_semantica(raiz->filhos[0]);
                TipoDado tipo_rhs = percorrer_ast_semantica(raiz->filhos[1]);
                if (tipo_lhs != tipo_rhs) {
                    printf("ERRO SEMÂNTICO: Atribuição com tipos incompatíveis (linha %d)\n", raiz->linha); exit(1);
                }
                tipo_resultante = tipo_lhs;
            } else {
                 if (raiz->n_filhos > 0 && raiz->filhos[0]) tipo_resultante = percorrer_ast_semantica(raiz->filhos[0]);
                 if (raiz->n_filhos > 1 && raiz->filhos[1]) percorrer_ast_semantica(raiz->filhos[1]);
                 tipo_resultante = TIPO_INT;
            }
            raiz->tipo_dado = tipo_resultante;
            break;
        default:
             for (int i = 0; i < raiz->n_filhos; i++) {
                if(raiz->filhos[i]) percorrer_ast_semantica(raiz->filhos[i]);
            }
            break;
    }
    return tipo_resultante;
}
