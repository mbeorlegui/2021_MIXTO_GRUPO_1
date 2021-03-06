#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void RecorrerArchivo(FILE*, FILE*, bool*);
void MaquinaDeEstados(char, int*);
void ImprimirArchivo(FILE*, int);

enum estados { q0,
               q1,
               q2,
               q3,
               q4,
               q5,
               q6 };

void main(void) {
    FILE* aEntrada = fopen("entrada.txt", "r");
    FILE* aSalida = fopen("salida.txt", "w");
    bool finalDelArchivo = false;

    while (finalDelArchivo == false) {
        RecorrerArchivo(aEntrada, aSalida, &finalDelArchivo);
    }

    fclose(aEntrada);
    fclose(aSalida);

    system("PAUSE");
}

void RecorrerArchivo(FILE* aEntrada, FILE* aSalida, bool* finalDelArchivo) {
    if (aEntrada != NULL) {
        char datoEntrada;
        int estadoActual = q0;

        datoEntrada = fgetc(aEntrada);
        if (datoEntrada != ',') {
            while (!feof(aEntrada)) {
                if (datoEntrada != ',') {
                    MaquinaDeEstados(datoEntrada, &estadoActual);
                    fwrite(&datoEntrada, sizeof(char), 1, aSalida);
                } else if (datoEntrada != '\0') {
                    ImprimirArchivo(aSalida, estadoActual);
                    estadoActual = q0;
                }
                fread(&datoEntrada, sizeof(char), 1, aEntrada);
                if (feof(aEntrada) != 0 && datoEntrada != '\0' && datoEntrada != ',')
                    ImprimirArchivo(aSalida, estadoActual);
            }
        }

        if (feof(aEntrada) != 0) {
            *finalDelArchivo = true;
        }
    }
}

void MaquinaDeEstados(char caracter, int* estado) {
    int tabla[7][6] = {
        {q1, q2, q2, q6, q6, q6},
        {q5, q5, q6, q6, q3, q6},
        {q2, q2, q2, q6, q6, q6},
        {q4, q4, q4, q4, q6, q6},
        {q4, q4, q4, q4, q6, q6},
        {q5, q5, q6, q6, q6, q6},
        {q6, q6, q6, q6, q6, q6}};

    switch (caracter) {
        case '0':
            *estado = tabla[*estado][0];
            break;
        case '1' ... '7':
            *estado = tabla[*estado][1];
            break;
        case '8' ... '9':
            *estado = tabla[*estado][2];
            break;
        case 'a' ... 'f':
        case 'A' ... 'F':
            *estado = tabla[*estado][3];
            break;
        case 'x':
        case 'X':
            *estado = tabla[*estado][4];
            break;
        default:
            *estado = tabla[*estado][5];
            break;
    }
}

void ImprimirArchivo(FILE* aSalida, int estado) {
    if (estado == q2)
        fprintf(aSalida, "\t\t->\t\tDECIMAL\n");
    else if (estado == q4)
        fprintf(aSalida, "\t\t->\t\tHEXADECIMAL\n");
    else if (estado == q1 || estado == q5)
        fprintf(aSalida, "\t\t->\t\tOCTAL\n");
    else
        fprintf(aSalida, "\t\t->\t\tNO RECONOCIDO\n");
}