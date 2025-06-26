#include <stdio.h>
#include <string.h>
#include "../includes/ast.h"

void gerar_codigo_mips(ASTNode* raiz, FILE* saida);

static int label_string = 0;

void gerar_codigo_mips(ASTNode* raiz, FILE* saida) {
    if (!raiz || !saida) return;

    switch (raiz->kind) {
        case NODE_CONST:
            fprintf(saida, "# constante: %d\n", raiz->valor_int);
            fprintf(saida, "li $t0, %d\n", raiz->valor_int);
            break;

        case NODE_ID:
            fprintf(saida, "# variável: %s\n", raiz->valor_str);
            break;

        case NODE_EXPR:
            if (raiz->n_filhos == 2 && strcmp(raiz->valor_str, "+") == 0) {
                gerar_codigo_mips(raiz->filhos[0], saida);
                fprintf(saida, "move $t1, $t0\n");
                gerar_codigo_mips(raiz->filhos[1], saida);
                fprintf(saida, "add $t0, $t1, $t0\n");
            } else if (raiz->n_filhos == 2 && strcmp(raiz->valor_str, "-") == 0) {
                gerar_codigo_mips(raiz->filhos[0], saida);
                fprintf(saida, "move $t1, $t0\n");
                gerar_codigo_mips(raiz->filhos[1], saida);
                fprintf(saida, "sub $t0, $t1, $t0\n");
            } else if (raiz->n_filhos == 2 && strcmp(raiz->valor_str, "*") == 0) {
                gerar_codigo_mips(raiz->filhos[0], saida);
                fprintf(saida, "move $t1, $t0\n");
                gerar_codigo_mips(raiz->filhos[1], saida);
                fprintf(saida, "mul $t0, $t1, $t0\n");
            } else if (raiz->n_filhos == 2 && strcmp(raiz->valor_str, "/") == 0) {
                gerar_codigo_mips(raiz->filhos[0], saida);
                fprintf(saida, "move $t1, $t0\n");
                gerar_codigo_mips(raiz->filhos[1], saida);
                fprintf(saida, "div $t0, $t1, $t0\n");
            } else if (strcmp(raiz->valor_str, "=") == 0) {
                gerar_codigo_mips(raiz->filhos[1], saida);
                fprintf(saida, "# atribuição para %s\n", raiz->filhos[0]->valor_str);
                fprintf(saida, "# sw $t0, 0($s0)  # salva $t0 na variável\n");
            }
            break;

        case NODE_CMD:
            if (raiz->valor_str && strcmp(raiz->valor_str, "escreva") == 0) {
                gerar_codigo_mips(raiz->filhos[0], saida); 
                fprintf(saida, "move $a0, $t0\n");
                fprintf(saida, "li $v0, 1\n");
                fprintf(saida, "syscall\n");
            }
            else if (raiz->valor_str && strcmp(raiz->valor_str, "escreva_str") == 0) {
                ASTNode* stringNode = raiz->n_filhos > 0 ? raiz->filhos[0] : NULL;
                if (stringNode && stringNode->valor_str) {
                    char label[32];
                    sprintf(label, "msg%d", label_string++);
                    fprintf(saida, ".data\n%s: .asciiz \"%s\"\n.text\n", label, stringNode->valor_str);
                    fprintf(saida, "li $v0, 4\n");
                    fprintf(saida, "la $a0, %s\n", label);
                    fprintf(saida, "syscall\n");
                }
            }
            break;

        case NODE_PROGRAMA:
        case NODE_FUNCAO:
        case NODE_DECLVAR:
        case NODE_BLOCO:
        case NODE_LISTA:
            break; 

        default:
            break;
    }

    for (int i = 0; i < raiz->n_filhos; i++) {
        gerar_codigo_mips(raiz->filhos[i], saida);
    }
}
