%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Inclui ast.h no prólogo principal
#include "../includes/ast.h"

// NOVO: Declaração forward para a struct ASTNode DENTRO do bloco %{ %}
struct ASTNode; 

// Declarações globais (extern) para variáveis e funções
extern int yylex();          // Declaração para a função do Flex
extern int yylineno;         // Declaração para a variável de linha do Flex
void yyerror(const char *s); // Declaração para a função de erro do Bison
extern ASTNode* ast_raiz;    // ASTNode deve ser reconhecido aqui
%}

%union {
    int valor_int;
    char* texto;
    struct ASTNode* no; // Usa 'struct ASTNode*' explicitamente
}

%token PROGRAMA TK_INT TK_CAR RETORNE LEIA ESCREVA NOVALINHA SE ENTAO SENAO ENQUANTO EXECUTE
%token <texto> ID
%token <texto> STRINGCONST
%token <texto> CARCONST
%token <texto> INTCONST

%token MAIS MENOS MULT DIV IGUAL DIFERENTE MENOR MAIOR MAIORIGUAL MENORIGUAL ATRIBUICAO
%token OU E
%token ABREPAR FECHAPAR ABRECHAVE FECHACHAVE VIRGULA PONTOVIRGULA

%type <no> Programa DeclFuncVar DeclProg Tipo DeclVar DeclFunc ListaParametros ListaParametrosCont Bloco ListaDeclVar ListaComando Comando Expr OrExpr AndExpr EqExpr DesigExpr AddExpr MulExpr UnExpr PrimExpr ListExpr

%start Programa

%%

Programa: DeclFuncVar DeclProg
    {
        ast_raiz = criar_no(NODE_PROGRAMA, @1.first_line, NULL, 0, TIPO_VOID, 2, $1, $2);
        (yyval.no) = ast_raiz;
    }
;

DeclFuncVar: Tipo ID DeclVar PONTOVIRGULA DeclFuncVar
    {
        ASTNode* atual = criar_no(NODE_DECLVAR, @1.first_line, $2, 0, $1->tipo_dado, 1, $3);
        (yyval.no) = $5 ? criar_no(NODE_LISTA, @1.first_line, NULL, 0, TIPO_UNKNOWN, 2, atual, $5) : atual;
    }
| Tipo ID DeclFunc DeclFuncVar
    {
        ASTNode* atual = criar_no(NODE_FUNCAO, @1.first_line, $2, 0, $1->tipo_dado, 1, $3);
        (yyval.no) = $4 ? criar_no(NODE_LISTA, @1.first_line, NULL, 0, TIPO_UNKNOWN, 2, atual, $4) : atual;
    }
| %empty
    {
        (yyval.no) = NULL;
    }
;

DeclProg: PROGRAMA Bloco
    {
        (yyval.no) = criar_no(NODE_BLOCO, @1.first_line, strdup("programa"), 0, TIPO_VOID, 1, $2);
    }
;

Tipo: TK_INT
    { (yyval.no) = criar_no(NODE_ID, @1.first_line, strdup("int"), 0, TIPO_INT, 0); }
| TK_CAR
    { (yyval.no) = criar_no(NODE_ID, @1.first_line, strdup("car"), 0, TIPO_CAR, 0); }
;

DeclVar: VIRGULA ID DeclVar
    {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, TIPO_UNKNOWN, 0);
        (yyval.no) = criar_no(NODE_LISTA, @1.first_line, NULL, 0, TIPO_UNKNOWN, 2, idNode, $3);
    }
| %empty
    {
        (yyval.no) = NULL;
    }
;

DeclFunc: ABREPAR ListaParametros FECHAPAR Bloco
    {
        (yyval.no) = criar_no(NODE_FUNCAO, @1.first_line, NULL, 0, TIPO_UNKNOWN, 2, $2, $4);
    }
;

ListaParametros: %empty
    { (yyval.no) = NULL; }
| ListaParametrosCont
    { (yyval.no) = $1; }
;

ListaParametrosCont: Tipo ID
    {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, $1->tipo_dado, 0);
        (yyval.no) = criar_no(NODE_LISTA, @1.first_line, strdup("param_list"), 0, TIPO_UNKNOWN, 1, idNode);
    }
| Tipo ID VIRGULA ListaParametrosCont
    {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, $1->tipo_dado, 0);
        (yyval.no) = criar_no(NODE_LISTA, @1.first_line, strdup("param_list"), 0, TIPO_UNKNOWN, 2, idNode, $4);
    }
;

Bloco: ABRECHAVE ListaDeclVar ListaComando FECHACHAVE
    {
        (yyval.no) = criar_no(NODE_BLOCO, @1.first_line, NULL, 0, TIPO_VOID, 2, $2, $3);
    }
;

ListaDeclVar: %empty
    { (yyval.no) = NULL; }
| Tipo ID DeclVar PONTOVIRGULA ListaDeclVar
    {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, $1->tipo_dado, 0);
        ASTNode* decl = criar_no(NODE_DECLVAR, @1.first_line, NULL, 0, $1->tipo_dado, 2, idNode, $3);
        (yyval.no) = criar_no(NODE_LISTA, @1.first_line, NULL, 0, TIPO_UNKNOWN, 2, decl, $5);
    }
;

ListaComando: Comando
    {
        (yyval.no) = criar_no(NODE_LISTA, @1.first_line, NULL, 0, TIPO_UNKNOWN, 1, $1);
    }
| ListaComando Comando
    {
        (yyval.no) = criar_no(NODE_LISTA, @2.first_line, NULL, 0, TIPO_UNKNOWN, 2, $1, $2);
    }
;

Comando: PONTOVIRGULA
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup(";"), 0, TIPO_VOID, 0);
    }
| Expr PONTOVIRGULA
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("expr;"), 0, TIPO_VOID, 1, $1);
    }
| RETORNE Expr PONTOVIRGULA
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("retorne"), 0, TIPO_VOID, 1, $2);
    }
| LEIA ID PONTOVIRGULA
    {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, TIPO_UNKNOWN, 0);
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("leia"), 0, TIPO_VOID, 1, idNode);
    }
| ESCREVA Expr PONTOVIRGULA
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("escreva"), 0, TIPO_VOID, 1, $2);
    }
| ESCREVA STRINGCONST PONTOVIRGULA
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("escreva_str"), 0, TIPO_VOID, 0);
    }
| NOVALINHA PONTOVIRGULA
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("novalinha"), 0, TIPO_VOID, 0);
    }
| SE ABREPAR Expr FECHAPAR ENTAO Comando
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("se"), 0, TIPO_VOID, 2, $3, $6);
    }
| SE ABREPAR Expr FECHAPAR ENTAO Comando SENAO Comando
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("se_senao"), 0, TIPO_VOID, 3, $3, $6, $8);
    }
| ENQUANTO ABREPAR Expr FECHAPAR EXECUTE Comando
    {
        (yyval.no) = criar_no(NODE_CMD, @1.first_line, strdup("enquanto"), 0, TIPO_VOID, 2, $3, $6);
    }
| Bloco
    {
        (yyval.no) = $1;
    }
;

Expr: OrExpr
    { (yyval.no) = $1; }
| ID ATRIBUICAO Expr
    {
        ASTNode* idNode = criar_no(NODE_ID, @1.first_line, $1, 0, TIPO_UNKNOWN, 0);
        (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("="), 0, TIPO_UNKNOWN, 2, idNode, $3);
    }
;

OrExpr: OrExpr OU AndExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("ou"), 0, TIPO_UNKNOWN, 2, $1, $3); }
| AndExpr
    { (yyval.no) = $1; }
;

AndExpr: AndExpr E EqExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("e"), 0, TIPO_UNKNOWN, 2, $1, $3); }
| EqExpr
    { (yyval.no) = $1; }
;

EqExpr: EqExpr IGUAL DesigExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("=="), 0, TIPO_UNKNOWN, 2, $1, $3); }
| EqExpr DIFERENTE DesigExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("!="), 0, TIPO_UNKNOWN, 2, $1, $3); }
| DesigExpr
    { (yyval.no) = $1; }
;

DesigExpr: DesigExpr MENOR AddExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("<"), 0, TIPO_UNKNOWN, 2, $1, $3); }
| DesigExpr MAIOR AddExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup(">"), 0, TIPO_UNKNOWN, 2, $1, $3); }
| DesigExpr MAIORIGUAL AddExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup(">="), 0, TIPO_UNKNOWN, 2, $1, $3); }
| DesigExpr MENORIGUAL AddExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("<="), 0, TIPO_UNKNOWN, 2, $1, $3); }
| AddExpr
    { (yyval.no) = $1; }
;

AddExpr: AddExpr MAIS MulExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("+"), 0, TIPO_UNKNOWN, 2, $1, $3); }
| AddExpr MENOS MulExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("-"), 0, TIPO_UNKNOWN, 2, $1, $3); }
| MulExpr
    { (yyval.no) = $1; }
;

MulExpr: MulExpr MULT UnExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("*"), 0, TIPO_UNKNOWN, 2, $1, $3); }
| MulExpr DIV UnExpr
    { (yyval.no) = criar_no(NODE_EXPR, @2.first_line, strdup("/"), 0, TIPO_UNKNOWN, 2, $1, $3); }
| UnExpr
    { (yyval.no) = $1; }
;

UnExpr: MENOS PrimExpr
    { (yyval.no) = criar_no(NODE_EXPR, @1.first_line, strdup("-"), 0, TIPO_UNKNOWN, 1, $2); }
| '!' PrimExpr
    { (yyval.no) = criar_no(NODE_EXPR, @1.first_line, strdup("!"), 0, TIPO_UNKNOWN, 1, $2); }
| PrimExpr
    { (yyval.no) = $1; }
;

PrimExpr: ID ABREPAR ListExpr FECHAPAR
    {
        ASTNode* idNode = criar_no(NODE_ID, @1.first_line, $1, 0, TIPO_UNKNOWN, 0);
        (yyval.no) = criar_no(NODE_EXPR, @1.first_line, strdup("call"), 0, TIPO_UNKNOWN, 2, idNode, $3);
    }
| ID ABREPAR FECHAPAR
    {
        ASTNode* idNode = criar_no(NODE_ID, @1.first_line, $1, 0, TIPO_UNKNOWN, 0);
        (yyval.no) = criar_no(NODE_EXPR, @1.first_line, strdup("call"), 0, TIPO_UNKNOWN, 1, idNode);
    }
| ID
    {
        (yyval.no) = criar_no(NODE_ID, @1.first_line, $1, 0, TIPO_UNKNOWN, 0);
    }
| CARCONST
    {
        (yyval.no) = criar_no(NODE_CONST, @1.first_line, NULL, $1[0], TIPO_CAR, 0);
    }
| INTCONST
    {
        (yyval.no) = criar_no(NODE_CONST, @1.first_line, NULL, atoi($1), TIPO_INT, 0);
    }
| ABREPAR Expr FECHAPAR
    {
        (yyval.no) = $2;
    }
;

ListExpr: Expr
    {
        (yyval.no) = criar_no(NODE_LISTA, @1.first_line, strdup("arg_list"), 0, TIPO_UNKNOWN, 1, $1);
    }
| ListExpr VIRGULA Expr
    {
        (yyval.no) = criar_no(NODE_LISTA, @2.first_line, strdup("arg_list"), 0, TIPO_UNKNOWN, 2, $1, $3);
    }
;

%%

void yyerror(const char *s) {
    printf("ERRO: %s linha %d\n", s, yylineno);
}