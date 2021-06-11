#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESC 27

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

typedef struct estadoAutomata {
    int estado;
    int to_push;
} t_estado;

void push(t_pila *, char);
char pop(t_pila *);
void imprimirLista(t_pila *);
void vaciarPila(t_pila *);

int main() {
    t_pila pila = NULL;
    char caracterDeFinalizacion;
    char operacion[30];

    push(&pila, '$');
    push(&pila, '$');
    push(&pila, '$');
    push(&pila, '$');
    push(&pila, '$');
    imprimirLista(&pila);
    vaciarPila(&pila);
    imprimirLista(&pila);
    imprimirLista(&pila);
    do {
        printf("Ingrese la operacion a analizar: ");
        fflush(stdin);
        gets(operacion);

        //Todo lo referido al automata

        printf("\nTermino de procesar el string\n");
        printf("Presione ESC para salir del programa o cualquier otra tecla para analizar otra cadena\n");
        fflush(stdin);
        caracterDeFinalizacion = getch();
        fflush(stdin);
        system("cls");
    } while (caracterDeFinalizacion != ESC);
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
    //printf("Hago POP de %c\n", dato);
    return dato;
}

void vaciarPila(t_pila *pila) {
    char out;
    while (*pila) {
        out = pop(pila);
        printf("%c ", out);
    }
}

void imprimirLista(t_nodo **pila) {
    t_nodo *aux = *pila;
    while (aux) {
        printf("%c ", aux->caracter);
        if (aux->sgte)
            printf("-> ");
        aux = aux->sgte;
    }
    printf("\n");
}
