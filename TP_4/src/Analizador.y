
%{
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

%}

%union {
  char cadena[30];
  int entero;
  float real;
}

%token <cadena> GOTO
%token <cadena> VOLATILE 
%token <cadena> TIPO_DATO
%token <cadena> SIGNED
%token <cadena> UNSIGNED  
%token <cadena> ENUM
%token <cadena> TYPEDEF
%token <cadena> AND_LOGICO
%token <cadena> OR_LOGICO
%token <cadena> CONST
%token <cadena> CASE 
%token <cadena> DEFAULT
%token <cadena> STRUCT
%token <cadena> UNION
%token <cadena> IGUAL_IGUAL
%token <cadena> DISTINTO
%token <cadena> MAYOR_IGUAL
%token <cadena> MENOR_IGUAL
%token <cadena> MAS_MAS
%token <cadena> MENOS_MENOS
%token <cadena> ASIGNACION_INCREMENTO
%token <cadena> ASIGNACION_DECREMENTO
%token <cadena> ASIGNACION_PRODUCTO
%token <cadena> ASIGNACION_DIVISION
%token <cadena> CORRIMIENTO_A_IZQUIERDA
%token <cadena> CORRIMIENTO_A_DERECHA
%token <real>   NUM_REAL
%token <cadena> PUNTERO_FLECHA
%token <entero> NUM
%token <cadena> IDENTIFICADOR
%token <cadena> LITERAL_CADENA
%token <cadena> SIZEOF
%token <cadena> IF
%token <cadena> BREAK
%token <cadena> FOR
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> SWITCH
%token <cadena> RETURN
%token <cadena> CONTINUE
%token <cadena> ERROR_LEXICO
%token <cadena> INCLUDE 
%token <cadena> DEFINE 
 
%left '+' '-' '*' '/'

%nonassoc IFX   
%nonassoc ELSE

%start input

// BNF DE C COMPLETA, FALTA AGREGAR FUNCIONES DE C (YA HECHAS) Y ERRORERES LEXICOS Y SINTACTICOS

%%
input:
      | input line
;  

line:  declaracion_externa 
     | sentencia
     | error {errorLinea = yylineno;}   declaracion_externa  {insertarElemento(&listaErroresSintacticos,"", "", errorLinea);} {printf("Error sintactico en linea %d\n", yylineno);}
     | error {errorLinea = yylineno;}   ';'  {insertarElemento(&listaErroresSintacticos,"", "", errorLinea);} {printf("Error sintactico en linea %d\n", yylineno);}
     | ERROR_LEXICO {printf("\n\n \t---> Error lexico en linea %d\n", yylineno); insertarElemento(&listaErroresLexicos,tipoDeDato,$<cadena>1,yylineno);} 
      
;

 

  
      
declaracion_externa: definicion_de_funcion {printf("declaracion_externa: definicion_de_funcion, %s \n",$<cadena>1); }
                | declaracion  
    
definicion_de_funcion:  especificadores_de_declaracion   declarador {free(tipoDatoFuncion); tipoDatoFuncion = strdup($<cadena>1) ;idFuncion = strdup($<cadena>2); lineaFuncion=yylineno;}  opcional_lista_de_declaracion 
               ;
 
opcional_lista_de_declaracion: sentencia_compuesta 
                              |  lista_de_declaracion sentencia_compuesta 
                              ;

declaracion: especificadores_de_declaracion lista_declaradores_init ';'
   {printf("\nCONTADOR VALE %d\n",contadorPuntero);} { while(contadorPuntero){
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
           | especificadores_de_declaracion ';'    
;

lista_de_declaracion:declaracion     {strcpy(tipoDatoFuncion, ""); printf("lista_de_declaracion:      declaracion  %s\n",tipoDatoFuncion ); }
                    | lista_de_declaracion declaracion     
;

especificadores_de_declaracion: especificador_categoria_almacenamiento especificadores_de_declaracion 
          | especificador_categoria_almacenamiento 
          | especificador_de_tipo especificadores_de_declaracion   
          | especificador_de_tipo      {printf("especificadores_de_declaracion:    especificador_de_tipo  %s\n",$<cadena>1);}
          | calificador_de_tipo especificadores_de_declaracion   
          | calificador_de_tipo 
;

especificador_categoria_almacenamiento: TYPEDEF 
; 

especificador_de_tipo: TIPO_DATO      {;free(tipoDeDato);tipoDeDato=strdup($<cadena>1);}
                     | SIGNED    {free(tipoDeDato);tipoDeDato=strdup("signed");}
                     | UNSIGNED  {free(tipoDeDato);tipoDeDato=strdup("unsigned");}
                     | especificador_estructura_o_union    
                     | especificador_enum                  
                     | nombre_typedef                      
;

calificador_de_tipo: CONST      
                   | VOLATILE    
;

especificador_estructura_o_union: estructura_o_union IDENTIFICADOR '{' lista_declaraciones_struct '}' { printf("\nNombre del identificador: %s\n\n", $<cadena>1);}
                                | estructura_o_union '{' lista_declaraciones_struct '}'   
                                | estructura_o_union IDENTIFICADOR { printf("\nNombre del identificador: %s\n\n", $<cadena>1);}
;

estructura_o_union: STRUCT    
                  | UNION     
;

lista_declaraciones_struct: declaracion_struct  
                          | lista_declaraciones_struct declaracion_struct  
;

lista_declaradores_init: declarador_init 
                       | lista_declaradores_init ',' declarador_init    
;

declarador_init: declarador  
                | declarador '=' inicializador   
;

declaracion_struct: lista_calificador_especificador lista_declaradores_struct ';'  
;

lista_calificador_especificador: especificador_de_tipo lista_calificador_especificador  
                                | especificador_de_tipo    
                                | calificador_de_tipo lista_calificador_especificador     
                                | calificador_de_tipo      
;

lista_declaradores_struct: declarador_struct        
                         | lista_declaradores_struct ',' declarador_struct        
;

declarador_struct: declarador      
                  | declarador ':' expresion_constante  
                  | ':' expresion_constante     
;

especificador_enum: ENUM IDENTIFICADOR '{' lista_de_enumerador '}'    
                  | ENUM '{' lista_de_enumerador '}'       
                  | ENUM IDENTIFICADOR              
;

lista_de_enumerador: enumerador   
                     | lista_de_enumerador ',' enumerador   
;

enumerador: IDENTIFICADOR      
            | IDENTIFICADOR '=' expresion_constante     
;

declarador: apuntador declarador_directo    
            | declarador_directo         
;

declarador_directo: IDENTIFICADOR   {printf("\nflagFuncion = %d\n",flagFuncion);
 free(id);
id = strdup($<cadena>1);}


                  | declarador_directo '[' expresion_constante  ']'   
                  | declarador_directo '['  ']'  
                  | declarador_directo {  free(idFuncion); idFuncion= strdup(id); free(tipoDatoFuncion); tipoDatoFuncion = strdup(tipoDeDato);}{printf("\n el idFuncion es: %s , tipod dato: %s   y el flagFuncion: %d \n",idFuncion, tipoDatoFuncion, flagFuncion); } '(' lista_op_parentesis   
;    
  
lista_op_parentesis:  lista_tipos_de_parametro{flagFuncion=0;} ')'  
                    | lista_de_identificadores {flagFuncion=0;}')' 
                    |{flagFuncion=0;} ')' 
;
apuntador: '*' {contadorPuntero++;} apuntador_aux 
;

apuntador_aux: 
              |  '*'{contadorPuntero++;} apuntador_aux 
;

opcional_lista_calificadores_de_tipo: 
                                    | lista_calificadores_de_tipo 
                                    ;

lista_calificadores_de_tipo: calificador_de_tipo     
                           | lista_calificadores_de_tipo calificador_de_tipo     
;

lista_tipos_de_parametro:  lista_de_parametros       
;
      
lista_de_parametros: declaracion_de_parametro     
                    | lista_de_parametros ',' declaracion_de_parametro    
;

declaracion_de_parametro:  especificadores_de_declaracion declarador {tipoDatoParametro = strdup($<cadena>1); idParametro = strdup($<cadena>2); insertarElemento(&listaParametros,tipoDeDato,idParametro,yylineno);printf("\n\n Se inserto a listaParametros : %s de tipo: %s\n\n",idParametro,tipoDatoParametro);} 
                        | especificadores_de_declaracion declarador_abstracto   
                        | especificadores_de_declaracion     
;

lista_de_identificadores:  IDENTIFICADOR        
                        | lista_de_identificadores ',' IDENTIFICADOR   
;

inicializador: expresion_de_asignacion     
             | '{' lista_de_inicializadores'}'    
             | '{' lista_de_inicializadores',' '}'   
;

lista_de_inicializadores: inicializador      
                   | lista_de_inicializadores',' inicializador   
;

nombre_de_tipo: lista_calificador_especificador declarador_abstracto     
              | lista_calificador_especificador                     
;

declarador_abstracto: apuntador   
                    | apuntador declarador_abstracto_directo    
                    | declarador_abstracto_directo      
;

declarador_abstracto_directo: '(' declarador_abstracto ')'  
                  | declarador_abstracto_directo '[' expresion_constante ']'   
                  | '[' expresion_constante ']'  
                  | declarador_abstracto_directo '[' ']'  
                  | '[' ']'     
                  | declarador_abstracto_directo '(' lista_tipos_de_parametro ')'  
                  | '(' lista_tipos_de_parametro ')'    
                  | declarador_abstracto_directo '(' ')'  
                  | '(' ')'    
;

nombre_typedef: 't'   
;

sentencia: sentencia_etiquetada    
         | sentencia_expresion    
         | sentencia_compuesta      
         | sentencia_de_seleccion      
         | sentencia_de_iteracion          
         | sentencia_de_salto   
;
   

sentencia_etiquetada: IDENTIFICADOR ':' sentencia      
                    | CASE expresion_constante  ':' sentencia  
                    | DEFAULT ':' sentencia       
;
 
sentencia_expresion:   expresion ';'   
                   | ';'       
;

sentencia_compuesta: '{'{ if(!flagSentencia) {insertarElemento(&listaFuncionesDefinidas,tipoDatoFuncion,idFuncion,lineaFuncion); ;printf("\n\n Se inserto a listaFuncionesDefinidas**: %s  de tipo: %s \n\n",idFuncion,tipoDatoFuncion);strcpy(tipoDatoFuncion,"");}}  lista_de_declaracion opcional_sentencia_compuesta
                   | '{' { if(!flagSentencia) {insertarElemento(&listaFuncionesDefinidas,tipoDatoFuncion,idFuncion,lineaFuncion);; printf("\n\n Se inserto a listaFuncionesDefinidas**: %s  de tipo: %s \n\n",idFuncion,tipoDatoFuncion);strcpy(tipoDatoFuncion,"");}}  lista_de_sentencias  '}'       
                   | '{'{if(!flagSentencia) {insertarElemento(&listaFuncionesDefinidas,tipoDatoFuncion,idFuncion,lineaFuncion);; printf("\n\n Se inserto a listaFuncionesDefinidas: %s  de tipo: %s \n\n",idFuncion,tipoDatoFuncion);strcpy(tipoDatoFuncion,"");}} '}'   
; 


opcional_sentencia_compuesta: lista_de_sentencias  '}'   
                            | '}'    
                            ;


lista_de_sentencias: sentencia       
                | lista_de_sentencias  sentencia        
;

sentencia_de_seleccion: IF {insertarElemento(&listaDeIf,"", "if", yylineno);}  '(' expresion ')' {flagSentencia=1;}sentencia  opcionElse {flagSentencia=0;}   %prec IFX {printf("IF en linea %d\n", yylineno);}
                   | SWITCH {insertarElemento(&listaDeSwitch,"", "switch", yylineno);}'(' expresion ')' {flagSentencia=1;} sentencia {flagSentencia=0;}     {printf(" SWITCH en linea %d\n", yylineno);}
; 
opcionElse: /*vacio*/
          |ELSE sentencia {printf("if else");}

;
sentencia_de_iteracion: WHILE {insertarElemento(&listaDeWhile, "","while", yylineno);} '(' expresion ')'  {flagSentencia=1;} sentencia {flagSentencia=0;}   {printf(" WHILE EN LINEA %d\n", yylineno);}
                   | DO{insertarElemento(&listaDeDo,"", "do", yylineno);}  {flagSentencia=1;} sentencia {flagSentencia=0;} WHILE {insertarElemento(&listaDeWhile,"", "while del do ", yylineno);} '(' expresion ')' ';'      
                   | FOR{insertarElemento(&listaDeFor,"", "for", yylineno);} '(' opcional_expresion ';' opcional_expresion ';' opcional_expresion ')'  {flagSentencia=1;}sentencia {flagSentencia=0;}
;

opcional_expresion: 
                  | expresion 
                  
;


sentencia_de_salto: GOTO IDENTIFICADOR ';'  
                  | CONTINUE ';'        
                  | BREAK ';'    
                  | RETURN expresion ';'       
                  | RETURN ';'              
;

expresion: expresion_de_asignacion  
         | expresion ',' expresion_de_asignacion    
;

expresion_de_asignacion: expresion_condicional  
                       | expresion_unaria operador_de_asignacion expresion_de_asignacion 
;

operador_de_asignacion:    ASIGNACION_DECREMENTO   
                           | ASIGNACION_DIVISION    
                           |ASIGNACION_INCREMENTO    
                           |ASIGNACION_PRODUCTO     
                           | '='
;  

expresion_condicional: expresion_logica_or     
                     | expresion_logica_or '?' expresion ':' expresion_condicional  
;  

expresion_constante: expresion_condicional    ;

expresion_logica_or: expresion_logica_and   
                   | expresion_logica_or OR_LOGICO expresion_logica_and      
;

expresion_logica_and: expresion_or_inclusivo   
                    | expresion_logica_and AND_LOGICO expresion_or_inclusivo  
;

expresion_or_inclusivo: expresion_or_exclusivo   
                      | expresion_or_inclusivo '|' expresion_or_exclusivo   
;

expresion_or_exclusivo: expresion_and   
                      | expresion_or_exclusivo '^' expresion_and      
;

expresion_and: expresion_de_igualdad  
             | expresion_and '&' expresion_de_igualdad 
;

expresion_de_igualdad: expresion_relacional  
                     | expresion_de_igualdad IGUAL_IGUAL expresion_relacional    
                     | expresion_de_igualdad DISTINTO expresion_relacional     
;

expresion_relacional: expresion_de_corrimiento    
                    | expresion_relacional '<' expresion_de_corrimiento     
                    | expresion_relacional '>' expresion_de_corrimiento     
                    | expresion_relacional MENOR_IGUAL expresion_de_corrimiento     
                    | expresion_relacional MAYOR_IGUAL expresion_de_corrimiento    
;

expresion_de_corrimiento: expresion_aditiva 
                        | expresion_de_corrimiento CORRIMIENTO_A_IZQUIERDA expresion_aditiva 
                        | expresion_de_corrimiento CORRIMIENTO_A_DERECHA expresion_aditiva   
;

expresion_aditiva: expresion_multiplicativa       
                            | expresion_aditiva '+' expresion_multiplicativa
                            | expresion_aditiva '-' expresion_multiplicativa
;

expresion_multiplicativa: expresion_cast  
                        | expresion_multiplicativa '*' expresion_cast         
                        | expresion_multiplicativa '/' expresion_cast         
                        | expresion_multiplicativa '%' expresion_cast         
;

expresion_cast: expresion_unaria  
              | '(' nombre_de_tipo ')' expresion_cast    
;

expresion_unaria: expresion_posfija     
                | MENOS_MENOS  expresion_unaria    
                | MAS_MAS expresion_unaria         
                | operador_unario  expresion_cast  
                | SIZEOF expresion_unaria          
                | SIZEOF '(' nombre_de_tipo ')'    
                
;

operador_unario: '&'   
               | '+'   
               | '-'   
               | '~'   
               | '!'   
;

expresion_posfija: expresion_primaria        
                 | expresion_posfija '.' IDENTIFICADOR 
                 | expresion_posfija PUNTERO_FLECHA IDENTIFICADOR 
                 | expresion_posfija MENOS_MENOS 
                 | expresion_posfija MAS_MAS 
;

expresion_primaria: IDENTIFICADOR     
                  | constante
                  | LITERAL_CADENA    
                  | '(' expresion')'  
;

lista_expresiones_argumento: expresion_de_asignacion     
                           | lista_expresiones_argumento ',' expresion_de_asignacion    
;

constante: NUM   
         | NUM_REAL  
;

%%

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