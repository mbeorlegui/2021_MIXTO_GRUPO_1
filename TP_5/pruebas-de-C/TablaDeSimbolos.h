#ifndef TABLADESIMBOLOS_H 
#define TABLADESIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Variables{
    char* tipo;
    char* nombre;
    int linea;
    struct Variables *sgte;
} Variables;  // Nodo de la lista de variables

typedef struct Funciones{
    char* nombreFuncion;
    char* tipoFuncion;     // Tipo de una funcion = valor que retorna la misma
    struct Variables *l_Parametros;
    struct Funciones *sgte;
} Funciones;  // Nodo de la lista de Funciones

typedef struct Error{
  char caracter; // Para mostrar el caracter que rompe si es LEXICO unicamente
  int linea;
  int tipo;     // 0 -> Lexico | 1 -> Sintactico | >= 2 -> Semantico
  struct Error *sgte;
} Error;      // Nodo de la lista de Errores

typedef struct TS {
  Variables *l_Variables;
  Funciones *l_FuncionesDefinidas;
  Funciones *l_FuncionesDeclaradas;
} TS;

/*
  Tipos de errores semanticos:
    2 -> Cantidad de parametros de funcion
    3 -> Tipos de parametros de funcion
    4 -> Multiple declaracion de variable
    5 -> Multiple declaracion de funcion
    6 -> Multiple definicion de funcion
    7 -> Validacion de tipo en alguna operacion binaria
*/


TS tabla = {
  .l_Variables = NULL,
  .l_FuncionesDefinidas = NULL,
  .l_FuncionesDeclaradas = NULL
};

Variables* listaDeVariables = NULL;
Funciones* listaDeFunciones = NULL;
Error* listaDeErrores = NULL;

int existeVariable(Variables *, char *);
int existeFuncion(Funciones *, char *);
Variables *obtenerUltimoNodoVariables(Variables *);
Funciones *obtenerUltimoNodoFunciones(Funciones *);
void insertarVariable(Variables **, char *, char *, int );
void insertarFuncion(Funciones **, char *, char *);
void agregarFuncionDefinidaATablaSinRepetir(TS *, Funciones);
void agregarFuncionDeclaradaATablaSinRepetir(TS *, Funciones);
void agregarVariableATablaSinRepetir(TS *, Variables);
void mostrarListaVariables(Variables **);
void mostrarListaFunciones(Funciones **);
void mostrarListaErrores(Error **);
Error *obtenerUltimoNodoErrores(Error *);
void insertarErrorNoLexico(Error **, int, char *, int);
void mostrarVariablesDeTabla(TS);


#endif