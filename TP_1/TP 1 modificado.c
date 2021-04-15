#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LecturaArchivoTXT(char textoExtraido[])
{
    FILE* fichero;

    //LECTURA
    fichero = fopen("Cadena.txt", "rt");
    fgets (textoExtraido, 50, fichero);



    fclose(fichero);
}

void ReconocerEntero(char[]);
int MaquinaDeEstados(char caracter, int estado);

enum estados { q0,      //Alias
               q1,
               q2,
               q3,
               q4,
               q5,
               ERROR };

int main()
{
    char textoExtraido [500];
    LecturaArchivoTXT(textoExtraido);
    printf ("Texto extraido es: %s\n ", textoExtraido);

    char *subCadena;
    subCadena = strtok(textoExtraido, ","); //Strtok, función q separa una cadena en varias de acuerdo a un delimitador.
    while(subCadena != NULL)
    {
    printf(" \nSubcadena -> %s", subCadena);
    ReconocerEntero(subCadena);
        subCadena = strtok(NULL, ",");

    }
    return 0;
}

void ReconocerEntero(char str[]) {

    int estado = q0;

    int caracterActual = 0;

    while (str[caracterActual] != '\0') { /

        estado = MaquinaDeEstados(str[caracterActual], estado);
        caracterActual++;


    }


    if (estado == q2)
        printf(" es DECIMAL\n");
    else if (estado == q4)
        printf(" es HEXADECIMAL\n");
    else if (estado == q1 || estado == q5)
        printf(" es OCTAL\n");
    else
        printf(" No puede reconocerse\n");








}


int MaquinaDeEstados(char caracter, int estado) {
    int q6 = ERROR;
    int tabla[7][5] = {
        {q1, q2, q2, q6, q6},
        {q5, q5, q6, q6, q3},
        {q2, q2, q2, q6, q6},
        {q4, q4, q4, q4, q6},
        {q4, q4, q4, q4, q6},
        {q5, q5, q6, q6, q6},
        {q6, q6, q6, q6, q6}};

    switch (caracter) {
        case '0':
            estado = tabla[estado][0];
            break;
        case '1' ... '7':
            estado = tabla[estado][1];
            break;
        case '8' ... '9':
            estado = tabla[estado][2];
            break;
        case 'a' ... 'f':
        case 'F' ... 'F':
            estado = tabla[estado][3];
            break;
        case 'x':
        case 'X':
            estado = tabla[estado][4];
            break;

        break;
        default:
            break;
    }
}
