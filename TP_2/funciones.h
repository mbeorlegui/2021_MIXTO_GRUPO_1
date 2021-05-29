#ifndef FUNCIONES_H
#define FUNCIONES_H

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
void recorrerCadena(t_estado, char *);

#endif