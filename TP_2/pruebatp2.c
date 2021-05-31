#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char caracter;
    struct nodo *sgte;
} t_nodo;

typedef t_nodo *t_pila;

enum to_push {
    $,
    R,
    R$,
    RR,
    e
};

enum estados {
    q0,
    q1,
    q2,
    q3
};

typedef struct estadoAutomata {
    int estado;
    int to_push;
} t_estado;

void push(t_nodo **, char);
char pop(t_nodo **);
void imprimirLista(t_nodo **);
int determinarColumna(char);
void verificarPilaVacia(t_pila *, bool *);
void recorrerCadena(t_estado, t_pila *, char *, bool *);
void agregarCaracter(t_pila *, int);

void main(void) {
    t_nodo *pila = NULL;
    bool estadoFinalDeLaPila = true, estadoDeError = false;
    t_estado estadoPila = {q0, $};
    char operacion[30];

    agregarCaracter(&pila, $);

    printf("Ingrese la operacion a analizar: ");
    scanf("%29s", operacion);

    recorrerCadena(estadoPila, &pila, operacion, &estadoDeError);
    verificarPilaVacia(&pila, &estadoFinalDeLaPila);

    if (estadoFinalDeLaPila == false || estadoDeError == true)
        printf("La operacion ingresada es sintacticamente incorrecta\n");
    else
        printf("La palabra ingresada es sintacticamente correcta\n");
}

void recorrerCadena(t_estado estadoPila, t_pila *pila, char *caracter, bool *estadoDeError) {
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

    int matrizColumna = 0, matrizFila = estadoPila.estado, matrizElegida;
    int quePushear;
    char resultadoPila;

    while (*caracter != '\0') {
        printf("%c\n", *caracter);
        resultadoPila = pop(pila);

        if (resultadoPila == '$')
            matrizElegida = $;
        else if (resultadoPila == 'R')
            matrizElegida = R;

        matrizColumna = determinarColumna(*caracter);

        resultadoMatriz = tabla[matrizElegida][matrizFila][matrizColumna];
        printf("Voy al estado:%i\n", resultadoMatriz.estado);
        matrizFila = resultadoMatriz.estado;
        quePushear = resultadoMatriz.to_push;

        agregarCaracter(pila, quePushear);

        caracter++;
    }

    printf("Me quede en el estado:%i\n", resultadoMatriz.estado);

    if (resultadoMatriz.estado == error.estado && resultadoPila == '$') {
        *estadoDeError = true;
        printf("Se espera un '('\n");
    } else if (resultadoMatriz.estado == q0 && resultadoPila == '$') {
        *estadoDeError = true;
        printf("Falta un numero despues de una operacion\n");
    } else if (resultadoMatriz.estado != error.estado && resultadoPila == 'R') {
        *estadoDeError = true;
        printf("Se espera un ')'\n");
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
            break;
    }

    return columna;
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

void verificarPilaVacia(t_pila *pila, bool *estadoFinalDeLaPila) {
    char resultadoPila;

    resultadoPila = pop(pila);

    if (resultadoPila == '$')
        *estadoFinalDeLaPila = true;
    else
        *estadoFinalDeLaPila = false;
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