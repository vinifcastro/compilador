%code requires {
    #include "../includes/ast.h"
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/ast.h"

extern int yylex();
extern int yylineno;
void yyerror(const char *s);

ASTNode* ast_raiz;
%}

%union {
    int valor_int;
    char* texto;
    ASTNode* no;
}

%token <texto> PROGRAMA TK_INT TK_CAR RETORNE LEIA ESCREVA NOVALINHA
%token <texto> SE ENTAO SENAO ENQUANTO EXECUTE
%token <texto> ID INTCONST CARCONST STRINGCONST
%token <texto> MAIS MENOS MULT DIV
%token <texto> IGUAL DIFERENTE MENOR MAIOR MAIORIGUAL MENORIGUAL
%token <texto> ATRIBUICAO OU E
%token <texto> ABREPAR FECHAPAR ABRECHAVE FECHACHAVE
%token <texto> VIRGULA PONTOVIRGULA

%type <no> Programa DeclFuncVar DeclProg DeclVar DeclFunc ListaParametros ListaParametrosCont
%type <no> Bloco ListaDeclVar ListaComando Comando Expr OrExpr AndExpr EqExpr DesigExpr
%type <no> AddExpr MulExpr UnExpr PrimExpr ListExpr Tipo

%%

Programa:
    DeclFuncVar DeclProg {
        ast_raiz = criar_no(NODE_PROGRAMA, @1.first_line, NULL, 0, 2, $1, $2);
        $$ = ast_raiz;
    };

DeclFuncVar:
    Tipo ID DeclVar PONTOVIRGULA DeclFuncVar {
        ASTNode* atual = criar_no(NODE_DECLVAR, @1.first_line, $2, 0, 1, $3);
        $$ = $5 ? criar_no(NODE_LISTA, @1.first_line, NULL, 0, 2, atual, $5) : atual;
    }
  | Tipo ID DeclFunc DeclFuncVar {
        ASTNode* atual = criar_no(NODE_FUNCAO, @1.first_line, $2, 0, 1, $3);
        $$ = $4 ? criar_no(NODE_LISTA, @1.first_line, NULL, 0, 2, atual, $4) : atual;
    }
  | /* vazio */ {
        $$ = NULL;
    };

DeclProg:
    PROGRAMA Bloco {
        $$ = criar_no(NODE_BLOCO, @1.first_line, strdup("programa"), 0, 1, $2);
    };

Tipo:
    TK_INT { $$ = criar_no(NODE_ID, @1.first_line, strdup("int"), 0, 0); }
  | TK_CAR { $$ = criar_no(NODE_ID, @1.first_line, strdup("car"), 0, 0); };

DeclVar:
    VIRGULA ID DeclVar {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, 0);
        $$ = criar_no(NODE_LISTA, @1.first_line, NULL, 0, 2, idNode, $3);
    }
  | /* vazio */ {
        $$ = NULL;
    };

DeclFunc:
    ABREPAR ListaParametros FECHAPAR Bloco {
        $$ = criar_no(NODE_FUNCAO, @1.first_line, NULL, 0, 2, $2, $4);
    };

ListaParametros:
    /* vazio */ { $$ = NULL; }
  | ListaParametrosCont { $$ = $1; };

ListaParametrosCont:
    Tipo ID {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, 0);
        $$ = criar_no(NODE_LISTA, @1.first_line, NULL, 0, 1, idNode);
    }
  | Tipo ID VIRGULA ListaParametrosCont {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, 0);
        $$ = criar_no(NODE_LISTA, @1.first_line, NULL, 0, 2, idNode, $4);
    };

Bloco:
    ABRECHAVE ListaDeclVar ListaComando FECHACHAVE {
        $$ = criar_no(NODE_BLOCO, @1.first_line, NULL, 0, 2, $2, $3);
    };

ListaDeclVar:
    /* vazio */ { $$ = NULL; }
  | Tipo ID DeclVar PONTOVIRGULA ListaDeclVar {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, 0);
        ASTNode* decl = criar_no(NODE_DECLVAR, @1.first_line, NULL, 0, 2, idNode, $3);
        $$ = criar_no(NODE_LISTA, @1.first_line, NULL, 0, 2, decl, $5);
    };

ListaComando:
    Comando {
        $$ = criar_no(NODE_LISTA, @1.first_line, NULL, 0, 1, $1);
    }
  | ListaComando Comando {
        $$ = criar_no(NODE_LISTA, @2.first_line, NULL, 0, 2, $1, $2);
    };

Comando:
    PONTOVIRGULA {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup(";"), 0, 0);
    }
  | Expr PONTOVIRGULA {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("expr;"), 0, 1, $1);
    }
  | RETORNE Expr PONTOVIRGULA {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("retorne"), 0, 1, $2);
    }
  | LEIA ID PONTOVIRGULA {
        ASTNode* idNode = criar_no(NODE_ID, @2.first_line, $2, 0, 0);
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("leia"), 0, 1, idNode);
    }
  | ESCREVA Expr PONTOVIRGULA {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("escreva"), 0, 1, $2);
    }
  | ESCREVA STRINGCONST PONTOVIRGULA {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("escreva_str"), 0, 0);
    }
  | NOVALINHA PONTOVIRGULA {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("novalinha"), 0, 0);
    }
  | SE ABREPAR Expr FECHAPAR ENTAO Comando {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("se"), 0, 2, $3, $6);
    }
  | SE ABREPAR Expr FECHAPAR ENTAO Comando SENAO Comando {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("se_senao"), 0, 3, $3, $6, $8);
    }
  | ENQUANTO ABREPAR Expr FECHAPAR EXECUTE Comando {
        $$ = criar_no(NODE_CMD, @1.first_line, strdup("enquanto"), 0, 2, $3, $6);
    }
  | Bloco {
        $$ = $1;
    };

Expr:
    OrExpr { $$ = $1; }
  | ID ATRIBUICAO Expr {
        ASTNode* idNode = criar_no(NODE_ID, @1.first_line, $1, 0, 0);
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("="), 0, 2, idNode, $3);
    };

OrExpr:
    OrExpr OU AndExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("ou"), 0, 2, $1, $3);
    }
  | AndExpr { $$ = $1; };

AndExpr:
    AndExpr E EqExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("e"), 0, 2, $1, $3);
    }
  | EqExpr { $$ = $1; };

EqExpr:
    EqExpr IGUAL DesigExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("=="), 0, 2, $1, $3);
    }
  | EqExpr DIFERENTE DesigExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("!="), 0, 2, $1, $3);
    }
  | DesigExpr { $$ = $1; };

DesigExpr:
    DesigExpr MENOR AddExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("<"), 0, 2, $1, $3);
    }
  | DesigExpr MAIOR AddExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup(">"), 0, 2, $1, $3);
    }
  | DesigExpr MAIORIGUAL AddExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup(">="), 0, 2, $1, $3);
    }
  | DesigExpr MENORIGUAL AddExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("<="), 0, 2, $1, $3);
    }
  | AddExpr { $$ = $1; };

AddExpr:
    AddExpr MAIS MulExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("+"), 0, 2, $1, $3);
    }
  | AddExpr MENOS MulExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("-"), 0, 2, $1, $3);
    }
  | MulExpr { $$ = $1; };

MulExpr:
    MulExpr MULT UnExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("*"), 0, 2, $1, $3);
    }
  | MulExpr DIV UnExpr {
        $$ = criar_no(NODE_EXPR, @2.first_line, strdup("/"), 0, 2, $1, $3);
    }
  | UnExpr { $$ = $1; };

UnExpr:
    MENOS PrimExpr {
        $$ = criar_no(NODE_EXPR, @1.first_line, strdup("-"), 0, 1, $2);
    }
  | '!' PrimExpr {
        $$ = criar_no(NODE_EXPR, @1.first_line, strdup("!"), 0, 1, $2);
    }
  | PrimExpr { $$ = $1; };

PrimExpr:
    ID ABREPAR ListExpr FECHAPAR {
        ASTNode* idNode = criar_no(NODE_ID, @1.first_line, $1, 0, 0);
        $$ = criar_no(NODE_EXPR, @1.first_line, strdup("call"), 0, 2, idNode, $3);
    }
  | ID ABREPAR FECHAPAR {
        ASTNode* idNode = criar_no(NODE_ID, @1.first_line, $1, 0, 0);
        $$ = criar_no(NODE_EXPR, @1.first_line, strdup("call"), 0, 1, idNode);
    }
  | ID {
        $$ = criar_no(NODE_ID, @1.first_line, $1, 0, 0);
    }
  | CARCONST {
        $$ = criar_no(NODE_CONST, @1.first_line, NULL, $1[0], 0);
    }
  | INTCONST {
        $$ = criar_no(NODE_CONST, @1.first_line, NULL, atoi($1), 0);
    }
  | ABREPAR Expr FECHAPAR {
        $$ = $2;
    };

ListExpr:
    Expr {
        $$ = criar_no(NODE_LISTA, @1.first_line, strdup("arg"), 0, 1, $1);
    }
  | ListExpr VIRGULA Expr {
        $$ = criar_no(NODE_LISTA, @2.first_line, strdup("arg"), 0, 2, $1, $3);
    };

%%

void yyerror(const char *s) {
    printf("ERRO: %s linha %d\n", s, yylineno);
}

