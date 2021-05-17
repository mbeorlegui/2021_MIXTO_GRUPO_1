#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum estados {  //Los distintos estados que tendra el AFP
    q0,
    q1,
    q2,
    ERROR 
};

enum alfabetoPila { //Las distintas combinaciones que se pueden dar con el alfabeto dado
    R,
    $,
    epsilon,
    RR,
    R$
};

typedef enum estados EstadosAutomata;
typedef enum alfabetoPila Alfabeto;

typedef struct matrizAutomata{
    EstadosAutomata estadoAutomata;
    Alfabeto alfabeto;
}t_estadoAutomata;

typedef struct nodo {
    char caracter;
    struct nodo *sgte;
} t_nodo;

typedef t_nodo *t_pila;

void push(t_nodo **, char);
char pop(t_nodo **);
void imprimirLista(t_nodo **);

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

void ingresoDeDatos(char caracter){
    int primerEstado = q0;
    char seguirIngresando = 'S';

    while(seguirIngresando == 's' || seguirIngresando == 'S'){
        printf("Ingrese un caracter: ");
        scanf("%c\n", &caracter);

        recorridoDelAutomata(caracter, primerEstado);
        printf("Desea seguir ingresando caracteres: ");
        scanf("%c\n", &seguirIngresando);
    }
}

int recorridoDelAutomata(char caracter, int estado){
    int q3 = ERROR;

    t_estadoAutomata tabla[6][5] = {  //Matriz del AFP
        {q3, (q1, $), q3, (q0, R$), q3},
        {(q1, $), (q1, $), (q0, $), q3, q3},
        {q3, (q1, R), q3, (q0, RR), q3},
        {(q1, R), (q1, R), (q0, R), q3, (q2,  epsilon)},
        {q3, q3, (q0, R), q3, (q2, epsilon)},
        {q3, q3, (q0, $), q3, q3}};


}