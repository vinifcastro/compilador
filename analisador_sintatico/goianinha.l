%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "goianinha.tab.h"

extern int yylineno;
int start_line = 0;
char string_buf[1024];
%}

%x COMMENT
%x STRING

%%

"programa"          { return PROGRAMA; }
"int"               { return TK_INT; }
"car"               { return TK_CAR; }
"retorne"           { return RETORNE; }
"leia"              { return LEIA; }
"escreva"           { return ESCREVA; }
"novalinha"         { return NOVALINHA; }
"se"                { return SE; }
"entao"             { return ENTAO; }
"senao"             { return SENAO; }
"enquanto"          { return ENQUANTO; }
"execute"           { return EXECUTE; }
"ou"                { return OU; }
"e"                 { return E; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.texto = strdup(yytext); return ID; }
[0-9]+              { yylval.texto = strdup(yytext); return INTCONST; }
'[^']'              { yylval.texto = strdup(yytext); return CARCONST; }

"=="                { return IGUAL; }
"!="                { return DIFERENTE; }
"<="                { return MENORIGUAL; }
">="                { return MAIORIGUAL; }
"="                 { return ATRIBUICAO; }
"<"                 { return MENOR; }
">"                 { return MAIOR; }
";"                 { return PONTOVIRGULA; }
","                 { return VIRGULA; }
"("                 { return ABREPAR; }
")"                 { return FECHAPAR; }
"{"                 { return ABRECHAVE; }
"}"                 { return FECHACHAVE; }
"+"                 { return MAIS; }
"-"                 { return MENOS; }
"*"                 { return MULT; }
"/"                 { return DIV; }
"!"                 { return '!'; }

[ \t\r]+            { }
\n                  { yylineno++; }

"/*"                { BEGIN(COMMENT); start_line = yylineno; }

<COMMENT>"*/"       { BEGIN(INITIAL); }
<COMMENT>\n         { yylineno++; }
<COMMENT>.          { }
<COMMENT><<EOF>>    { 
                        printf("ERRO: COMENTARIO NAO TERMINA (iniciado na linha %d)\n", start_line); 
                        exit(1); 
                    }

"\"" {
    BEGIN(STRING);
    start_line = yylineno;
    string_buf[0] = '\0';
}

<STRING>[^\"\n\\]+  { strcat(string_buf, yytext); }
<STRING>\\n         { strcat(string_buf, "\n"); }
<STRING>\\t         { strcat(string_buf, "\t"); }
<STRING>\\\"        { strcat(string_buf, "\""); }

<STRING>"\"" {
    BEGIN(INITIAL);
    yylval.texto = strdup(string_buf);
    return STRINGCONST;
}

<STRING>\n {
    printf("ERRO: CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA (iniciada na linha %d)\n", start_line);
    exit(1);
}
<STRING><<EOF>> {
    printf("ERRO: STRING NAO TERMINADA (iniciada na linha %d)\n", start_line);
    exit(1);
}

.                   { 
                        printf("ERRO: CARACTERE INVALIDO '%s' na linha %d\n", yytext, yylineno); 
                        exit(1);
                    }

%%

int yywrap(void) {
    return 1;
}
