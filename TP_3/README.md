# TRABAJO PRÁCTICO N° 3

El objetivo de este trabajo practico es implementar en C un programa que permita reconocer en un archivo.c de entrada todas las categorías léxicas de C, comentarios. El mismo deberá  dar como salida en pantalla un reporte. Para desarrollar dicho programa deberá utilizar LEX/FLEX para la generación del código C que implemente un analizador léxico que cumpla con los requisitos:

**Categorías léxicas de C a reconocer**:
- Constantes (Entera decimal, entera octal, entera hexadecimal, real, caracter)
- Literal cadena
- Palabras reservadas (distinguir entre tipo de dato, estructuras de control y otros)
- Identificadores 
- Caracteres de puntuación/operadores de C.


**Comentarios** (en realidad son reconocidos por el PREPROCESADOR):
- Comentarios de una línea
- Comentarios de múltiples líneas

**El archivo de reporte deberá contener lo siguiente**:
- Listado de identificadores encontrados indicando la cantidad de veces que aparece cada uno de ellos. El listado debe estar ordenado alfabéticamente.
- Listado de literales cadena encontrados indicando la longitud de los mismos y ordenados por longitud ascendente. En caso de igual longitud no importa el orden.
- Listado de palabras reservadas en el orden en el que han aparecido en el archivO.
- Listado de constantes indicando según su tipo:
  - Para las constantes octales indicar su valor entero decimal.
  - Para las constante hexadecimales indicar su valor entero decimal
  - Para las constantes decimales indicar el valor de cada una y el total acumulado de sumar todas ellas
  - Para las constantes reales indicar el valor de su mantisa y parte entera
  - Para las constantes carácter, enumerarlas según orden de aparición
- Listado de operadores/caracteres de puntuación indicando cantidad de veces que aparecen.
- Listado de comentarios encontrados distinguiendo si se trata de comentarios de una línea o múltiples líneas.
- Listado de cadenas y/o caracteres no reconocidos indicando el número de línea donde se encontraron.


---
## Compilar y correr (con makefile)
```
$ make
```

---
### Cómo instalar `make` en Windows

1. Descargar [Chocolatey](https://chocolatey.org/install)
2. Ejecutar el CMD como administrador
3. Ingresar allí el comando `choco install make`
4. Ya vas a poder usar todos los makefiles que quieras 😁