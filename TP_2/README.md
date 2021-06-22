# TRABAJO PRÁCTICO N° 2

El objetivo de este trabajo práctico es implementar en C un programa que permita reconocer expresiones aritméticas de suma, resta, producto y cociente . El mismo deberá tomar una expresión (cadena de caracteres) ingresada por el usuario desde la entrada estándar (STDIN) y deberá indicar por pantalla (STDOUT) si la expresión es sintácticamente correcta o no. Dicho proceso se deberá poder repetir para cada cadena que vaya ingresando el usuario, siempre de a una cadena por vez. 


El programa debe contemplar la implementación de un autómata finito de pila, en este caso el que se encuentra en la siguiente tabla de trancisiones:

### Tabla de trancisiones
<div align="center">

| **(ESTADO/CIMA_PILA)** |   0   | [1-9] | {+,-,*,/} |   (   |   )   |
| :--------------------: | :---: | :---: | :-------: | :---: | :---: |
|      **(q0, $)**       |  q1   |  q2   |    q2     |  q6   |  q6   |
|      **(q1, $)+**      |  q5   |  q5   |    q6     |  q6   |  q3   |
|      **(q0, R)**       |  q2   |  q2   |    q2     |  q6   |  q6   |
|      **(q1, R)**       |  q4   |  q4   |    q4     |  q4   |  q6   |
|      **(q2, R)+**      |  q4   |  q4   |    q4     |  q4   |  q6   |
|      **(q2, R)**       |  q5   |  q5   |    q6     |  q6   |  q6   |

</div>

Tener en cuenta:
- Alfabeto de las expresiones o cadenas de caracteres: `{ 0,1,2,3,4,5,6,7,8,9,+,-,*,/,(,) }`
- Alfabeto de la pila: `{R,$}`
- Símbolo de pila vacía: `p0 = $`
- Los espacios entre números y operadores no son obligatorios. El programa debe omitirlos en caso de que los hubiese.

---
## Compilar
```
$ gcc -o TP2 *.c
```
## Correr
```
$ ./TP2
```
---
[< Trabajo práctico anterior](https://github.com/utn-frba-ssl/21-001-09/tree/main/01-Implementacion-de-un-AFD-para-GR)