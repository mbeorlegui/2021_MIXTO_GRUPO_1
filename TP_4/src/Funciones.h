#ifndef FUNCIONES_H 
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    char *info;
    int linea;
    char *tipo;
    struct Nodo *siguiente;
}Nodo;

void mostrarLista(Nodo **, int);
void insertarElemento(Nodo **,char*, char*, int);
Nodo *obtenerUltimoNodo(Nodo *);
int separarPorTipos(char *);


#endif