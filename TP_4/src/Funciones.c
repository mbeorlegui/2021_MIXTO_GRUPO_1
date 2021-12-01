#include "Funciones.h"

void insertarElemento(Nodo **lista, char *tipoDeVariable, char *infoDeVariable, int lineaDeclaracion) {
    Nodo *lista_aux;
    //si hay algo en la lista, inserto un Nodo nuevo luego del ultimo y lo "lleno"
    if (*lista) {
        lista_aux = obtenerUltimoNodo(*lista);
        lista_aux->siguiente = malloc(sizeof(Nodo));
        lista_aux = lista_aux->siguiente;
        lista_aux->tipo = strdup(tipoDeVariable);
        lista_aux->info = strdup(infoDeVariable);
        lista_aux->linea = lineaDeclaracion;
        lista_aux->siguiente = NULL;
        //si la lista esta vacia, simplemente creo el Nodo y lo "lleno"
    } else {
        *lista = malloc(sizeof(Nodo));
        (*lista)->tipo = strdup(tipoDeVariable);
        (*lista)->info = strdup(infoDeVariable);
        (*lista)->linea = lineaDeclaracion;
        (*lista)->siguiente = NULL;
    }
}

int existeElementoEnLista(){
    // TODO
    return 1;
}

Nodo *obtenerUltimoNodo(Nodo *lista) {
    while (lista && lista->siguiente)
        lista = lista->siguiente;

    return lista;
}

void mostrarLista(Nodo **lista,int texto) {
    Nodo *actual = *lista;
    
    while (actual != NULL) {
        
        if(texto==1){printf("\nSe declara \"%s\" en la linea %d", actual->info, actual->linea);}
        if(texto==2){printf("\nHay error lexico en la linea %d debido a: \"%s\"", actual->linea,actual->info);}
        if(texto==3){printf("\nHay error sintactico en la linea %d ", actual->linea);}
        if(texto==4){printf("\nSe declara \"%s\" de tipo \"%s\" en la linea %d", actual->info, actual->tipo, actual->linea);}
        if(texto==5){printf("\nSe define \"%s\" de tipo \"%s\" en la linea %d", actual->info, actual->tipo, actual->linea);}
        if(texto==6){printf("\nParametro \"%s\" de tipo \"%s\" en la linea %d", actual->info, actual->tipo, actual->linea);}
        actual = actual->siguiente;
    }
}
