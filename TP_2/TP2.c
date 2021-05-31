#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "funciones.h"

void main(void) {
    t_nodo* pila = NULL;
    bool estadoFinalDeLaPila = true, estadoDeError = false;
    t_estado estadoPila = {q0, $};
    char operacion[30], cimaPila;


    printf("Ingrese la operacion a analizar: ");
    scanf("%29s", operacion);

    recorrerCadena(estadoPila, &pila, operacion, &estadoDeError);
    verificarPilaVacia(&pila, &estadoFinalDeLaPila);

    if(estadoFinalDeLaPila == false || estadoDeError == true)
        printf("La operacion ingresada es sintacticamente incorrecta\n");
    else
        printf("La palabra ingresada es sintacticamente correcta\n");
}
