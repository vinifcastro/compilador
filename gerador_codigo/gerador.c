#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/ast.h"
#include "../includes/tabela_simbolos.h"
#include "../includes/gerador.h"

// --- Protótipo da Função (Declaração Forward) ---
// CORREÇÃO: Adicionada a declaração da função para resolver o warning de compilação.
void gerar_codigo_mips_ast(ASTNode* raiz, FILE* saida);


// --- Variáveis Globais ---
static int label_count = 0;
static int string_label_count = 0;
static char *current_function_name = NULL;

// --- Funções Auxiliares ---
char* novo_label() {
    char* label = malloc(16);
    if (!label) {
        perror("Falha ao alocar memória para label");
        exit(1);
    }
    sprintf(label, "L%d", label_count++);
    return label;
}

char* novo_label_string() {
    char* label = malloc(16);
     if (!label) {
        perror("Falha ao alocar memória para label de string");
        exit(1);
    }
    sprintf(label, "str%d", string_label_count++);
    return label;
}

// --- Geração de Código ---

void gerar_dados(FILE* saida) {
    fprintf(saida, ".data\n");
    fprintf(saida, "_nl: .asciiz \"\\n\"\n");
}

void gerar_codigo_mips(ASTNode* raiz, FILE* saida) {
    if (!raiz || !saida) return;

    // Cabeçalho
    fprintf(saida, ".text\n");
    fprintf(saida, ".globl main\n\n");

    // Seção de dados
    gerar_dados(saida);

    // Corpo do código
    fprintf(saida, "\n.text\n");
    gerar_codigo_mips_ast(raiz, saida);

    // Finalização do programa
    fprintf(saida, "\n# Fim do programa (syscall 10)\n");
    fprintf(saida, "li $v0, 10\n");
    fprintf(saida, "syscall\n");
}

void gerar_codigo_mips_ast(ASTNode* raiz, FILE* saida) {
    if (!raiz) return;

    switch (raiz->kind) {
        case NODE_PROGRAMA:
            // Processa declarações globais e funções
            for (int i = 0; i < raiz->n_filhos; i++) {
                 if (raiz->filhos[i]) {
                    if (raiz->filhos[i]->kind == NODE_FUNCAO || raiz->filhos[i]->kind == NODE_DECLVAR) {
                        gerar_codigo_mips_ast(raiz->filhos[i], saida);
                    }
                }
            }
            // Encontra o bloco 'programa' (main)
             for (int i = 0; i < raiz->n_filhos; i++) {
                 if (raiz->filhos[i] && raiz->filhos[i]->kind == NODE_BLOCO && raiz->filhos[i]->valor_str && strcmp(raiz->filhos[i]->valor_str, "programa") == 0) {
                    fprintf(saida, "\nmain:\n");
                    fprintf(saida, "move $fp, $sp\n");
                    gerar_codigo_mips_ast(raiz->filhos[i], saida);
                    break; // Assume que só há um bloco 'programa'
                }
            }
            break;

        case NODE_FUNCAO:
            if (raiz->valor_str) {
                current_function_name = strdup(raiz->valor_str);
                fprintf(saida, "\n%s:\n", raiz->valor_str);

                // Prólogo
                fprintf(saida, "sw $ra, -4($sp)\n");
                fprintf(saida, "sw $fp, -8($sp)\n");
                fprintf(saida, "move $fp, $sp\n");
                fprintf(saida, "addiu $sp, $sp, -8\n"); // Aloca espaço base para $ra e $fp

                // Corpo da função
                for (int i = 0; i < raiz->n_filhos; i++) {
                    if(raiz->filhos[i]) gerar_codigo_mips_ast(raiz->filhos[i], saida);
                }

                // Epílogo
                fprintf(saida, "%s_exit:\n", current_function_name);
                fprintf(saida, "move $sp, $fp\n");
                fprintf(saida, "lw $ra, -4($sp)\n");
                fprintf(saida, "lw $fp, -8($sp)\n");
                fprintf(saida, "jr $ra\n");
                free(current_function_name);
                current_function_name = NULL;
            } else {
                for (int i = 0; i < raiz->n_filhos; i++) {
                     if(raiz->filhos[i]) gerar_codigo_mips_ast(raiz->filhos[i], saida);
                }
            }
            break;

        case NODE_DECLVAR:
            // No gerador, a declaração aloca espaço na pilha
            fprintf(saida, "addiu $sp, $sp, -4 # Aloca espaco para var\n");
            // Se houver inicialização, gerar código para a expressão
            if (raiz->n_filhos > 0 && raiz->filhos[0]) {
                 // A gramática parece não suportar inicialização direta (ex: int x = 5;)
                 // Se suportasse, o código viria aqui.
            }
            break;

        case NODE_BLOCO:
            for (int i = 0; i < raiz->n_filhos; i++) {
                if(raiz->filhos[i]) gerar_codigo_mips_ast(raiz->filhos[i], saida);
            }
            break;

        case NODE_CMD:
            if (!raiz->valor_str) break;

            if (strcmp(raiz->valor_str, "escreva") == 0) {
                if (raiz->n_filhos > 0 && raiz->filhos[0]) {
                    gerar_codigo_mips_ast(raiz->filhos[0], saida);
                    fprintf(saida, "move $a0, $t0\n");
                    fprintf(saida, "li $v0, 1\n"); // syscall print_int
                    fprintf(saida, "syscall\n");
                }
            } else if (strcmp(raiz->valor_str, "escreva_str") == 0) {
                 if (raiz->n_filhos > 0 && raiz->filhos[0] && raiz->filhos[0]->valor_str) {
                    char* str_label = novo_label_string();
                    fprintf(saida, ".data\n%s: .asciiz %s\n.text\n", str_label, raiz->filhos[0]->valor_str);
                    fprintf(saida, "la $a0, %s\n", str_label);
                    fprintf(saida, "li $v0, 4\n"); // syscall print_string
                    fprintf(saida, "syscall\n");
                    free(str_label);
                 }
            } else if (strcmp(raiz->valor_str, "novalinha") == 0) {
                fprintf(saida, "la $a0, _nl\n");
                fprintf(saida, "li $v0, 4\n");
                fprintf(saida, "syscall\n");
            } else if (strcmp(raiz->valor_str, "retorne") == 0) {
                if (current_function_name) {
                    if (raiz->n_filhos > 0 && raiz->filhos[0]) {
                        gerar_codigo_mips_ast(raiz->filhos[0], saida);
                        fprintf(saida, "move $v0, $t0\n"); // Valor de retorno
                    }
                    fprintf(saida, "j %s_exit\n", current_function_name);
                }
            } else if (strcmp(raiz->valor_str, "se") == 0) {
                char* else_label = novo_label();
                char* end_label = novo_label();

                if (raiz->n_filhos > 0 && raiz->filhos[0]) {
                    gerar_codigo_mips_ast(raiz->filhos[0], saida);
                }
                fprintf(saida, "beq $t0, $zero, %s\n", raiz->n_filhos == 3 ? else_label : end_label);

                if (raiz->n_filhos > 1 && raiz->filhos[1]) {
                     gerar_codigo_mips_ast(raiz->filhos[1], saida);
                }

                if (raiz->n_filhos == 3) { // Estrutura if-else
                     fprintf(saida, "j %s\n", end_label);
                     fprintf(saida, "%s:\n", else_label);
                     if (raiz->filhos[2]) gerar_codigo_mips_ast(raiz->filhos[2], saida);
                } else { // Estrutura if
                     fprintf(saida, "%s:\n", else_label); // No 'if' simples, o else_label é o fim
                }

                fprintf(saida, "%s:\n", end_label);
                free(else_label);
                free(end_label);
            } else if (strcmp(raiz->valor_str, "enquanto") == 0) {
                char* start_label = novo_label();
                char* end_label = novo_label();

                fprintf(saida, "%s:\n", start_label);
                if (raiz->n_filhos > 0 && raiz->filhos[0]) {
                    gerar_codigo_mips_ast(raiz->filhos[0], saida);
                }
                fprintf(saida, "beq $t0, $zero, %s\n", end_label);
                if (raiz->n_filhos > 1 && raiz->filhos[1]) {
                    gerar_codigo_mips_ast(raiz->filhos[1], saida);
                }
                fprintf(saida, "j %s\n", start_label);
                fprintf(saida, "%s:\n", end_label);

                free(start_label);
                free(end_label);
            } else { // Comandos não reconhecidos, apenas percorre
                 for (int i = 0; i < raiz->n_filhos; i++) {
                    if(raiz->filhos[i]) gerar_codigo_mips_ast(raiz->filhos[i], saida);
                }
            }
            break;

        case NODE_EXPR:
            if (!raiz->valor_str) break;
            if (raiz->n_filhos == 2) { // Operador binário
                if (!raiz->filhos[0] || !raiz->filhos[1]) break; // Segurança

                gerar_codigo_mips_ast(raiz->filhos[0], saida);
                fprintf(saida, "addiu $sp, $sp, -4\nsw $t0, 0($sp)\n");
                gerar_codigo_mips_ast(raiz->filhos[1], saida);
                fprintf(saida, "lw $t1, 0($sp)\naddiu $sp, $sp, 4\n");
                fprintf(saida, "move $t2, $t0\n"); // movendo o resultado de filhos[1] para t2
                fprintf(saida, "move $t0, $t1\n"); // movendo o resultado de filhos[0] para t0
                fprintf(saida, "move $t1, $t2\n"); // movendo o resultado de filhos[1] para t1


                if (strcmp(raiz->valor_str, "+") == 0) fprintf(saida, "add $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "-") == 0) fprintf(saida, "sub $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "*") == 0) fprintf(saida, "mul $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "/") == 0) fprintf(saida, "div $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "<") == 0) fprintf(saida, "slt $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, ">") == 0) fprintf(saida, "sgt $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "==") == 0) fprintf(saida, "seq $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "!=") == 0) fprintf(saida, "sne $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "<=") == 0) fprintf(saida, "sle $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, ">=") == 0) fprintf(saida, "sge $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "e") == 0) fprintf(saida, "and $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "ou") == 0) fprintf(saida, "or $t0, $t0, $t1\n");
                else if (strcmp(raiz->valor_str, "=") == 0) {
                    if (raiz->filhos[0]->valor_str) {
                        EntradaTabela* var = buscar_simbolo(raiz->filhos[0]->valor_str);
                        if(var) {
                            // O valor a ser atribuído está em $t1
                            fprintf(saida, "sw $t1, %d($fp) # Atribuindo valor a %s\n", var->posicao, var->nome);
                            fprintf(saida, "move $t0, $t1\n");
                        }
                    }
                }
            } else if (raiz->n_filhos == 1) { // Operador unário
                 if (!raiz->filhos[0]) break;
                 gerar_codigo_mips_ast(raiz->filhos[0], saida);
                 if (strcmp(raiz->valor_str, "-") == 0) fprintf(saida, "neg $t0, $t0\n");
                 else if (strcmp(raiz->valor_str, "!") == 0) fprintf(saida, "seq $t0, $t0, $zero\n");
            }
            break;

        case NODE_CONST:
            fprintf(saida, "li $t0, %d\n", raiz->valor_int);
            break;

        case NODE_ID:
            if (!raiz->valor_str) break;
            EntradaTabela* var = buscar_simbolo(raiz->valor_str);
            if (var) {
                fprintf(saida, "lw $t0, %d($fp) # Carregando var %s\n", var->posicao, var->nome);
            }
            break;

        default:
            for (int i = 0; i < raiz->n_filhos; i++) {
                if(raiz->filhos[i]) gerar_codigo_mips_ast(raiz->filhos[i], saida);
            }
            break;
    }
}