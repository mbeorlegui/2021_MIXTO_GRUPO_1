#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Enum para asignarle un numero a cada tipo de token
enum tipoToken {palabraReservada = 1, identificador = 2, operadorOCaracterDePuntuacion = 3, literalCadena = 4, constanteOctal = 5};

// Estructura nodo para guardar cada token
typedef struct nodo
{
    int numeroDeLinea;
    enum tipoToken token;
    char* texto;
    int longitudDeTexto;
    struct nodo* siguiente;   
}NODO;

/* Para que cada token se agregue una sola vez a la lista uso la funcion buscarEnLista que devuelve 0 si 
   el token NO esta y devuevle 1 si el token SI esta 
*/
int buscarEnLista(NODO* lista, char* texto);

// Para insertar un nodo al final de la lista si NO aparece en la lista
void insertarAlFinalDeLaLista(NODO**lista, int numeroDeLinea, enum tipoToken token, char* texto, int longitudTexto);

// Longitud maxima del texto de un token, lo voy a usar para alinear la tabla
int longitudMaximaDeTexto(NODO* lista);

// Imprimo la lista de tokens 
void imprimirListaEnArchivo(FILE* archivo, NODO* lista);

// Libero memoria ocupada por lista
void liberarMemoriaOcupadaPorLista(NODO* lista);