%option yylineno 
%option noyywrap
%{

#include <stdlib.h>
#include <string.h>
#include "Analizador.tab.h"
extern FILE* yyin;
%}



CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_HEXADECIMAL 0[xX][0-9a-fA-F]+
CONSTANTE_REAL (((([0-9]*\.[0-9]+)|[0-9]+\.)([eE][-+]?[0-9]+)?)|[0-9]+[eE][-+]?[0-9]+)[fFlL]?
CONSTANTE_CARACTER (\'.\'|"'\\n'")
LITERAL_CADENA \"[^"]*\"
IDENTIFICADOR [A-Za-z_][A-Za-z_0-9]*



%%  
"#include"      {return INCLUDE;}
"#define"       {return DEFINE;}
"if"            {return IF;}
"else"          {return ELSE;}
"typedef"       {return TYPEDEF;}
"signed"        {return SIGNED;}
"unsigned"      {return UNSIGNED;}
"for"           {return FOR;}
"while"         {return WHILE;}
"do"            {return DO;}
"switch"        {return SWITCH;}
"goto"          {return GOTO;}
"continue"      {return CONTINUE;}
"break"         {return BREAK;}
"return"        {return RETURN;}
"sizeof"        {return SIZEOF;}
"const"         {return CONST;}
"enum"          {return ENUM;}
"case"          {return CASE;}
"default"       {return DEFAULT;}
"struct"        {return STRUCT;} 
"union"         {return UNION;}
"=="            {return IGUAL_IGUAL;}
"!="            {return DISTINTO;}
">="            {return MAYOR_IGUAL;}
"<="            {return MENOR_IGUAL;}
"++"            {return MAS_MAS;}
"--"            {return MENOS_MENOS;}
"||"            {return OR_LOGICO;}
"&&"            {return AND_LOGICO;}
"+="            {return ASIGNACION_INCREMENTO;}
"-="            {return ASIGNACION_DECREMENTO;}
"*="            {return ASIGNACION_PRODUCTO;}
"/="            {return ASIGNACION_DIVISION;}
"->"            {return PUNTERO_FLECHA;}
void|char|float|int|long|short|double {strcpy(yylval.cadena,yytext); return TIPO_DATO; } 
"<<"            {return CORRIMIENTO_A_IZQUIERDA;}
">>"            {return CORRIMIENTO_A_DERECHA;}     
":"|";"|"="|","|"{"|"}"|"("|")"|"["|"]"|"*"|"+"|"-"|"/"|"?"|";"|"&"|"|"|"^"|"!"|"~"|"%"|"<"|">" {return yytext[0];}
 
{LITERAL_CADENA}        {strcpy(yylval.cadena, yytext); return LITERAL_CADENA;}
{CONSTANTE_CARACTER}    {yylval.entero = yytext[1]; return NUM;}
{CONSTANTE_REAL}        {yylval.real = atof(yytext); return NUM_REAL;}
{CONSTANTE_HEXADECIMAL} {yylval.entero = strtol(yytext, NULL, 0); return NUM;}
{CONSTANTE_OCTAL}       {yylval.entero = strtol(yytext, NULL, 0);  return NUM;}
{CONSTANTE_DECIMAL}	    {yylval.entero = atoi(yytext);  return NUM;}
{IDENTIFICADOR}         {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;}
[^\t\n' ']              {printf("\nDetecto error lexico\n"); strcpy(yylval.cadena, yytext); return ERROR_LEXICO;}


%%

/*  yytext es lo que lee del archivo de entrada en nuestro caso
    Lo que hacemos es almacenarlo en el campo de yylval
    Para los que son numeros, lo almacenamos en el campo entero
    Para el resto lo almacenamos en el campo cadena 
*/
