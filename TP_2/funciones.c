#include "funciones.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recorrerCadena(t_estado estadoPila, t_pila *pila, char *caracter, bool *estadoDeError) {
     char cimaPila, resultadoPila, ultimoCaraterDeCadena;
     bool igualAOperador;
     int matrizColumna = 0, matrizFila = estadoPila.estado, matrizElegida, quePushear;
    t_estado error = {q3, e}, resultadoMatriz;
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

    push(pila, $); 
    agregarCaracter(pila, $, &cimaPila);

    while (*caracter != '\0' && resultadoMatriz.estado != 3) {
        //printf("%c\n", *caracter);
        ultimoCaraterDeCadena = *caracter;
        resultadoPila = pop(pila);

        if (resultadoPila == '$')
            matrizElegida = $;
        else if (resultadoPila == 'R')
            matrizElegida = R;

        matrizColumna = determinarColumna(*caracter);

        resultadoMatriz = tabla[matrizElegida][matrizFila][matrizColumna];
        //printf("Voy al estado: q%i", resultadoMatriz.estado);
        matrizFila = resultadoMatriz.estado;
        quePushear = resultadoMatriz.to_push;

        agregarCaracter(pila, quePushear, &cimaPila);

        caracter++;
    }

    //printf("Me quede en el estado: q%i\n", resultadoMatriz.estado);
    //printf("Cima de la pila: %c\n", cimaPila);
    igualAOperador = distintoDeOperadores(ultimoCaraterDeCadena);
    
    if(matrizColumna == 5){
        *estadoDeError = true;
        printf("Caracter no reconocido por el programa\n");
    }
    else{
        if(resultadoMatriz.estado == 3 && cimaPila == '$' && ultimoCaraterDeCadena == '0'){
        *estadoDeError = true;
        printf("El numero ingresado no es reconocido\n");
        }  
        else if(resultadoMatriz.estado == 3 && cimaPila == '$' && ultimoCaraterDeCadena == ')'){
            *estadoDeError = true;
            printf("Se espera un '('\n");
        }   
        else if(resultadoMatriz.estado == 3 && cimaPila == '$' && !igualAOperador){
            *estadoDeError = true;
            printf("Se espera un/os numero/s antes o entre de un operador\n");
        }
        else if(resultadoMatriz.estado == 3 && cimaPila == '$' && igualAOperador){
            *estadoDeError = true;
            printf("Se espera un/os numero/s entre o despues de algun signo de operacion\n");
        }
        else if(resultadoMatriz.estado == 0 && cimaPila == '$'){  ///CHEQUEAR
            *estadoDeError = true;
            printf("Falta un numero despues de una operacion\n");
        }
        else if(resultadoMatriz.estado == 3 && cimaPila == 'R' && ultimoCaraterDeCadena != ')'){  
            *estadoDeError = true;
            printf("Falta un numero despues de una operacion\n");
        }
        else if(resultadoMatriz.estado == 1 && cimaPila == 'R'){
            *estadoDeError = true;
            printf("Se espera un ')'\n");
        }
        else if(resultadoMatriz.estado == 2 && cimaPila == 'R'){
            *estadoDeError = true;
            printf("Se espera un ')'\n");
        }
        else if(resultadoMatriz.estado == 3 && cimaPila == 'R' && ultimoCaraterDeCadena == ')'){
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

void agregarCaracter(t_pila *pila, int to_push, char *cimaPila) {
    switch (to_push) {
        case $:
            //printf(" Pusheo $\n");
            push(pila, '$');
            *cimaPila = '$';
            break;
        case R:
            //printf(" Pusheo R\n");
            push(pila, 'R');
            *cimaPila = 'R';
            break;
        case R$:
            //printf(" Pusheo R$\n");
            push(pila, '$');
            push(pila, 'R');
            *cimaPila = 'R';
            break;
        case RR:
            //printf(" Pusheo RR\n");
            push(pila, 'R');
            push(pila, 'R');
            *cimaPila = 'R';
            break;
        case e:
            //printf(" No pusheo\n");
            break;
        default:
            //printf(" No pusheo\n");
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