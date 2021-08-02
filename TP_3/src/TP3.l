%option noyywrap

%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo {
    char *info;
    int cantidad;
    struct nodo *sgte;
    int posicion;
};

typedef struct nodo nodo;

nodo *listaLiterales = NULL;
nodo *listaPalabrasReservadas = NULL;
nodo *listaIdentificadores = NULL;
nodo *listaOctales = NULL;
nodo *listaHexa = NULL;
nodo *listaDecimales = NULL;
nodo *listaConstantesCaracter = NULL;
nodo *listaOperadores = NULL;
nodo *listaComentariosCortos = NULL;
nodo *listaComentariosLargos = NULL;
nodo *listaReales = NULL;
nodo *listaNoReconocidos = NULL;
nodo *listaDirectivas = NULL;

int mostrarTotal = 0;  //Sumatoria de numeros decimales
int lineas = 1;        //Cantidad de lineas de codigo

void insertarOrdenado(char texto[], nodo **lista);
void insertarElemento(char texto[], nodo **lista);
void mostrarLista(nodo **lista, int literalCadena, char *texto);
int existeEnLaLista(char texto[], nodo *lista);
char* sacarComillas(char texto[]);
nodo *obtenerUltimoNodo(nodo *lista);

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


// Funcion para insertar ordenado cada elemento en su debida lista
void insertarOrdenado(char texto[], nodo **lista) {
    nodo *lista_aux;
    nodo *nuevo = malloc(sizeof(nodo));
    nuevo->info = strdup(texto);
    nuevo->cantidad = 1;
    if (!(*lista) || (*lista && strcmp((*lista)->info, texto) > 0)) {
        nuevo->sgte = (*lista);
        (*lista) = nuevo;
    } else {
        lista_aux = *lista;
        if (existeEnLaLista(texto, *lista)) {
            while (lista_aux && strcmp(lista_aux->info, texto))
                lista_aux = lista_aux->sgte;
            (lista_aux->cantidad)++;
        } else {
            while (lista_aux && lista_aux->sgte && strcmp(lista_aux->sgte->info, texto) < 0)
                lista_aux = lista_aux->sgte;
            nuevo->sgte = lista_aux->sgte;
            lista_aux->sgte = nuevo;
        }
    }
}

// Funcion para insertar cada elemento en su debida lista, sin contemplar orden
void insertarElemento(char texto[], nodo **lista) {
    for (int i = 0; i < strlen(texto); i++) {
        if (texto[i] == '\n')
            lineas++;
    }
    texto = sacarComillas(texto);
    nodo *lista_aux;
    if (*lista) {
        lista_aux = obtenerUltimoNodo(*lista);
        lista_aux->sgte = malloc(sizeof(nodo));
        lista_aux = lista_aux->sgte;
        lista_aux->info = strdup(texto);
        lista_aux->cantidad = -1;
        lista_aux->posicion = lineas;
        lista_aux->sgte = NULL;
    } else {
        *lista = malloc(sizeof(nodo));
        (*lista)->info = strdup(texto);
        (*lista)->cantidad = -1;
        (*lista)->posicion = lineas;
        (*lista)->sgte = NULL;
    }
    return;
}

void mostrarLista(nodo **lista, int literalCadena, char *texto) {
    nodo *lista_aux;
    if (*lista) {
        if (literalCadena) {
            printf("Literales Cadena:\n");
            while (*lista) {
                printf("%s cuya longitud es %d\n", (*lista)->info, strlen((*lista)->info));
                lista_aux = (*lista)->sgte;
                free(*lista);
                *lista = lista_aux;
            }
        } else {
            printf(texto);
            while (*lista) {
                if ((*lista)->cantidad != -1)
                    printf("%s que aparece %d veces\n", (*lista)->info, (*lista)->cantidad);
                else
                    printf("%s\n", (*lista)->info);

                lista_aux = (*lista)->sgte;
                free(*lista);
                *lista = lista_aux;
            }
        }
        printf("\n");
    }
}

int existeEnLaLista(char texto[], nodo *lista) {
    nodo *actual = malloc(sizeof(nodo));
    int encontrado = 0;
    actual = lista;
    while (actual && strcmp(actual->info, texto) <= 0) {
        if (!strcmp(actual->info, texto)) {
            encontrado = 1;
        }
        actual = actual->sgte;
    }
    return encontrado;
}

char* sacarComillas(char texto[]){
    char* auxiliar = malloc(strlen(texto));
    int j = 0;
    for(int i=0; i < strlen(texto); i++){
        if(texto[i] != 34){
            auxiliar[j] = texto[i];
            j++;
        }
    }
    auxiliar[j] = '\0';
    return auxiliar;
}

nodo *obtenerUltimoNodo(nodo *lista){
    while(lista && lista -> sgte)
        lista = lista -> sgte;
    return lista;
}

int main(){
  yyin = fopen("entrada.c", "r");
  system("color 71");
  printf("\n\nHolaaa!");
  yylex();
  mostrarLista(&listaDirectivas, 0, "Directivas del Precompilador:\n");
  mostrarLista(&listaPalabrasReservadas, 0, "Palabras reservadas:\n");
  mostrarLista(&listaLiterales, 1, "Literales Cadena:\n");
  mostrarLista(&listaConstantesCaracter, 0, "Constantes Caracter:\n");
  mostrarLista(&listaOperadores, 0, "Operadores:\n");
  mostrarLista(&listaComentariosCortos, 0, "Comentarios Cortos:\n");
  mostrarLista(&listaComentariosLargos, 0, "Comentarios Largos:\n");
}