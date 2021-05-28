#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char caracter;
    struct nodo *sgte;
} t_nodo;

typedef t_nodo *t_pila;

void push(t_nodo **, char);
char pop(t_nodo **);
void imprimirLista(t_nodo **);
int determinarColumna(char);

int main(void) {
    t_nodo *pila = NULL;

    push(&pila, 'h');
    imprimirLista(&pila);

    char out = pop(&pila);
    printf("\nEl ultimo dato sacado de la pila es: %c", out);
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