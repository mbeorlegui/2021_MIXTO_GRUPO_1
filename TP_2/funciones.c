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

    return columna;
}

void recorrerCadena(t_estado estadoPila, t_pila *pila, char *caracter) {
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

    int matrizColumna = 5, matrizFila = estadoPila.estado, matrizElegida;
    int quePushear;
    char resultadoPila;

    while (*caracter != '\0') {
        printf("Entro al while\n");
        resultadoPila = pop(pila);

        if (resultadoPila == '$')
            matrizElegida = $;
        else if (resultadoPila == 'R')
            matrizElegida = R;

        matrizColumna = determinarColumna(*caracter);

        t_estado resultadoMatriz = tabla[matrizElegida][matrizFila][matrizColumna];
        matrizFila = resultadoMatriz.estado;
        quePushear = resultadoMatriz.to_push;

        agregarCaracter(pila, quePushear);

        caracter++;
    }
}

void push(t_nodo **pila, char dato) {
    printf("Hago PUSH de %c\n", dato);
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
    printf("Hago POP de %c\n", dato);
    return dato;
}

void imprimirLista(t_nodo **pila) {
    t_nodo *aux = *pila;

    while (aux) {
        printf("%c\n", aux->caracter);
        aux = aux->sgte;
    }
}

void agregarCaracter(t_pila *pila, int to_push) {
    switch (to_push) {
        case $:
            printf("Pusheo $\n");
            push(pila, '$');
            break;
        case R:
            printf("Pusheo R\n");
            push(pila, 'R');
            break;
        case R$:
            printf("Pusheo R$\n");
            push(pila, '$');
            push(pila, 'R');
            break;
        case RR:
            printf("Pusheo RR\n");
            push(pila, 'R');
            push(pila, 'R');
            break;
        case e:
            printf("No pusheo\n");
        default:
            printf("No pusheo x2\n");
            break;
    }
}
