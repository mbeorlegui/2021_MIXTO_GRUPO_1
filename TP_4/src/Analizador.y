

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
%token <cadena> OPERADOR_AND        //TERMINALES
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
%token <cadena> BREAK


%start programa

%% /* Reglas y acciones */

programa:    /* vacio */
        | programa {flagError = 0;}line 
;

line: sentenciaDeclaracion 
    | sentencia
;

expresion: expresionAsignacion
         | expresion ', ' expresionAsignacion   //HAY QUE SEGUIR CONSTRUYENDO LOS != TIPOS DE EXPRESIONES

sentenciaDeclaracion: {printf("hola\n");};
sentencia: sentenciaExpresion
           | sentenciaCompuesta
           | sentenciaSeleccion
           | sentenciaIteracion
           | sentenciaSalto
;

sentenciaExpresion: expresionOpcional ';'
;

expresionOpcional:   /* Vacio */
               | expresion
;

sentenciaCompuesta: '{' listaCompuesta '}'
;

listaCompuesta: listaDeclaracionesOpcional listaSentenciasOpcional
              | listaCompuesta listaDeclaracionesOpcional listaSentenciasOpcional
; //HAY QUE HACER LOS != TIPOS DE LISTAS

listaDeclaracionesOpcional:   /* Vacio */
                         | listaDeclaraciones
;

listaSentenciasOpcional:   /* Vacio */
                      | listaSentencias
;

listaDeclaraciones:   declaracion ';'
                     | listaDeclaraciones declaracion ';'
;

listaSentencias:   sentencia
                  | listaSentencias sentencia
;

sentenciaSeleccion: IF '(' expresion ')' sentencia {fprintf(yyout, "Se encontro la sentencia IF\n");}
                  | IF '(' expresion ')' sentencia ELSE sentencia {fprintf(yyout, "Se encontro la sentencia IF y ELSE\n");}
                  | SWITCH '(' expresion ')' sentencia {fprintf(yyout, "Se encontro la sentencia SWITCH\n");}
;

sentenciaIteracion: WHILE '(' expresion ')' sentencia {fprintf(yyout, "Se encontro la sentencia WHILE\n");}                                         
                  | DO sentencia WHILE '(' expresion ')' ';' {fprintf(yyout, "Se encontro la sentencia DO WHILE\n");}                                  
                  | FOR '(' forOpcional ';' expresionOpcional ';' expresionOpcional ')' sentencia {fprintf(yyout, "Se encontro la sentencia FOR\n");}
;

forOpcional:   /* Vacio */
         | expresion
         | declaracion
;

sentenciaSalto: BREAK ';'
              | RETURN expresionOpcional ';'
;


/* IF {printf("Hay un IF\n");}
         | WHILE {printf("Hay un WHILE\n");}
         | FOR {printf("Hay un FOR\n");}
         | SWITCH {printf("Hay un SWITCH\n");}
*/


/* EXPRESION */


%%
void yyerror (char const *s) {
   fprintf (stderr, "Error sintactico en la linea %d\n", yylineno);
}

int main(){
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

  return 0;
}
