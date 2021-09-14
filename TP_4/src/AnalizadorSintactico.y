/* Calculadora NOTACION INFIJA */

%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern FILE* yyin;

int yylex ();
void yyerror (char const *s);
int yywrap(){return(1);}

int flagError=0;
extern int yylineno;


%}
%union {
  char cadena[30];
  int entero;
  float real;
}



%token <real>   NUM_REAL
%token <entero> NUM
%token <cadena> IDENTIFICADOR
%token <cadena> TIPO_DATO
%token <entero> ERROR
%token <cadena> LITERAL_CADENA
%token <cadena> OPERADOR_ASIGNACION
%token <cadena> OPERADOR_RELACIONAL
%token <cadena> OPERADOR_IGUALDAD
%token <cadena> OPERADOR_UNARIO
%token <cadena> OPERADOR_OR
%token <cadena> OPERADOR_AND
%token <cadena> SIZEOF
%token <cadena> OPERADOR_MULTIPLICATIVO
%token <cadena> VOID
%token <cadena> IF
%token <cadena> ELSE
%token <cadena> FOR
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> SWITCH
%token <cadena> RETURN


%start programa

%% /* Reglas y acciones */

programa:    /* vacio */
        | programa {flagError = 0;}
;

/* EXPRESION */ 



%%
void yyerror (char const *s) {
   fprintf (stderr, "Error sintactico en la linea %d\n", yylineno);
}

void main(){
  #ifdef BISON_DEBUG
    yydebug = 1;
  #endif    
 
  yyin = fopen("entrada.c", "r"); 
  if (!yyin)
   {
      printf("No se encuentra el archivo de entrada \n"); 
      return -1;
   }
	yyparse();

  getchar();
}
