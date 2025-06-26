#ifndef AST_H
#define AST_H

typedef enum {
    NODE_PROGRAMA, NODE_FUNCAO, NODE_DECLVAR, NODE_BLOCO,
    NODE_CMD, NODE_EXPR, NODE_ID, NODE_CONST,
    NODE_LISTA 
} NodeKind;

typedef struct ASTNode {
    NodeKind kind;
    char* valor_str;     
    int valor_int;       
    int linha;
    struct ASTNode** filhos;
    int n_filhos;
} ASTNode;

ASTNode* criar_no(NodeKind tipo, int linha, char* valor_str, int valor_int, int n_filhos, ...);
void imprimir_ast(ASTNode* raiz, int nivel);
void liberar_ast(ASTNode* raiz);

#endif
