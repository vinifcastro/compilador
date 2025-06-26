/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "analisador_sintatico/goianinha.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/ast.h"

extern int yylex();
extern int yylineno;
void yyerror(const char *s);

ASTNode* ast_raiz;

#line 84 "analisador_sintatico/goianinha.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "goianinha.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAMA = 3,                   /* PROGRAMA  */
  YYSYMBOL_TK_INT = 4,                     /* TK_INT  */
  YYSYMBOL_TK_CAR = 5,                     /* TK_CAR  */
  YYSYMBOL_RETORNE = 6,                    /* RETORNE  */
  YYSYMBOL_LEIA = 7,                       /* LEIA  */
  YYSYMBOL_ESCREVA = 8,                    /* ESCREVA  */
  YYSYMBOL_NOVALINHA = 9,                  /* NOVALINHA  */
  YYSYMBOL_SE = 10,                        /* SE  */
  YYSYMBOL_ENTAO = 11,                     /* ENTAO  */
  YYSYMBOL_SENAO = 12,                     /* SENAO  */
  YYSYMBOL_ENQUANTO = 13,                  /* ENQUANTO  */
  YYSYMBOL_EXECUTE = 14,                   /* EXECUTE  */
  YYSYMBOL_ID = 15,                        /* ID  */
  YYSYMBOL_INTCONST = 16,                  /* INTCONST  */
  YYSYMBOL_CARCONST = 17,                  /* CARCONST  */
  YYSYMBOL_STRINGCONST = 18,               /* STRINGCONST  */
  YYSYMBOL_MAIS = 19,                      /* MAIS  */
  YYSYMBOL_MENOS = 20,                     /* MENOS  */
  YYSYMBOL_MULT = 21,                      /* MULT  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_IGUAL = 23,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 24,                 /* DIFERENTE  */
  YYSYMBOL_MENOR = 25,                     /* MENOR  */
  YYSYMBOL_MAIOR = 26,                     /* MAIOR  */
  YYSYMBOL_MAIORIGUAL = 27,                /* MAIORIGUAL  */
  YYSYMBOL_MENORIGUAL = 28,                /* MENORIGUAL  */
  YYSYMBOL_ATRIBUICAO = 29,                /* ATRIBUICAO  */
  YYSYMBOL_OU = 30,                        /* OU  */
  YYSYMBOL_E = 31,                         /* E  */
  YYSYMBOL_ABREPAR = 32,                   /* ABREPAR  */
  YYSYMBOL_FECHAPAR = 33,                  /* FECHAPAR  */
  YYSYMBOL_ABRECHAVE = 34,                 /* ABRECHAVE  */
  YYSYMBOL_FECHACHAVE = 35,                /* FECHACHAVE  */
  YYSYMBOL_VIRGULA = 36,                   /* VIRGULA  */
  YYSYMBOL_PONTOVIRGULA = 37,              /* PONTOVIRGULA  */
  YYSYMBOL_38_ = 38,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_Programa = 40,                  /* Programa  */
  YYSYMBOL_DeclFuncVar = 41,               /* DeclFuncVar  */
  YYSYMBOL_DeclProg = 42,                  /* DeclProg  */
  YYSYMBOL_Tipo = 43,                      /* Tipo  */
  YYSYMBOL_DeclVar = 44,                   /* DeclVar  */
  YYSYMBOL_DeclFunc = 45,                  /* DeclFunc  */
  YYSYMBOL_ListaParametros = 46,           /* ListaParametros  */
  YYSYMBOL_ListaParametrosCont = 47,       /* ListaParametrosCont  */
  YYSYMBOL_Bloco = 48,                     /* Bloco  */
  YYSYMBOL_ListaDeclVar = 49,              /* ListaDeclVar  */
  YYSYMBOL_ListaComando = 50,              /* ListaComando  */
  YYSYMBOL_Comando = 51,                   /* Comando  */
  YYSYMBOL_Expr = 52,                      /* Expr  */
  YYSYMBOL_OrExpr = 53,                    /* OrExpr  */
  YYSYMBOL_AndExpr = 54,                   /* AndExpr  */
  YYSYMBOL_EqExpr = 55,                    /* EqExpr  */
  YYSYMBOL_DesigExpr = 56,                 /* DesigExpr  */
  YYSYMBOL_AddExpr = 57,                   /* AddExpr  */
  YYSYMBOL_MulExpr = 58,                   /* MulExpr  */
  YYSYMBOL_UnExpr = 59,                    /* UnExpr  */
  YYSYMBOL_PrimExpr = 60,                  /* PrimExpr  */
  YYSYMBOL_ListExpr = 61                   /* ListExpr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    46,    50,    54,    59,    64,    65,    68,
      72,    77,    82,    83,    86,    90,    96,   101,   102,   109,
     112,   117,   120,   123,   126,   130,   133,   136,   139,   142,
     145,   148,   153,   154,   160,   163,   166,   169,   172,   175,
     178,   181,   184,   187,   190,   193,   196,   199,   202,   205,
     208,   211,   214,   217,   220,   223,   227,   231,   234,   237,
     240,   245,   248
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAMA", "TK_INT",
  "TK_CAR", "RETORNE", "LEIA", "ESCREVA", "NOVALINHA", "SE", "ENTAO",
  "SENAO", "ENQUANTO", "EXECUTE", "ID", "INTCONST", "CARCONST",
  "STRINGCONST", "MAIS", "MENOS", "MULT", "DIV", "IGUAL", "DIFERENTE",
  "MENOR", "MAIOR", "MAIORIGUAL", "MENORIGUAL", "ATRIBUICAO", "OU", "E",
  "ABREPAR", "FECHAPAR", "ABRECHAVE", "FECHACHAVE", "VIRGULA",
  "PONTOVIRGULA", "'!'", "$accept", "Programa", "DeclFuncVar", "DeclProg",
  "Tipo", "DeclVar", "DeclFunc", "ListaParametros", "ListaParametrosCont",
  "Bloco", "ListaDeclVar", "ListaComando", "Comando", "Expr", "OrExpr",
  "AndExpr", "EqExpr", "DesigExpr", "AddExpr", "MulExpr", "UnExpr",
  "PrimExpr", "ListExpr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,   -39,   -39,     9,     8,     4,   -39,    -1,   -39,   -29,
      60,   -39,    60,    11,    12,    60,    36,    53,    38,    43,
     -39,    44,    60,   -39,    44,    84,    52,    14,    35,    54,
      56,   -11,   -39,   -39,    39,    84,   -39,    39,   -39,     7,
     -39,    61,    75,    83,    34,    92,    55,    62,   -39,   -39,
      85,    -1,   -39,   -39,    93,    94,    95,    96,    97,   -39,
      84,    84,    84,    77,   103,   -39,   104,   -39,   -39,   -39,
     -39,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    60,   -39,    60,   -39,   -39,   -39,   -39,
     105,   106,   -39,   -39,   -39,    -8,   -39,    83,    34,    92,
      92,    55,    55,    55,    55,    62,    62,   -39,   -39,   -39,
     -39,   117,   122,   -39,    84,    53,    53,   -39,   128,   -39,
      53,   -39
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     7,     8,     0,     0,     0,     1,     0,     2,    10,
      17,     6,    12,     0,     0,     5,     0,     0,     0,     0,
      13,    10,     5,     4,    10,     0,     0,     0,     0,     0,
       0,    57,    59,    58,     0,     0,    21,     0,    31,     0,
      19,     0,    32,    35,    37,    40,    45,    48,    51,    54,
      14,     0,     9,     3,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,    57,    52,     0,    53,    16,    20,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    17,    23,    24,    26,    25,
       0,     0,    33,    56,    61,     0,    60,    34,    36,    38,
      39,    41,    42,    43,    44,    46,    47,    49,    50,    15,
      18,     0,     0,    55,     0,     0,     0,    62,    28,    30,
       0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -10,   -39,    -4,    19,   -39,   -39,    58,    -3,
      57,   -39,   -38,   -25,   -39,    72,    73,    22,    49,    23,
      31,    13,   -39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     8,     5,    14,    15,    19,    20,    38,
      17,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    69,    58,    12,    11,    23,    16,    13,    18,     6,
      66,     7,    53,    25,    26,    27,    28,    29,    62,     9,
      30,    63,    31,    32,    33,   113,    21,    34,   114,    31,
      32,    33,    57,    10,    34,    90,    91,    92,    94,    35,
      52,    10,    68,    54,    36,    37,    35,    65,    84,    22,
      67,    24,    37,    50,    64,    32,    33,    73,    74,    25,
      26,    27,    28,    29,     1,     2,    30,    56,    31,    32,
      33,    35,    59,    34,    79,    80,    51,   118,   119,    18,
      13,    16,   121,    81,    82,    35,    60,    10,    61,   117,
      36,    37,    31,    32,    33,    99,   100,    34,    70,    31,
      32,    33,   105,   106,    34,    71,    64,    32,    33,    35,
      93,    34,   107,   108,    72,    37,    35,    75,    76,    77,
      78,    83,    37,    35,   101,   102,   103,   104,   115,    37,
      85,    86,    87,    88,    89,    63,   116,    96,   111,   112,
     120,   109,   110,    97,     0,    98
};

static const yytype_int8 yycheck[] =
{
      25,    39,    27,    32,     7,    15,    10,    36,    12,     0,
      35,     3,    22,     6,     7,     8,     9,    10,    29,    15,
      13,    32,    15,    16,    17,    33,    15,    20,    36,    15,
      16,    17,    18,    34,    20,    60,    61,    62,    63,    32,
      21,    34,    35,    24,    37,    38,    32,    34,    51,    37,
      37,    15,    38,    15,    15,    16,    17,    23,    24,     6,
       7,     8,     9,    10,     4,     5,    13,    15,    15,    16,
      17,    32,    37,    20,    19,    20,    33,   115,   116,    83,
      36,    85,   120,    21,    22,    32,    32,    34,    32,   114,
      37,    38,    15,    16,    17,    73,    74,    20,    37,    15,
      16,    17,    79,    80,    20,    30,    15,    16,    17,    32,
      33,    20,    81,    82,    31,    38,    32,    25,    26,    27,
      28,    36,    38,    32,    75,    76,    77,    78,    11,    38,
      37,    37,    37,    37,    37,    32,    14,    33,    33,    33,
      12,    83,    85,    71,    -1,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    40,    41,    43,     0,     3,    42,    15,
      34,    48,    32,    36,    44,    45,    43,    49,    43,    46,
      47,    15,    37,    41,    15,     6,     7,     8,     9,    10,
      13,    15,    16,    17,    20,    32,    37,    38,    48,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      15,    33,    44,    41,    44,    52,    15,    18,    52,    37,
      32,    32,    29,    32,    15,    60,    52,    60,    35,    51,
      37,    30,    31,    23,    24,    25,    26,    27,    28,    19,
      20,    21,    22,    36,    48,    37,    37,    37,    37,    37,
      52,    52,    52,    33,    52,    61,    33,    54,    55,    56,
      56,    57,    57,    57,    57,    58,    58,    59,    59,    47,
      49,    33,    33,    33,    36,    11,    14,    52,    51,    51,
      12,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    42,    43,    43,    44,
      44,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      55,    56,    56,    56,    56,    56,    57,    57,    57,    58,
      58,    58,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     5,     4,     0,     2,     1,     1,     3,
       0,     4,     0,     1,     2,     4,     4,     0,     5,     1,
       2,     1,     2,     3,     3,     3,     3,     2,     6,     8,
       6,     1,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     2,     1,     4,     3,     1,     1,     1,
       3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Programa: DeclFuncVar DeclProg  */
#line 40 "analisador_sintatico/goianinha.y"
                         {
        ast_raiz = criar_no(NODE_PROGRAMA, (yylsp[-1]).first_line, NULL, 0, 2, (yyvsp[-1].no), (yyvsp[0].no));
        (yyval.no) = ast_raiz;
    }
#line 1336 "analisador_sintatico/goianinha.tab.c"
    break;

  case 3: /* DeclFuncVar: Tipo ID DeclVar PONTOVIRGULA DeclFuncVar  */
#line 46 "analisador_sintatico/goianinha.y"
                                             {
        ASTNode* atual = criar_no(NODE_DECLVAR, (yylsp[-4]).first_line, (yyvsp[-3].texto), 0, 1, (yyvsp[-2].no));
        (yyval.no) = (yyvsp[0].no) ? criar_no(NODE_LISTA, (yylsp[-4]).first_line, NULL, 0, 2, atual, (yyvsp[0].no)) : atual;
    }
#line 1345 "analisador_sintatico/goianinha.tab.c"
    break;

  case 4: /* DeclFuncVar: Tipo ID DeclFunc DeclFuncVar  */
#line 50 "analisador_sintatico/goianinha.y"
                                 {
        ASTNode* atual = criar_no(NODE_FUNCAO, (yylsp[-3]).first_line, (yyvsp[-2].texto), 0, 1, (yyvsp[-1].no));
        (yyval.no) = (yyvsp[0].no) ? criar_no(NODE_LISTA, (yylsp[-3]).first_line, NULL, 0, 2, atual, (yyvsp[0].no)) : atual;
    }
#line 1354 "analisador_sintatico/goianinha.tab.c"
    break;

  case 5: /* DeclFuncVar: %empty  */
#line 54 "analisador_sintatico/goianinha.y"
                {
        (yyval.no) = NULL;
    }
#line 1362 "analisador_sintatico/goianinha.tab.c"
    break;

  case 6: /* DeclProg: PROGRAMA Bloco  */
#line 59 "analisador_sintatico/goianinha.y"
                   {
        (yyval.no) = criar_no(NODE_BLOCO, (yylsp[-1]).first_line, strdup("programa"), 0, 1, (yyvsp[0].no));
    }
#line 1370 "analisador_sintatico/goianinha.tab.c"
    break;

  case 7: /* Tipo: TK_INT  */
#line 64 "analisador_sintatico/goianinha.y"
           { (yyval.no) = criar_no(NODE_ID, (yylsp[0]).first_line, strdup("int"), 0, 0); }
#line 1376 "analisador_sintatico/goianinha.tab.c"
    break;

  case 8: /* Tipo: TK_CAR  */
#line 65 "analisador_sintatico/goianinha.y"
           { (yyval.no) = criar_no(NODE_ID, (yylsp[0]).first_line, strdup("car"), 0, 0); }
#line 1382 "analisador_sintatico/goianinha.tab.c"
    break;

  case 9: /* DeclVar: VIRGULA ID DeclVar  */
#line 68 "analisador_sintatico/goianinha.y"
                       {
        ASTNode* idNode = criar_no(NODE_ID, (yylsp[-1]).first_line, (yyvsp[-1].texto), 0, 0);
        (yyval.no) = criar_no(NODE_LISTA, (yylsp[-2]).first_line, NULL, 0, 2, idNode, (yyvsp[0].no));
    }
#line 1391 "analisador_sintatico/goianinha.tab.c"
    break;

  case 10: /* DeclVar: %empty  */
#line 72 "analisador_sintatico/goianinha.y"
                {
        (yyval.no) = NULL;
    }
#line 1399 "analisador_sintatico/goianinha.tab.c"
    break;

  case 11: /* DeclFunc: ABREPAR ListaParametros FECHAPAR Bloco  */
#line 77 "analisador_sintatico/goianinha.y"
                                           {
        (yyval.no) = criar_no(NODE_FUNCAO, (yylsp[-3]).first_line, NULL, 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1407 "analisador_sintatico/goianinha.tab.c"
    break;

  case 12: /* ListaParametros: %empty  */
#line 82 "analisador_sintatico/goianinha.y"
                { (yyval.no) = NULL; }
#line 1413 "analisador_sintatico/goianinha.tab.c"
    break;

  case 13: /* ListaParametros: ListaParametrosCont  */
#line 83 "analisador_sintatico/goianinha.y"
                        { (yyval.no) = (yyvsp[0].no); }
#line 1419 "analisador_sintatico/goianinha.tab.c"
    break;

  case 14: /* ListaParametrosCont: Tipo ID  */
#line 86 "analisador_sintatico/goianinha.y"
            {
        ASTNode* idNode = criar_no(NODE_ID, (yylsp[0]).first_line, (yyvsp[0].texto), 0, 0);
        (yyval.no) = criar_no(NODE_LISTA, (yylsp[-1]).first_line, NULL, 0, 1, idNode);
    }
#line 1428 "analisador_sintatico/goianinha.tab.c"
    break;

  case 15: /* ListaParametrosCont: Tipo ID VIRGULA ListaParametrosCont  */
#line 90 "analisador_sintatico/goianinha.y"
                                        {
        ASTNode* idNode = criar_no(NODE_ID, (yylsp[-2]).first_line, (yyvsp[-2].texto), 0, 0);
        (yyval.no) = criar_no(NODE_LISTA, (yylsp[-3]).first_line, NULL, 0, 2, idNode, (yyvsp[0].no));
    }
#line 1437 "analisador_sintatico/goianinha.tab.c"
    break;

  case 16: /* Bloco: ABRECHAVE ListaDeclVar ListaComando FECHACHAVE  */
#line 96 "analisador_sintatico/goianinha.y"
                                                   {
        (yyval.no) = criar_no(NODE_BLOCO, (yylsp[-3]).first_line, NULL, 0, 2, (yyvsp[-2].no), (yyvsp[-1].no));
    }
#line 1445 "analisador_sintatico/goianinha.tab.c"
    break;

  case 17: /* ListaDeclVar: %empty  */
#line 101 "analisador_sintatico/goianinha.y"
                { (yyval.no) = NULL; }
#line 1451 "analisador_sintatico/goianinha.tab.c"
    break;

  case 18: /* ListaDeclVar: Tipo ID DeclVar PONTOVIRGULA ListaDeclVar  */
#line 102 "analisador_sintatico/goianinha.y"
                                              {
        ASTNode* idNode = criar_no(NODE_ID, (yylsp[-3]).first_line, (yyvsp[-3].texto), 0, 0);
        ASTNode* decl = criar_no(NODE_DECLVAR, (yylsp[-4]).first_line, NULL, 0, 2, idNode, (yyvsp[-2].no));
        (yyval.no) = criar_no(NODE_LISTA, (yylsp[-4]).first_line, NULL, 0, 2, decl, (yyvsp[0].no));
    }
#line 1461 "analisador_sintatico/goianinha.tab.c"
    break;

  case 19: /* ListaComando: Comando  */
#line 109 "analisador_sintatico/goianinha.y"
            {
        (yyval.no) = criar_no(NODE_LISTA, (yylsp[0]).first_line, NULL, 0, 1, (yyvsp[0].no));
    }
#line 1469 "analisador_sintatico/goianinha.tab.c"
    break;

  case 20: /* ListaComando: ListaComando Comando  */
#line 112 "analisador_sintatico/goianinha.y"
                         {
        (yyval.no) = criar_no(NODE_LISTA, (yylsp[0]).first_line, NULL, 0, 2, (yyvsp[-1].no), (yyvsp[0].no));
    }
#line 1477 "analisador_sintatico/goianinha.tab.c"
    break;

  case 21: /* Comando: PONTOVIRGULA  */
#line 117 "analisador_sintatico/goianinha.y"
                 {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[0]).first_line, strdup(";"), 0, 0);
    }
#line 1485 "analisador_sintatico/goianinha.tab.c"
    break;

  case 22: /* Comando: Expr PONTOVIRGULA  */
#line 120 "analisador_sintatico/goianinha.y"
                      {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-1]).first_line, strdup("expr;"), 0, 1, (yyvsp[-1].no));
    }
#line 1493 "analisador_sintatico/goianinha.tab.c"
    break;

  case 23: /* Comando: RETORNE Expr PONTOVIRGULA  */
#line 123 "analisador_sintatico/goianinha.y"
                              {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-2]).first_line, strdup("retorne"), 0, 1, (yyvsp[-1].no));
    }
#line 1501 "analisador_sintatico/goianinha.tab.c"
    break;

  case 24: /* Comando: LEIA ID PONTOVIRGULA  */
#line 126 "analisador_sintatico/goianinha.y"
                         {
        ASTNode* idNode = criar_no(NODE_ID, (yylsp[-1]).first_line, (yyvsp[-1].texto), 0, 0);
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-2]).first_line, strdup("leia"), 0, 1, idNode);
    }
#line 1510 "analisador_sintatico/goianinha.tab.c"
    break;

  case 25: /* Comando: ESCREVA Expr PONTOVIRGULA  */
#line 130 "analisador_sintatico/goianinha.y"
                              {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-2]).first_line, strdup("escreva"), 0, 1, (yyvsp[-1].no));
    }
#line 1518 "analisador_sintatico/goianinha.tab.c"
    break;

  case 26: /* Comando: ESCREVA STRINGCONST PONTOVIRGULA  */
#line 133 "analisador_sintatico/goianinha.y"
                                     {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-2]).first_line, strdup("escreva_str"), 0, 0);
    }
#line 1526 "analisador_sintatico/goianinha.tab.c"
    break;

  case 27: /* Comando: NOVALINHA PONTOVIRGULA  */
#line 136 "analisador_sintatico/goianinha.y"
                           {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-1]).first_line, strdup("novalinha"), 0, 0);
    }
#line 1534 "analisador_sintatico/goianinha.tab.c"
    break;

  case 28: /* Comando: SE ABREPAR Expr FECHAPAR ENTAO Comando  */
#line 139 "analisador_sintatico/goianinha.y"
                                           {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-5]).first_line, strdup("se"), 0, 2, (yyvsp[-3].no), (yyvsp[0].no));
    }
#line 1542 "analisador_sintatico/goianinha.tab.c"
    break;

  case 29: /* Comando: SE ABREPAR Expr FECHAPAR ENTAO Comando SENAO Comando  */
#line 142 "analisador_sintatico/goianinha.y"
                                                         {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-7]).first_line, strdup("se_senao"), 0, 3, (yyvsp[-5].no), (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1550 "analisador_sintatico/goianinha.tab.c"
    break;

  case 30: /* Comando: ENQUANTO ABREPAR Expr FECHAPAR EXECUTE Comando  */
#line 145 "analisador_sintatico/goianinha.y"
                                                   {
        (yyval.no) = criar_no(NODE_CMD, (yylsp[-5]).first_line, strdup("enquanto"), 0, 2, (yyvsp[-3].no), (yyvsp[0].no));
    }
#line 1558 "analisador_sintatico/goianinha.tab.c"
    break;

  case 31: /* Comando: Bloco  */
#line 148 "analisador_sintatico/goianinha.y"
          {
        (yyval.no) = (yyvsp[0].no);
    }
#line 1566 "analisador_sintatico/goianinha.tab.c"
    break;

  case 32: /* Expr: OrExpr  */
#line 153 "analisador_sintatico/goianinha.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 1572 "analisador_sintatico/goianinha.tab.c"
    break;

  case 33: /* Expr: ID ATRIBUICAO Expr  */
#line 154 "analisador_sintatico/goianinha.y"
                       {
        ASTNode* idNode = criar_no(NODE_ID, (yylsp[-2]).first_line, (yyvsp[-2].texto), 0, 0);
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("="), 0, 2, idNode, (yyvsp[0].no));
    }
#line 1581 "analisador_sintatico/goianinha.tab.c"
    break;

  case 34: /* OrExpr: OrExpr OU AndExpr  */
#line 160 "analisador_sintatico/goianinha.y"
                      {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("ou"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1589 "analisador_sintatico/goianinha.tab.c"
    break;

  case 35: /* OrExpr: AndExpr  */
#line 163 "analisador_sintatico/goianinha.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1595 "analisador_sintatico/goianinha.tab.c"
    break;

  case 36: /* AndExpr: AndExpr E EqExpr  */
#line 166 "analisador_sintatico/goianinha.y"
                     {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("e"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1603 "analisador_sintatico/goianinha.tab.c"
    break;

  case 37: /* AndExpr: EqExpr  */
#line 169 "analisador_sintatico/goianinha.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 1609 "analisador_sintatico/goianinha.tab.c"
    break;

  case 38: /* EqExpr: EqExpr IGUAL DesigExpr  */
#line 172 "analisador_sintatico/goianinha.y"
                           {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("=="), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1617 "analisador_sintatico/goianinha.tab.c"
    break;

  case 39: /* EqExpr: EqExpr DIFERENTE DesigExpr  */
#line 175 "analisador_sintatico/goianinha.y"
                               {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("!="), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1625 "analisador_sintatico/goianinha.tab.c"
    break;

  case 40: /* EqExpr: DesigExpr  */
#line 178 "analisador_sintatico/goianinha.y"
              { (yyval.no) = (yyvsp[0].no); }
#line 1631 "analisador_sintatico/goianinha.tab.c"
    break;

  case 41: /* DesigExpr: DesigExpr MENOR AddExpr  */
#line 181 "analisador_sintatico/goianinha.y"
                            {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("<"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1639 "analisador_sintatico/goianinha.tab.c"
    break;

  case 42: /* DesigExpr: DesigExpr MAIOR AddExpr  */
#line 184 "analisador_sintatico/goianinha.y"
                            {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup(">"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1647 "analisador_sintatico/goianinha.tab.c"
    break;

  case 43: /* DesigExpr: DesigExpr MAIORIGUAL AddExpr  */
#line 187 "analisador_sintatico/goianinha.y"
                                 {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup(">="), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1655 "analisador_sintatico/goianinha.tab.c"
    break;

  case 44: /* DesigExpr: DesigExpr MENORIGUAL AddExpr  */
#line 190 "analisador_sintatico/goianinha.y"
                                 {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("<="), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1663 "analisador_sintatico/goianinha.tab.c"
    break;

  case 45: /* DesigExpr: AddExpr  */
#line 193 "analisador_sintatico/goianinha.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1669 "analisador_sintatico/goianinha.tab.c"
    break;

  case 46: /* AddExpr: AddExpr MAIS MulExpr  */
#line 196 "analisador_sintatico/goianinha.y"
                         {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("+"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1677 "analisador_sintatico/goianinha.tab.c"
    break;

  case 47: /* AddExpr: AddExpr MENOS MulExpr  */
#line 199 "analisador_sintatico/goianinha.y"
                          {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("-"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1685 "analisador_sintatico/goianinha.tab.c"
    break;

  case 48: /* AddExpr: MulExpr  */
#line 202 "analisador_sintatico/goianinha.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1691 "analisador_sintatico/goianinha.tab.c"
    break;

  case 49: /* MulExpr: MulExpr MULT UnExpr  */
#line 205 "analisador_sintatico/goianinha.y"
                        {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("*"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1699 "analisador_sintatico/goianinha.tab.c"
    break;

  case 50: /* MulExpr: MulExpr DIV UnExpr  */
#line 208 "analisador_sintatico/goianinha.y"
                       {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("/"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1707 "analisador_sintatico/goianinha.tab.c"
    break;

  case 51: /* MulExpr: UnExpr  */
#line 211 "analisador_sintatico/goianinha.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 1713 "analisador_sintatico/goianinha.tab.c"
    break;

  case 52: /* UnExpr: MENOS PrimExpr  */
#line 214 "analisador_sintatico/goianinha.y"
                   {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("-"), 0, 1, (yyvsp[0].no));
    }
#line 1721 "analisador_sintatico/goianinha.tab.c"
    break;

  case 53: /* UnExpr: '!' PrimExpr  */
#line 217 "analisador_sintatico/goianinha.y"
                 {
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-1]).first_line, strdup("!"), 0, 1, (yyvsp[0].no));
    }
#line 1729 "analisador_sintatico/goianinha.tab.c"
    break;

  case 54: /* UnExpr: PrimExpr  */
#line 220 "analisador_sintatico/goianinha.y"
             { (yyval.no) = (yyvsp[0].no); }
#line 1735 "analisador_sintatico/goianinha.tab.c"
    break;

  case 55: /* PrimExpr: ID ABREPAR ListExpr FECHAPAR  */
#line 223 "analisador_sintatico/goianinha.y"
                                 {
        ASTNode* idNode = criar_no(NODE_ID, (yylsp[-3]).first_line, (yyvsp[-3].texto), 0, 0);
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-3]).first_line, strdup("call"), 0, 2, idNode, (yyvsp[-1].no));
    }
#line 1744 "analisador_sintatico/goianinha.tab.c"
    break;

  case 56: /* PrimExpr: ID ABREPAR FECHAPAR  */
#line 227 "analisador_sintatico/goianinha.y"
                        {
        ASTNode* idNode = criar_no(NODE_ID, (yylsp[-2]).first_line, (yyvsp[-2].texto), 0, 0);
        (yyval.no) = criar_no(NODE_EXPR, (yylsp[-2]).first_line, strdup("call"), 0, 1, idNode);
    }
#line 1753 "analisador_sintatico/goianinha.tab.c"
    break;

  case 57: /* PrimExpr: ID  */
#line 231 "analisador_sintatico/goianinha.y"
       {
        (yyval.no) = criar_no(NODE_ID, (yylsp[0]).first_line, (yyvsp[0].texto), 0, 0);
    }
#line 1761 "analisador_sintatico/goianinha.tab.c"
    break;

  case 58: /* PrimExpr: CARCONST  */
#line 234 "analisador_sintatico/goianinha.y"
             {
        (yyval.no) = criar_no(NODE_CONST, (yylsp[0]).first_line, NULL, (yyvsp[0].texto)[0], 0);
    }
#line 1769 "analisador_sintatico/goianinha.tab.c"
    break;

  case 59: /* PrimExpr: INTCONST  */
#line 237 "analisador_sintatico/goianinha.y"
             {
        (yyval.no) = criar_no(NODE_CONST, (yylsp[0]).first_line, NULL, atoi((yyvsp[0].texto)), 0);
    }
#line 1777 "analisador_sintatico/goianinha.tab.c"
    break;

  case 60: /* PrimExpr: ABREPAR Expr FECHAPAR  */
#line 240 "analisador_sintatico/goianinha.y"
                          {
        (yyval.no) = (yyvsp[-1].no);
    }
#line 1785 "analisador_sintatico/goianinha.tab.c"
    break;

  case 61: /* ListExpr: Expr  */
#line 245 "analisador_sintatico/goianinha.y"
         {
        (yyval.no) = criar_no(NODE_LISTA, (yylsp[0]).first_line, strdup("arg"), 0, 1, (yyvsp[0].no));
    }
#line 1793 "analisador_sintatico/goianinha.tab.c"
    break;

  case 62: /* ListExpr: ListExpr VIRGULA Expr  */
#line 248 "analisador_sintatico/goianinha.y"
                          {
        (yyval.no) = criar_no(NODE_LISTA, (yylsp[-1]).first_line, strdup("arg"), 0, 2, (yyvsp[-2].no), (yyvsp[0].no));
    }
#line 1801 "analisador_sintatico/goianinha.tab.c"
    break;


#line 1805 "analisador_sintatico/goianinha.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 252 "analisador_sintatico/goianinha.y"


void yyerror(const char *s) {
    printf("ERRO: %s linha %d\n", s, yylineno);
}

