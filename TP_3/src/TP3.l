%option noyywrap

%{
  #include "Funciones.h"
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
COMENTARIO_LARGO "/*"([^*]|\*+[^/])*"*/" 
ESPACIO_TAB (\ |"	")*
SALTO_DE_LINEA \n
CARACTER_RECHAZO .
DIRECTIVAS #(include|define).*                 

%%

 /* Para cada categoria lexica debo agregar elementos a la lista con yytext,
    salvo para el identificador y los operadores de puntuacion que deben ir
    ordenados. 
    * Para los saltos de linea debo agregar iterar sobre una varaible,
      asi puedo contar la linea en la que estan las categorias lexicas
 */
{DIRECTIVAS}            { insertarElemento(yytext, &listaDirectivas)        ;}
{CONSTANTE_OCTAL}       { insertarElemento(yytext, &listaOctales)           ;}
{CONSTANTE_DECIMAL}     { insertarElemento(yytext, &listaDecimales)         ;}
{CONSTANTE_HEXADECIMAL} { insertarElemento(yytext, &listaHexa)              ;}
{CONSTANTE_REAL}        { insertarElemento(yytext, &listaReales)            ;}
{CONSTANTE_CARACTER}    { insertarElemento(yytext, &listaConstantesCaracter);}
{LITERAL_CADENA}        { insertarElemento(yytext, &listaLiterales)         ;}
{PALABRASRESERVADAS}    { insertarElemento(yytext, &listaPalabrasReservadas);}
{IDENTIFICADOR}         { insertarOrdenado(yytext, &listaIdentificadores)   ;}
{PUNTUACION_OPERADORES} { insertarOrdenado(yytext, &listaOperadores)        ;}
{COMENTARIO_CORTO}      { insertarElemento(yytext, &listaComentariosCortos) ;}
{COMENTARIO_LARGO}      { insertarElemento(yytext, &listaComentariosLargos) ;}
{SALTO_DE_LINEA}        { lineas++                                          ;}
{ESPACIO_TAB}           {                                                   ;}
{CARACTER_RECHAZO}      { insertarElemento(yytext, &listaNoReconocidos)     ;}
%%


int main(){
  FILE* aReportes = fopen("Reportes.txt", "w");

  yyin = fopen("entrada.c", "r");
  system("color 71");
  yylex();
  
  //PARTE DE LOS IDENTIFICADORES
  fputs("\nIDENTIFICADORES\n", aReportes);
  archivarIdentificadoresOperadaresYCaracteres(&listaIdentificadores, &aReportes);

  //PARTE DE LOS LITERALES CADENA  
  fputs("\n\nLITERALES CADENA\n", aReportes);
  archivarLiteralesCadena(&listaLiterales, &aReportes);
  
  //PARTE DE LAS PALABRAS RESERVADAS
  fputs("\n\nPALABRAS RESERVADAS\n", aReportes);
  archivarPalabrasReservadasComentariosYDirectivas(&listaPalabrasReservadas, &aReportes);

  //PARTE DE LOS OPERADORES
  fputs("\n\nOPERADORES\n", aReportes);
  archivarIdentificadoresOperadaresYCaracteres(&listaOperadores, &aReportes);

  //PARTE DE LOS COMENTARIOS CORTOS
  fputs("\n\nCOMENTARIOS CORTOS\n", aReportes);
  archivarPalabrasReservadasComentariosYDirectivas(&listaComentariosCortos, &aReportes);

  //PARTE DE LOS COMENTARIOS LARGOS
  fputs("\n\nCOMENTARIOS LARGOS\n", aReportes);
  archivarPalabrasReservadasComentariosYDirectivas(&listaComentariosLargos, &aReportes);

  //COMENTARIOS NO RECONOCIDOS
  fputs("\n\nCARACTERES NO RECONOCIDOS\n", aReportes);
  archivarNoReconocidos(&listaNoReconocidos, &aReportes);
    
  //PARTE DE LAS DIRECTIVAS
  fputs("\n\nDIRECTIVAS\n", aReportes);
  archivarPalabrasReservadasComentariosYDirectivas(&listaDirectivas, &aReportes);

  //PARTE DE LAS CONSTANTES CARACTER
  fputs("\n\nCONSTANTES OCTALES\n", aReportes);
  archivarConstantes(&listaOctales, &aReportes, 8);
  
  fputs("\n\nCONSTANTES HEXADECIMALES\n", aReportes);
  archivarConstantes(&listaHexa, &aReportes, 16);

  fputs("\n\nCONSTANTES DECIMALES\n", aReportes);
  archivarConstantes(&listaDecimales, &aReportes, 10);
  
  fputs("\n\nCONSTANTES REALES\n", aReportes);
  archivarReales(&listaReales, &aReportes);
  
  fputs("\n\nCONSTANTES CARACTERES\n", aReportes);
  archivarCaracteres(&listaConstantesCaracter, &aReportes);
  printf("\nLlegie hasta aca2\n");

  fclose(aReportes);
  return 0;
}