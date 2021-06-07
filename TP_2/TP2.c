#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

void main(void) {
    t_nodo* pila = NULL;
    bool estadoFinalDeLaPila = true, estadoDeError = false;
    t_estado estadoPila = {q0, $};
    char operacion[30], cimaPila;
    int a=0, i, largo;

    printf("Ingrese la operacion a analizar: ");
    gets(operacion);
    
    printf("Operacion (con espacios): ");
    puts(operacion);
    
    largo=strlen(operacion);
    
    while(operacion[a]!='\0'){
        while(operacion[a]==' '){
            for(i=a;i<largo;i++){ 
                operacion[i]=operacion[i+1];
            }
        largo--;
        }
        a++;  
    } 

    recorrerCadena(estadoPila, &pila, operacion, &estadoDeError);
    verificarPilaVacia(&pila, &estadoFinalDeLaPila);

    if (estadoFinalDeLaPila == true && estadoDeError == false)
        printf("La palabra ingresada es sintacticamente correcta\n");
}
