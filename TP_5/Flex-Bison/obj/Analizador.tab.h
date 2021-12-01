/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 76 "../src/Analizador.y" /* yacc.c:1909  */

  char cadena[30];
  int entero;
  float real;

#line 108 "Analizador.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALIZADOR_TAB_H_INCLUDED  */
