#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../includes/ast.h"

ASTNode* criar_no(NodeKind tipo, int linha, char* valor_str, int valor_int, TipoDado tipo_dado, int n_filhos, ...) {
    ASTNode* no = malloc(sizeof(ASTNode));
    if (!no) {
        perror("Erro ao alocar ASTNode");
        exit(1);
    }
    no->kind = tipo;
    no->linha = linha;
    no->valor_str = valor_str ? strdup(valor_str) : NULL;
    no->valor_int = valor_int;
    no->tipo_dado = tipo_dado;
    no->n_filhos = n_filhos;
    no->filhos = n_filhos ? malloc(sizeof(ASTNode*) * n_filhos) : NULL;
    if (n_filhos > 0 && !no->filhos) {
        perror("Erro ao alocar filhos de ASTNode");
        exit(1);
    }

    va_list args;
    va_start(args, n_filhos);
    for (int i = 0; i < n_filhos; i++) {
        no->filhos[i] = va_arg(args, ASTNode*);
    }
    va_end(args);
    return no;
}

void imprimir_ast(ASTNode* raiz, int nivel) {
    if (!raiz) return;
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("- [%d] ", raiz->linha);
    switch (raiz->kind) {
        case NODE_PROGRAMA: printf("PROGRAMA\n"); break;
        case NODE_FUNCAO:   printf("FUNCAO (%s, tipo_retorno=%d)\n", raiz->valor_str ? raiz->valor_str : "", raiz->tipo_dado); break;
        case NODE_DECLVAR:  printf("DECLVAR (%s, tipo=%d)\n", raiz->valor_str ? raiz->valor_str : "", raiz->tipo_dado); break;
        case NODE_BLOCO:    printf("BLOCO\n"); break;
        case NODE_CMD:      printf("COMANDO (%s)\n", raiz->valor_str ? raiz->valor_str : ""); break;
        case NODE_EXPR:     printf("EXPR (%s, tipo=%d)\n", raiz->valor_str ? raiz->valor_str : "", raiz->tipo_dado); break;
        case NODE_ID:       printf("ID (%s, tipo=%d)\n", raiz->valor_str ? raiz->valor_str : "", raiz->tipo_dado); break;
        case NODE_CONST:    printf("CONST (%d, tipo=%d)\n", raiz->valor_int, raiz->tipo_dado); break;
        case NODE_LISTA:    printf("LISTA\n"); break;
        default:            printf("NODE desconhecido (tipo=%d)\n", raiz->kind);
    }

    for (int i = 0; i < raiz->n_filhos; i++) {
        imprimir_ast(raiz->filhos[i], nivel + 1);
    }
}

void liberar_ast(ASTNode* raiz) {
    if (!raiz) return;
    for (int i = 0; i < raiz->n_filhos; i++) {
        liberar_ast(raiz->filhos[i]);
    }
    if (raiz->filhos) free(raiz->filhos);
    if (raiz->valor_str) free(raiz->valor_str);
    free(raiz);
}
