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

void archivarPalabrasReservadasComentariosYDirectivas(nodo **lista, FILE **aR){
    nodo *lista_aux;
    
    if(*lista){
        while (*lista) {
            printf("%s", (*lista)->info);
            fprintf(*aR, "%s", (*lista)->info);

            if((*lista)->sgte != NULL){
                printf(", ");
                fputs(", ", *aR);
            }     
            else{
                printf(".");
                fputs(".", *aR);
            }

            lista_aux = (*lista)->sgte;
            free(*lista);
            *lista = lista_aux;
        }
    }
}

void archivarNoReconocidos(nodo **lista, FILE **aR){
    nodo *lista_aux;
    
    if(*lista){
        while (*lista) {
            printf("%s", (*lista)->info);
            fprintf(*aR, "%s", (*lista)->info);
            printf("%d", (*lista)->posicion);
            fprintf(*aR, "%d", (*lista)->posicion);

            if((*lista)->sgte != NULL){
                printf(", ");
                fputs(", ", *aR);
            }     
            else{
                printf(".");
                fputs(".", *aR);
            }

            lista_aux = (*lista)->sgte;
            free(*lista);
            *lista = lista_aux;
        }
    }
}

void archivarConstantes(nodo **lista, FILE **aR, int base) {
    int sumatoria = 0;
    char *numPtr;
    nodo *lista_aux;

    while (*lista){
        fputs("Para la cadena en base ", *aR);
        fprintf(*aR, "%d, ", base);
        fprintf(*aR, "%s", (*lista)->info);
        printf("\nVariable en base %d: %s", base, (*lista)->info);
        fputs(" su valor entero decimal es: ", *aR);
        printf("\nSu valor entero decimal es: %lld\n", strtoll((*lista)->info, NULL, base));
        fprintf(*aR, "%lld\n", strtoll((*lista)->info, NULL , base));

        if(base == 10){
            int pasarAInt = (int) ((*lista)->info);
            printf("\n%d\n", pasarAInt);
            sumatoria += pasarAInt;
        }

        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }

    if(base == 10)
        printf("\nLa sumatoria de todos los numeros es: %d", sumatoria);
}  

void archivarConstantesDecimales(nodo **lista, FILE **aR){
    int sumatoria = 0;
    nodo *lista_aux;

    while(*lista){
        printf("\nVariable en base 10: %s", (*lista)->info);
        int pasarAInt = (int) ((*lista)->info);
        printf("\n%d\n", pasarAInt);
        sumatoria += pasarAInt;

        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }

    printf("\nLa sumatoria de todos los numeros es: %d", sumatoria);
}

void archivarReales(nodo **lista, FILE **aR) {
    nodo *lista_aux; 
    while (*lista){
        double mantisa, parteEntera;
        double numero =atof((*lista)->info);
        mantisa = modf(numero, &parteEntera);
        fprintf(*aR,"Parte entera: %f. Parte decimal: %f\n", parteEntera, mantisa);
        lista_aux = (*lista)->sgte;
        free(*lista);
        *lista = lista_aux;
    }  
}

void archivarCaracteres(nodo**lista, FILE **aR) {
    nodo *lista_aux;
    while (*lista){
    int i;
     for(i = 1;(*lista)->info;i++) {
         fprintf(*aR,"%c caracter que aparece es: \"%s\n", i, (*lista)->info);
         lista_aux= (*lista)->sgte;
         *lista = lista_aux;
     }
    }
    
}