/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "../src/Analizador.y" /* yacc.c:339  */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"

extern int yylineno;            // Numero de linea en que se encuentra
extern FILE* yyin; 

int yylex (void);
void yyerror (char const *s); 
int yywrap(){return(1);}


int contadorPuntero=0;          // Para contar los * de los identificadores
int flagError=0;                // Para saber si se produjo un error
char* tipoDeDato;//=strdup(""); // Para imprimir el tipo de dato
char* idFuncion;                       // Para imprimir el identificador 
char* tipoFuncion;              // Para imprimir el tipo de la funcion
char* nombreIdent;              // Para imprimir el nombre del identificador
char* nombreIdFuncion;          // Para imprimir el nombre de una funcion
int contadorDeVariables = 0;    // Para contar las variables
int flagFuncion=0;              // Toma el valor 1 cuando es definicion, y 0 cuando es declaracion de función
int flagSentencia =0;           
char* tipo;
char* tipoDatoFuncion;
char* id;
int lineaFuncion=0;
char* tipoDatoParametro;
char* idParametro;
int errorLinea =0; 




Nodo *listaDeFor = NULL;
Nodo *listaDeIf = NULL;
Nodo *listaDeElse = NULL;
Nodo *listaDeWhile = NULL;
Nodo *listaDeDo = NULL;
Nodo *listaDeSwitch = NULL;
Nodo *listaIdentificadorVariable = NULL;
Nodo *listaIdentificadorFuncion = NULL;
Nodo *listaParametros = NULL;
Nodo *listaFuncionesDefinidas = NULL;
Nodo *listaErrores = NULL;
Nodo *listaErroresLexicos = NULL;
Nodo *listaErroresSintacticos = NULL;
Nodo *declaracionFunciones = NULL;


#line 120 "Analizador.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Analizador.tab.h".  */
#ifndef YY_YY_ANALIZADOR_TAB_H_INCLUDED
# define YY_YY_ANALIZADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GOTO = 258,
    VOLATILE = 259,
    TIPO_DATO = 260,
    SIGNED = 261,
    UNSIGNED = 262,
    ENUM = 263,
    TYPEDEF = 264,
    AND_LOGICO = 265,
    OR_LOGICO = 266,
    CONST = 267,
    CASE = 268,
    DEFAULT = 269,
    STRUCT = 270,
    UNION = 271,
    IGUAL_IGUAL = 272,
    DISTINTO = 273,
    MAYOR_IGUAL = 274,
    MENOR_IGUAL = 275,
    MAS_MAS = 276,
    MENOS_MENOS = 277,
    ASIGNACION_INCREMENTO = 278,
    ASIGNACION_DECREMENTO = 279,
    ASIGNACION_PRODUCTO = 280,
    ASIGNACION_DIVISION = 281,
    CORRIMIENTO_A_IZQUIERDA = 282,
    CORRIMIENTO_A_DERECHA = 283,
    NUM_REAL = 284,
    PUNTERO_FLECHA = 285,
    NUM = 286,
    IDENTIFICADOR = 287,
    LITERAL_CADENA = 288,
    SIZEOF = 289,
    IF = 290,
    BREAK = 291,
    FOR = 292,
    WHILE = 293,
    DO = 294,
    SWITCH = 295,
    RETURN = 296,
    CONTINUE = 297,
    ERROR_LEXICO = 298,
    INCLUDE = 299,
    DEFINE = 300,
    IFX = 301,
    ELSE = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "../src/Analizador.y" /* yacc.c:355  */

  char cadena[30];
  int entero;
  float real;

#line 214 "Analizador.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALIZADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "Analizador.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   938

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,     2,     2,    69,    66,     2,
      60,    61,    48,    46,    55,    47,    72,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    52,
      67,    56,    68,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,    65,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    62,     2,     2,     2,
       2,     2,     2,    53,    64,    54,    70,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   117,   120,   121,   122,   122,   122,   123,
     123,   123,   124,   132,   133,   135,   135,   138,   139,   143,
     142,   156,   159,   160,   163,   164,   165,   166,   167,   168,
     171,   174,   175,   176,   177,   178,   179,   182,   183,   186,
     187,   188,   191,   192,   195,   196,   199,   200,   203,   204,
     207,   210,   211,   212,   213,   216,   217,   220,   221,   222,
     225,   226,   227,   230,   231,   234,   235,   238,   239,   242,
     247,   248,   249,   249,   249,   252,   252,   253,   253,   254,
     254,   256,   256,   259,   260,   260,   271,   274,   275,   278,
     279,   280,   283,   284,   287,   288,   289,   292,   293,   296,
     297,   300,   301,   302,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   316,   319,   320,   321,   322,   323,   324,
     328,   329,   330,   333,   334,   337,   337,   338,   338,   339,
     339,   343,   344,   348,   349,   352,   352,   352,   352,   353,
     353,   353,   353,   355,   356,   359,   359,   359,   359,   360,
     360,   360,   360,   360,   361,   361,   361,   364,   365,   370,
     371,   372,   373,   374,   377,   378,   381,   382,   385,   386,
     387,   388,   389,   392,   393,   396,   398,   399,   402,   403,
     406,   407,   410,   411,   414,   415,   418,   419,   420,   423,
     424,   425,   426,   427,   430,   431,   432,   435,   436,   437,
     440,   441,   442,   443,   446,   447,   450,   451,   452,   453,
     454,   455,   459,   460,   461,   462,   463,   466,   467,   468,
     469,   470,   473,   474,   475,   476,   483,   484
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GOTO", "VOLATILE", "TIPO_DATO",
  "SIGNED", "UNSIGNED", "ENUM", "TYPEDEF", "AND_LOGICO", "OR_LOGICO",
  "CONST", "CASE", "DEFAULT", "STRUCT", "UNION", "IGUAL_IGUAL", "DISTINTO",
  "MAYOR_IGUAL", "MENOR_IGUAL", "MAS_MAS", "MENOS_MENOS",
  "ASIGNACION_INCREMENTO", "ASIGNACION_DECREMENTO", "ASIGNACION_PRODUCTO",
  "ASIGNACION_DIVISION", "CORRIMIENTO_A_IZQUIERDA",
  "CORRIMIENTO_A_DERECHA", "NUM_REAL", "PUNTERO_FLECHA", "NUM",
  "IDENTIFICADOR", "LITERAL_CADENA", "SIZEOF", "IF", "BREAK", "FOR",
  "WHILE", "DO", "SWITCH", "RETURN", "CONTINUE", "ERROR_LEXICO", "INCLUDE",
  "DEFINE", "'+'", "'-'", "'*'", "'/'", "IFX", "ELSE", "';'", "'{'", "'}'",
  "','", "'='", "':'", "'['", "']'", "'('", "')'", "'t'", "'?'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'%'", "'~'", "'!'", "'.'", "$accept",
  "input", "line", "$@1", "$@2", "$@3", "$@4", "declaracion_externa",
  "definicion_de_funcion", "$@5", "opcional_lista_de_declaracion",
  "declaracion", "$@6", "lista_de_declaracion",
  "especificadores_de_declaracion",
  "especificador_categoria_almacenamiento", "especificador_de_tipo",
  "calificador_de_tipo", "especificador_estructura_o_union",
  "estructura_o_union", "lista_declaraciones_struct",
  "lista_declaradores_init", "declarador_init", "declaracion_struct",
  "lista_calificador_especificador", "lista_declaradores_struct",
  "declarador_struct", "especificador_enum", "lista_de_enumerador",
  "enumerador", "declarador", "declarador_directo", "$@7", "$@8",
  "lista_op_parentesis", "$@9", "$@10", "$@11", "apuntador", "$@12",
  "apuntador_aux", "$@13", "lista_tipos_de_parametro",
  "lista_de_parametros", "declaracion_de_parametro",
  "lista_de_identificadores", "inicializador", "lista_de_inicializadores",
  "nombre_de_tipo", "declarador_abstracto", "declarador_abstracto_directo",
  "nombre_typedef", "sentencia", "sentencia_etiquetada",
  "sentencia_expresion", "sentencia_compuesta", "$@14", "$@15", "$@16",
  "opcional_sentencia_compuesta", "lista_de_sentencias",
  "sentencia_de_seleccion", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "opcionElse", "sentencia_de_iteracion", "$@23", "$@24", "$@25", "$@26",
  "$@27", "$@28", "$@29", "$@30", "$@31", "opcional_expresion",
  "sentencia_de_salto", "expresion", "expresion_de_asignacion",
  "operador_de_asignacion", "expresion_condicional", "expresion_constante",
  "expresion_logica_or", "expresion_logica_and", "expresion_or_inclusivo",
  "expresion_or_exclusivo", "expresion_and", "expresion_de_igualdad",
  "expresion_relacional", "expresion_de_corrimiento", "expresion_aditiva",
  "expresion_multiplicativa", "expresion_cast", "expresion_unaria",
  "operador_unario", "expresion_posfija", "expresion_primaria",
  "constante", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    43,    45,    42,    47,
     301,   302,    59,   123,   125,    44,    61,    58,    91,    93,
      40,    41,   116,    63,   124,    94,    38,    60,    62,    37,
     126,    33,    46
};
# endif

#define YYPACT_NINF -262

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-262)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -262,   321,  -262,    18,    53,  -262,  -262,  -262,  -262,    20,
    -262,  -262,   824,    -4,  -262,  -262,   845,   845,  -262,  -262,
     104,  -262,   867,  -262,   135,  -262,  -262,  -262,  -262,   708,
     167,  -262,  -262,  -262,  -262,    21,   555,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   130,   604,   604,   604,  -262,
      67,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
      60,  -262,  -262,     8,   189,   171,   177,   180,    39,    78,
     175,   164,    -3,  -262,   264,   824,    29,  -262,  -262,   604,
     197,   203,   207,   262,  -262,  -262,   238,  -262,   191,   824,
    -262,  -262,   191,   555,  -262,   236,  -262,   237,   240,  -262,
     243,  -262,   120,  -262,   604,   191,   244,   185,   185,   205,
     245,    61,  -262,  -262,  -262,   131,  -262,   101,   156,   273,
    -262,  -262,  -262,   254,   185,  -262,   824,   824,   824,   824,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,   824,   824,   824,  -262,  -262,  -262,  -262,
    -262,   824,  -262,  -262,  -262,   276,   278,  -262,  -262,  -262,
     262,   256,   204,  -262,   191,  -262,  -262,   253,   824,   824,
     824,   191,   824,  -262,  -262,   390,   130,  -262,   444,  -262,
    -262,  -262,   730,   588,   157,  -262,   176,   824,  -262,   268,
    -262,     7,   751,   102,   781,  -262,   156,   185,   652,  -262,
       6,  -262,   189,   195,   171,   177,   180,    39,    78,    78,
     175,   175,   175,   175,   164,   164,    -3,    -3,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,   215,   824,  -262,   262,
    -262,  -262,    88,   265,   263,    97,  -262,    99,  -262,  -262,
    -262,   498,   267,  -262,  -262,  -262,   260,  -262,   148,   279,
     284,  -262,   280,   176,   802,   270,  -262,  -262,  -262,  -262,
    -262,   751,  -262,  -262,  -262,   102,  -262,  -262,   285,   286,
     665,  -262,  -262,   824,   143,  -262,   288,   824,  -262,  -262,
    -262,  -262,   824,  -262,   309,  -262,  -262,  -262,  -262,     0,
    -262,  -262,   604,  -262,  -262,   289,  -262,   304,   268,  -262,
     218,  -262,  -262,   623,  -262,  -262,  -262,     6,   824,  -262,
     191,   297,   191,  -262,   191,  -262,  -262,  -262,  -262,  -262,
     662,  -262,  -262,   305,  -262,   314,  -262,  -262,   319,   824,
    -262,   311,  -262,  -262,  -262,  -262,   315,   340,   316,   191,
    -262,   317,  -262,   824,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,   110,   191,   323,  -262,  -262
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     6,     0,    38,    31,    32,    33,     0,
      30,    37,     0,     0,    42,    43,     0,     0,   227,   226,
     222,   224,     0,   135,     0,   154,   145,   149,   139,     0,
       0,    12,   213,   214,   124,   127,     0,   113,   212,   215,
     216,     3,     4,    13,    14,     0,    25,    27,    29,    34,
       0,    35,    36,     5,   114,   115,   116,   117,   118,   119,
       0,   164,   166,   173,   176,   178,   180,   182,   184,   186,
     189,   194,   197,   200,   204,     0,   206,   217,   223,     0,
       0,     0,    62,     0,   222,   175,     0,   204,     0,     0,
     208,   207,     0,     0,   210,     0,   161,     0,     0,   150,
       0,   163,     0,   160,     0,     0,     0,    52,    54,   100,
       0,     0,    69,    81,    21,     0,    46,    15,    68,     0,
      24,    26,    28,    41,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,   168,   171,   169,
     172,     0,   209,   221,   220,     0,     0,     7,    10,   159,
       0,    65,     0,    63,     0,   122,   120,     0,     0,   157,
       0,     0,     0,   162,    22,     0,     0,   133,     0,   130,
      51,    53,     0,     0,   101,    99,   103,     0,   225,    83,
      19,     0,     0,     0,     0,    73,    67,     0,     0,    44,
       0,   165,   177,     0,   179,   181,   183,   185,   187,   188,
     193,   192,   190,   191,   195,   196,   198,   199,   201,   202,
     203,   167,   219,   218,     8,    11,     0,     0,    61,     0,
     121,   211,     0,     0,   158,     0,   151,     0,   132,    23,
     126,     0,    48,   128,   134,   108,     0,   112,    91,     0,
      86,    87,     0,   102,     0,     0,   205,    84,    82,    20,
      47,     0,    49,    94,    16,     0,    17,    71,     0,     0,
       0,    40,    45,     0,     0,    55,    57,     0,    60,    66,
      64,   136,   157,   146,     0,   140,   131,   106,    89,   101,
      90,   110,     0,   104,   107,     0,   111,     0,    83,    97,
       0,    18,    70,    79,    39,    59,    50,     0,     0,   174,
       0,     0,     0,   152,     0,    88,   105,   109,    85,    95,
       0,    92,    74,     0,    75,    77,    56,    58,   143,   157,
     147,     0,   141,    96,    98,    80,     0,     0,     0,     0,
     137,     0,   148,     0,   142,    76,    93,    78,   144,   138,
     155,     0,     0,     0,   156,   153
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,  -262,  -262,  -262,  -262,  -262,  -262,   300,  -262,  -262,
    -262,   -91,  -262,   187,     1,  -262,   -31,   -29,  -262,  -262,
     188,  -262,   193,  -180,   -19,  -262,    75,  -262,   226,   159,
     -41,  -110,  -262,  -262,  -262,  -262,  -262,  -262,   -97,  -262,
      91,  -262,  -231,  -262,    98,  -262,  -238,  -262,   307,  -152,
    -170,  -262,    -1,  -262,  -262,  -173,  -262,  -262,  -262,  -262,
     232,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -261,
    -262,   -28,  -111,  -262,    -9,  -160,  -262,   274,   281,   283,
     277,   282,   147,   -94,   144,   150,   -40,    -6,  -262,  -262,
    -262,  -262
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    41,    79,   224,    80,   225,    42,    43,   193,
     264,    44,   259,   175,   176,    46,    47,    48,    49,    50,
     198,   115,   116,   199,   200,   274,   275,    51,   162,   163,
     242,   118,   195,   269,   322,   336,   338,   323,   119,   189,
     258,   298,   249,   250,   251,   325,   262,   300,   110,   185,
     186,    52,   177,    54,    55,    56,   104,   105,   106,   240,
     178,    57,    95,   310,   349,   100,   314,   344,   340,    58,
      98,   312,   342,    99,   171,   284,   331,    97,   352,   233,
      59,    60,    61,   151,    62,    86,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   102,    45,    85,   117,   107,    87,   108,   111,   196,
      90,    91,   184,   174,   253,   201,    94,   109,   272,   127,
     266,   311,   246,   299,   297,  -125,  -125,  -125,  -125,  -125,
    -125,   252,   112,  -125,   268,   152,  -125,  -125,   112,   112,
     221,   210,   211,   212,   213,   143,   144,   120,   121,   122,
     153,   154,    82,    88,   113,   113,   133,   134,   182,   155,
     183,   111,   107,   273,   108,   111,   145,   279,   341,    87,
      -9,   128,   324,    83,   109,  -129,   107,   107,   108,   108,
      45,   263,   334,  -125,   239,    81,   184,   165,   180,   181,
     272,   166,   301,   107,   295,   108,   290,   135,   136,   123,
     203,   156,   174,   218,   219,   220,     5,     6,     7,     8,
       9,    10,   125,   305,    11,   126,   126,    14,    15,   253,
     124,    87,   188,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
     232,   234,   235,   126,   237,   137,   138,   256,   327,   281,
     263,   289,   126,   -48,   126,    35,   -48,   192,   283,   276,
     285,    92,   112,   230,    37,   126,   107,   107,   108,   108,
     236,   353,   173,    85,   239,   126,    87,   244,   113,   196,
     112,    87,   114,   190,   248,    85,   191,    96,    87,     5,
       6,     7,     8,     9,     4,   306,   113,    11,   307,   129,
      14,    15,   139,   140,    12,    13,   182,   288,   183,   263,
     141,   142,    16,    17,   194,   182,   -72,   183,    85,   103,
      18,    87,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   254,   130,   255,    32,    33,   107,
     244,   108,   131,    34,    35,    85,   132,    37,    87,   158,
     126,    36,   277,   113,   234,   159,   248,    38,   228,   229,
     160,    39,    40,   182,    85,   183,   276,    87,   309,   278,
     229,    87,   319,   320,     5,     6,     7,     8,     9,    10,
     208,   209,    11,   214,   215,    14,    15,   146,   147,   148,
     149,   216,   217,   248,   161,   164,   168,   169,   179,    85,
     170,   234,    87,   172,   248,   112,   187,   197,   222,   328,
     223,   330,   227,   332,   231,   351,   257,   282,   126,   287,
     150,     2,     3,   192,     4,     5,     6,     7,     8,     9,
      10,   296,    37,    11,    12,    13,    14,    15,   348,   292,
     291,   293,    16,    17,   302,   308,   303,   313,   316,   329,
      18,   354,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   317,   335,    32,    33,   337,
     339,   343,   346,    34,    35,   355,   345,   347,   350,   157,
     265,    36,   326,    37,   260,   270,   226,    38,   280,   318,
     315,    39,    40,     4,     5,     6,     7,     8,     9,    10,
     167,   202,    11,    12,    13,    14,    15,   241,   206,     0,
     204,    16,    17,   205,   207,     0,     0,     0,     0,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,    32,    33,     0,     0,
       0,     0,    34,    35,   238,     0,     0,     4,     0,     0,
      36,     0,    37,     0,     0,     0,    38,    12,    13,     0,
      39,    40,     0,     0,     0,    16,    17,     0,     0,     0,
       0,     0,     0,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
      32,    33,     0,     0,     0,     0,    34,    35,   243,     0,
       0,     4,     0,     0,    36,     0,     0,     0,     0,     0,
      38,    12,    13,     0,    39,    40,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,    32,    33,     0,     0,     0,     0,
      34,    35,   286,     0,     0,     0,     0,     0,    36,     5,
       6,     7,     8,     9,    38,     0,     0,    11,    39,    40,
      14,    15,     0,     0,     0,     0,    16,    17,     0,     0,
       0,     0,     0,     0,    18,     0,    19,    84,    21,    22,
       0,     0,     5,     6,     7,     8,     9,    10,     0,     0,
      11,    32,    33,    14,    15,     0,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    36,    11,    37,     0,    14,
      15,    38,     0,     0,     0,    39,    40,     5,     6,     7,
       8,     9,    10,     0,     0,    11,   113,     0,    14,    15,
       0,     0,     0,     0,     0,     0,   182,     0,   183,   247,
      37,     0,     0,     0,     0,   321,     5,     6,     7,     8,
       9,     0,     0,     0,    11,     0,    37,    14,    15,     5,
       6,     7,     8,     9,     0,     0,     0,    11,     0,     0,
      14,    15,     0,    16,    17,    37,     0,     0,     0,     0,
       0,    18,     0,    19,    84,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,    32,    33,
       0,     0,     0,     0,    37,   261,   333,     0,     0,   304,
       0,     0,    36,     0,     0,     0,     0,    37,    38,    16,
      17,     0,    39,    40,     0,     0,     0,    18,     0,    19,
      84,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,     0,    32,    33,     0,     0,     0,    18,
     101,    19,    84,    21,    22,     0,     0,     0,    36,     0,
       0,     0,    16,    17,    38,     0,    32,    33,    39,    40,
      18,     0,    19,    84,    21,    22,     0,     0,     0,   245,
      36,     0,     0,     0,     0,     0,    38,    32,    33,     0,
      39,    40,    16,    17,   261,     0,     0,     0,     0,     0,
      18,    36,    19,    84,    21,    22,     0,    38,     0,     0,
       0,    39,    40,    16,    17,     0,     0,    32,    33,     0,
       0,    18,     0,    19,    84,    21,    22,     0,     0,     0,
     267,    36,     0,     0,     0,    16,    17,    38,    32,    33,
       0,    39,    40,    18,     0,    19,    84,    21,    22,     0,
       0,   294,    36,     0,     0,     0,    16,    17,    38,     0,
      32,    33,    39,    40,    18,     0,    19,    84,    21,    22,
       0,     0,     0,     0,    36,     0,     0,     0,    16,    17,
      38,    32,    33,     0,    39,    40,    18,     0,    19,    84,
      21,    22,     0,     0,     0,    89,     0,     0,     0,     0,
       0,    38,     0,    32,    33,    39,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     0,     0,    38,     0,     0,     0,    39,    40
};

static const yytype_int16 yycheck[] =
{
       1,    29,     1,    12,    45,    36,    12,    36,    36,   119,
      16,    17,   109,   104,   184,   126,    22,    36,   198,    11,
     193,   282,   182,   261,   255,     4,     5,     6,     7,     8,
       9,   183,    32,    12,   194,    75,    15,    16,    32,    32,
     151,   135,   136,   137,   138,    48,    49,    46,    47,    48,
      21,    22,    32,    57,    48,    48,    17,    18,    58,    30,
      60,    89,    93,    57,    93,    93,    69,   227,   329,    75,
      52,    63,   303,    53,    93,    54,   107,   108,   107,   108,
      79,   192,   320,    62,   175,    32,   183,    88,   107,   108,
     270,    92,   265,   124,   254,   124,   248,    19,    20,    32,
     128,    72,   193,   143,   144,   145,     4,     5,     6,     7,
       8,     9,    52,   273,    12,    55,    55,    15,    16,   289,
      53,   127,    61,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     168,   169,   170,    55,   172,    67,    68,   187,   308,    61,
     261,   248,    55,    52,    55,    53,    55,    56,    61,   200,
      61,    57,    32,   164,    62,    55,   197,   198,   197,   198,
     171,    61,    52,   182,   265,    55,   182,   178,    48,   289,
      32,   187,    52,    52,   183,   194,    55,    52,   194,     4,
       5,     6,     7,     8,     3,    52,    48,    12,    55,    10,
      15,    16,    27,    28,    13,    14,    58,   248,    60,   320,
      46,    47,    21,    22,    58,    58,    60,    60,   227,    52,
      29,   227,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    58,    64,    60,    46,    47,   270,
     241,   270,    65,    52,    53,   254,    66,    62,   254,    52,
      55,    60,    57,    48,   282,    52,   255,    66,    54,    55,
      53,    70,    71,    58,   273,    60,   307,   273,   277,    54,
      55,   277,    54,    55,     4,     5,     6,     7,     8,     9,
     133,   134,    12,   139,   140,    15,    16,    23,    24,    25,
      26,   141,   142,   292,    32,    57,    60,    60,    54,   308,
      60,   329,   308,    60,   303,    32,    61,    53,    32,   310,
      32,   312,    56,   314,    61,   343,    48,    52,    55,    59,
      56,     0,     1,    56,     3,     4,     5,     6,     7,     8,
       9,    61,    62,    12,    13,    14,    15,    16,   339,    55,
      61,    61,    21,    22,    59,    57,    60,    38,    59,    52,
      29,   352,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    61,    61,    46,    47,    55,
      51,    60,    32,    52,    53,    52,    61,    61,    61,    79,
     193,    60,   307,    62,   191,   197,   160,    66,   229,   298,
     292,    70,    71,     3,     4,     5,     6,     7,     8,     9,
      93,   127,    12,    13,    14,    15,    16,   175,   131,    -1,
     129,    21,    22,   130,   132,    -1,    -1,    -1,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,     3,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    66,    13,    14,    -1,
      70,    71,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,     3,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    13,    14,    -1,    70,    71,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,     4,
       5,     6,     7,     8,    66,    -1,    -1,    12,    70,    71,
      15,    16,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,    34,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    46,    47,    15,    16,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    60,    12,    62,    -1,    15,
      16,    66,    -1,    -1,    -1,    70,    71,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    48,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    32,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    62,    15,    16,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    21,    22,    62,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    46,    47,
      -1,    -1,    -1,    -1,    62,    53,    54,    -1,    -1,    54,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    62,    66,    21,
      22,    -1,    70,    71,    -1,    -1,    -1,    29,    -1,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    -1,    46,    47,    -1,    -1,    -1,    29,
      52,    31,    32,    33,    34,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    21,    22,    66,    -1,    46,    47,    70,    71,
      29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    66,    46,    47,    -1,
      70,    71,    21,    22,    53,    -1,    -1,    -1,    -1,    -1,
      29,    60,    31,    32,    33,    34,    -1,    66,    -1,    -1,
      -1,    70,    71,    21,    22,    -1,    -1,    46,    47,    -1,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    21,    22,    66,    46,    47,
      -1,    70,    71,    29,    -1,    31,    32,    33,    34,    -1,
      -1,    59,    60,    -1,    -1,    -1,    21,    22,    66,    -1,
      46,    47,    70,    71,    29,    -1,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    21,    22,
      66,    46,    47,    -1,    70,    71,    29,    -1,    31,    32,
      33,    34,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    46,    47,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    70,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    12,    13,    14,    15,    16,    21,    22,    29,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    46,    47,    52,    53,    60,    62,    66,    70,
      71,    75,    80,    81,    84,    87,    88,    89,    90,    91,
      92,   100,   124,   125,   126,   127,   128,   134,   142,   153,
     154,   155,   157,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    76,
      78,    32,    32,    53,    32,   157,   158,   170,    57,    60,
     170,   170,    57,    60,   170,   135,    52,   150,   143,   146,
     138,    52,   154,    52,   129,   130,   131,    89,    90,    97,
     121,   154,    32,    48,    52,    94,    95,   103,   104,   111,
      87,    87,    87,    32,    53,    52,    55,    11,    63,    10,
      64,    65,    66,    17,    18,    19,    20,    67,    68,    27,
      28,    46,    47,    48,    49,    69,    23,    24,    25,    26,
      56,   156,   169,    21,    22,    30,    72,    80,    52,    52,
      53,    32,   101,   102,    57,   125,   125,   121,    60,    60,
      60,   147,    60,    52,    84,    86,    87,   125,   133,    54,
      97,    97,    58,    60,   111,   122,   123,    61,    61,   112,
      52,    55,    56,    82,    58,   105,   104,    53,    93,    96,
      97,   155,   160,   154,   161,   162,   163,   164,   165,   165,
     166,   166,   166,   166,   167,   167,   168,   168,   169,   169,
     169,   155,    32,    32,    77,    79,   101,    56,    54,    55,
     125,    61,   154,   152,   154,   154,   125,   154,    54,    84,
     132,   133,   103,    54,   125,    59,   158,    61,    87,   115,
     116,   117,   122,   123,    58,    60,   169,    48,   113,    85,
      95,    53,   119,   155,    83,    86,   128,    59,   158,   106,
      93,    54,    96,    57,    98,    99,   103,    57,    54,   158,
     102,    61,    52,    61,   148,    61,    54,    59,   103,   111,
     122,    61,    55,    61,    59,   158,    61,   115,   114,   119,
     120,   128,    59,    60,    54,   158,    52,    55,    57,   157,
     136,   152,   144,    38,   139,   117,    59,    61,   113,    54,
      55,    32,   107,   110,   115,   118,    99,   158,   125,    52,
     125,   149,   125,    54,   119,    61,   108,    55,   109,    51,
     141,   152,   145,    60,   140,    61,    32,    61,   125,   137,
      61,   154,   151,    61,   125,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    74,    75,    75,    76,    77,    75,    78,
      79,    75,    75,    80,    80,    82,    81,    83,    83,    85,
      84,    84,    86,    86,    87,    87,    87,    87,    87,    87,
      88,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    97,    97,    97,    97,    98,    98,    99,    99,    99,
     100,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   104,   105,   106,   104,   108,   107,   109,   107,   110,
     107,   112,   111,   113,   114,   113,   115,   116,   116,   117,
     117,   117,   118,   118,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   127,   127,   129,   128,   130,   128,   131,
     128,   132,   132,   133,   133,   135,   136,   137,   134,   138,
     139,   140,   134,   141,   141,   143,   144,   145,   142,   146,
     147,   148,   149,   142,   150,   151,   142,   152,   152,   153,
     153,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   156,   156,   157,   157,   158,   159,   159,   160,   160,
     161,   161,   162,   162,   163,   163,   164,   164,   164,   165,
     165,   165,   165,   165,   166,   166,   166,   167,   167,   167,
     168,   168,   168,   168,   169,   169,   170,   170,   170,   170,
     170,   170,   171,   171,   171,   171,   171,   172,   172,   172,
     172,   172,   173,   173,   173,   173,   174,   174
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     0,     0,     4,     0,
       0,     4,     1,     1,     1,     0,     4,     1,     2,     0,
       4,     2,     1,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       3,     2,     1,     2,     1,     1,     3,     1,     3,     2,
       5,     4,     2,     1,     3,     1,     3,     2,     1,     1,
       4,     3,     0,     0,     5,     0,     3,     0,     3,     0,
       2,     0,     3,     0,     0,     3,     1,     1,     3,     2,
       2,     1,     1,     3,     1,     3,     4,     1,     3,     2,
       1,     1,     2,     1,     3,     4,     3,     3,     2,     4,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     1,     0,     4,     0,     4,     0,
       3,     2,     1,     1,     2,     0,     0,     0,     9,     0,
       0,     0,     8,     0,     2,     0,     0,     0,     8,     0,
       0,     0,     0,    11,     0,     0,    11,     0,     1,     3,
       2,     2,     3,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     4,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     2,     1,     1,     1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 122 "../src/Analizador.y" /* yacc.c:1646  */
    {errorLinea = yylineno;}
#line 1725 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarElemento(&listaErroresSintacticos,"", "", errorLinea);}
#line 1731 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("Error sintactico en linea %d\n", yylineno);}
#line 1737 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "../src/Analizador.y" /* yacc.c:1646  */
    {errorLinea = yylineno;}
#line 1743 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarElemento(&listaErroresSintacticos,"", "", errorLinea);}
#line 1749 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("Error sintactico en linea %d\n", yylineno);}
#line 1755 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("\n\n \t---> Error lexico en linea %d\n", yylineno); insertarElemento(&listaErroresLexicos,tipoDeDato,(yyvsp[0].cadena),yylineno);}
#line 1761 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 132 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("declaracion_externa: definicion_de_funcion, %s \n",(yyvsp[0].cadena)); }
#line 1767 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 135 "../src/Analizador.y" /* yacc.c:1646  */
    {free(tipoDatoFuncion); tipoDatoFuncion = strdup((yyvsp[-1].cadena)) ;idFuncion = strdup((yyvsp[0].cadena)); lineaFuncion=yylineno;}
#line 1773 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 143 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("\nCONTADOR VALE %d\n",contadorPuntero);}
#line 1779 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "../src/Analizador.y" /* yacc.c:1646  */
    { while(contadorPuntero){
                   printf("\nCONTADOR VALE ///  %d\n",contadorPuntero);
                   tipoDeDato = realloc(tipoDeDato,strlen(tipoDeDato) + strlen("*") + 2); //el +2 por el /0
                   strcat(tipoDeDato, "*");
                   contadorPuntero--;
                 }  printf("\ntipoDatoFuncion:  %s, tipoDato %s\n",tipoDatoFuncion, tipoDeDato); 
                 if(tipoDatoFuncion && strcmp(tipoDatoFuncion,"")) {
                   insertarElemento(&listaIdentificadorFuncion,tipoDatoFuncion,idFuncion,yylineno); 
                   printf("\n\nSE insertoElemento a listaIdentificadorfuncion: %s, tipo: %s \n\n",tipoDatoFuncion,idFuncion); 
                   strcpy(tipoDatoFuncion,"");
                   }else if(strcmp(tipoDeDato,"")){insertarElemento(&listaIdentificadorVariable,tipoDeDato,id,yylineno);
                   printf("\n\nSE insertoElemento a listaIdentificadorVariable: %s, tipo: %s \n\n",tipoDeDato,id);}
                  }
#line 1797 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 159 "../src/Analizador.y" /* yacc.c:1646  */
    {strcpy(tipoDatoFuncion, ""); printf("lista_de_declaracion:      declaracion  %s\n",tipoDatoFuncion ); }
#line 1803 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 166 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("especificadores_de_declaracion:    especificador_de_tipo  %s\n",(yyvsp[0].cadena));}
#line 1809 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 174 "../src/Analizador.y" /* yacc.c:1646  */
    {;free(tipoDeDato);tipoDeDato=strdup((yyvsp[0].cadena));}
#line 1815 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "../src/Analizador.y" /* yacc.c:1646  */
    {free(tipoDeDato);tipoDeDato=strdup("signed");}
#line 1821 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 176 "../src/Analizador.y" /* yacc.c:1646  */
    {free(tipoDeDato);tipoDeDato=strdup("unsigned");}
#line 1827 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 186 "../src/Analizador.y" /* yacc.c:1646  */
    { printf("\nNombre del identificador: %s\n\n", (yyvsp[-4].cadena));}
#line 1833 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 188 "../src/Analizador.y" /* yacc.c:1646  */
    { printf("\nNombre del identificador: %s\n\n", (yyvsp[-1].cadena));}
#line 1839 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 242 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("\nflagFuncion = %d\n",flagFuncion);
 free(id);
id = strdup((yyvsp[0].cadena));}
#line 1847 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 249 "../src/Analizador.y" /* yacc.c:1646  */
    {  free(idFuncion); idFuncion= strdup(id); free(tipoDatoFuncion); tipoDatoFuncion = strdup(tipoDeDato);}
#line 1853 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 249 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("\n el idFuncion es: %s , tipod dato: %s   y el flagFuncion: %d \n",idFuncion, tipoDatoFuncion, flagFuncion); }
#line 1859 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 252 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncion=0;}
#line 1865 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 253 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncion=0;}
#line 1871 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 254 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncion=0;}
#line 1877 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 256 "../src/Analizador.y" /* yacc.c:1646  */
    {contadorPuntero++;}
#line 1883 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 260 "../src/Analizador.y" /* yacc.c:1646  */
    {contadorPuntero++;}
#line 1889 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 278 "../src/Analizador.y" /* yacc.c:1646  */
    {tipoDatoParametro = strdup((yyvsp[-1].cadena)); idParametro = strdup((yyvsp[0].cadena)); insertarElemento(&listaParametros,tipoDeDato,idParametro,yylineno);printf("\n\n Se inserto a listaParametros : %s de tipo: %s\n\n",idParametro,tipoDatoParametro);}
#line 1895 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 337 "../src/Analizador.y" /* yacc.c:1646  */
    { if(!flagSentencia) {insertarElemento(&listaFuncionesDefinidas,tipoDatoFuncion,idFuncion,lineaFuncion); ;printf("\n\n Se inserto a listaFuncionesDefinidas**: %s  de tipo: %s \n\n",idFuncion,tipoDatoFuncion);strcpy(tipoDatoFuncion,"");}}
#line 1901 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 338 "../src/Analizador.y" /* yacc.c:1646  */
    { if(!flagSentencia) {insertarElemento(&listaFuncionesDefinidas,tipoDatoFuncion,idFuncion,lineaFuncion);; printf("\n\n Se inserto a listaFuncionesDefinidas**: %s  de tipo: %s \n\n",idFuncion,tipoDatoFuncion);strcpy(tipoDatoFuncion,"");}}
#line 1907 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 339 "../src/Analizador.y" /* yacc.c:1646  */
    {if(!flagSentencia) {insertarElemento(&listaFuncionesDefinidas,tipoDatoFuncion,idFuncion,lineaFuncion);; printf("\n\n Se inserto a listaFuncionesDefinidas: %s  de tipo: %s \n\n",idFuncion,tipoDatoFuncion);strcpy(tipoDatoFuncion,"");}}
#line 1913 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 352 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarElemento(&listaDeIf,"", "if", yylineno);}
#line 1919 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 352 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 1925 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 352 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 1931 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 352 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("IF en linea %d\n", yylineno);}
#line 1937 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 353 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarElemento(&listaDeSwitch,"", "switch", yylineno);}
#line 1943 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 353 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 1949 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 353 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 1955 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 353 "../src/Analizador.y" /* yacc.c:1646  */
    {printf(" SWITCH en linea %d\n", yylineno);}
#line 1961 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 356 "../src/Analizador.y" /* yacc.c:1646  */
    {printf("if else");}
#line 1967 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 359 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarElemento(&listaDeWhile, "","while", yylineno);}
#line 1973 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 359 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 1979 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 359 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 1985 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 359 "../src/Analizador.y" /* yacc.c:1646  */
    {printf(" WHILE EN LINEA %d\n", yylineno);}
#line 1991 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 360 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarElemento(&listaDeDo,"", "do", yylineno);}
#line 1997 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 360 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 2003 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 360 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 2009 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 360 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarElemento(&listaDeWhile,"", "while del do ", yylineno);}
#line 2015 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 361 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarElemento(&listaDeFor,"", "for", yylineno);}
#line 2021 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 361 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 2027 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 361 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 2033 "Analizador.tab.c" /* yacc.c:1646  */
    break;


#line 2037 "Analizador.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 487 "../src/Analizador.y" /* yacc.c:1906  */


void yyerror (const char *msg) {
   //fprintf (stderr, "*** Error sintactico en la linea %d ***\n", yylineno);
}


int main(){
    #ifdef BISON_DEBUG
      yydebug = 1;
    #endif
 
    yyin = fopen("entrada.c", "r"); 
    if (!yyin){
        printf("No se encuentra el archivo de entrada \n"); 
        return -1;
    }
    
    printf("\n\n----------------------------------\n\n");
    yyparse();

    printf("\n\n----------------------------------\n\n");
    printf("\n- Lista de PALABRAS RESERVADAS:\n");
    mostrarLista(&listaDeIf,1);
    mostrarLista(&listaDeElse,1);
    mostrarLista(&listaDeDo,1);
    mostrarLista(&listaDeWhile,1);
    mostrarLista(&listaDeFor,1);
    mostrarLista(&listaDeSwitch,1);
    printf("\n\n\n- Lista de DECLARACIONES:\n");
    mostrarLista(&listaIdentificadorVariable,4);
    printf("\n\n\n- Lista de DECLARACIONES FUNCIONES:\n");
    mostrarLista(&listaIdentificadorFuncion,4);
    printf("\n\n\n- Lista de DEFINICIONES:\n");
    mostrarLista(&listaFuncionesDefinidas,5);
    //mostrarLista(&listaFuncionesFloat,1);
     printf("\n\n\n- Lista de PARAMETROS:\n");
    mostrarLista(&listaParametros,6);
    printf("\n\n\n- Lista de ERRORES LEXICOS:\n");
    mostrarLista(&listaErroresLexicos,2);
    printf("\n\n\n- Lista de ERRORES SINTACTICOS:\n");
    mostrarLista(&listaErroresSintacticos,3);    

    fclose(yyin);
    printf("\n\n----------------------------------\n\n");


    return 0;
}    
