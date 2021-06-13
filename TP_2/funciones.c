#include "funciones.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recorrerCadena(t_estado estadoPila, t_pila *pila, char *caracter, bool *estadoDeError) {
    char resultadoPila, ultimoCaraterDeCadena;
    bool igualAOperador;
    int matrizColumna = 0, matrizFila = estadoPila.estado, matrizElegida, quePushear;
    t_estado errorMatrizCero = {q3, $}, errorMatrizUno = {q3, R}, resultadoMatriz;
    t_estado tabla[2][4][6] =
        // Tabla de los $
        {
            {{errorMatrizCero, {q1, $}, errorMatrizCero, {q0, R$}, errorMatrizCero, errorMatrizCero},                  //q0,$
             {{q1, $}, {q1, $}, {q0, $}, errorMatrizCero, errorMatrizCero, errorMatrizCero},                           //q1,$
             {errorMatrizCero, errorMatrizCero, {q0, $}, errorMatrizCero, errorMatrizCero, errorMatrizCero},           //q2,$
             {errorMatrizCero, errorMatrizCero, errorMatrizCero, errorMatrizCero, errorMatrizCero, errorMatrizCero}},  //q3,$

            //Tabla de los R
            {{errorMatrizUno, {q1, R}, errorMatrizUno, {q0, RR}, errorMatrizUno, errorMatrizUno},                 //q0,R
             {{q1, R}, {q1, R}, {q0, R}, errorMatrizUno, {q2, e}, errorMatrizUno},                                //q1,R
             {errorMatrizUno, errorMatrizUno, {q0, R}, errorMatrizUno, {q2, e}, errorMatrizUno},                  //q2,R
             {errorMatrizUno, errorMatrizUno, errorMatrizUno, errorMatrizUno, errorMatrizUno, errorMatrizUno}}};  //q3,R

    agregarCaracter(pila, $);

    while (*caracter != '\0') {
        //printf("%c, ", *caracter);
        ultimoCaraterDeCadena = *caracter;
        resultadoPila = pop(pila);

        if (resultadoPila == '$')
            matrizElegida = $;
        else if (resultadoPila == 'R')
            matrizElegida = R;

        matrizColumna = determinarColumna(*caracter);

        resultadoMatriz = tabla[matrizElegida][matrizFila][matrizColumna];
        matrizFila = resultadoMatriz.estado;
        quePushear = resultadoMatriz.to_push;

        agregarCaracter(pila, quePushear);

        caracter++;
    }

    resultadoPila = pop(pila);

    igualAOperador = distintoDeOperadores(ultimoCaraterDeCadena);
    push(pila, resultadoPila);

    if (matrizColumna == 5) {
        *estadoDeError = true;
        printf("Caracter no reconocido por el programa\n");
    } else {
        if (resultadoMatriz.estado == 0 && resultadoPila == 'R') {
            *estadoDeError = true;
            printf("Se esperan mas caracteres despues de un '('\n");
        } else if (resultadoMatriz.estado == 3 && ultimoCaraterDeCadena == '0' && resultadoPila == '$') {
            *estadoDeError = true;
            printf("El numero ingresado no es reconocido\n");
        } else if (resultadoMatriz.estado == 3 && ultimoCaraterDeCadena == ')' && resultadoPila == '$') {
            *estadoDeError = true;
            printf("Se espera un '('\n");
        } else if (resultadoMatriz.estado == 3 && !igualAOperador && resultadoPila == '$') {
            *estadoDeError = true;
            printf("Se espera un/os numero/s antes o entre de un operador\n");
        } else if (resultadoMatriz.estado == 3 && igualAOperador && resultadoPila == '$') {
            *estadoDeError = true;
            printf("Se espera un/os numero/s entre o despues de algun signo de operacion\n");
        } else if (resultadoMatriz.estado == 0 && resultadoPila == '$') {
            *estadoDeError = true;
            printf("Falta un numero despues de una operacion\n");
        } else if (resultadoMatriz.estado == 3 && ultimoCaraterDeCadena != ')' && resultadoPila == 'R') {
            *estadoDeError = true;
            printf("Falta un numero despues de una operacion\n");
        } else if (resultadoMatriz.estado == 1 && resultadoPila == 'R') {
            *estadoDeError = true;
            printf("Se espera un ')'\n");
        } else if (resultadoMatriz.estado == 2 && resultadoPila == 'R') {
            *estadoDeError = true;
            printf("Se espera un ')'\n");
        } else if (resultadoMatriz.estado == 3 && ultimoCaraterDeCadena == ')' && resultadoPila == 'R') {
            *estadoDeError = true;
            printf("Faltan numeros entre los parentesis\n");
        }
    }
}

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
            columna = 5;
            break;
    }

    return columna;
}

bool distintoDeOperadores(char ultimoCaracter) {
    if (ultimoCaracter != '+' && ultimoCaracter != '-' && ultimoCaracter != '*' && ultimoCaracter != '/')
        return true;
    else
        return false;
}

void agregarCaracter(t_pila *pila, int to_push) {
    switch (to_push) {
        case $:
            push(pila, '$');
            break;
        case R:
            push(pila, 'R');
            break;
        case R$:
            push(pila, '$');
            push(pila, 'R');
            break;
        case RR:
            push(pila, 'R');
            push(pila, 'R');
            break;
        case e:
            break;
        default:
            pop(pila);
            break;
    }
}

void verificarPilaVacia(t_pila *pila, bool *estadoFinalDeLaPila) {
    char resultadoPila;

    resultadoPila = pop(pila);

    if (resultadoPila == '$')
        *estadoFinalDeLaPila = true;
    else
        *estadoFinalDeLaPila = false;
}

void push(t_nodo **pila, char dato) {
    //printf("Hago PUSH de %c\n", dato);
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
    //printf("Hago POP de %c\n", dato);
    return dato;
}

void imprimirLista(t_nodo **pila) {
    t_nodo *aux = *pila;
    while (aux) {
        printf("%c\n", aux->caracter);
        aux = aux->sgte;
    }
}

void vaciarPila(t_pila *pila) {
    char out;
    while (*pila) {
        out = pop(pila);
        printf("%c ", out);
    }
}