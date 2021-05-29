#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

void main(void) {
    t_nodo* pila = NULL;
    t_estado estadoPila = {q0, $};
    char operacion[30];

    push(&pila, $);  // <-- Cambiar tipo de dato de pila

    printf("Ingrese la operacion a analizar: ");
    scanf("%29s", operacion);

    recorrerCadena(estadoPila, operacion);
}
