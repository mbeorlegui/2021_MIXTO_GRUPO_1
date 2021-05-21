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
void ingresoDeDatos(char, t_nodo*);
int recorridoDelAutomata(char, t_estadoAutomata, t_nodo*);

int main(void) {
    t_nodo *pila = NULL;
    char caracter;

    push(&pila, '$');
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

void ingresoDeDatos(char caracter, t_nodo *pila){
    t_estadoAutomata primerEstado;
    primerEstado.estadoAutomata = q1;
    char seguirIngresando = 'S';

    while(seguirIngresando == 's' || seguirIngresando == 'S'){
        printf("Ingrese un caracter: ");
        scanf("%c\n", &caracter);

        recorridoDelAutomata(caracter, primerEstado, &pila);
        printf("Desea seguir ingresando caracteres: ");
        scanf("%c\n", &seguirIngresando);
    }
}

int recorridoDelAutomata(char caracter, t_estadoAutomata estado, t_nodo *pila){
    int q3 = ERROR, estadoActual;

    t_estadoAutomata tabla[6][5] = {  //Matriz del AFP
        {q3, (q1, $), q3, (q0, R$), q3},
        {(q1, $), (q1, $), (q0, $), q3, q3},
        {q3, (q1, R), q3, (q0, RR), q3},
        {(q1, R), (q1, R), (q0, R), q3, (q2,  epsilon)},
        {q3, q3, (q0, R), q3, (q2, epsilon)},
        {q3, q3, (q0, $), q3, q3}};

    /*switch (caracter)  // REVISAR
    {
    case '0':
        estado = tabla[estado.estadoAutomata][0];
        if(estadoActual == (q1, $))
            push(&pila, '$');
        else if(estadoActual == (q1, R))
            push(&pila, 'R');
        break;
    case '[1-9]':
        estado = tabla[estado.estadoAutomata][1];
        if(estadoActual == (q1, $) && estado.estadoAutomata == q0){
            //pop(&pila);
            //push(&pila, '$');
        }
        else if(estadoActual == (q1, $) && estado.estadoAutomata == q1){
            //pop(&pila);
           //push(&pila, '$');
        }
        else if(estadoActual == (q1, R) && estado.estadoAutomata == q0){

        }
        break;
    case '+':
    case '-':
    case '*':
    case '/': 
        estado = tabla[estado.estadoAutomata][2];
        break;

        break;
    
    default:
        break;
    } */
}