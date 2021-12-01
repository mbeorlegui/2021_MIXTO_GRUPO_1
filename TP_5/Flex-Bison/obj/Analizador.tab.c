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
#line 1 "../src/Analizador.y" /* yacc.c:339  */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"
#include "tabla.h"
 
extern int yylineno;            // Numero de linea en que se encuentra
extern FILE* yyin; 
 
int yylex (void);
void yyerror (char const *s); 
int yywrap(){return(1);}
 
int contadorPuntero=0;          // Para contar los * de los identificadores
int flagError=0;                // Para saber si se produjo un error
char* tipoDeDato;                // Para imprimir el tipo de dato
char* idFuncion;                // Para imprimir el identificador 
char* tipoFuncion;              // Para imprimir el tipo de la funcion
char* nombreIdent;              // Para imprimir el nombre del identificador
char* nombreIdFuncion;          // Para imprimir el nombre de una funcion
int contadorDeVariables = 0;    // Para contar las variables
int flagFuncion=0;              // Toma el valor 1 cuando es definicion, y 0 cuando es declaracion de función
int flagSentencia = 0;           
char* tipo;
char* tipoDatoFuncion;
char* id;
int lineaFuncion=0;
char* tipoDatoParametro;
char* idParametro;
char* idAsignacion;
char* tipoDatoAsignacion;
int errorLinea = 0;
char* tipoDatoBinario;
int flagSuma = 0;
int flagOperacion = 0;
int flagDefinicion = 1;
int flagFuncionLlamada = 0;
int flagSentencia2 = 0;
 
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
 
TS tabla = {
  .l_Variables = NULL,
  .l_FuncionesDefinidas = NULL,
  .l_FuncionesDeclaradas = NULL
};
 
Error *listaDeErrores = NULL;
 
Variables variable;
Variables variableParametro;
Variables* lauxParametros = NULL;
Variables* lauxBinaria = NULL;
 
Funciones funcionDeclarada;
Funciones funcionDefinida;
 

#line 141 "Analizador.tab.c" /* yacc.c:339  */

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
#line 76 "../src/Analizador.y" /* yacc.c:355  */

  char cadena[30];
  int entero;
  float real;

#line 235 "Analizador.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALIZADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "Analizador.tab.c" /* yacc.c:358  */

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
#define YYLAST   1064

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  106
/* YYNRULES -- Number of rules.  */
#define YYNRULES  234
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  368

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
       0,   136,   136,   137,   137,   140,   141,   142,   142,   143,
     148,   149,   152,   152,   155,   156,   159,   184,   187,   188,
     191,   192,   193,   194,   195,   196,   199,   202,   203,   204,
     205,   206,   207,   210,   211,   214,   215,   216,   219,   220,
     223,   224,   227,   228,   231,   232,   235,   238,   239,   240,
     241,   244,   245,   248,   249,   250,   253,   254,   255,   258,
     259,   262,   263,   266,   267,   270,   274,   275,   276,   276,
     284,   284,   285,   285,   286,   286,   288,   288,   291,   292,
     292,   303,   306,   320,   336,   337,   338,   341,   342,   345,
     346,   347,   350,   351,   354,   355,   358,   359,   360,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   374,   377,
     378,   379,   380,   381,   382,   386,   387,   388,   391,   392,
     395,   395,   407,   408,   409,   412,   413,   417,   418,   421,
     421,   421,   421,   421,   422,   422,   422,   422,   422,   424,
     425,   428,   428,   428,   428,   428,   429,   429,   429,   429,
     429,   430,   430,   430,   430,   433,   434,   439,   440,   441,
     442,   443,   446,   447,   450,   451,   451,   458,   459,   460,
     461,   462,   465,   466,   469,   471,   472,   475,   476,   479,
     480,   483,   484,   487,   488,   491,   492,   493,   496,   497,
     498,   499,   500,   503,   504,   505,   508,   509,   509,   531,
     534,   535,   536,   537,   540,   541,   544,   545,   546,   547,
     548,   549,   553,   554,   555,   556,   557,   560,   561,   562,
     563,   563,   564,   565,   566,   568,   569,   572,   580,   581,
     587,   590,   591,   594,   595
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
  "input", "$@1", "line", "$@2", "declaracion_externa",
  "definicion_de_funcion", "$@3", "opcional_lista_de_declaracion",
  "declaracion", "lista_de_declaracion", "especificadores_de_declaracion",
  "especificador_categoria_almacenamiento", "especificador_de_tipo",
  "calificador_de_tipo", "especificador_estructura_o_union",
  "estructura_o_union", "lista_declaraciones_struct",
  "lista_declaradores_init", "declarador_init", "declaracion_struct",
  "lista_calificador_especificador", "lista_declaradores_struct",
  "declarador_struct", "especificador_enum", "lista_de_enumerador",
  "enumerador", "declarador", "declarador_directo", "$@4",
  "lista_op_parentesis", "$@5", "$@6", "$@7", "apuntador", "$@8",
  "apuntador_aux", "$@9", "lista_tipos_de_parametro",
  "lista_de_parametros", "declaracion_de_parametro",
  "lista_de_identificadores", "inicializador", "lista_de_inicializadores",
  "nombre_de_tipo", "declarador_abstracto", "declarador_abstracto_directo",
  "nombre_typedef", "sentencia", "sentencia_etiquetada",
  "sentencia_expresion", "sentencia_compuesta", "$@10",
  "sentencia_compuesta_derivado", "opcional_sentencia_compuesta",
  "lista_de_sentencias", "sentencia_de_seleccion", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "opcionElse",
  "sentencia_de_iteracion", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24",
  "$@25", "$@26", "$@27", "$@28", "$@29", "opcional_expresion",
  "sentencia_de_salto", "expresion", "expresion_de_asignacion", "$@30",
  "operador_de_asignacion", "expresion_condicional", "expresion_constante",
  "expresion_logica_or", "expresion_logica_and", "expresion_or_inclusivo",
  "expresion_or_exclusivo", "expresion_and", "expresion_de_igualdad",
  "expresion_relacional", "expresion_de_corrimiento", "expresion_aditiva",
  "$@31", "expresion_multiplicativa", "expresion_cast", "expresion_unaria",
  "operador_unario", "expresion_posfija", "$@32",
  "opcional_lista_expresiones_argumento", "expresion_primaria",
  "lista_expresiones_argumento", "constante", YY_NULLPTR
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

#define YYPACT_NINF -270

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-270)))

#define YYTABLE_NINF -198

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -270,    40,  -270,   341,  -270,    13,  -270,  -270,  -270,  -270,
      30,  -270,  -270,   950,    11,  -270,  -270,   972,   972,  -270,
    -270,    19,  -270,   993,  -270,     2,  -270,  -270,  -270,  -270,
     813,    58,  -270,  -270,  -270,  -270,  -270,   698,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,   139,   766,   766,   766,
    -270,    84,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,    56,  -270,  -270,    12,    89,    50,    54,    98,    14,
      33,   198,   188,   -31,  -270,   106,   950,    21,  -270,  -270,
     123,   133,   154,   160,  -270,  -270,   143,  -270,   641,   950,
    -270,  -270,   641,   698,  -270,   155,  -270,   158,   169,  -270,
     172,  -270,    66,  -270,   410,   189,   189,   120,   175,   -34,
    -270,  -270,  -270,   122,  -270,   134,    68,   220,  -270,  -270,
    -270,   202,   189,  -270,   950,   950,   950,   950,   950,   950,
     950,   950,   950,   950,   950,   950,   950,   950,   950,   950,
     196,   950,   950,   950,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,   226,   950,  -270,   239,  -270,  -270,   160,
     218,   185,  -270,   641,  -270,  -270,   221,   950,   950,   950,
     641,   950,  -270,  -270,  -270,   479,   139,  -270,  -270,   533,
    -270,  -270,   835,   215,    76,  -270,   121,   950,  -270,   233,
    -270,    -4,   856,   241,   886,   223,    68,   189,    51,  -270,
      -7,  -270,    89,   151,    50,    54,    98,    14,    33,    33,
     198,   198,   198,   198,   188,   188,   -31,   950,  -270,  -270,
    -270,   950,  -270,    47,   907,  -270,   206,   950,  -270,   160,
    -270,  -270,   229,   234,   229,   229,  -270,   229,  -270,  -270,
    -270,   587,   231,  -270,  -270,  -270,   230,  -270,    64,   224,
     235,  -270,   232,   121,   929,   731,  -270,  -270,  -270,  -270,
     856,  -270,  -270,  -270,   241,  -270,  -270,   236,   747,   779,
    -270,  -270,   950,   147,  -270,   242,   950,   -31,  -270,  -270,
    -270,  -270,  -270,   -25,  -270,  -270,  -270,   237,   950,   240,
     253,   243,  -270,  -270,  -270,    75,  -270,  -270,   766,  -270,
    -270,   246,  -270,   245,   233,  -270,   210,  -270,  -270,  -270,
    -270,   248,  -270,   247,  -270,  -270,  -270,    -7,   950,  -270,
     950,  -270,  -270,   244,  -270,   250,  -270,  -270,  -270,  -270,
    -270,  -270,   783,  -270,   252,   268,   254,  -270,  -270,  -270,
     641,   950,   641,   950,   641,  -270,  -270,  -270,  -270,  -270,
     256,   255,  -270,   229,  -270,   641,  -270,  -270,  -270,   257,
    -270,  -270,  -270,   641,   259,  -270,  -270,  -270
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     3,     1,     0,     7,     0,    34,    27,    28,    29,
       0,    26,    33,     0,     0,    38,    39,     0,     0,   234,
     233,   227,   229,     0,   129,     0,   151,   141,   146,   134,
       0,     0,     9,   213,   214,   119,   120,     0,   108,   212,
     215,   216,     4,     5,    10,    11,     0,    21,    23,    25,
      30,     0,    31,    32,     6,   109,   110,   111,   112,   113,
     114,     0,   162,   164,   172,   175,   177,   179,   181,   183,
     185,   188,   193,   196,   200,   204,     0,   206,   217,   228,
       0,     0,    58,     0,   227,   174,     0,   204,     0,     0,
     208,   207,     0,     0,   210,     0,   159,     0,     0,   147,
       0,   161,     0,   158,     0,    48,    50,    95,     0,     0,
      65,    76,    17,     0,    42,    12,    64,     0,    20,    22,
      24,    37,     0,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   167,   170,   168,   171,   165,
     209,   224,   223,     0,     0,   220,     0,     8,   157,     0,
      61,     0,    59,     0,   117,   115,     0,     0,   155,     0,
       0,     0,   160,   124,    18,     0,     0,   127,   121,     0,
      47,    49,     0,     0,    96,    94,    98,     0,   230,    78,
      16,     0,     0,     0,     0,     0,    63,     0,     0,    40,
       0,   163,   176,     0,   178,   180,   182,   184,   186,   187,
     192,   191,   189,   190,   194,   195,   199,     0,   201,   202,
     203,     0,   222,     0,     0,   218,     0,     0,    57,     0,
     116,   211,   130,     0,   156,   142,   148,   135,   126,    19,
     122,     0,    44,   123,   128,   103,     0,   107,    86,     0,
      81,    82,     0,    97,     0,     0,   205,    79,    77,    43,
       0,    45,    89,    13,     0,    14,    67,     0,    74,     0,
      36,    41,     0,     0,    51,    53,     0,   198,   166,   219,
     225,   231,   221,     0,    56,    62,    60,     0,   155,     0,
       0,     0,   125,   101,    84,    96,    85,   105,     0,    99,
     102,     0,   106,     0,    78,    92,     0,    15,    66,    87,
      69,     0,    70,    72,    35,    55,    46,     0,     0,   173,
       0,   226,   131,     0,   143,     0,   136,    83,   100,   104,
      80,    90,     0,    75,     0,     0,     0,    52,    54,   232,
       0,   155,     0,     0,     0,    91,    93,    71,    88,    73,
     139,     0,   144,   149,   137,     0,   132,   152,   145,     0,
     138,   140,   133,     0,     0,   153,   150,   154
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,     8,
     124,    -1,  -270,   -32,   -28,  -270,  -270,   125,  -270,   128,
    -182,    -2,  -270,     3,  -270,   162,    94,   -39,  -107,  -270,
    -270,  -270,  -270,  -270,   -85,  -270,    20,  -270,  -242,  -270,
      27,  -270,  -246,  -270,   238,  -168,  -172,  -270,    -3,  -270,
    -270,  -169,  -270,  -270,  -270,   152,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -269,  -270,
     -29,  -104,  -270,  -270,   -10,  -145,  -270,   201,   203,   200,
     204,   199,   137,    78,   142,  -270,  -133,   -72,    16,  -270,
    -270,  -270,  -270,  -270,  -270,  -270
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     3,    42,    80,    43,    44,   193,   263,   174,
     175,   176,    47,    48,    49,    50,    51,   198,   113,   114,
     199,   200,   273,   274,    52,   161,   162,   242,   116,   195,
     310,   334,   336,   311,   117,   189,   258,   304,   249,   250,
     251,   313,   261,   306,   108,   185,   186,    53,   177,    55,
      56,    57,   104,   178,   240,   179,    58,    95,   287,   340,
     362,   100,   291,   344,   360,   356,    59,    98,   289,   342,
     358,    99,   170,   290,   359,    97,   363,   367,   233,    60,
      61,    62,   221,   149,    63,    86,    64,    65,    66,    67,
      68,    69,    70,    71,    72,   140,    73,    74,    75,    76,
      77,   224,   282,    78,   283,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   102,    46,    85,   150,   105,   216,   115,   109,   106,
     196,    45,   253,   303,   305,   252,   271,   141,   142,   323,
     201,   124,   184,   125,   265,   110,   312,   188,   110,    87,
     320,   131,   132,    90,    91,   107,   321,   246,   143,    94,
       2,   111,   151,   152,   111,    81,   118,   119,   120,   267,
     272,   153,   133,   134,    96,     6,     7,     8,     9,    10,
     109,   105,    82,    12,   109,   106,    15,    16,    88,   218,
     219,   220,   351,   105,   105,   126,    92,   106,   106,   154,
     296,   155,   285,    83,   277,   164,   346,   271,   262,   165,
     105,   107,    87,   156,   106,   307,   110,   203,   184,   127,
     135,   136,   124,   180,   181,   270,   279,   110,   123,   301,
     103,   124,   111,    38,   128,   256,   121,   278,   172,   129,
     281,   124,   182,   253,   183,   223,   194,   315,   -68,   144,
     145,   146,   147,   182,   182,   183,   183,   122,   232,   234,
     235,    87,   237,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,   262,    87,    87,    87,
     230,   275,   148,   295,   130,   105,   105,   236,   111,   106,
     106,   110,    85,   338,   190,   157,   244,   191,   182,   254,
     183,   255,   248,   239,    85,   158,   -44,   111,   196,   -44,
     192,   112,   160,     6,     7,     8,     9,    10,    87,   316,
     163,    12,   317,    87,    15,    16,   124,   159,   276,   294,
      87,   210,   211,   212,   213,   167,   339,    85,   168,     6,
       7,     8,     9,    10,    11,   137,   138,    12,   262,   169,
      15,    16,   171,    87,  -197,   139,   187,   105,   244,   228,
     229,   106,   217,    87,    85,     6,     7,     8,     9,    10,
      11,    38,   110,    12,   248,   197,    15,    16,   222,   234,
     284,   229,    85,   111,   331,   332,   319,   248,   208,   209,
      87,   225,   239,   182,   227,   183,   247,    38,   275,   214,
     215,   257,   231,   268,   124,   297,   288,   192,    87,   293,
     298,   325,    87,   299,    36,   308,   341,   248,   322,   318,
     348,   324,   335,    38,   326,   328,   329,   355,    85,   333,
     343,   366,   234,   347,   353,   349,   357,   264,   364,   259,
     337,   226,   269,   286,   330,   327,   202,   241,   205,   207,
     204,   166,     0,   206,    87,     0,     0,   350,     0,   352,
       0,   354,     4,     0,     5,     6,     7,     8,     9,    10,
      11,     0,   361,    12,    13,    14,    15,    16,     0,     0,
     365,     0,    17,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,     0,    33,    34,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,    37,     0,    38,     0,     0,     0,    39,     0,     0,
       0,    40,    41,     5,     6,     7,     8,     9,    10,    11,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,     0,    33,    34,     0,     0,
       0,     0,    35,    36,   173,     0,     0,     0,     0,     0,
      37,     0,    38,     0,     0,     0,    39,     0,     0,     0,
      40,    41,     5,     6,     7,     8,     9,    10,    11,     0,
       0,    12,    13,    14,    15,    16,     0,     0,     0,     0,
      17,    18,     0,     0,     0,     0,     0,     0,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,     0,    33,    34,     0,     0,     0,
       0,    35,    36,   238,     0,     0,     5,     0,     0,    37,
       0,    38,     0,     0,     0,    39,    13,    14,     0,    40,
      41,     0,     0,     0,    17,    18,     0,     0,     0,     0,
       0,     0,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,     0,     0,    33,
      34,     0,     0,     0,     0,    35,    36,   243,     0,     0,
       5,     0,     0,    37,     0,     0,     0,     0,     0,    39,
      13,    14,     0,    40,    41,     0,     0,     0,    17,    18,
       0,     0,     0,     0,     0,     0,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,     0,    33,    34,     0,     0,     0,     0,    35,
      36,   292,     0,     0,     5,     0,     0,    37,     0,     0,
       0,     0,     0,    39,    13,    14,     0,    40,    41,     0,
       0,     0,    17,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,     0,    33,    34,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,    37,     6,     7,     8,     9,    10,    39,     0,     0,
      12,    40,    41,    15,    16,     0,     0,     0,     0,    17,
      18,     0,     0,     0,     0,     0,     0,    19,     0,    20,
      84,    22,    23,     0,     0,     6,     7,     8,     9,    10,
      11,     0,     0,    12,    33,    34,    15,    16,     0,     0,
       0,     6,     7,     8,     9,    10,    11,     0,    37,    12,
      38,     0,    15,    16,    39,     0,     0,     0,    40,    41,
       6,     7,     8,     9,    10,    11,     0,     0,    12,   309,
       0,    15,    16,     6,     7,     8,     9,    10,     0,     0,
       0,    12,   302,    38,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,     0,     0,     0,    38,
       0,     0,    19,     0,    20,    84,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    33,
      34,     0,     0,   314,    17,    18,   260,   345,     0,     0,
       0,    38,    19,    37,    20,    84,    22,    23,     0,    39,
       0,     0,     0,    40,    41,     0,    17,    18,     0,    33,
      34,     0,     0,     0,    19,   101,    20,    84,    22,    23,
       0,     0,     0,    37,     0,     0,     0,    17,    18,    39,
       0,    33,    34,    40,    41,    19,     0,    20,    84,    22,
      23,     0,     0,     0,   245,    37,     0,     0,     0,     0,
       0,    39,    33,    34,     0,    40,    41,    17,    18,   260,
       0,     0,     0,     0,     0,    19,    37,    20,    84,    22,
      23,     0,    39,     0,     0,     0,    40,    41,    17,    18,
       0,     0,    33,    34,     0,     0,    19,     0,    20,    84,
      22,    23,     0,     0,     0,   266,    37,     0,     0,     0,
      17,    18,    39,    33,    34,     0,    40,    41,    19,     0,
      20,    84,    22,    23,     0,     0,     0,    37,   280,     0,
       0,    17,    18,    39,     0,    33,    34,    40,    41,    19,
       0,    20,    84,    22,    23,     0,     0,     0,   300,    37,
       0,     0,     0,    17,    18,    39,    33,    34,     0,    40,
      41,    19,     0,    20,    84,    22,    23,     0,     0,     0,
      37,     0,     0,     0,    17,    18,    39,     0,    33,    34,
      40,    41,    19,     0,    20,    84,    22,    23,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,    39,    33,
      34,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,     0,    39,
       0,     0,     0,    40,    41
};

static const yytype_int16 yycheck[] =
{
       3,    30,     3,    13,    76,    37,   139,    46,    37,    37,
     117,     3,   184,   255,   260,   183,   198,    48,    49,   288,
     124,    55,   107,    11,   193,    32,   268,    61,    32,    13,
      55,    17,    18,    17,    18,    37,    61,   182,    69,    23,
       0,    48,    21,    22,    48,    32,    47,    48,    49,   194,
      57,    30,    19,    20,    52,     4,     5,     6,     7,     8,
      89,    93,    32,    12,    93,    93,    15,    16,    57,   141,
     142,   143,   341,   105,   106,    63,    57,   105,   106,    58,
     248,    60,   227,    53,   217,    88,   332,   269,   192,    92,
     122,    93,    76,    72,   122,   264,    32,   126,   183,    10,
      67,    68,    55,   105,   106,    54,    59,    32,    52,   254,
      52,    55,    48,    62,    64,   187,    32,   221,    52,    65,
     224,    55,    58,   295,    60,   154,    58,   272,    60,    23,
      24,    25,    26,    58,    58,    60,    60,    53,   167,   168,
     169,   125,   171,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   260,   141,   142,   143,
     163,   200,    56,   248,    66,   197,   198,   170,    48,   197,
     198,    32,   182,   318,    52,    52,   179,    55,    58,    58,
      60,    60,   183,   175,   194,    52,    52,    48,   295,    55,
      56,    52,    32,     4,     5,     6,     7,     8,   182,    52,
      57,    12,    55,   187,    15,    16,    55,    53,    57,   248,
     194,   133,   134,   135,   136,    60,   320,   227,    60,     4,
       5,     6,     7,     8,     9,    27,    28,    12,   332,    60,
      15,    16,    60,   217,    46,    47,    61,   269,   241,    54,
      55,   269,    46,   227,   254,     4,     5,     6,     7,     8,
       9,    62,    32,    12,   255,    53,    15,    16,    32,   288,
      54,    55,   272,    48,    54,    55,   276,   268,   131,   132,
     254,    32,   264,    58,    56,    60,    61,    62,   317,   137,
     138,    48,    61,    60,    55,    61,    52,    56,   272,    59,
      55,    38,   276,    61,    53,    59,    52,   298,    61,    57,
      32,    61,    55,    62,    61,    59,    61,    51,   318,    61,
      60,    52,   341,    61,   343,    61,    61,   193,    61,   191,
     317,   159,   197,   229,   304,   298,   125,   175,   128,   130,
     127,    93,    -1,   129,   318,    -1,    -1,   340,    -1,   342,
      -1,   344,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,   355,    12,    13,    14,    15,    16,    -1,    -1,
     363,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    62,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    70,    71,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    -1,    -1,     3,    -1,    -1,    60,
      -1,    62,    -1,    -1,    -1,    66,    13,    14,    -1,    70,
      71,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,
       3,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      13,    14,    -1,    70,    71,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    -1,    -1,     3,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    66,    13,    14,    -1,    70,    71,    -1,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    60,     4,     5,     6,     7,     8,    66,    -1,    -1,
      12,    70,    71,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,
      32,    33,    34,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    46,    47,    15,    16,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    60,    12,
      62,    -1,    15,    16,    66,    -1,    -1,    -1,    70,    71,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    32,
      -1,    15,    16,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    61,    62,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    62,
      -1,    -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    46,
      47,    -1,    -1,    54,    21,    22,    53,    54,    -1,    -1,
      -1,    62,    29,    60,    31,    32,    33,    34,    -1,    66,
      -1,    -1,    -1,    70,    71,    -1,    21,    22,    -1,    46,
      47,    -1,    -1,    -1,    29,    52,    31,    32,    33,    34,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    21,    22,    66,
      -1,    46,    47,    70,    71,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    66,    46,    47,    -1,    70,    71,    21,    22,    53,
      -1,    -1,    -1,    -1,    -1,    29,    60,    31,    32,    33,
      34,    -1,    66,    -1,    -1,    -1,    70,    71,    21,    22,
      -1,    -1,    46,    47,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      21,    22,    66,    46,    47,    -1,    70,    71,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    60,    61,    -1,
      -1,    21,    22,    66,    -1,    46,    47,    70,    71,    29,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    21,    22,    66,    46,    47,    -1,    70,
      71,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    21,    22,    66,    -1,    46,    47,
      70,    71,    29,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    46,
      47,    -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    70,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,     0,    75,     1,     3,     4,     5,     6,     7,
       8,     9,    12,    13,    14,    15,    16,    21,    22,    29,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    46,    47,    52,    53,    60,    62,    66,
      70,    71,    76,    78,    79,    82,    84,    85,    86,    87,
      88,    89,    97,   120,   121,   122,   123,   124,   129,   139,
     152,   153,   154,   157,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   169,   170,   171,   172,   173,   176,   178,
      77,    32,    32,    53,    32,   157,   158,   171,    57,    60,
     171,   171,    57,    60,   171,   130,    52,   148,   140,   144,
     134,    52,   153,    52,   125,    86,    87,    94,   117,   153,
      32,    48,    52,    91,    92,   100,   101,   107,    84,    84,
      84,    32,    53,    52,    55,    11,    63,    10,    64,    65,
      66,    17,    18,    19,    20,    67,    68,    27,    28,    47,
     168,    48,    49,    69,    23,    24,    25,    26,    56,   156,
     170,    21,    22,    30,    58,    60,    72,    52,    52,    53,
      32,    98,    99,    57,   121,   121,   117,    60,    60,    60,
     145,    60,    52,    54,    82,    83,    84,   121,   126,   128,
      94,    94,    58,    60,   107,   118,   119,    61,    61,   108,
      52,    55,    56,    80,    58,   102,   101,    53,    90,    93,
      94,   154,   160,   153,   161,   162,   163,   164,   165,   165,
     166,   166,   166,   166,   167,   167,   169,    46,   170,   170,
     170,   155,    32,   153,   174,    32,    98,    56,    54,    55,
     121,    61,   153,   151,   153,   153,   121,   153,    54,    82,
     127,   128,   100,    54,   121,    59,   158,    61,    84,   111,
     112,   113,   118,   119,    58,    60,   170,    48,   109,    92,
      53,   115,   154,    81,    83,   124,    59,   158,    60,    90,
      54,    93,    57,    95,    96,   100,    57,   169,   154,    59,
      61,   154,   175,   177,    54,   158,    99,   131,    52,   141,
     146,   135,    54,    59,   100,   107,   118,    61,    55,    61,
      59,   158,    61,   111,   110,   115,   116,   124,    59,    32,
     103,   106,   111,   114,    54,   158,    52,    55,    57,   157,
      55,    61,    61,   151,    61,    38,    61,   113,    59,    61,
     109,    54,    55,    61,   104,    55,   105,    96,   158,   154,
     132,    52,   142,    60,   136,    54,   115,    61,    32,    61,
     121,   151,   121,   153,   121,    51,   138,    61,   143,   147,
     137,   121,   133,   149,    61,   121,    52,   150
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    74,    76,    76,    77,    76,    76,
      78,    78,    80,    79,    81,    81,    82,    82,    83,    83,
      84,    84,    84,    84,    84,    84,    85,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    93,    94,    94,    94,
      94,    95,    95,    96,    96,    96,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   101,   102,   101,
     104,   103,   105,   103,   106,   103,   108,   107,   109,   110,
     109,   111,   112,   112,   113,   113,   113,   114,   114,   115,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   121,
     121,   121,   121,   121,   121,   122,   122,   122,   123,   123,
     125,   124,   126,   126,   126,   127,   127,   128,   128,   130,
     131,   132,   133,   129,   134,   135,   136,   137,   129,   138,
     138,   140,   141,   142,   143,   139,   144,   145,   146,   147,
     139,   148,   149,   150,   139,   151,   151,   152,   152,   152,
     152,   152,   153,   153,   154,   155,   154,   156,   156,   156,
     156,   156,   157,   157,   158,   159,   159,   160,   160,   161,
     161,   162,   162,   163,   163,   164,   164,   164,   165,   165,
     165,   165,   165,   166,   166,   166,   167,   168,   167,   167,
     169,   169,   169,   169,   170,   170,   171,   171,   171,   171,
     171,   171,   172,   172,   172,   172,   172,   173,   173,   173,
     174,   173,   173,   173,   173,   175,   175,   176,   176,   176,
     176,   177,   177,   178,   178
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     3,     1,     1,     0,     3,     1,
       1,     1,     0,     4,     1,     2,     3,     2,     1,     2,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     3,     2,     1,     2,
       1,     1,     3,     1,     3,     2,     5,     4,     2,     1,
       3,     1,     3,     2,     1,     1,     4,     3,     0,     4,
       0,     3,     0,     3,     0,     2,     0,     3,     0,     0,
       3,     1,     1,     3,     2,     2,     1,     1,     3,     1,
       3,     4,     1,     3,     2,     1,     1,     2,     1,     3,
       4,     3,     3,     2,     4,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     1,
       0,     3,     2,     2,     1,     2,     1,     1,     2,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     9,     0,
       2,     0,     0,     0,     0,     9,     0,     0,     0,     0,
      11,     0,     0,     0,    12,     0,     1,     3,     2,     2,
       3,     2,     1,     3,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     5,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     0,     4,     3,
       1,     3,     3,     3,     1,     4,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     3,     4,
       0,     4,     3,     2,     2,     1,     2,     1,     1,     1,
       3,     1,     3,     1,     1
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
        case 3:
#line 137 "../src/Analizador.y" /* yacc.c:1646  */
    {lauxParametros = NULL;}
#line 1779 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 142 "../src/Analizador.y" /* yacc.c:1646  */
    {errorLinea = yylineno;}
#line 1785 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 142 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarErrorNoLexico(&listaDeErrores, 1, "", yylineno);}
#line 1791 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarErrorLexico(&listaDeErrores,(yyvsp[0].cadena)[0], yylineno);}
#line 1797 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 152 "../src/Analizador.y" /* yacc.c:1646  */
    {free(tipoDatoFuncion); tipoDatoFuncion = strdup((yyvsp[-1].cadena)); idFuncion = strdup((yyvsp[0].cadena)); lineaFuncion=yylineno;}
#line 1803 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "../src/Analizador.y" /* yacc.c:1646  */
    { 
                  while(contadorPuntero){
                   tipoDeDato = realloc(tipoDeDato,strlen(tipoDeDato) + strlen("*") + 2); //el +2 por el /0
                   strcat(tipoDeDato, "*");
                   contadorPuntero--;
                 } 
 
                 if(tipoDatoFuncion && strcmp(tipoDatoFuncion,"")) {
                    insertarElemento(&listaIdentificadorFuncion,tipoDatoFuncion,idFuncion,yylineno); 
                    funcionDeclarada.nombreFuncion = strdup(idFuncion);
                    funcionDeclarada.tipoFuncion = strdup(tipoDatoFuncion);
                    agregarFuncionDeclaradaATablaSinRepetir(&tabla, funcionDeclarada, &listaDeErrores, &lauxParametros, yylineno);
                    lauxParametros = NULL;
                    free(tipoDatoFuncion);
                    tipoDatoFuncion = strdup("");
 
                  }else if(strcmp(tipoDeDato,"")){
                      insertarElemento(&listaIdentificadorVariable,tipoDeDato,id,yylineno);
                      variable.nombre = strdup(id);
                      variable.tipo = strdup(tipoDeDato);
                      variable.linea = yylineno; 
                      agregarVariableATablaSinRepetir(&tabla, variable, &listaDeErrores);
                    }
                    lauxParametros = NULL;
                  }
#line 1833 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 187 "../src/Analizador.y" /* yacc.c:1646  */
    {free(tipoDatoFuncion); tipoDatoFuncion = strdup("");}
#line 1839 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 202 "../src/Analizador.y" /* yacc.c:1646  */
    {free(tipoDeDato);tipoDeDato=strdup((yyvsp[0].cadena));}
#line 1845 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 203 "../src/Analizador.y" /* yacc.c:1646  */
    {free(tipoDeDato);tipoDeDato=strdup("signed");}
#line 1851 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 204 "../src/Analizador.y" /* yacc.c:1646  */
    {free(tipoDeDato);tipoDeDato=strdup("unsigned");}
#line 1857 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 270 "../src/Analizador.y" /* yacc.c:1646  */
    {
                      free(id);
                      id = strdup((yyvsp[0].cadena));
                    }
#line 1866 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 276 "../src/Analizador.y" /* yacc.c:1646  */
    { 
                    free(idFuncion);
                    idFuncion= strdup(id); 
                    free(tipoDatoFuncion);
                    tipoDatoFuncion = strdup(tipoDeDato); }
#line 1876 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 284 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncion=0;}
#line 1882 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 285 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncion=0;}
#line 1888 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 286 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncion=0;}
#line 1894 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 288 "../src/Analizador.y" /* yacc.c:1646  */
    {contadorPuntero++;}
#line 1900 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 292 "../src/Analizador.y" /* yacc.c:1646  */
    {contadorPuntero++;}
#line 1906 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 306 "../src/Analizador.y" /* yacc.c:1646  */
    {
                      tipoDatoParametro = strdup((yyvsp[0].cadena)); 
                      idParametro = strdup((yyvsp[0].cadena)); 
                      insertarElemento(&listaParametros,tipoDeDato,idParametro,yylineno);
                      variable.nombre = strdup(id);
                      variable.tipo = strdup(tipoDatoParametro);
                      variable.linea = yylineno;
                      if(flagDefinicion){
                        insertarVariable(&lauxParametros, variable.nombre, tipoDatoParametro, yylineno); 
                      } else{
                        insertarVariable(&lauxParametros, NULL, tipoDatoParametro, yylineno); 
                      }
                      flagDefinicion = 1;
                    }
#line 1925 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 320 "../src/Analizador.y" /* yacc.c:1646  */
    {
                      tipoDatoParametro = strdup((yyvsp[0].cadena)); 
                      idParametro = strdup((yyvsp[0].cadena)); 
                      insertarElemento(&listaParametros,tipoDeDato,idParametro,yylineno);
                      variable.nombre = strdup(id);
                      variable.tipo = strdup(tipoDatoParametro);
                      variable.linea = yylineno;
                      if(flagDefinicion){
                        insertarVariable(&lauxParametros, variable.nombre, tipoDatoParametro, yylineno); 
                      } else{
                        insertarVariable(&lauxParametros, NULL, tipoDatoParametro, yylineno); 
                      }
                      flagDefinicion = 1;
                    }
#line 1944 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 341 "../src/Analizador.y" /* yacc.c:1646  */
    {existeVariableEnTabla(&tabla, (yyvsp[0].cadena), yylineno, &listaDeErrores);}
#line 1950 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 342 "../src/Analizador.y" /* yacc.c:1646  */
    {existeVariableEnTabla(&tabla, (yyvsp[0].cadena), yylineno, &listaDeErrores);}
#line 1956 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 386 "../src/Analizador.y" /* yacc.c:1646  */
    {existeVariableEnTabla(&tabla, (yyvsp[-2].cadena), yylineno, &listaDeErrores);}
#line 1962 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 395 "../src/Analizador.y" /* yacc.c:1646  */
    { if(!flagSentencia) {
                        agregarListaDeVariablesATablaSinRepetir(&tabla, lauxParametros, &listaDeErrores);
                        insertarElemento(&listaFuncionesDefinidas,tipoDatoFuncion,idFuncion,lineaFuncion);
                        funcionDefinida.nombreFuncion = strdup(idFuncion);
                        funcionDefinida.tipoFuncion = strdup(tipoDatoFuncion);
                        agregarFuncionDefinidaATablaSinRepetir(&tabla, funcionDefinida, &listaDeErrores, &lauxParametros, yylineno);
                        lauxParametros = NULL;
                        free(tipoDatoFuncion);
                        tipoDatoFuncion = strdup(""); }
                    }
#line 1977 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 421 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia2=1;}
#line 1983 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 421 "../src/Analizador.y" /* yacc.c:1646  */
    {if(flagFuncionLlamada==1){existeVariableEnTabla(&tabla, idAsignacion, yylineno, &listaDeErrores);}}
#line 1989 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 421 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 1995 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 421 "../src/Analizador.y" /* yacc.c:1646  */
    { flagSentencia=0; }
#line 2001 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 421 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncionLlamada=0;}
#line 2007 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 422 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia2=1;}
#line 2013 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 422 "../src/Analizador.y" /* yacc.c:1646  */
    {if(flagFuncionLlamada==1){existeVariableEnTabla(&tabla, idAsignacion, yylineno, &listaDeErrores);}}
#line 2019 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 422 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 2025 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 422 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 2031 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 422 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncionLlamada=0;}
#line 2037 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 428 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia2=1;}
#line 2043 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 428 "../src/Analizador.y" /* yacc.c:1646  */
    {if(flagFuncionLlamada==1){existeVariableEnTabla(&tabla, idAsignacion, yylineno, &listaDeErrores);}}
#line 2049 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 428 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 2055 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 428 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 2061 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 428 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncionLlamada=0;}
#line 2067 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 429 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia2=1;}
#line 2073 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 429 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 2079 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 429 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 2085 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 429 "../src/Analizador.y" /* yacc.c:1646  */
    {if(flagFuncionLlamada==1){existeVariableEnTabla(&tabla, idAsignacion, yylineno, &listaDeErrores);}}
#line 2091 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 429 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncionLlamada=0;}
#line 2097 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 430 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia2=1;}
#line 2103 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 430 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=1;}
#line 2109 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 430 "../src/Analizador.y" /* yacc.c:1646  */
    {flagSentencia=0;}
#line 2115 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 430 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncionLlamada=0;}
#line 2121 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 434 "../src/Analizador.y" /* yacc.c:1646  */
    {if(flagFuncionLlamada==1){existeVariableEnTabla(&tabla, idAsignacion, yylineno, &listaDeErrores);}}
#line 2127 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 439 "../src/Analizador.y" /* yacc.c:1646  */
    { existeVariableEnTabla(&tabla, (yyvsp[-1].cadena), yylineno, &listaDeErrores); }
#line 2133 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 442 "../src/Analizador.y" /* yacc.c:1646  */
    { if(flagOperacion == 1){existeVariableEnTabla(&tabla, (yyvsp[-1].cadena), yylineno, &listaDeErrores);} flagOperacion = 0;}
#line 2139 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 451 "../src/Analizador.y" /* yacc.c:1646  */
    {
                         if(strcmp((yyvsp[-1].cadena),idAsignacion)){
                          insertarErrorNoLexico(&listaDeErrores, 10, "", yylineno);
                         }
                         }
#line 2149 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 503 "../src/Analizador.y" /* yacc.c:1646  */
    { if(flagSuma){ variablesOperablesEntreSi(lauxBinaria, yylineno, &listaDeErrores); lauxBinaria = NULL; flagSuma = 0;}}
#line 2155 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 509 "../src/Analizador.y" /* yacc.c:1646  */
    {
                      if(!flagFuncion && !strcmp(idAsignacion,"")){
                        free(tipoDatoBinario);
                        tipoDatoBinario = strdup(buscarTipoDatoVariableEnTabla(&tabla, idAsignacion, yylineno , &listaDeErrores));
                        insertarVariable(&lauxBinaria,"",tipoDatoBinario,yylineno); 
                      }else if(!flagFuncion && strcmp(idAsignacion,"")){
                        existeVariableEnTabla(&tabla, idAsignacion, yylineno, &listaDeErrores);
                        tipoDatoBinario = strdup(buscarTipoDatoVariableEnTabla(&tabla, idAsignacion, yylineno , &listaDeErrores));
                        insertarVariable(&lauxBinaria,"",tipoDatoBinario,yylineno); 
                      }
                    }
#line 2171 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 519 "../src/Analizador.y" /* yacc.c:1646  */
    {
                    flagSuma = 1;
                      if(!flagFuncion && !strcmp(idAsignacion,"")){
                        free(tipoDatoBinario);
                        tipoDatoBinario = strdup(buscarTipoDatoVariableEnTabla(&tabla, idAsignacion, yylineno , &listaDeErrores));
                        insertarVariable(&lauxBinaria,"",tipoDatoBinario,yylineno); 
                      }else if(!flagFuncion && strcmp(idAsignacion,"")){
                        /* existeVariableEnTabla(&tabla, idAsignacion, yylineno, &listaDeErrores); */
                        tipoDatoBinario = strdup(buscarTipoDatoVariableEnTabla(&tabla, idAsignacion, yylineno , &listaDeErrores));
                        insertarVariable(&lauxBinaria,"",tipoDatoBinario,yylineno); 
                      }
                    }
#line 2188 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 563 "../src/Analizador.y" /* yacc.c:1646  */
    {existeFuncionDeclaradaEnTabla(&tabla, idAsignacion, yylineno, &listaDeErrores);}
#line 2194 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 563 "../src/Analizador.y" /* yacc.c:1646  */
    {flagFuncion = 2;}
#line 2200 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 572 "../src/Analizador.y" /* yacc.c:1646  */
    {
 
                          free(idAsignacion);
                          idAsignacion = strdup((yyvsp[0].cadena));
                          if(flagSentencia2==1)
                          flagFuncionLlamada= 1;
                           flagOperacion = 1;
                          }
#line 2213 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 580 "../src/Analizador.y" /* yacc.c:1646  */
    {if( flagFuncionLlamada == 0){free(idAsignacion); idAsignacion = strdup("");} flagOperacion=0;}
#line 2219 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 581 "../src/Analizador.y" /* yacc.c:1646  */
    {free(idAsignacion);
                  insertarVariable(&lauxBinaria,(yyvsp[0].cadena),"char*",yylineno);
                  idAsignacion = strdup("");
                  flagOperacion=0;
                  if( flagFuncionLlamada ==0){free(idAsignacion); idAsignacion = strdup("");}
                  }
#line 2230 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 594 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarVariable(&lauxBinaria,"","int",yylineno);}
#line 2236 "Analizador.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 595 "../src/Analizador.y" /* yacc.c:1646  */
    {insertarVariable(&lauxBinaria,"","float",yylineno);}
#line 2242 "Analizador.tab.c" /* yacc.c:1646  */
    break;


#line 2246 "Analizador.tab.c" /* yacc.c:1646  */
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
#line 598 "../src/Analizador.y" /* yacc.c:1906  */

 
void yyerror (const char *msg) {
 
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
 
    yyparse();
 
    printf("\n----------------------------------");
    printf("\n BIENVENIDO AL COMPILADOR DE C-BA2");
    printf("\n----------------------------------");
 
    fclose(yyin);
 
 
    printf("\n\nMOSTRANDO LISTA DE ERRORES\n\n");
    mostrarListaErrores(&listaDeErrores);
    printf("\n\n");
 
 
 
 
    printf("\n----------------------------------\n\n");
    printf("\n\nMOSTRANDO VARIABLES DE LA TS\n\n"); 
    mostrarVariablesDeTabla(tabla);
 
 
    printf("\n\n----------------------------------\n\n");
    printf("\n\nMOSTRANDO FUNCIONES DEFINIDAS DE LA TS\n\n");
    mostrarFuncionesDefinidasDeTabla(tabla);
    printf("\n\n----------------------------------\n\n");
    printf("\n\nMOSTRANDO FUNCIONES DECLARADAS DE LA TS\n\n");
    mostrarFuncionesDeclaradasDeTabla(&tabla);
 
 
    return 0;
} 
