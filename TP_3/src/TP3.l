
%option noyywrap

%{

#include <stdio.h>

%}
CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_HEXADECIMAL 0[xX][0-9a-fA-F]+
CONSTANTE_REAL (((([0-9]*\.[0-9]+)|[0-9]+\.)([eE][-+]?[0-9]+)?)|[0-9]+[eE][-+]?[0-9]+)[fFlL]?
CONSTANTE_CARACTER (\'.\'|"'\\n'")
LITERAL_CADENA \"[^"]*\"
PALABRASRESERVADAS auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
IDENTIFICADOR [a-zA-Z_][0-9a-zA-Z_]*
PUNTUACION_OPERADORES \[|\]|\(|\)|\{|\}|\,|\;|\:|\*|\=|\#|\!|\%|\^|\&|\–|\+|\||\~|\\|\'|\<|\>|\?|\.|\/|\=\=|\+\=|\-\=|\~|\&\&|\!\=|\+\+|\-\-
COMENTARIO_CORTO \/\/.*
COMENTARIO_LARGO "/*"([^*]|\*+[^/])*\*+\/
ESPACIO_TAB (\ |"	")*
SALTO_DE_LINEA \n
CARACTER_RECHAZO .
DIRECTIVAS #(include|define).*


%%

{CONSTANTE_DECIMAL}     {printf("Encontre una constante entera decimal \n");}
{CONSTANTE_OCTAL}       {printf("Encontre una constante entera octal \n");}
{CONSTANTE_HEXADECIMAL} {printf("Encontre una constante entera hexadecimal \n");}
{IDENTIFICADOR}         {printf("Encontre un identificador \n");}
{CONSTANTE_REAL}        {printf("Encontre una constante real\n");}
{CONSTANTE_CARACTER}    {printf("Encontre una constante caracter\n");}
{LITERAL_CADENA}        {printf("Encontre un literal cadena \n");}
{PALABRASRESERVADAS}    {printf("Encontre una palabra reservada \n");}
{PUNTUACION_OPERADORES} {printf("Encontre un operador de puntuacion \n");}
{COMENTARIO_CORTO}      {printf("Encontre un comentario corto\n");}
{COMENTARIO_LARGO}      {printf("Encontre un comentario largo\n");}
{ESPACIO_TAB}           {printf("Encontre una tabulacion \n");}
{SALTO_DE_LINEA}        {printf("Encontre un salto de linea \n");}
{CARACTER_RECHAZO}      {printf("Encontre un caracter de rechazo \n");}
{DIRECTIVAS}            {printf("Encontre una directiva de precompilador \n");}
%%

