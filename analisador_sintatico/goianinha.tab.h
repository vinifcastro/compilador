/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ANALISADOR_SINTATICO_GOIANINHA_TAB_H_INCLUDED
# define YY_YY_ANALISADOR_SINTATICO_GOIANINHA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAMA = 258,                /* PROGRAMA  */
    TK_INT = 259,                  /* TK_INT  */
    TK_CAR = 260,                  /* TK_CAR  */
    RETORNE = 261,                 /* RETORNE  */
    LEIA = 262,                    /* LEIA  */
    ESCREVA = 263,                 /* ESCREVA  */
    NOVALINHA = 264,               /* NOVALINHA  */
    SE = 265,                      /* SE  */
    ENTAO = 266,                   /* ENTAO  */
    SENAO = 267,                   /* SENAO  */
    ENQUANTO = 268,                /* ENQUANTO  */
    EXECUTE = 269,                 /* EXECUTE  */
    ID = 270,                      /* ID  */
    STRINGCONST = 271,             /* STRINGCONST  */
    CARCONST = 272,                /* CARCONST  */
    INTCONST = 273,                /* INTCONST  */
    MAIS = 274,                    /* MAIS  */
    MENOS = 275,                   /* MENOS  */
    MULT = 276,                    /* MULT  */
    DIV = 277,                     /* DIV  */
    IGUAL = 278,                   /* IGUAL  */
    DIFERENTE = 279,               /* DIFERENTE  */
    MENOR = 280,                   /* MENOR  */
    MAIOR = 281,                   /* MAIOR  */
    MAIORIGUAL = 282,              /* MAIORIGUAL  */
    MENORIGUAL = 283,              /* MENORIGUAL  */
    ATRIBUICAO = 284,              /* ATRIBUICAO  */
    OU = 285,                      /* OU  */
    E = 286,                       /* E  */
    ABREPAR = 287,                 /* ABREPAR  */
    FECHAPAR = 288,                /* FECHAPAR  */
    ABRECHAVE = 289,               /* ABRECHAVE  */
    FECHACHAVE = 290,              /* FECHACHAVE  */
    VIRGULA = 291,                 /* VIRGULA  */
    PONTOVIRGULA = 292             /* PONTOVIRGULA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "analisador_sintatico/goianinha.y"

    int valor_int;
    char* texto;
    struct ASTNode* no;

#line 107 "analisador_sintatico/goianinha.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_ANALISADOR_SINTATICO_GOIANINHA_TAB_H_INCLUDED  */
