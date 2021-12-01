#include "TablaDeSimbolos.h"

/*
    Para compilar: gcc -o TS TablaDeSimbolos.c
    Para correr: ./TS
*/

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

void insertarErrorNoLexico(Error **listaDeErrores, int tipoError, char *cadena, int lineaDeError) {
    Error *lista_aux;
    if (*listaDeErrores) {
        lista_aux = obtenerUltimoNodoErrores(*listaDeErrores);
        lista_aux->sgte = malloc(sizeof(Error));
        lista_aux = lista_aux->sgte;
        lista_aux->tipo = tipoError;
        lista_aux->nombre = strdup(cadena);
        lista_aux->linea = lineaDeError;
        lista_aux->sgte = NULL;
    } else {
        *listaDeErrores = malloc(sizeof(Error));
        (*listaDeErrores)->tipo = tipoError;
        (*listaDeErrores)->linea = lineaDeError;
        (*listaDeErrores)->nombre = strdup(cadena);
        (*listaDeErrores)->sgte = NULL;
    }
}

void insertarErrorLexico(Error **listaDeErrores, char caracter, int lineaDeError) {
    int tipoError = 0;  // Por defecto el error es de tipo 0 (lexico)
    Error *lista_aux;
    if (*listaDeErrores) {
        lista_aux = obtenerUltimoNodoErrores(*listaDeErrores);
        lista_aux->sgte = malloc(sizeof(Error));
        lista_aux = lista_aux->sgte;
        lista_aux->tipo = tipoError;
        lista_aux->linea = lineaDeError;
        lista_aux->caracter = caracter;
        lista_aux->sgte = NULL;
    } else {
        *listaDeErrores = malloc(sizeof(Error));
        (*listaDeErrores)->tipo = tipoError;
        (*listaDeErrores)->linea = lineaDeError;
        (*listaDeErrores)->caracter = caracter;
        (*listaDeErrores)->sgte = NULL;
    }
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

void insertarFuncion(Funciones **listaDeFunciones, char *nombreDeFuncion, char *tipoDeFuncion, Variables **lasVariablesDeLaFuncion) {  // Inserta una funcion a una lista de funciones
    Funciones *lista_aux;
    //printf("\nENTRE A insertarFuncion\n");
    if (*listaDeFunciones) {
        lista_aux = obtenerUltimoNodoFunciones(*listaDeFunciones);
        lista_aux->sgte = malloc(sizeof(Funciones));
        lista_aux = lista_aux->sgte;
        lista_aux->nombreFuncion = strdup(nombreDeFuncion);
        lista_aux->tipoFuncion = strdup(tipoDeFuncion);
        lista_aux->l_Parametros = malloc(sizeof(Variables));
        lista_aux->l_Parametros = *lasVariablesDeLaFuncion;  // A revisar
        lista_aux->sgte = NULL;

    } else {
        *listaDeFunciones = malloc(sizeof(Funciones));
        (*listaDeFunciones)->nombreFuncion = strdup(nombreDeFuncion);
        (*listaDeFunciones)->tipoFuncion = strdup(tipoDeFuncion);
        (*listaDeFunciones)->l_Parametros = malloc(sizeof(Variables));
        (*listaDeFunciones)->l_Parametros = *lasVariablesDeLaFuncion;  // A revisar
        (*listaDeFunciones)->sgte = NULL;
    }
}

void agregarVariableATablaSinRepetir(TS *tablaDeSimbolos, Variables nodoVariable, Error **listaDeErrores) {
    int resultadoDeBusqueda;
    Variables *listaAux = (*tablaDeSimbolos).l_Variables;

    resultadoDeBusqueda = existeVariable(listaAux, nodoVariable.nombre);

    if (resultadoDeBusqueda == 0) {
        insertarVariable(&(*tablaDeSimbolos).l_Variables, nodoVariable.nombre, nodoVariable.tipo, nodoVariable.linea);
    } else {
        insertarErrorNoLexico(listaDeErrores, 4, nodoVariable.nombre, nodoVariable.linea);
    }
}

void agregarFuncionDefinidaATablaSinRepetir(TS *tablaDeSimbolos, Funciones nodoFuncion, Error **listaDeErrores, Variables **listaParametros) {
    int resultadoDeBusqueda;
    Funciones *listaAux = (*tablaDeSimbolos).l_FuncionesDefinidas;
    Funciones *nodoAux;

    printf("\nEn funcion DEFINIDA -> Nombre: %s - Tipo: %s\n", (nodoFuncion).nombreFuncion, (nodoFuncion).tipoFuncion);

    resultadoDeBusqueda = existeFuncion(listaAux, nodoFuncion.nombreFuncion);

    if (resultadoDeBusqueda == 0) {
        // Si la funcion no fue definida previamente...
        printf("\nLa funcion %s no fue definida previamente", nodoFuncion.nombreFuncion);
        if (existeFuncion(tablaDeSimbolos->l_FuncionesDeclaradas, nodoFuncion.nombreFuncion)) {
            printf("\nLa funcion esta en la lista de funciones declaradas");
            nodoAux = obtenerNodoFunciones(tablaDeSimbolos->l_FuncionesDeclaradas, nodoFuncion.nombreFuncion);

            if (!funcionesTienenIgualCantParametros(*nodoAux, *listaParametros)) {
                printf("\nLa funcion no coindide con la cantidad de parametros con su declaracion");
                insertarErrorNoLexico(listaDeErrores, 9, nodoAux->nombreFuncion, 0);
            } else {
                printf("\nLa funcion coindide con la cantidad de parametros con su declaracion");
                insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDefinidas, nodoAux->nombreFuncion, nodoAux->tipoFuncion, listaParametros);
            }
        } else {
            printf("\nLa funcion %s no esta en la lista de funciones declaradas", nodoFuncion.nombreFuncion);
            insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDefinidas, nodoFuncion.nombreFuncion, nodoFuncion.tipoFuncion, listaParametros);
        }
        // Verifico si esta en las funciones declaradas, y si esta, que coincidan en cantidad de parametros
        // Si no coinciden, lo mando a error de tipo 9
    } else {
        // Si la funcion fue definida previamente...
        insertarErrorNoLexico(listaDeErrores, 6, nodoAux->nombreFuncion, 0);
        //printf("\nERROR, LA FUNCION %s YA EXISTE EN LA TABLA DE SIMBOLOS (ya fue definida previamente)\n", nodoFuncion.nombreFuncion);
    }
}

void agregarFuncionDeclaradaATablaSinRepetir(TS *tablaDeSimbolos, Funciones nodoFuncion, Error **listaDeErrores, Variables **listaParametros) {
    int resultadoDeBusqueda;
    Funciones *listaAux = (*tablaDeSimbolos).l_FuncionesDeclaradas;
    Funciones *nodoAux;

    resultadoDeBusqueda = existeFuncion(listaAux, nodoFuncion.nombreFuncion);

    if (resultadoDeBusqueda == 0) {
        printf("\nLa funcion no fue declarada previamente");
        // Si la funcion no fue declarada previamente...
        if (existeFuncion(tablaDeSimbolos->l_FuncionesDefinidas, nodoFuncion.nombreFuncion)) {
            printf("\nLa funcion esta en la lista de funciones definidas");
            nodoAux = obtenerNodoFunciones(tablaDeSimbolos->l_FuncionesDefinidas, nodoFuncion.nombreFuncion);

            if (!funcionesTienenIgualCantParametros(*nodoAux, *listaParametros)) {
                printf("\nLa funcion no coindide con la cantidad de parametros con su definicion");
                printf("\n nodoAux: %s \n", nodoAux->nombreFuncion);
                insertarErrorNoLexico(listaDeErrores, 7, nodoAux->nombreFuncion, 0);
                printf("\n inserto a error no lexico: %s ", nodoAux->nombreFuncion);  // Aca no es el problema
            } else {
                printf("\nLa funcion coindide con la cantidad de parametros con su definicion");
                insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDeclaradas, nodoAux->nombreFuncion, nodoAux->tipoFuncion, listaParametros);
            }
            printf("\nENTRE1 : %s\n", nodoAux->nombreFuncion);
        } else {
            printf("\nLa funcion no esta en la lista de funciones definidas");
            insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDeclaradas, nodoFuncion.nombreFuncion, nodoFuncion.tipoFuncion, listaParametros);
        }
        printf("\n ENTRE2 %s \n", nodoAux->nombreFuncion);
        // Verifico si esta en las funciones definidas, y si esta, que coincidan en cantidad de parametros
        // Si no coinciden, lo mando a error de tipo 7
    } else {
        // Si la funcion fue declarada previamente...
        insertarErrorNoLexico(listaDeErrores, 5, nodoFuncion.nombreFuncion, 0);
        //printf("ERROR, LA FUNCION %s YA EXISTE EN LA TABLA DE SIMBOLOS (ya fue declarada previamente)\n", nodoFuncion.nombreFuncion);  // Borrar porque se muestra despues
    }
    printf("\n ENTRE 3 %s\n", nodoAux->nombreFuncion);
}

int funcionesTienenIgualCantParametros(Funciones f1, Variables *f2) {
    printf("\n%d\n", obtenerCantidadDeParametros(f1.l_Parametros) == obtenerCantidadDeParametros(f2));
    return obtenerCantidadDeParametros(f1.l_Parametros) == obtenerCantidadDeParametros(f2);
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

void mostrarVariablesDeTabla(TS tabla) {
    Variables *actual = tabla.l_Variables;
    int contador = 1;
    while (actual != NULL) {
        printf("Variable numero: %d\n", contador);
        printf("Nombre de variable: %s\n", actual->nombre);
        printf("Tipo de variable: %s\n", actual->tipo);
        printf("Linea de declaracion: %d\n\n", actual->linea);

        contador += 1;
        actual = actual->sgte;
    }
}
void mostrarFuncionesDefinidasDeTabla(TS tabla) {
    Funciones *actual = tabla.l_FuncionesDefinidas;
    int contador = 1;
    int contador2 = 1;
    while (actual != NULL) {
        printf("\nFuncion definida numero: %d\n", contador);
        printf("Nombre de Funcion: %s\n", actual->nombreFuncion);
        printf("Tipo de Funcion: %s\n", actual->tipoFuncion);
        if (actual->l_Parametros == NULL) {
            printf("LA LISTA DE PARAMETROS ESTA VACIA\n");
        }
        while (actual->l_Parametros != NULL) {
            printf("Parametro numero %d = %s\n", contador2, (actual->l_Parametros)->nombre);
            actual->l_Parametros = actual->l_Parametros->sgte;
            contador2 += 1;
        }
        contador2 = 0;
        contador += 1;
        actual = actual->sgte;
    }
}
void mostrarFuncionesDeclaradasDeTabla(TS *tabla) {
    Funciones *actual = tabla->l_FuncionesDeclaradas;
    int contador = 1;
    int contador2 = 1;
    while (actual != NULL) {
        printf("\nFuncion declarada numero: %d\n", contador);
        printf("Nombre de funcion: %s\n", actual->nombreFuncion);
        printf("Tipo de funcion: %s\n", actual->tipoFuncion);
        if (actual->l_Parametros == NULL) {
            printf("LA LISTA DE PARAMETROS ESTA VACIA\n");
        }

        while (actual->l_Parametros != NULL) {
            printf("Parametro numero %d = %s\n", contador2, (actual->l_Parametros)->nombre);
            actual->l_Parametros = actual->l_Parametros->sgte;
            contador2 += 1;
        }
        contador2 = 0;
        contador += 1;
        actual = actual->sgte;
    }
}

void mostrarListaErrores(Error **listaDeError) {
    Error *actual = *listaDeError;
    while (actual != NULL) {
        if (actual->tipo == 0) {
            printf("\n- Error lexico en linea %d ", actual->linea);
            printf("debido a caracter %c que no es reconocido\n", actual->caracter);
        }
        if (actual->tipo == 1) {
            if (actual->linea != 11)
                printf("\n- Error sintactico en linea %d \n", actual->linea);
        }
        if (actual->tipo >= 2) {
            printf("\n- Error semantico ");
            printf("debido a: \n");  // Error tipo 2, 3 y 7, estan considerados y mostrados otras funciones
            if (actual->tipo == 4) {
                printf("\t - Multiple declaracion de la variable %s en linea %d, ", actual->nombre, actual->linea);
                printf("declarada anteriormente");
            }
            if (actual->tipo == 5) {
                printf("\t - Multiple declaracion de funcion %s", actual->nombre);  // Declaracion ;
            }
            if (actual->tipo == 6) {
                printf("\t - Multiple definicion de funcion %s\n", actual->nombre);  // Definicion {}
            }
            if (actual->tipo == 7) {
                printf("\t - La funcion %s no coincide en cantidad de parametros en la definicion previa", actual->nombre);  // Definicion {}
            }
            if (actual->tipo == 8) {
                printf("\t - No se declara previamente la variable %s", actual->nombre);
            }
            if (actual->tipo == 9) {
                printf("\t - La funcion %s no coincide en cantidad de parametros en la declaracion previa", actual->nombre);
            }
            if (actual->tipo == 10) {
                printf("\t - Se espera una variable antes del '=' (valor l modificable)");
            }
            if (actual->tipo == 11) {
                printf("\t - La funcion %s no coincide en los tipos de parametros en la declaracion previa", actual->nombre);
            }
            if (actual->tipo == 13) {
                printf("\t - La funcion %s no coincide en los tipos de parametros en la definicion previa", actual->nombre);
            }
            if (actual->tipo == 14) {
                printf("\t - La funcion %s no coincide en los tipos ni en la cantidad de parametros en la definicion previa", actual->nombre);
            }
            if (actual->tipo == 15) {
                printf("\t - La funcion %s no coincide en el tipo de la declaracion previa", actual->nombre);
            }
            if (actual->tipo == 16) {
                printf("\t - La funcion %s no coincide en el tipo de la definicion previa", actual->nombre);
            }
            if (actual->linea != 0)
                printf(" en linea %d\n", actual->linea);
        }
        actual = actual->sgte;
    }
}

void vaciarListaVariables(Variables **cabeza) {
    Variables *aux = *cabeza;
    while (*cabeza) {
        *cabeza = (*cabeza)->sgte;
        printf("\nBORRANDO VARIABLE DE NOMBRE %s\n", aux->nombre);
        free(aux->nombre);
        free(aux->tipo);
        free(aux);
        aux = (Variables *)malloc(sizeof(Variables));
        aux = *cabeza;
    }
}

int existeVariableEnTabla(TS *tablaDeSimbolos, char *nombreVariable, int lineaError, Error **listaDeErrores) {
    int resultadoDeBusqueda;
    Variables *listaAux = (*tablaDeSimbolos).l_Variables;
    if (existeVariable(listaAux, nombreVariable) == 0) {
        insertarErrorNoLexico(listaDeErrores, 8, nombreVariable, lineaError);
        //printf("ERROR, LA VARIABLE %s NO FUE DECLARADA PREVIAMENTE\n", nombreVariable);  // Borrar porque se muestra despues
        return 1;
    } else
        return 0;
}

void matcheanCantidadDeParametros(Funciones *listaDeFuncionesDefinidas, Funciones *listaDeFuncionesDeclaradas) {  // Esta funcion iria al final de todo en el main
    Funciones *l_aux_definida = listaDeFuncionesDefinidas;
    Funciones *l_aux_declarada = listaDeFuncionesDeclaradas;
    Funciones *direcNodoAuxDeclarado = NULL;
    int cantParamFuncionDefinida, cantParamFuncionDeclarada;
    int flagHuboUnErrorOMas = 0;

    printf("\nVERIFICACION DE CANTIDAD DE PARAMETROS:\n");

    while (l_aux_definida != NULL) {
        if (existeFuncion(listaDeFuncionesDefinidas, l_aux_definida->nombreFuncion) && (existeFuncion(listaDeFuncionesDeclaradas, l_aux_declarada->nombreFuncion))) {
            //printf("\nENTRE  \n");
            direcNodoAuxDeclarado = obtenerNodoFunciones(l_aux_declarada, l_aux_definida->nombreFuncion);
            cantParamFuncionDeclarada = obtenerCantidadDeParametros(direcNodoAuxDeclarado->l_Parametros);
            cantParamFuncionDefinida = obtenerCantidadDeParametros(l_aux_definida->l_Parametros);
            if (cantParamFuncionDeclarada != cantParamFuncionDefinida) {
                printf("\n - Error Semantico: La cantidad de parametros de la funcion %s no coinciden en la definicion y declaracion: ", l_aux_definida->nombreFuncion);
                printf("\n\t - Se define/n %d parametro/s, y se declara/n %d parametro/s", cantParamFuncionDefinida, cantParamFuncionDeclarada);
                flagHuboUnErrorOMas = 1;
            }
        }
        l_aux_definida = l_aux_definida->sgte;
    }
    if (flagHuboUnErrorOMas == 0) {
        printf("- Todas las funciones se declaran y definen con igual cantidad de parametros\n");
    }
}

Funciones *obtenerNodoFunciones(Funciones *listaDeFunciones, char *nombreDeFuncionABuscar) {
    Funciones *lista_aux = listaDeFunciones;
    while (lista_aux && strcmp(lista_aux->nombreFuncion, nombreDeFuncionABuscar) != 0)
        lista_aux = lista_aux->sgte;
    return lista_aux;  // ANDANDO
}

int obtenerCantidadDeParametros(Variables *listaDeVariables) {
    Variables *lista_aux = listaDeVariables;
    int contador = 0;

    while (lista_aux != NULL) {
        contador += 1;
        lista_aux = lista_aux->sgte;
    }
    printf("\nCantidad de parametros: %d\n", contador);
    return contador;
}

void matcheanTiposDeFunciones(Funciones *listaDeFuncionesDefinidas, Funciones *listaDeFuncionesDeclaradas) {
    Funciones *l_aux_definida = listaDeFuncionesDefinidas;
    Funciones *l_aux_declarada = listaDeFuncionesDeclaradas;
    Funciones *direcNodoAuxDeclarado = NULL;
    int flagHuboUnErrorOMas = 0;

    printf("\nVERIFICACION DE TIPO DE FUNCIONES:\n");

    while (l_aux_definida != NULL) {
        direcNodoAuxDeclarado = obtenerNodoFunciones(l_aux_declarada, l_aux_definida->nombreFuncion);

        if (strcmp(direcNodoAuxDeclarado->tipoFuncion, l_aux_definida->tipoFuncion) != 0) {
            printf(" - Error semantico: La funcion %s", l_aux_definida->nombreFuncion);
            printf(" se declara tipo %s y se define tipo %s\n", l_aux_declarada->tipoFuncion, l_aux_definida->tipoFuncion);
            flagHuboUnErrorOMas = 1;
        }

        l_aux_definida = l_aux_definida->sgte;
    }
    if (flagHuboUnErrorOMas == 0) {
        printf("\n\n- Todas las funciones tipan correctamente\n\n\n");
    }
}

void matcheanTiposDeParametros(Funciones *listaDeFuncionesDefinidas, Funciones *listaDeFuncionesDeclaradas) {
    Funciones *l_aux_definida = listaDeFuncionesDefinidas;
    Funciones *l_aux_declarada = listaDeFuncionesDeclaradas;
    Funciones *direcNodoAuxDeclarado = NULL;
    char *tipoDeVariableDeclarada, *tipoDeVariableDefinida;
    int flagHuboUnErrorOMas = 0;

    printf("\nVERIFICACION DE TIPO DE PARAMETROS:\n");

    while (l_aux_definida != NULL) {
        direcNodoAuxDeclarado = obtenerNodoFunciones(l_aux_declarada, l_aux_definida->nombreFuncion);

        Variables *listaParametrosDefinidos = l_aux_definida->l_Parametros;
        Variables *listaParametrosDeclarados = direcNodoAuxDeclarado->l_Parametros;

        while (listaParametrosDeclarados != NULL) {
            if (strcmp(listaParametrosDeclarados->tipo, listaParametrosDefinidos->tipo) != 0) {
                printf(" - Error Semantico: La variable %s de la funcion %s", listaParametrosDeclarados->nombre, l_aux_definida->nombreFuncion);
                printf("\n\t - Se declara tipo %s y se define tipo %s\n", listaParametrosDeclarados->tipo, listaParametrosDefinidos->tipo);
                flagHuboUnErrorOMas = 1;
            }

            listaParametrosDeclarados = listaParametrosDeclarados->sgte;
            listaParametrosDefinidos = listaParametrosDefinidos->sgte;
        }

        l_aux_definida = l_aux_definida->sgte;
    }
    if (flagHuboUnErrorOMas == 0) {
        printf("- Todos los parametros de las funciones tipan correctamente\n");
    }
}

int variablesOperablesEntreSi(Variables *lasVariables) {
    Variables *cabeza = lasVariables;
    Variables *resto;

    if (cabeza == NULL) {
        printf("\nLa lista esta vacia");
        return 0;
    }

    while (cabeza) {
        resto = cabeza->sgte;
        while (resto) {
            if (sonTiposNoOperables(cabeza->tipo, resto->tipo))
                return 0;
            resto = resto->sgte;
        }
        cabeza = cabeza->sgte;
    }
    return 1;
}

int sonTiposNoOperables(char *tipo1, char *tipo2) {
    return (strcmp(tipo1, "char*") == 0 && strcmp(tipo2, "char*") == 0) ||
           (strcmp(tipo1, "char*") == 0 && strcmp(tipo2, "float") == 0) ||
           (strcmp(tipo1, "float") == 0 && strcmp(tipo2, "char*") == 0);
}

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

int existeVariableTipo(Variables *lasVariables, char *tipoABuscar) {  // Esta funcion anda
    if (lasVariables == NULL)
        return 0;
    else if (strcmp(lasVariables->tipo, tipoABuscar) == 0)
        return 1;
    else
        return existeVariableTipo(lasVariables->sgte, tipoABuscar);  // Utilizo recursividad
}

int existeFuncionDeclaradaEnTabla(TS *tablaDeSimbolos, char *nombreFuncion, int lineaError, Error **listaDeErrores) {
    int resultadoDeBusqueda;
    Funciones *listaAux = (*tablaDeSimbolos).l_FuncionesDeclaradas;
    if (existeFuncion(listaAux, nombreFuncion)) {
        printf("La funcion NO existe");
        return 1;
    } else{
        printf("La funcion NO existe");
        //insertarErrorNoLexico(listaDeErrores, 17, nombreFuncion, lineaError);
        return 0;
    }
} 

int main() {
    Variables variableDePrueba;
    Variables variableDePrueba2;
    Variables variableDePrueba3;
    Variables *listaDeVariablesPrueba = NULL;

    printf("\n--------------");
    printf("\nSumables entre si?: %d", variablesOperablesEntreSi(listaDeVariablesPrueba));

    insertarVariable(&listaDeVariablesPrueba, "varint", "int", 1);
    insertarVariable(&listaDeVariablesPrueba, "varfloat", "float", 2);
    insertarVariable(&listaDeVariablesPrueba, "varfloat", "char", 2);
    printf("\nSumables entre si?: %d", variablesOperablesEntreSi(listaDeVariablesPrueba));
    printf("\nSumables entre si?: %d", variablesOperablesEntreSi(listaDeVariablesPrueba));
    printf("\nSumables entre si?: %d", variablesOperablesEntreSi(listaDeVariablesPrueba));
    insertarVariable(&listaDeVariablesPrueba, "varfloat", "char*", 2);
    printf("\nSumables entre si?: %d", variablesOperablesEntreSi(listaDeVariablesPrueba));

}