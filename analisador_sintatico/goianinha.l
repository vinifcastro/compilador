%option noyywrap
%x COMMENT

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "goianinha.tab.h"
extern int yylineno;
%}


%%

programa        { yylval.texto = strdup(yytext); return PROGRAMA; }
int             { yylval.texto = strdup(yytext); return TK_INT; }
car             { yylval.texto = strdup(yytext); return TK_CAR; }
retorne         { yylval.texto = strdup(yytext); return RETORNE; }
leia            { yylval.texto = strdup(yytext); return LEIA; }
escreva         { yylval.texto = strdup(yytext); return ESCREVA; }
novalinha       { yylval.texto = strdup(yytext); return NOVALINHA; }
se              { yylval.texto = strdup(yytext); return SE; }
entao           { yylval.texto = strdup(yytext); return ENTAO; }
senao           { yylval.texto = strdup(yytext); return SENAO; }
enquanto        { yylval.texto = strdup(yytext); return ENQUANTO; }
execute         { yylval.texto = strdup(yytext); return EXECUTE; }

[ \t\r]+        { }
\n              { yylineno++; }

"/*"            { BEGIN(COMMENT); }
<COMMENT>{
    [^*\n]*     ;
    \*+[^*/]*   ;
    \n          { yylineno++; }
    "*/"        { BEGIN(INITIAL); }
    <<EOF>>     { printf("ERRO: COMENTARIO NAO TERMINA %d\n", yylineno); exit(1); }
}

\"([^\"\\\n]|\\.)*\"      { yylval.texto = strdup(yytext); return STRINGCONST; }
\"([^\"\\\n]|\\.)*\n      { printf("ERRO: STRING NAO TERMINADA na linha %d\n", yylineno); exit(1); }
\"([^\"\\\n]|\\.)*        { printf("ERRO: STRING NAO TERMINADA na linha %d\n", yylineno); exit(1); }

[0-9]+                   { yylval.texto = strdup(yytext); return INTCONST; }

'[^\'\n]'                { yylval.texto = strdup(yytext); return CARCONST; }

[a-zA-Z_][a-zA-Z0-9_]*   { yylval.texto = strdup(yytext); return ID; }

"=="                     { yylval.texto = strdup(yytext); return IGUAL; }
"!="                     { yylval.texto = strdup(yytext); return DIFERENTE; }
"<="                     { yylval.texto = strdup(yytext); return MENORIGUAL; }
">="                     { yylval.texto = strdup(yytext); return MAIORIGUAL; }

";"                      { yylval.texto = strdup(yytext); return PONTOVIRGULA; }
","                      { yylval.texto = strdup(yytext); return VIRGULA; }
"("                      { yylval.texto = strdup(yytext); return ABREPAR; }
")"                      { yylval.texto = strdup(yytext); return FECHAPAR; }
"{"                      { yylval.texto = strdup(yytext); return ABRECHAVE; }
"}"                      { yylval.texto = strdup(yytext); return FECHACHAVE; }
"="                      { yylval.texto = strdup(yytext); return ATRIBUICAO; }
"+"                      { yylval.texto = strdup(yytext); return MAIS; }
"-"                      { yylval.texto = strdup(yytext); return MENOS; }
"*"                      { yylval.texto = strdup(yytext); return MULT; }
"/"                      { yylval.texto = strdup(yytext); return DIV; }
"<"                      { yylval.texto = strdup(yytext); return MENOR; }
">"                      { yylval.texto = strdup(yytext); return MAIOR; }
"!"                      { yylval.texto = strdup(yytext); return '!'; }

.                        {
    printf("ERRO: CARACTERE INVALIDO '%s' na linha %d\n", yytext, yylineno);
    exit(1);
}

%%
