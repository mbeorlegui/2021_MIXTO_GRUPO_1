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
void ingresoDeDatos(t_nodo*);
int recorridoDelAutomata(char*, EstadosAutomata, t_nodo*);
void verificarPilaVacia(t_nodo*);

int main(void) {
    t_nodo *pila = NULL;
    push(&pila, '$');
    //imprimirLista(&pila);
    ingresoDeDatos(&pila);
    //char out = pop(&pila);
    //printf("\nEl ultimo dato sacado de la pila es: %c", out);
    verificarPilaVacia(&pila);
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

void ingresoDeDatos(t_nodo *pila){
    char caracter[50];
    EstadosAutomata estado = q0;
    //char seguirIngresando = 'S';

    //while(seguirIngresando == 's' || seguirIngresando == 'S'){
    printf("Ingrese un caracter: ");
    scanf("%s\n", &caracter);
    recorridoDelAutomata(caracter, estado, &pila);
        //printf("Desea seguir ingresando caracteres: ");
       // scanf("%c\n", &seguirIngresando);
    //}
}

int recorridoDelAutomata(char *caracter, EstadosAutomata estado, t_nodo *pila){
    t_estadoAutomata q3 = {ERROR, epsilon}, estadoActual;
    char resultadoPila;
    int matrizElegida, matrizFila, matrizColumna, quePushear;

    t_estadoAutomata tabla[1][2][4] = {  //Matriz del AFP
        {{q3, {q1, $}, q3, {q0, R$}, q3},
        {{q1, $}, {q1, $}, {q0, $}, q3, q3},
        {q3, {q1, R}, q3, {q0, RR}, q3}},
        
        {{{q1, R}, {q1, R}, {q0, R}, q3, {q2, epsilon}},
        {q3, q3, {q0, R}, q3, {q2,  epsilon}},
        {q3, q3, {q0, $}, q3, q3}}};

    
    matrizFila = estado;

    while(*caracter != '\0'){
        resultadoPila = pop(&pila);

        if(resultadoPila == '$')
            matrizElegida = 0;
        else if(resultadoPila == 'R')
            matrizElegida = 1;
       
        switch (*caracter){
        case '0':
            matrizColumna = 0;
            break;
        case '1' ... '9':
            matrizColumna = 1;
            break;
        case '+':
        case '-':
        case '*':
        case '/': 
            matrizColumna = 2;
            break;
        
        case '(': 
            matrizColumna = 3;
            break;

        case ')':
            matrizColumna = 4;
            break;
        
        default:
            break;
        } 
        caracter++;

        quePushear = tabla[matrizElegida][matrizFila][matrizColumna].alfabeto;

        switch (quePushear)
        {
            case 0:
                push(&pila, 'R');
                break;
            case 1: 
                push(&pila, '$');
                break;
            case 2:
                break;
            case 3:
                push(&pila, 'R');
                push(&pila, 'R');
                break;
            case 4: 
                push(&pila, '$');
                push(&pila, 'R');
                break;
        }
        matrizFila = tabla[matrizElegida][matrizFila][matrizColumna].estadoAutomata;
    }

    //VAMOS A TENER EL ESTADO ACTUAL Y EL ELEMENTO DE LA PILA ACA
}

void verificarPilaVacia(t_nodo *pila){
    char resultadoPila;
    
    pop(&pila);

    if(resultadoPila == '$')
        printf("La pila se vacio correctamente");
    else
        printf("ERROR, la pila no vacia");
}