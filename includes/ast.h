#ifndef AST_H
#define AST_H

// Tipos de dados para o sistema de tipos
typedef enum {
    TIPO_INT,
    TIPO_CAR,
    TIPO_VOID,     // Para funções sem retorno
    TIPO_UNKNOWN,  // Tipo desconhecido (ex: erro, não inferido)
    TIPO_INVALID   // Tipo inválido (indicador de erro de tipo)
} TipoDado;

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
    TipoDado tipo_dado; // NOVO: Tipo do dado associado a este nó
    struct ASTNode** filhos;
    int n_filhos;
} ASTNode;

// NOVO: Adicionado tipo_dado ao criar_no
ASTNode* criar_no(NodeKind tipo, int linha, char* valor_str, int valor_int, TipoDado tipo_dado, int n_filhos, ...);
void imprimir_ast(ASTNode* raiz, int nivel);
void liberar_ast(ASTNode* raiz);

#endif