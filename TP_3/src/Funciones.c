#include "Funciones.h"

int buscarEnLista(NODO* lista, char* texto){
    NODO* aux = lista;

    while (aux != NULL){
        if(strcmp(aux->texto, texto) == 0)
            return 1;

        aux = aux->siguiente;    
    }
    
    return 0;
}

void insertarAlFinalDeLaLista(NODO**lista, int numeroDeLinea, enum tipoToken token, char* texto, int longitudTexto){
    if(buscarEnLista(*lista, texto)==0){
        NODO* actual = *lista;
        NODO* nuevo = (NODO*) malloc(sizeof(NODO));

        nuevo->numeroDeLinea = numeroDeLinea;
        nuevo->token = token;
        nuevo->texto = strdup(texto);
        nuevo->longitudDeTexto = longitudTexto;

        if(*lista == NULL){
            nuevo->siguiente = *lista;
            *lista = nuevo;
        }
        else{
            while(actual->siguiente != NULL)
                actual = actual->siguiente; 

            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;
        }
    }
}

int longitudMaximaDeTexto(NODO* lista){
    NODO* aux = lista;
    int maximo = 0;

    while(aux != NULL){
        if(aux->longitudDeTexto > maximo)
            maximo = aux->longitudDeTexto;

        aux = aux->siguiente;
    }

    return maximo;
}

void imprimirListaEnArchivo(FILE* archivo, NODO* lista){
    int i, longMaxima;
    NODO* temp = lista;

    longMaxima = longitudMaximaDeTexto(lista);
    fprintf(archivo, "\n_____________________________________________________________________\n\n");    
    fprintf(archivo, "\tNRO.LINEA\t\tLEXEMA");
    
    // Para alinear la tabla
    for(i = 0; i < (longMaxima - strlen("TOKEN")); i++){
        fprintf(archivo, " ");
    }

    fprintf(archivo, "TOKEN\n");
    fprintf(archivo, "\n_____________________________________________________________________\n\n");

    while(temp != NULL){
        fprintf(archivo, "\t\t%d\t\t\t%s", temp->numeroDeLinea, temp->texto);
        // Para alinear la tabla
        for(i = 0; i < (longMaxima - temp->longitudDeTexto); i++){
            fprintf(archivo, " ");
        }

        switch(temp->token){
            case palabraReservada: fprintf(archivo, "Palabra reservada\n");
                                   break;
            case identificador: fprintf(archivo, "Identificador\n");
                                break;
            case operadorOCaracterDePuntuacion: fprintf(archivo, "Operador o caracter de puntuacion\n");
                                                break;
            case literalCadena: fprintf(archivo, "Literal cadena\n");
                                break;
            case constanteOctal: fprintf(archivo, "Constante octal\n");
                                 break;
        }

        fprintf(archivo, "\n_____________________________________________________________________\n\n");
        temp = temp->siguiente;
    }
}

void liberarMemoriaOcupadaPorLista(NODO* lista){
    if(lista != NULL){
        liberarMemoriaOcupadaPorLista(lista->siguiente);
        free(lista);
    }
}