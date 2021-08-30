
// Funcion para insertar ordenado cada elemento en su debida lista
void insertarOrdenado(char texto[], nodo **lista) {
    nodo *lista_aux;                     //creo lista
    nodo *nuevo = malloc(sizeof(nodo));  //creo nuevo nodo y solicito memoria
    nuevo->info = strdup(texto);
    nuevo->cantidad = 1;
    //si la lista esta vacía o el texto leido es mayor al que esta en el tope de la lista, el nuevo nodo estara en el tope
    if (!(*lista) || (*lista && strcmp((*lista)->info, texto) > 0)) {
        nuevo->sgte = (*lista);
        (*lista) = nuevo;
        //si la lista no esta vacia y el texto leido no es mayot al del tope:
    } else {
        lista_aux = *lista;
        //si el texto leido ya existe en la lista
        if (existeEnLaLista(texto, *lista)) {
            //sumo uno a la cantidad
            while (lista_aux && strcmp(lista_aux->info, texto))
                lista_aux = lista_aux->sgte;
            (lista_aux->cantidad)++;
            //si no existe en la lista
        } else {
            //coloco el nodo donde corresponde
            while (lista_aux && lista_aux->sgte && strcmp(lista_aux->sgte->info, texto) < 0)
                lista_aux = lista_aux->sgte;
            nuevo->sgte = lista_aux->sgte;
            lista_aux->sgte = nuevo;
        }
    }
}

// Funcion para insertar cada elemento en su debida lista, sin contemplar orden
void insertarElemento(char texto[], nodo **lista) {
    //cuento las lineas
    for (int i = 0; i < strlen(texto); i++) {
        if (texto[i] == '\n')
            lineas++;
    }
    //saco las comillas
    texto = sacarComillas(texto);

    nodo *lista_aux;
    //si hay algo en la lista, inserto un nodo nuevo luego del ultimo y lo "lleno"
    if (*lista) {
        lista_aux = obtenerUltimoNodo(*lista);
        lista_aux->sgte = malloc(sizeof(nodo));
        lista_aux = lista_aux->sgte;
        lista_aux->info = strdup(texto);
        lista_aux->cantidad = -1;
        lista_aux->posicion = lineas;
        lista_aux->sgte = NULL;
        //si la lista esta vacia, simplemente creo el nodo y lo "lleno"
    } else {
        *lista = malloc(sizeof(nodo));
        (*lista)->info = strdup(texto);
        (*lista)->cantidad = -1;
        (*lista)->posicion = lineas;
        (*lista)->sgte = NULL;
    }
    return;
}

int existeEnLaLista(char texto[], nodo *lista) {
    nodo *actual = malloc(sizeof(nodo));  //creo un nodo y solicito memoria
    int encontrado = 0;                   //creo un "flag" que se hará uno si el texto fue encontrado
    actual = lista;

    //voy recorriendo la lista
    while (actual && strcmp(actual->info, texto) <= 0) {
        //si en algun momento encuentro el texto en la lista, pongo el flag en 1
        if (!strcmp(actual->info, texto)) {
            encontrado = 1;
        }
        actual = actual->sgte;
    }

    return encontrado;
}

char *sacarComillas(char texto[]) {
    char *auxiliar = malloc(strlen(texto));  //creo un puntero a char y solicito el largo del texto
    int j = 0;
    //recorro el texto y lo copio en auxiliar mientras no tenga comillas
    for (int i = 0; i < strlen(texto); i++) {
        if (texto[i] != 34) {
            auxiliar[j] = texto[i];
            j++;
        }
    }
    auxiliar[j] = '\0';
    //finalmente retorno el texto sin comillas
    return auxiliar;
}

nodo *obtenerUltimoNodo(nodo *lista) {
    while (lista && lista->sgte)
        lista = lista->sgte;
    return lista;
}

void archivarIdentificadoresOperadaresYCaracteres(nodo **lista, FILE **aR) {
    nodo *lista_aux;

    while (*lista) {
        if ((*lista)->cantidad != -1) {
            fprintf(*aR, "%s", (*lista)->info);
            fputs(", que aparece ", *aR);
            fprintf(*aR, "%d", (*lista)->cantidad);
            printf("%s que aparece %d ", (*lista)->info, (*lista)->cantidad);
            if ((*lista)->cantidad == 1) {
                fputs(" vez\n", *aR);
                printf(" vez\n");
            }
            if ((*lista)->cantidad > 1) {
                fputs(" veces\n", *aR);
                printf(" veces\n");
            }

        } else
            printf("%s\n", (*lista)->info);

        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }
}

void archivarLiteralesCadena(nodo **lista, FILE **aR) {
    nodo *lista_aux;

    //Mientras la lista no este vacia, imprimo los literales cadena y sus longitudes
    while (*lista) {
        fprintf(*aR, "%s", (*lista)->info);
        fputs(", cuya longitud es ", *aR);
        fprintf(*aR, "%d", strlen((*lista)->info));
        printf("%s cuya longitud es %d\n", (*lista)->info), strlen((*lista)->info);
        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }
}

void archivarPalabrasReservadasComentariosYDirectivas(nodo **lista, FILE **aR) {
    nodo *lista_aux;

    //si la lista no esta vacia, se muestra el elemento

    if (*lista) {
        while (*lista) {
            printf("%s", (*lista)->info);
            fprintf(*aR, "%s", (*lista)->info);

            //Si no es el ultimo elemento separar por coma, sino por punto
            if ((*lista)->sgte != NULL) {
                printf(", ");
                fputs(", ", *aR);
            } else {
                printf(".");
                fputs(".", *aR);
            }

            lista_aux = (*lista)->sgte;
            free(*lista);
            *lista = lista_aux;
        }
    }
}

void archivarNoReconocidos(nodo **lista, FILE **aR) {
    nodo *lista_aux;

    //si la lista no esta vacia, se muestra el caracter no reconocido y su posicion
    while (*lista) {
        printf("No se reconocio: %s", (*lista)->info);
        fputs("No se reconocio ", *aR);
        fprintf(*aR, "%s", (*lista)->info);
        printf(" en la linea %d", (*lista)->posicion);
        fputs(" en la linea ", *aR);
        fprintf(*aR, "%d", (*lista)->posicion);

        //Si no es el ultimo elemento separar por coma, sino por punto
        if ((*lista)->sgte != NULL) {
            printf(".\n");
            fputs(".\n", *aR);
        } else {
            printf(".");
            fputs(".", *aR);
        }

        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }
}

void archivarConstantes(nodo **lista, FILE **aR, int base) {
    int sumatoria = 0;
    char *numPtr;
    nodo *lista_aux;

    //voy recorriendo la lista, de las constantes hexa y octales se indica el valor decimal

    while (*lista) {
        fputs("Para la constante en base ", *aR);
        fprintf(*aR, "%d, ", base);
        fprintf(*aR, "%s", (*lista)->info);
        printf("\nVariable en base %d: %s", base, (*lista)->info);
        fputs(" su valor entero decimal es: ", *aR);
        printf("\nSu valor entero decimal es: %lld\n", strtoll((*lista)->info, NULL, base));
        fprintf(*aR, "%lld\n", strtoll((*lista)->info, NULL, base));

        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }

    //de las decimales hago la sumatoria

    if (base == 10) {
        printf("\nLa sumatoria de todos los numeros es: %d", sumatoria);
        fputs("\nLa sumatoria de todos los numeros es: ", *aR);
        fprintf(*aR, "%d", sumatoria);
    }
}

void archivarReales(nodo **lista, FILE **aR) {
    nodo *lista_aux;  //recorro constantes reales mostrando el valor de su mantisa y parte entera
    if (*lista == NULL) {
        printf("\nEl archivo de entrada no presenta constantes reales\n");
        fputs("El archivo de entrada no presenta constantes reales\n", *aR);
    }
    while (*lista) {
        double mantisa, parteEntera;
        double numero = atof((*lista)->info);
        mantisa = modf(numero, &parteEntera);
        fprintf(*aR, "Parte entera: %f. Parte decimal: %f\n", parteEntera, mantisa);
        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }
}

void archivarCaracteres(nodo **lista, FILE **aR) {
    nodo *lista_aux;
    //voy recorriendo la lista y mostrando las constantes caracter
    while (*lista) {
        fprintf(*aR, "Caracter que aparece es: %s\n", (*lista)->info);
        printf("Caracter que aparece es: %s\n", (*lista)->info);

        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }
}