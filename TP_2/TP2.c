#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

void main(void) {
    system("cls");
    char caracterDeFinalizacion;
    do {
        t_nodo* pila = NULL;
        t_estado estadoPila = {q0, $};
        bool estadoFinalDeLaPila = true, estadoDeError = false;
        char operacion[30], cimaPila;
        int a = 0, i, largoCadena;
        printf("Ingrese la operacion a analizar: ");
        gets(operacion);

        largoCadena = strlen(operacion);

        while (operacion[a] != '\0') {
            while (operacion[a] == ' ') {
                for (i = a; i < largoCadena; i++) {
                    operacion[i] = operacion[i + 1];
                }
                largoCadena--;
            }
            a++;
        }

        printf("Operacion (sin espacios): ");
        puts(operacion);

        recorrerCadena(estadoPila, &pila, operacion, &estadoDeError);
        verificarPilaVacia(&pila, &estadoFinalDeLaPila);

        if (estadoFinalDeLaPila == true && estadoDeError == false)
            printf("La palabra ingresada es sintacticamente correcta\n");

        vaciarPila(&pila);
        printf("Presione ESC para salir del programa o cualquier otra tecla para analizar otra cadena\n");
        fflush(stdin);
        caracterDeFinalizacion = getch();
        fflush(stdin);
        system("cls");

    } while (caracterDeFinalizacion != ESC);
}
