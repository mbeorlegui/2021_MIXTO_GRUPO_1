#include "funciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int determinarColumna(char caracter) {
    int columna = -1;

    switch (caracter) {
        case '0':
            columna = 0;
            break;

        case '1' ... '9':
            columna = 1;
            break;

        case '+':
        case '-':
        case '*':
        case '/':
            columna = 2;
            break;

        case '(':
            columna = 3;
            break;

        case ')':
            columna = 4;
            break;
        default:
            break;
    }

    //printf("%d\n", columna);

    return columna;
}

void recorrerCadena(t_estado estadoPila, char *caracter) {
    t_estado error = {q3, e};
    t_estado tabla[2][4][6] =
        {//q0,$                      q1,$            q2,$                q3,$
         {{error, {q1, $}, error, {q0, R$}, error, error},
          {{q1, $}, {q1, $}, {q0, $}, error, error, error},
          {error, error, {q0, $}, error, error, error},
          {error, error, error, error, error, error}},
         //q0,R                      q1,R            q2,R                q3,R
         {{error, {q1, R}, error, {q0, RR}, error, error},
          {{q1, R}, {q1, R}, {q0, R}, error, {q2, e}, error},
          {error, error, {q0, R}, error, {q2, e}, error},
          {error, error, error, error, error, error}}};

    while (*caracter != '\0') {
        printf("%c", *caracter);
        caracter++;
    }
}

void push(t_nodo **pila, char dato) {
    t_nodo *aux;
    aux = (t_nodo *)malloc(sizeof(t_nodo));  // Casteo antes del malloc
    aux->caracter = dato;
    aux->sgte = *pila;
    *pila = aux;
}

char pop(t_nodo **pila) {
    t_nodo *aux;
    aux = (t_nodo *)malloc(sizeof(t_nodo));
    aux = *pila;
    *pila = aux->sgte;
    char dato = aux->caracter;
    free(aux);
    return dato;
}

void imprimirLista(t_nodo **pila) {
    t_nodo *aux = *pila;

    while (aux) {
        printf("%c\n", aux->caracter);
        aux = aux->sgte;
    }
}
