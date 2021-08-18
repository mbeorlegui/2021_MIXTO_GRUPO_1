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

void insertarOrdenado(char[], nodo **);
void insertarElemento(char[], nodo **);
void mostrarLista(nodo **, int, char *);
int existeEnLaLista(char[], nodo *);
char *sacarComillas(char[]);
nodo *obtenerUltimoNodo(nodo *);
void archivarIdentificadores(nodo **, FILE **);
void archivarLiteralesCadena(nodo **, FILE **);

// Definiciones de funciones, variables y estructuras.