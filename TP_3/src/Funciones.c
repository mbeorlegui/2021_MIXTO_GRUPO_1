//#include "Funciones.h" -> No hace falta.

// Funcion para insertar ordenado cada elemento en su debida lista
void insertarOrdenado(char texto[], nodo **lista) {
    nodo *lista_aux;
    nodo *nuevo = malloc(sizeof(nodo));
    nuevo->info = strdup(texto);
    nuevo->cantidad = 1;
    if (!(*lista) || (*lista && strcmp((*lista)->info, texto) > 0)) {
        nuevo->sgte = (*lista);
        (*lista) = nuevo;
    } else {
        lista_aux = *lista;
        if (existeEnLaLista(texto, *lista)) {
            while (lista_aux && strcmp(lista_aux->info, texto))
                lista_aux = lista_aux->sgte;
            (lista_aux->cantidad)++;
        } else {
            while (lista_aux && lista_aux->sgte && strcmp(lista_aux->sgte->info, texto) < 0)
                lista_aux = lista_aux->sgte;
            nuevo->sgte = lista_aux->sgte;
            lista_aux->sgte = nuevo;
        }
    }
}

// Funcion para insertar cada elemento en su debida lista, sin contemplar orden
void insertarElemento(char texto[], nodo **lista) {
    for (int i = 0; i < strlen(texto); i++) {
        if (texto[i] == '\n')
            lineas++;
    }
    texto = sacarComillas(texto);
    nodo *lista_aux;
    if (*lista) {
        lista_aux = obtenerUltimoNodo(*lista);
        lista_aux->sgte = malloc(sizeof(nodo));
        lista_aux = lista_aux->sgte;
        lista_aux->info = strdup(texto);
        lista_aux->cantidad = -1;
        lista_aux->posicion = lineas;
        lista_aux->sgte = NULL;
    } else {
        *lista = malloc(sizeof(nodo));
        (*lista)->info = strdup(texto);
        (*lista)->cantidad = -1;
        (*lista)->posicion = lineas;
        (*lista)->sgte = NULL;
    }
    return;
}

void archivarLiteralesCadena(nodo **lista, FILE **aR) {
    nodo *lista_aux;

    while (*lista) {
        fprintf(*aR, "%s", (*lista)->info);
        fputs(", cuya longitud es ", *aR);
        fprintf(*aR, "%d", strlen((*lista)->info));
        printf("%s cuya longitud es %d\n", (*lista)->info, strlen((*lista)->info));
        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }
}

void mostrarLista(nodo **lista, int literalCadena, char *texto) {
    nodo *lista_aux;
    if (*lista) {
        if (literalCadena) {
            printf("Literales Cadena:\n");
            while (*lista) {
                printf("%s cuya longitud es %d\n", (*lista)->info, strlen((*lista)->info));
                lista_aux = (*lista)->sgte;
                free(*lista);
                *lista = lista_aux;
            }
        } else {
            printf(texto);
            while (*lista) {
                if ((*lista)->cantidad != -1) {
                    printf("%s que aparece %d ", (*lista)->info, (*lista)->cantidad);
                    if ((*lista)->cantidad == 1)
                        printf("vez\n");
                    if ((*lista)->cantidad > 1)
                        printf("veces\n");
                } else {
                    printf("%s\n", (*lista)->info);
                }

                lista_aux = (*lista)->sgte;
                free(*lista);
                *lista = lista_aux;
            }
        }
        printf("\n");
    }
}

int existeEnLaLista(char texto[], nodo *lista) {
    nodo *actual = malloc(sizeof(nodo));
    int encontrado = 0;
    actual = lista;
    while (actual && strcmp(actual->info, texto) <= 0) {
        if (!strcmp(actual->info, texto)) {
            encontrado = 1;
        }
        actual = actual->sgte;
    }
    return encontrado;
}

char *sacarComillas(char texto[]) {
    char *auxiliar = malloc(strlen(texto));
    int j = 0;
    for (int i = 0; i < strlen(texto); i++) {
        if (texto[i] != 34) {
            auxiliar[j] = texto[i];
            j++;
        }
    }
    auxiliar[j] = '\0';
    return auxiliar;
}

nodo *obtenerUltimoNodo(nodo *lista) {
    while (lista && lista->sgte)
        lista = lista->sgte;
    return lista;
}

void archivarIdentificadores(nodo **lista, FILE **aR) {
    nodo *lista_aux;

    while (*lista) {
        if ((*lista)->cantidad != -1) {
            fprintf(*aR, "%s", (*lista)->info);
            fputs(", que aparece ", *aR);
            fprintf(*aR, "%d", (*lista)->cantidad);
            printf("%s que aparece %d ", (*lista)->info, (*lista)->cantidad);
            if ((*lista)->cantidad == 1) {
                fputs(" vez\n", *aR);
            }
            if ((*lista)->cantidad > 1) {
                fputs(" veces\n", *aR);
            }
        } else
            printf("%s\n", (*lista)->info);

        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }
}