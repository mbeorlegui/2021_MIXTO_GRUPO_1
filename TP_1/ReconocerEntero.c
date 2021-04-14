#include <stdio.h>

void ReconocerEntero(char[]);
int MaquinaDeEstados(char caracter, int estado);

enum estados { q0,
               q1,
               q2,
               q3,
               q4,
               q5,
               ERROR };

void main(void) {
    char decimal[6] = "129";
    char hexa[6] = "0x12";
    char octal[6] = "0072";
    char noReconocido[6] = "001A";

    ReconocerEntero(decimal);
    ReconocerEntero(hexa);
    ReconocerEntero(octal);
    ReconocerEntero(noReconocido);
}

void ReconocerEntero(char str[]) {
    int estado = q0;
    int caracterActual = 0;

    while (str[caracterActual] != '\0') {
        estado = MaquinaDeEstados(str[caracterActual], estado);
        caracterActual++;
    }

    if (estado == q2)
        printf("El numero ingresado es DECIMAL\n");
    else if (estado == q4)
        printf("El numero ingresado es HEXADECIMAL\n");
    else if (estado == q1 || estado == q5)
        printf("El numero ingresado es OCTAL\n");
    else
        printf("El numero ingresado no puede reconocerse\n");
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
        default:
            break;
    }
}
