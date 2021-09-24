
%{

#include <stdlib.h>
#include <string.h>
#include "Analizador.tab.h"

void errorLexico(void);



%}

%option yylineno
%option noyywrap

CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_HEXADECIMAL 0[xX][0-9a-fA-F]+
CONSTANTE_REAL (((([0-9]*\.[0-9]+)|[0-9]+\.)([eE][-+]?[0-9]+)?)|[0-9]+[eE][-+]?[0-9]+)[fFlL]?
CONSTANTE_CARACTER (\'.\'|"'\\n'")
TIPO_DATO char|int|double
VOID void
LITERAL_CADENA \"[^"]*\"
OPERADOR_ASIGNACION \+\=
OPERADOR_RELACIONAL \>\=|\>|\<|\<\=
OPERADOR_IGUALDAD \=\=|\!\=
OPERADOR_UNARIO \*|\&|\-|\!|\+\+
OPERADOR_OR \|\|
OPERADOR_AND \&\&
OPERADOR_MULTIPLICATIVO \*|\/|\%
SIZEOF sizeof
RETURN return
IF if
ELSE else
FOR for
WHILE while
DO do
SWITCH switch
IDENTIFICADOR [A-Za-z_][A-Za-z_0-9]*

%%



{IF}       {strcpy(yylval.cadena, yytext); return IF;}
{ELSE}     {strcpy(yylval.cadena, yytext); return ELSE;}
{FOR}      {strcpy(yylval.cadena, yytext); return FOR;}
{WHILE}    {strcpy(yylval.cadena, yytext); return WHILE;}
{DO}       {strcpy(yylval.cadena, yytext); return DO;}
{SWITCH}   {strcpy(yylval.cadena, yytext); return SWITCH;}
{VOID}     {strcpy(yylval.cadena, yytext); return VOID;}
{RETURN}   {strcpy(yylval.cadena, yytext); return RETURN;}
{OPERADOR_MULTIPLICATIVO} {strcpy(yylval.cadena, yytext); return OPERADOR_MULTIPLICATIVO;}
{OPERADOR_ASIGNACION}  {strcpy(yylval.cadena, yytext); return OPERADOR_ASIGNACION;}
{OPERADOR_RELACIONAL} {strcpy(yylval.cadena, yytext); return OPERADOR_RELACIONAL;}
{OPERADOR_IGUALDAD} {strcpy(yylval.cadena, yytext); return OPERADOR_IGUALDAD;}
{OPERADOR_UNARIO} {strcpy(yylval.cadena, yytext); return OPERADOR_UNARIO;}
{OPERADOR_OR} {strcpy(yylval.cadena, yytext); return OPERADOR_OR;}
{OPERADOR_AND} {strcpy(yylval.cadena, yytext); return OPERADOR_AND;}
{SIZEOF} {strcpy(yylval.cadena, yytext); return SIZEOF;}
{LITERAL_CADENA} {strcpy(yylval.cadena, yytext); return LITERAL_CADENA;}
{CONSTANTE_CARACTER} {yylval.entero = yytext[1]; return NUM;}
{CONSTANTE_REAL} {yylval.real = atof(yytext); return NUM_REAL;}
{CONSTANTE_HEXADECIMAL} {yylval.entero = strtol(yytext, NULL, 0); return NUM;}
{CONSTANTE_OCTAL}   {yylval.entero = strtol(yytext, NULL, 0);  return NUM;}
{CONSTANTE_DECIMAL}	{yylval.entero = atoi(yytext);  return NUM;}
{TIPO_DATO} {strcpy(yylval.cadena,yytext); return TIPO_DATO;}
{IDENTIFICADOR} {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;}

"+"     {return '+';}     
"?"     {return '?';}     
":"     {return ':';}
"("     {return '(';}
")"     {return ')';}
"["     {return '[';}
"]"     {return ']';}
"{"     {return '{';}
"}"     {return '}';}     
","     {return ',';}
"="     {return '=';}
";"     {return ';';}
\n
[\t ]
.       {errorLexico();} // Error Lexico

%%

/*  yytext es lo que lee del archivo de entrada en nuestro caso
    Lo que hacemos es almacenarlo en el campo de yylval
    Para los que son numeros, lo almacenamos en el campo entero
    Para el resto lo almacenamos en el campo cadena 
*/

void errorLexico(void){
	printf("Error lexico: caracter %s invalido. En linea %d.", yytext, yylineno);
    getchar();
    exit(0);
}