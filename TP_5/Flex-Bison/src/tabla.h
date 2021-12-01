#ifndef TABLA_H
#define TABLA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Variables {
    char *tipo;
    char *nombre;
    int linea;
    struct Variables *sgte;
} Variables;  // Nodo de la lista de variables

typedef struct Funciones {
    char *nombreFuncion;
    char *tipoFuncion;  // Tipo de una funcion = valor que retorna la misma
    struct Variables *l_Parametros;
    struct Funciones *sgte;
} Funciones;  // Nodo de la lista de Funciones

typedef struct Error {
    char caracter;  // Para mostrar el caracter que rompe si es LEXICO unicamente
    int linea;
    int tipo;      // 0 -> Lexico | 1 -> Sintactico | >= 2 -> Semantico
    char *nombre;  // Nombre de la variable o funcion en el error (de ser necesaria, ya que si no es util, no se muestra directamente)
    struct Error *sgte;
} Error;  // Nodo de la lista de Errores

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

int existeVariable(Variables *, char *);
int existeFuncion(Funciones *, char *);
Variables *obtenerUltimoNodoVariables(Variables *);
Funciones *obtenerUltimoNodoFunciones(Funciones *);
Error *obtenerUltimoNodoErrores(Error *);
void insertarErrorNoLexico(Error **, int, char *, int);
void insertarErrorLexico(Error **, char, int);
void insertarVariable(Variables **, char *, char *, int);
void insertarFuncion(Funciones **, char *, char *, Variables **);
void agregarVariableATablaSinRepetir(TS *, Variables, Error **);
void agregarFuncionDefinidaATablaSinRepetir(TS *, Funciones, Error **, Variables **, int);
void agregarFuncionDeclaradaATablaSinRepetir(TS *, Funciones, Error **, Variables **, int);
void mostrarListaVariables(Variables **);
void mostrarListaFunciones(Funciones **);
void mostrarVariablesDeTabla(TS);
void mostrarListaErrores(Error **);
void mostrarFuncionesDeclaradasDeTabla(TS *);
void mostrarFuncionesDefinidasDeTabla(TS);
void vaciarListaVariables(Variables **);
int existeVariableEnTabla(TS *, char *, int, Error **);
char *buscarTipoDatoVariable(Variables *, char *);
char *buscarTipoDatoVariableEnTabla(TS *, char *, int, Error **);
Funciones *obtenerNodoFunciones(Funciones *, char *);
int obtenerCantidadDeParametros(Variables *);
int funcionesTienenIgualCantParametros(Funciones, Variables *);
int todosTiposIguales(Variables *, Variables *);
int sonTiposNoOperables(char *, char *);
int funcionesSonDeDistintoTipo(Funciones *, Funciones);
int sonTiposNoOperables(char *, char *);
int variablesOperablesEntreSi(Variables *, int, Error **);
int existeFuncionDeclaradaEnTabla(TS *, char *, int, Error **);
void agregarListaDeVariablesATablaSinRepetir(TS *, Variables *, Error **);

#endif