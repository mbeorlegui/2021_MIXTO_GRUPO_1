#include "TablaDeSimbolos.h"

/*

Para compilar: gcc -o TS TablaDeSimbolos.c
Para correr: ./TS

*/

int existeVariable(Variables *listaDeVariables, char *nombreVariable) {  // Esta funcion anda
    if (listaDeVariables == NULL)
        return 0;
    else if (strcmp(listaDeVariables->nombre, nombreVariable) == 0)
        return 1;
    else
        return existeVariable(listaDeVariables->sgte, nombreVariable);  // Utilizo recursividad
}

int existeFuncion(Funciones *listaDeFunciones, char *funcionABuscar) {
    if (listaDeFunciones == NULL)
        return 0;
    else if (strcmp(listaDeFunciones->nombreFuncion, funcionABuscar) == 0)
        return 1;
    else
        return existeFuncion(listaDeFunciones->sgte, funcionABuscar);
}

Variables *obtenerUltimoNodoVariables(Variables *listaDeVariables) {
    while (listaDeVariables && listaDeVariables->sgte)
        listaDeVariables = listaDeVariables->sgte;
    return listaDeVariables;
}

Funciones *obtenerUltimoNodoFunciones(Funciones *listaDeFunciones) {
    while (listaDeFunciones && listaDeFunciones->sgte)
        listaDeFunciones = listaDeFunciones->sgte;
    return listaDeFunciones;
}

Error *obtenerUltimoNodoErrores(Error *listaDeErrores) {
    while (listaDeErrores && listaDeErrores->sgte)
        listaDeErrores = listaDeErrores->sgte;
    return listaDeErrores;
}

void insertarErrorNoLexico(Error **listaDeErrores, int tipoError, char* cadena, int lineaDeError) {
    // TODO
}
void insertarErrorLexico(Error **listaDeErrores, char caracter, int lineaDeError) {
    int tipoError = 0; // Por defecto el error es de tipo 0 (lexico)
    // TODO
}

void insertarVariable(Variables **listaDeVariables, char *nombreVariable, char *tipoVariable, int lineaDeclaracion) {
    Variables *lista_aux;
    //si hay algo en la lista, inserto un Nodo nuevo luego del ultimo y lo "lleno"
    if (*listaDeVariables) {
        lista_aux = obtenerUltimoNodoVariables(*listaDeVariables);
        lista_aux->sgte = malloc(sizeof(Variables));
        lista_aux = lista_aux->sgte;
        lista_aux->nombre = strdup(nombreVariable);
        lista_aux->tipo = strdup(tipoVariable);
        lista_aux->linea = lineaDeclaracion;
        lista_aux->sgte = NULL;
        //si la listaDeVariables esta vacia, simplemente creo el Nodo y lo "lleno"
    } else {
        *listaDeVariables = malloc(sizeof(Variables));
        (*listaDeVariables)->nombre = strdup(nombreVariable);
        (*listaDeVariables)->tipo = strdup(tipoVariable);
        (*listaDeVariables)->linea = lineaDeclaracion;
        (*listaDeVariables)->sgte = NULL;
    }
}

void insertarFuncion(Funciones **listaDeFunciones, char *nombreDeFuncion, char *tipoDeFuncion) {
    Funciones *lista_aux;
    if (*listaDeFunciones) {
        lista_aux = obtenerUltimoNodoFunciones(*listaDeFunciones);
        lista_aux->sgte = malloc(sizeof(Funciones));
        lista_aux = lista_aux->sgte;
        lista_aux->nombreFuncion = strdup(nombreDeFuncion);
        lista_aux->tipoFuncion = strdup(tipoDeFuncion);
        lista_aux->sgte = NULL;
    } else {
        *listaDeFunciones = malloc(sizeof(Funciones));
        (*listaDeFunciones)->nombreFuncion = strdup(nombreDeFuncion);
        (*listaDeFunciones)->tipoFuncion = strdup(tipoDeFuncion);
        (*listaDeFunciones)->sgte = NULL;
    }
}

void agregarFuncionDefinidaATablaSinRepetir(TS *tablaDeSimbolos, Funciones nodoFuncion) {
    int resultadoDeBusqueda;
    Funciones *listaAux = (*tablaDeSimbolos).l_FuncionesDefinidas;

    resultadoDeBusqueda = existeFuncion(listaAux, nodoFuncion.nombreFuncion);

    if (resultadoDeBusqueda == 0) {
        insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDefinidas, nodoFuncion.nombreFuncion, nodoFuncion.tipoFuncion);
    } else {
        //insertarErrorNoLexico(&listaDeErrores, 6, nodoFuncion.nombreFuncion, lineaDeError);
        printf("ERROR, LA FUNCION YA EXISTE EN LA TABLA DE SIMBOLOS (ya fue definida previamente)\n");
        // Agregar a lista de error con el tipo 6
    }
}

void agregarFuncionDeclaradaATablaSinRepetir(TS *tablaDeSimbolos, Funciones nodoFuncion) {
    int resultadoDeBusqueda;
    Funciones *listaAux = (*tablaDeSimbolos).l_FuncionesDeclaradas;

    resultadoDeBusqueda = existeFuncion(listaAux, nodoFuncion.nombreFuncion);

    if (resultadoDeBusqueda == 0) {
        insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDeclaradas, nodoFuncion.nombreFuncion, nodoFuncion.tipoFuncion);
    } else {
        //insertarErrorNoLexico(&listaDeErrores, 5, nodoFuncion.nombreFuncion, lineaDeError)
        printf("ERROR, LA FUNCION YA EXISTE EN LA TABLA DE SIMBOLOS (ya fue declarada previamente)\n");
        // Agregar a lista de error con el tipo 5
    }
}

void agregarVariableATablaSinRepetir(TS *tablaDeSimbolos, Variables nodoVariable) {  // Esta hay que probarla todavia
    int resultadoDeBusqueda;
    Variables *listaAux = (*tablaDeSimbolos).l_Variables;

    resultadoDeBusqueda = existeVariable(listaAux, nodoVariable.nombre);

    if (resultadoDeBusqueda == 0) {
        insertarVariable(&(*tablaDeSimbolos).l_Variables, nodoVariable.nombre, nodoVariable.tipo, nodoVariable.linea);
    } else {
        insertarErrorNoLexico(&listaDeErrores, 4, nodoVariable.nombre, nodoVariable.linea);
        printf("ERROR, LA VARIABLE YA EXISTE EN LA TABLA DE SIMBOLOS (fue declarada previamente)\n");
        // Agregar a lista de error con el tipo 4
    }
}

void mostrarListaVariables(Variables **listaDeVariables) {
    Variables *actual = *listaDeVariables;

    while (actual != NULL) {
        printf("\nNombre de la variable: %s", actual->nombre);
        printf("\nTipo de la variable: %s", actual->tipo);
        printf("\nLinea de declaracion: %d\n", actual->linea);
        actual = actual->sgte;
    }
}

void mostrarListaFunciones(Funciones **listaDeFunciones) {
    Funciones *actual = *listaDeFunciones;

    while (actual != NULL) {
        printf("\nNombre de la funcion: %s", actual->nombreFuncion);
        printf("\nTipo de la funcion: %s\n", actual->tipoFuncion);
        actual = actual->sgte;
    }
}

void mostrarListaErrores(Error **listaDeError) {
    Error *actual = *listaDeError;

    while (actual != NULL) {
        if (actual->tipo == 0) {
            printf("Error léxico en linea %d ", actual->linea);
            printf("debido a caracter %c\n", actual->caracter);
        }
        if (actual->tipo == 1) {
            printf("Error sintáctico en linea %d ", actual->linea);
        }
        if (actual->tipo >= 2) {
            printf("Error semántico en linea %d ", actual->linea);
            printf("debido a: ");
            if (actual->tipo == 2)
                printf("La cantidad de parametros de la funcion no coinciden\n");
            if (actual->tipo == 3)
                printf("Los tipos de parametro de la funcion no coinciden\n");
            if (actual->tipo == 4)
                printf("Multiple declaracion de variable\n");
            if (actual->tipo == 5)
                printf("Multiple declaracion de funcion\n");
            if (actual->tipo == 6)
                printf("Multiple definicion de funcion\n");
            if (actual->tipo == 7)
                printf("Validacion de tipo en alguna operacion\n");
        }
        actual = actual->sgte;
    }
}

void mostrarVariablesDeTabla(TS tabla) {
    Variables *actual = tabla.l_Variables;
    int contador = 1;
    while (actual != NULL) {
        printf("Variable numero: %d\n", contador);
        printf("Nombre de variable: %s\n", actual->nombre);
        printf("Tipo de variable: %s\n", actual->tipo);
        printf("Linea de decalracion: %d\n\n", actual->linea);

        contador += 1;
        actual = actual->sgte;
    }
}

int main() {
    Variables variableDePrueba;
    Variables variableDePrueba2;
    Variables funcionDePrueba1;
    Variables funcionDePrueba2;

    variableDePrueba.nombre = strdup("nombreVariable1");
    variableDePrueba.tipo = strdup("tipoVariable1");
    variableDePrueba.linea = 7;

    variableDePrueba.nombre = strdup("nombreVariable2");
    variableDePrueba.tipo = strdup("tipoVariable2");
    variableDePrueba.linea = 542;

    agregarVariableATablaSinRepetir(&tabla, variableDePrueba);
    agregarVariableATablaSinRepetir(&tabla, variableDePrueba2);
    agregarVariableATablaSinRepetir(&tabla, variableDePrueba2);

    printf("\n\nMOSTRANDO VARIABLES DE LA TS\n\n");
    mostrarVariablesDeTabla(tabla);

    printf("\n\nMOSTRANDO LISTA DE ERRORES\n");
    mostrarListaErrores(&listaDeErrores);
}
