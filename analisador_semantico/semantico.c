#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/semantico.h"
#include "../includes/tabela_simbolos.h" // Inclui ast.h via tabela_simbolos.h

// Variável global para armazenar o tipo de retorno da função atual
// Para checar 'retorne Expr;'
static TipoDado tipo_retorno_funcao_atual = TIPO_UNKNOWN;
// Variável global para armazenar o nome da função atual para mensagens de erro
static char *nome_funcao_atual = NULL;

// Declaração forward para permitir recursão mútua
TipoDado percorrer_ast_semantica(ASTNode *raiz);

// NOVO: Função auxiliar para processar listas de IDs em declarações
// `tipo_herdado` é o tipo do contexto (ex: int de 'int x,y;')
void processar_lista_ids_declaracao(ASTNode *lista_node, TipoDado tipo_herdado)
{
    if (!lista_node)
        return;

    // Se o nó atual é um ID, insere-o na tabela de símbolos com o tipo herdado
    if (lista_node->kind == NODE_ID)
    {
        char *nome = lista_node->valor_str;
        TipoDado tipo_var = tipo_herdado; // O tipo é herdado do nó DECLVAR pai ou do Tipo original

        EntradaTabela *entrada_existente = buscar_variavel_no_escopo_atual(nome);
        if (entrada_existente != NULL)
        {
            printf("ERRO SEMÂNTICO: Variável '%s' já declarada neste escopo (linha %d)\n", nome, lista_node->linha);
            exit(1);
        }
        inserir_variavel(nome, tipo_var, 0, 0);
        lista_node->tipo_dado = tipo_var; // Atualiza o tipo do nó AST para o ID
    }
    // Se o nó atual é uma lista, percorre seus filhos recursivamente
    else if (lista_node->kind == NODE_LISTA)
    {
        for (int i = 0; i < lista_node->n_filhos; i++)
        {
            if (lista_node->filhos[i])
            {
                processar_lista_ids_declaracao(lista_node->filhos[i], tipo_herdado);
            }
        }
    }
    // Outros tipos de nó dentro da lista de DeclVar não são esperados aqui
}

int contar_argumentos(ASTNode *no)
{
    if (!no)
        return 0;
    if (no->kind == NODE_LISTA)
    {
        int soma = 0;
        for (int i = 0; i < no->n_filhos; i++)
        {
            soma += contar_argumentos(no->filhos[i]);
        }
        return soma;
    }
    // Supondo que NODE_ID, NODE_CONST e NODE_EXPR (que são argumentos) contam como 1
    // Ajuste se a gramática de ListExpr for diferente (e.g., ListExpr -> Expr | ListExpr, Expr)
    if (no->kind == NODE_ID || no->kind == NODE_CONST || no->kind == NODE_EXPR)
        return 1;
    return 0;
}

ASTNode *extrair_parametros_node(ASTNode *func_node)
{
    if (func_node && func_node->kind == NODE_FUNCAO)
    {
        // --- INÍCIO DA CORREÇÃO ---

        // Verifica se o primeiro filho é o nó de função aninhado, criado pelo parser.
        if (func_node->n_filhos > 0 && func_node->filhos[0] && func_node->filhos[0]->kind == NODE_FUNCAO)
        {
            ASTNode *inner_func_node = func_node->filhos[0];

            // A lista de parâmetros é o primeiro filho deste nó aninhado.
            if (inner_func_node->n_filhos > 0 && inner_func_node->filhos[0] && inner_func_node->filhos[0]->kind == NODE_LISTA)
            {
                return inner_func_node->filhos[0];
            }
        }
        // --- FIM DA CORREÇÃO ---
    }
    return NULL;
}

void inserir_parametros_formais(ASTNode *parametros_node)
{
    if (!parametros_node)
        return;

    if (parametros_node->kind == NODE_LISTA)
    {
        for (int i = 0; i < parametros_node->n_filhos; i++)
        {
            ASTNode *param = parametros_node->filhos[i];
            if (param && param->kind == NODE_ID)
            {
                inserir_variavel(param->valor_str, param->tipo_dado, 0, 1); // 1 indica que é parâmetro
            }
            else if (param && param->kind == NODE_LISTA)
            {
                inserir_parametros_formais(param);
            }
        }
    }
}

void analisar_semantica(ASTNode *raiz)
{
    iniciar_pilha_tabela();
    percorrer_ast_semantica(raiz);
    eliminar_pilha_tabela();
}

TipoDado percorrer_ast_semantica(ASTNode *raiz)
{
    if (!raiz)
        return TIPO_UNKNOWN;

    TipoDado tipo_resultante = TIPO_UNKNOWN;
    TipoDado tipo_filho1 = TIPO_UNKNOWN;
    TipoDado tipo_filho2 = TIPO_UNKNOWN;

    switch (raiz->kind)
    {
    case NODE_PROGRAMA:
        // Primeira passagem: Registrar todas as funções no escopo global
        // E registrar as variáveis globais.
        // Percorre todos os filhos diretos de PROGRAMA
        for (int i = 0; i < raiz->n_filhos; i++)
        {
            ASTNode *child = raiz->filhos[i];
            if (!child)
                continue;

            if (child->kind == NODE_FUNCAO)
            {
                if (child->valor_str)
                {
                    if (buscar_funcao_em_escopo(child->valor_str) != NULL)
                    {
                        printf("ERRO SEMÂNTICO: função '%s' já declarada (linha %d)\n", child->valor_str, child->linha);
                        exit(1);
                    }
                    ASTNode *parametros_node = extrair_parametros_node(child);
                    int num_param = contar_argumentos(parametros_node);
                    inserir_funcao_em_escopo(child->valor_str, child->tipo_dado, num_param);
                }
            }
            else if (child->kind == NODE_DECLVAR)
            {
                // --- INÍCIO DA CORREÇÃO ---

                // 1. Processa a primeira variável, cujo nome está em 'valor_str' do nó DECLVAR.
                char *nome_primeira_var = child->valor_str;
                TipoDado tipo_declarado = child->tipo_dado;

                if (nome_primeira_var)
                {
                    // Verifica se a variável global já foi declarada
                    if (buscar_variavel_no_escopo_atual(nome_primeira_var) != NULL)
                    {
                        printf("ERRO SEMÂNTICO: Variável global '%s' já declarada (linha %d)\n", nome_primeira_var, child->linha);
                        exit(1);
                    }
                    // Insere a primeira variável na tabela de símbolos
                    inserir_variavel(nome_primeira_var, tipo_declarado, 0, 0);
                }

                // 2. Processa o restante das variáveis da lista de filhos.
                // A lista de outras variáveis (se houver) é o primeiro filho do nó DECLVAR.
                if (child->n_filhos > 0 && child->filhos[0])
                {
                    processar_lista_ids_declaracao(child->filhos[0], tipo_declarado);
                }

                // --- FIM DA CORREÇÃO ---
            }
        }

        // Segunda passagem: Realizar a análise semântica completa para todos os nós
        // Esta segunda passagem irá analisar os comandos e expressões, que agora terão acesso
        // às funções e variáveis globais já registradas.
        for (int i = 0; i < raiz->n_filhos; i++)
        {
            if (raiz->filhos[i])
            {
                // Se já processou a declaração na primeira passada, não precisa chamar percorrer_ast_semantica novamente para ela
                // Mas sim para o bloco principal e chamadas de função, etc.
                // Uma forma mais limpa seria separar as declarações e o bloco principal na AST de nível superior
                // Ou garantir que esta segunda passada não insira novamente, apenas analise o uso.
                // Por simplicidade, assumimos que esta passada é para uso e sub-escopos.
                percorrer_ast_semantica(raiz->filhos[i]);
            }
        }
        break;

    case NODE_BLOCO:
        criar_escopo();
        for (int i = 0; i < raiz->n_filhos; i++)
            if (raiz->filhos[i])
                percorrer_ast_semantica(raiz->filhos[i]);
        remover_escopo();
        break;

    case NODE_LISTA:
        for (int i = 0; i < raiz->n_filhos; i++)
            if (raiz->filhos[i])
                percorrer_ast_semantica(raiz->filhos[i]);
        break;

    case NODE_DECLVAR:
    {
        // Este caso é agora principalmente para variáveis locais dentro de blocos
        // As variáveis globais são tratadas no NODE_PROGRAMA
        ASTNode *first_id_node = raiz->filhos[0];
        TipoDado declared_type = TIPO_UNKNOWN;

        if (first_id_node && first_id_node->kind == NODE_ID)
        {
            char *nome = first_id_node->valor_str;
            declared_type = raiz->tipo_dado; // Tipo do DECLVAR (herdado do Tipo)

            EntradaTabela *entrada_existente = buscar_variavel_no_escopo_atual(nome);
            if (entrada_existente != NULL)
            {
                printf("ERRO SEMÂNTICO: Variável '%s' já declarada neste escopo (linha %d)\n", nome, raiz->linha);
                exit(1);
            }
            inserir_variavel(nome, declared_type, 0, 0);
            first_id_node->tipo_dado = declared_type; // Atualiza o tipo do nó AST para o ID
        }

        if (raiz->n_filhos > 1 && raiz->filhos[1])
        {
            processar_lista_ids_declaracao(raiz->filhos[1], declared_type);
        }
        break;
    }

    case NODE_FUNCAO:
    {
        // --- INÍCIO DA CORREÇÃO ---
        // Apenas o nó de função externo (com nome) deve criar um escopo e definir o contexto.
        if (raiz->valor_str && raiz->valor_str[0] != '\0')
        {
            criar_escopo();
            nome_funcao_atual = raiz->valor_str;
            tipo_retorno_funcao_atual = raiz->tipo_dado;

            ASTNode *parametros_node = extrair_parametros_node(raiz);
            inserir_parametros_formais(parametros_node);

            // Percorre os filhos (que inclui o nó de função aninhado)
            for (int i = 0; i < raiz->n_filhos; i++)
            {
                if (raiz->filhos[i])
                    percorrer_ast_semantica(raiz->filhos[i]);
            }

            remover_escopo();
            tipo_retorno_funcao_atual = TIPO_UNKNOWN;
            nome_funcao_atual = NULL;
        }
        else
        {
            // Para o nó de função aninhado e sem nome, que é um artefato do parser,
            // apenas percorremos seus filhos sem alterar o contexto da função atual.
            for (int i = 0; i < raiz->n_filhos; i++)
            {
                if (raiz->filhos[i])
                    percorrer_ast_semantica(raiz->filhos[i]);
            }
        }
        // --- FIM DA CORREÇÃO ---
        break;
    }

    case NODE_ID:
    {
        EntradaTabela *entrada = buscar_simbolo(raiz->valor_str);
        EntradaFuncao *func = buscar_funcao_em_escopo(raiz->valor_str);
        if (!entrada && !func)
        {
            printf("ERRO SEMÂNTICO: identificador '%s' não declarado (linha %d)\n", raiz->valor_str, raiz->linha);
            exit(1);
        }
        if (entrada)
            raiz->tipo_dado = entrada->tipo;
        else if (func)
            raiz->tipo_dado = func->tipo_retorno;
        else
            raiz->tipo_dado = TIPO_UNKNOWN;
        tipo_resultante = raiz->tipo_dado;
        break;
    }

    case NODE_CONST:
        tipo_resultante = raiz->tipo_dado;
        break;

    case NODE_CMD:
    {
        if (raiz->valor_str && strcmp(raiz->valor_str, "retorne") == 0)
        {
            if (raiz->n_filhos > 0 && raiz->filhos[0])
            {
                TipoDado tipo_retorno_expr = percorrer_ast_semantica(raiz->filhos[0]);
                if (tipo_retorno_funcao_atual == TIPO_UNKNOWN)
                {
                    printf("AVISO SEMÂNTICO: 'retorne' fora de uma função ou tipo de retorno indefinido (linha %d)\n", raiz->linha);
                }
                else if (tipo_retorno_expr != tipo_retorno_funcao_atual)
                {
                    printf("ERRO SEMÂNTICO: Função '%s' deveria retornar tipo %d, mas retornou tipo %d (linha %d)\n",
                           nome_funcao_atual ? nome_funcao_atual : "desconhecida", tipo_retorno_funcao_atual, tipo_retorno_expr, raiz->linha);
                    exit(1);
                }
            }
            else
            {
                if (tipo_retorno_funcao_atual != TIPO_VOID)
                {
                    printf("ERRO SEMÂNTICO: Função '%s' deveria retornar tipo %d, mas retornou vazio (linha %d)\n",
                           nome_funcao_atual ? nome_funcao_atual : "desconhecida", tipo_retorno_funcao_atual, raiz->linha);
                    exit(1);
                }
            }
        }
        else if (raiz->valor_str && strcmp(raiz->valor_str, "leia") == 0)
        {
            if (raiz->n_filhos > 0 && raiz->filhos[0] && raiz->filhos[0]->kind == NODE_ID)
            {
                percorrer_ast_semantica(raiz->filhos[0]);
            }
            else
            {
                printf("ERRO SEMÂNTICO: Comando 'leia' requer um identificador (linha %d)\n", raiz->linha);
                exit(1);
            }
        }
        else if (raiz->valor_str && strcmp(raiz->valor_str, "escreva") == 0)
        {
            if (raiz->n_filhos > 0 && raiz->filhos[0])
            {
                percorrer_ast_semantica(raiz->filhos[0]);
            }
            else
            {
                printf("ERRO SEMÂNTICO: Comando 'escreva' requer uma expressão (linha %d)\n", raiz->linha);
                exit(1);
            }
        }
        else if (raiz->valor_str && (strcmp(raiz->valor_str, "se") == 0 ||
                                     (strcmp(raiz->valor_str, "se_senao") == 0) ||
                                     (strcmp(raiz->valor_str, "enquanto") == 0)))
        {
            if (raiz->n_filhos > 0 && raiz->filhos[0])
            {
                TipoDado cond_tipo = percorrer_ast_semantica(raiz->filhos[0]);
                if (cond_tipo != TIPO_INT)
                {
                    printf("ERRO SEMÂNTICO: Condição em '%s' deve ser um inteiro, mas é tipo %d (linha %d)\n",
                           raiz->valor_str, cond_tipo, raiz->linha);
                    exit(1);
                }
            }
            for (int i = 1; i < raiz->n_filhos; i++)
            {
                if (raiz->filhos[i])
                    percorrer_ast_semantica(raiz->filhos[i]);
            }
        }
        for (int i = 0; i < raiz->n_filhos; i++)
            if (raiz->filhos[i])
                percorrer_ast_semantica(raiz->filhos[i]);
        break;
    }

    case NODE_EXPR:
    {
        if (raiz->valor_str && strcmp(raiz->valor_str, "call") == 0)
        {
            if (raiz->n_filhos >= 1 && raiz->filhos[0])
            {
                ASTNode *idNode = raiz->filhos[0];
                EntradaFuncao *func = buscar_funcao_em_escopo(idNode->valor_str);
                if (!func)
                {
                    printf("ERRO SEMÂNTICO: chamada para função '%s' não declarada (linha %d)\n", idNode->valor_str, raiz->linha);
                    exit(1);
                }

                int fornecidos = (raiz->n_filhos == 2 && raiz->filhos[1]) ? contar_argumentos(raiz->filhos[1]) : 0;
                if (fornecidos != func->numero_parametros)
                {
                    printf("ERRO SEMÂNTICO: função '%s' espera %d argumento(s), mas %d fornecido(s) (linha %d)\n",
                           idNode->valor_str, func->numero_parametros, fornecidos, raiz->linha);
                    exit(1);
                }

                raiz->tipo_dado = func->tipo_retorno;
                tipo_resultante = raiz->tipo_dado;
            }
            else
            {
                printf("ERRO SEMÂNTICO: Chamada de função inválida (linha %d)\n", raiz->linha);
                exit(1);
            }
        }
        else if (raiz->valor_str && strcmp(raiz->valor_str, "=") == 0)
        {
            if (raiz->n_filhos == 2 && raiz->filhos[0] && raiz->filhos[1])
            {
                ASTNode *lhs_node = raiz->filhos[0];
                if (lhs_node->kind != NODE_ID)
                {
                    printf("ERRO SEMÂNTICO: Atribuição inválida, lado esquerdo não é um identificador (linha %d)\n", raiz->linha);
                    exit(1);
                }

                TipoDado tipo_lhs = percorrer_ast_semantica(lhs_node);
                TipoDado tipo_rhs = percorrer_ast_semantica(raiz->filhos[1]);

                if (tipo_lhs == TIPO_UNKNOWN || tipo_rhs == TIPO_UNKNOWN)
                {
                    printf("AVISO SEMÂNTICO: Tipos desconhecidos em atribuição (linha %d)\n", raiz->linha);
                }
                else if (tipo_lhs != tipo_rhs)
                {
                    printf("ERRO SEMÂNTICO: Atribuição de tipos incompativeis: '%s' (tipo %d) = Expressão (tipo %d) (linha %d)\n",
                           lhs_node->valor_str, tipo_lhs, tipo_rhs, raiz->linha);
                    exit(1);
                }
                raiz->tipo_dado = tipo_lhs;
                tipo_resultante = raiz->tipo_dado;
            }
        }
        else if (raiz->valor_str && (strcmp(raiz->valor_str, "+") == 0 || strcmp(raiz->valor_str, "-") == 0 ||
                                     strcmp(raiz->valor_str, "*") == 0 || strcmp(raiz->valor_str, "/") == 0))
        {
            if (raiz->n_filhos == 2 && raiz->filhos[0] && raiz->filhos[1])
            {
                tipo_filho1 = percorrer_ast_semantica(raiz->filhos[0]);
                tipo_filho2 = percorrer_ast_semantica(raiz->filhos[1]);

                if (tipo_filho1 != TIPO_INT || tipo_filho2 != TIPO_INT)
                {
                    printf("ERRO SEMÂNTICO: Operadores aritméticos exigem operandos do tipo INT, mas são %d e %d (linha %d)\n",
                           tipo_filho1, tipo_filho2, raiz->linha);
                    exit(1);
                }
                raiz->tipo_dado = TIPO_INT;
                tipo_resultante = TIPO_INT;
            }
            else if (raiz->valor_str && strcmp(raiz->valor_str, "-") == 0 && raiz->n_filhos == 1)
            {
                tipo_filho1 = percorrer_ast_semantica(raiz->filhos[0]);
                if (tipo_filho1 != TIPO_INT)
                {
                    printf("ERRO SEMÂNTICO: Operador unário '-' exige operando do tipo INT, mas é %d (linha %d)\n",
                           tipo_filho1, raiz->linha);
                    exit(1);
                }
                raiz->tipo_dado = TIPO_INT;
                tipo_resultante = TIPO_INT;
            }
        }
        else if (raiz->valor_str && (strcmp(raiz->valor_str, "==") == 0 || strcmp(raiz->valor_str, "!=") == 0 ||
                                     strcmp(raiz->valor_str, "<") == 0 || strcmp(raiz->valor_str, ">") == 0 ||
                                     strcmp(raiz->valor_str, ">=") == 0 || strcmp(raiz->valor_str, "<=") == 0))
        {
            if (raiz->n_filhos == 2 && raiz->filhos[0] && raiz->filhos[1])
            {
                tipo_filho1 = percorrer_ast_semantica(raiz->filhos[0]);
                tipo_filho2 = percorrer_ast_semantica(raiz->filhos[1]);

                if (tipo_filho1 == TIPO_UNKNOWN || tipo_filho2 == TIPO_UNKNOWN)
                {
                    printf("AVISO SEMÂNTICO: Tipos desconhecidos em operação relacional (linha %d)\n", raiz->linha);
                }
                else if (tipo_filho1 != tipo_filho2)
                {
                    printf("ERRO SEMÂNTICO: Operadores relacionais exigem operandos do mesmo tipo, mas são %d e %d (linha %d)\n",
                           tipo_filho1, tipo_filho2, raiz->linha);
                    exit(1);
                }
                raiz->tipo_dado = TIPO_INT;
                tipo_resultante = TIPO_INT;
            }
        }
        else if (raiz->valor_str && (strcmp(raiz->valor_str, "ou") == 0 || strcmp(raiz->valor_str, "e") == 0))
        {
            if (raiz->n_filhos == 2 && raiz->filhos[0] && raiz->filhos[1])
            {
                tipo_filho1 = percorrer_ast_semantica(raiz->filhos[0]);
                tipo_filho2 = percorrer_ast_semantica(raiz->filhos[1]);

                if (tipo_filho1 != TIPO_INT || tipo_filho2 != TIPO_INT)
                {
                    printf("ERRO SEMÂNTICO: Operadores lógicos exigem operandos do tipo INT, mas são %d e %d (linha %d)\n",
                           tipo_filho1, tipo_filho2, raiz->linha);
                    exit(1);
                }
                raiz->tipo_dado = TIPO_INT;
                tipo_resultante = TIPO_INT;
            }
        }
        else if (raiz->valor_str && strcmp(raiz->valor_str, "!") == 0)
        {
            if (raiz->n_filhos == 1 && raiz->filhos[0])
            {
                tipo_filho1 = percorrer_ast_semantica(raiz->filhos[0]);
                if (tipo_filho1 != TIPO_INT)
                {
                    printf("ERRO SEMÂNTICO: Operador lógico '!' exige operando do tipo INT, mas é %d (linha %d)\n",
                           tipo_filho1, raiz->linha);
                    exit(1);
                }
                raiz->tipo_dado = TIPO_INT;
                tipo_resultante = TIPO_INT;
            }
        }
        else
        {
            for (int i = 0; i < raiz->n_filhos; i++)
            {
                if (raiz->filhos[i])
                {
                    tipo_resultante = percorrer_ast_semantica(raiz->filhos[i]);
                }
            }
            raiz->tipo_dado = tipo_resultante;
        }
        break;
    }

    default:
        for (int i = 0; i < raiz->n_filhos; i++)
            if (raiz->filhos[i])
                percorrer_ast_semantica(raiz->filhos[i]);
        break;
    }
    return tipo_resultante;
}