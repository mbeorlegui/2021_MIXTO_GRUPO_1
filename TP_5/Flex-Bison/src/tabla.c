#include "tabla.h"
 
int existeVariable(Variables *listaDeVariables, char *nombreVariable) {  // Esta funcion anda
    Variables *listaAux = listaDeVariables;
    if (listaAux == NULL)
        return 0;
    else if (strcmp(listaAux->nombre, nombreVariable) == 0)
        return 1;
    else
        return existeVariable(listaAux->sgte, nombreVariable);  // Utilizo recursividad
}
 
char *buscarTipoDatoVariable(Variables *listaDeVariables, char *nombreVariable) {  // Esta funcion anda
    Variables *listaAux = listaDeVariables;
    while (listaAux != NULL && strcmp(listaAux->nombre, nombreVariable) != 0) {
        listaAux = listaAux->sgte;
    }
    if (listaAux != NULL)
        return listaAux->tipo;
    return "";
}
 
char *buscarTipoDatoVariableEnTabla(TS *tablaDeSimbolos, char *nombreVariable, int lineaError, Error **listaDeErrores) {
    Variables *listaAux = (*tablaDeSimbolos).l_Variables;
    if (listaAux != NULL) {
        return buscarTipoDatoVariable(listaAux, nombreVariable);
    } else {
        return "";
    }
}
 
int sonTiposNoOperables(char *tipo1, char *tipo2) {
    return (strcmp(tipo1, "char*") == 0 && strcmp(tipo2, "char*") == 0) ||
           (strcmp(tipo1, "char*") == 0 && strcmp(tipo2, "float") == 0) ||
           (strcmp(tipo1, "float") == 0 && strcmp(tipo2, "char*") == 0);
}
 
int existeFuncion(Funciones *listaDeFunciones, char *funcionABuscar) {
    Funciones *listaAux = listaDeFunciones;
    if (listaAux == NULL)
        return 0;
    else if (strcmp(listaAux->nombreFuncion, funcionABuscar) == 0)
        return 1;
    else
        return existeFuncion(listaAux->sgte, funcionABuscar);
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
 
    if (*listaDeVariables) {
        lista_aux = obtenerUltimoNodoVariables(*listaDeVariables);
        lista_aux->sgte = malloc(sizeof(Variables));
        lista_aux = lista_aux->sgte;
        if (nombreVariable != NULL)
            lista_aux->nombre = strdup(nombreVariable);
        else
            lista_aux->nombre = strdup("Sin nombre");
        lista_aux->tipo = strdup(tipoVariable);
        lista_aux->linea = lineaDeclaracion;
        lista_aux->sgte = NULL;
    } else {
        *listaDeVariables = malloc(sizeof(Variables));
        if (nombreVariable != NULL)
            (*listaDeVariables)->nombre = strdup(nombreVariable);
        else
            (*listaDeVariables)->nombre = strdup("Sin nombre");
        (*listaDeVariables)->tipo = strdup(tipoVariable);
        (*listaDeVariables)->linea = lineaDeclaracion;
        (*listaDeVariables)->sgte = NULL;
    }
}
 
void insertarFuncion(Funciones **listaDeFunciones, char *nombreDeFuncion, char *tipoDeFuncion, Variables **lasVariablesDeLaFuncion) {  // Inserta una funcion a una lista de funciones
    Funciones *lista_aux;
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
        (*listaDeFunciones)->l_Parametros = *lasVariablesDeLaFuncion;
        (*listaDeFunciones)->sgte = NULL;
    }
}
 
void agregarVariableATablaSinRepetir(TS *tablaDeSimbolos, Variables nodoVariable, Error **listaDeErrores) {
    int resultadoDeBusqueda;
    Variables *listaAux = (*tablaDeSimbolos).l_Variables;
 
    resultadoDeBusqueda = existeVariable(listaAux, nodoVariable.nombre);
    if (strcmp(nodoVariable.nombre, "Sin nombre")) {
        if (resultadoDeBusqueda == 0) {
            insertarVariable(&(*tablaDeSimbolos).l_Variables, nodoVariable.nombre, nodoVariable.tipo, nodoVariable.linea);
        } else {
            insertarErrorNoLexico(listaDeErrores, 4, nodoVariable.nombre, nodoVariable.linea);
        }
    }
}
 
void agregarFuncionDefinidaATablaSinRepetir(TS *tablaDeSimbolos, Funciones nodoFuncion, Error **listaDeErrores, Variables **listaParametros, int lineaDeFuncion) {
    int resultadoDeBusqueda;
    Funciones *listaAux = (*tablaDeSimbolos).l_FuncionesDefinidas;
    Funciones *nodoAux;
 
    resultadoDeBusqueda = existeFuncion(listaAux, nodoFuncion.nombreFuncion);
    if (resultadoDeBusqueda == 0) {
        // Si la funcion no fue definida previamente...
        if (existeFuncion(tablaDeSimbolos->l_FuncionesDeclaradas, nodoFuncion.nombreFuncion)) {
            nodoAux = obtenerNodoFunciones(tablaDeSimbolos->l_FuncionesDeclaradas, nodoFuncion.nombreFuncion);
            if (funcionesSonDeDistintoTipo(nodoAux, nodoFuncion)) {
                insertarErrorNoLexico(listaDeErrores, 15, nodoAux->nombreFuncion, lineaDeFuncion);
            } else if (funcionesTienenIgualCantParametros(*nodoAux, *listaParametros) && todosTiposIguales(nodoAux->l_Parametros, *listaParametros)) {  // Tiene igual cantidad y tipos de parametros
                insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDefinidas, nodoAux->nombreFuncion, nodoAux->tipoFuncion, listaParametros);
            } else if (!funcionesTienenIgualCantParametros(*nodoAux, *listaParametros) && todosTiposIguales(nodoAux->l_Parametros, *listaParametros)) {
                insertarErrorNoLexico(listaDeErrores, 9, nodoAux->nombreFuncion, lineaDeFuncion);
            } else if (funcionesTienenIgualCantParametros(*nodoAux, *listaParametros) && !todosTiposIguales(nodoAux->l_Parametros, *listaParametros)) {
                insertarErrorNoLexico(listaDeErrores, 11, nodoAux->nombreFuncion, lineaDeFuncion);
            } else if (!funcionesTienenIgualCantParametros(*nodoAux, *listaParametros) && !todosTiposIguales(nodoAux->l_Parametros, *listaParametros)) {
                insertarErrorNoLexico(listaDeErrores, 9, nodoAux->nombreFuncion, lineaDeFuncion);
            }
        } else {
            insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDefinidas, nodoFuncion.nombreFuncion, nodoFuncion.tipoFuncion, listaParametros);
        }
        // Verifico si esta en las funciones declaradas, y si esta, que coincidan en cantidad de parametros
        // Si no coinciden, lo mando a error de tipo 9
    } else {
        // Si la funcion fue definida previamente...
        insertarErrorNoLexico(listaDeErrores, 6, nodoFuncion.nombreFuncion, lineaDeFuncion);
    }
}
 
void agregarFuncionDeclaradaATablaSinRepetir(TS *tablaDeSimbolos, Funciones nodoFuncion, Error **listaDeErrores, Variables **listaParametros, int lineaDeFuncion) {
    int resultadoDeBusqueda;
    Funciones *listaAux = (*tablaDeSimbolos).l_FuncionesDeclaradas;
    Funciones *nodoAux;
 
    resultadoDeBusqueda = existeFuncion(listaAux, nodoFuncion.nombreFuncion);
 
    if (resultadoDeBusqueda == 0) {
        // Si la funcion no fue declarada previamente...
        if (existeFuncion(tablaDeSimbolos->l_FuncionesDefinidas, nodoFuncion.nombreFuncion)) {
            nodoAux = obtenerNodoFunciones(tablaDeSimbolos->l_FuncionesDefinidas, nodoFuncion.nombreFuncion);
 
            if (funcionesSonDeDistintoTipo(nodoAux, nodoFuncion)) {
                insertarErrorNoLexico(listaDeErrores, 16, nodoAux->nombreFuncion, lineaDeFuncion);
            } else if (funcionesTienenIgualCantParametros(*nodoAux, *listaParametros) && todosTiposIguales(nodoAux->l_Parametros, *listaParametros)) {  // Tiene igual cantidad de parametros
                insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDeclaradas, nodoAux->nombreFuncion, nodoAux->tipoFuncion, listaParametros);
            } else if (!funcionesTienenIgualCantParametros(*nodoAux, *listaParametros) && todosTiposIguales(nodoAux->l_Parametros, *listaParametros)) {
                insertarErrorNoLexico(listaDeErrores, 7, nodoAux->nombreFuncion, lineaDeFuncion);
            } else if (funcionesTienenIgualCantParametros(*nodoAux, *listaParametros) && !todosTiposIguales(nodoAux->l_Parametros, *listaParametros)) {
                insertarErrorNoLexico(listaDeErrores, 13, nodoAux->nombreFuncion, lineaDeFuncion);
            } else if (!funcionesTienenIgualCantParametros(*nodoAux, *listaParametros) && !todosTiposIguales(nodoAux->l_Parametros, *listaParametros)) {
                insertarErrorNoLexico(listaDeErrores, 14, nodoAux->nombreFuncion, lineaDeFuncion);
            }
        } else {
            insertarFuncion(&(*tablaDeSimbolos).l_FuncionesDeclaradas, nodoFuncion.nombreFuncion, nodoFuncion.tipoFuncion, listaParametros);
        }
        // Verifico si esta en las funciones definidas, y si esta, que coincidan en cantidad de parametros
        // Si no coinciden, lo mando a error de tipo 7
    } else {
        // Si la funcion fue declarada previamente...
        insertarErrorNoLexico(listaDeErrores, 5, nodoFuncion.nombreFuncion, lineaDeFuncion);
    }
}
 
int funcionesSonDeDistintoTipo(Funciones *nodoAux, Funciones nodoFuncion) {
    return strcmp(nodoAux->tipoFuncion, nodoFuncion.tipoFuncion);
}
 
int funcionesTienenIgualCantParametros(Funciones f1, Variables *f2) {
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
            printf("Parametro numero %d: %s - Tipo: %s\n", contador2, (actual->l_Parametros)->nombre, (actual->l_Parametros)->tipo);
            actual->l_Parametros = actual->l_Parametros->sgte;
            contador2 += 1;
        }
        contador2 = 1;
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
            if (strcmp((actual->l_Parametros)->nombre, actual->nombreFuncion) != 0)
                printf("Parametro numero %d: %s - Tipo: %s\n", contador2, (actual->l_Parametros)->nombre, (actual->l_Parametros)->tipo);
            else
                printf("Parametro numero %d: Sin nombre - Tipo: %s\n", contador2, (actual->l_Parametros)->tipo);
 
            actual->l_Parametros = actual->l_Parametros->sgte;
            contador2 += 1;
        }
        contador2 = 1;
        contador += 1;
        actual = actual->sgte;
    }
}
 
void mostrarListaErrores(Error **listaDeError) {
    Error *actual = *listaDeError;
    while (actual != NULL) {
        if (actual->tipo == 0) {
            printf("\n\n- Error lexico en linea %d ", actual->linea);
            printf("debido a:\n \t * Caracter '%c' que no es reconocido", actual->caracter);
        }
        if (actual->tipo == 1) {
            if (actual->linea != 11)
                printf("\n\n- Error sintactico en linea %d", actual->linea);
        }
        if (actual->tipo >= 2) {
            if (strcmp(actual->nombre, "Sin nombre")) {
                printf("\n\n- Error semantico ");
                printf("debido a: \n");  // Error tipo 2, 3 y 7, estan considerados y mostrados otras funciones
                if (actual->tipo == 4) {
                    printf("\t * Multiple declaracion de la variable %s, ", actual->nombre);
                    printf("declarada anteriormente");
                } else if (actual->tipo == 5) {
                    printf("\t * Multiple declaracion de funcion %s", actual->nombre);  // Declaracion ;
                } else if (actual->tipo == 6) {
                    printf("\t * Multiple definicion de funcion %s", actual->nombre);  // Definicion {}
                } else if (actual->tipo == 7) {
                    printf("\t * La funcion %s no coincide en cantidad de parametros en la definicion previa", actual->nombre);  // Definicion {}
                } else if (actual->tipo == 8) {
                    printf("\t * No se declara previamente la variable %s", actual->nombre);
                } else if (actual->tipo == 9) {
                    printf("\t * La funcion %s no coincide en cantidad de parametros en la declaracion previa", actual->nombre);
                } else if (actual->tipo == 10) {
                    printf("\t * Se espera una variable antes del '=' (valor l modificable)");
                } else if (actual->tipo == 11) {
                    printf("\t * La funcion %s no coincide en los tipos de parametros en la declaracion previa", actual->nombre);
                } else if (actual->tipo == 13) {
                    printf("\t * La funcion %s no coincide en los tipos de parametros en la definicion previa", actual->nombre);
                } else if (actual->tipo == 14) {
                    printf("\t * La funcion %s no coincide en los tipos ni en la cantidad de parametros en la definicion previa", actual->nombre);
                } else if (actual->tipo == 15) {
                    printf("\t * La funcion %s no coincide en el tipo de la declaracion previa", actual->nombre);
                } else if (actual->tipo == 16) {
                    printf("\t * La funcion %s no coincide en el tipo de la definicion previa", actual->nombre);
                } else if (actual->tipo == 17) {
                    printf("\t * Las variables no son sumables");
                }
                if (actual->tipo == 18) {
                    printf("\t * No se define previamente la funcion %s", actual->nombre);
                }
                printf(" -> error en linea: %d", actual->linea);
            }
        }
        actual = actual->sgte;
    }
}
 
void vaciarListaVariables(Variables **cabeza) {
    Variables *aux = *cabeza;
    while (*cabeza) {
        *cabeza = (*cabeza)->sgte;
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
        return 1;
    } else
        return 0;
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
    return contador;
}
 
int variablesOperablesEntreSi(Variables *lasVariables, int numeroDeLinea, Error **listaDeErrores) {
    Variables *cabeza = lasVariables;
    Variables *resto;
 
    if (cabeza == NULL) {
        return 0;
    }
    while (cabeza) {
        resto = cabeza->sgte;
        while (resto) {
            if (sonTiposNoOperables(cabeza->tipo, resto->tipo)) {
                insertarErrorNoLexico(listaDeErrores, 17, "", numeroDeLinea);
                return 0;
            }
            resto = resto->sgte;
        }
        cabeza = cabeza->sgte;
    }
    return 1;
}
 
int todosTiposIguales(Variables *listaDeVariables1, Variables *listaDeVariables2) {
    Variables *lista_aux1 = listaDeVariables1;
    Variables *lista_aux2 = listaDeVariables2;
 
    while (lista_aux1 != NULL && lista_aux2 != NULL) {
        if (strcmp(lista_aux1->tipo, lista_aux2->tipo) != 0) {
            return 0;
        }
        lista_aux1 = lista_aux1->sgte;
        lista_aux2 = lista_aux2->sgte;
    }
    return 1;
}
 
int existeFuncionDeclaradaEnTabla(TS *tablaDeSimbolos, char *nombreFuncion, int lineaError, Error **listaDeErrores) {
    Funciones *listaAux = (*tablaDeSimbolos).l_FuncionesDefinidas;
    if (existeFuncion(listaAux, nombreFuncion)) {
        return 1;
    } else {
        insertarErrorNoLexico(listaDeErrores, 18, nombreFuncion, lineaError);
        return 0;
    }
}
 
void agregarListaDeVariablesATablaSinRepetir(TS *tablaDeSimbolos, Variables *listaDeVariables1, Error **listaDeErrores) {
    Variables *l_aux = listaDeVariables1;
    while (l_aux) {
        agregarVariableATablaSinRepetir(tablaDeSimbolos, *l_aux, listaDeErrores);
        l_aux = l_aux->sgte;
    }
}