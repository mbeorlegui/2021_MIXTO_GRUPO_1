# TRABAJO PRÁCTICO N° 1

El objetivo de este trabajo práctico era reconocer el tipo de variables decimales entregadas a traves de un archivo llamado `entrada.txt` en el cual las variables estaran separadas por comas. 
Este reconocimiento debo hacerlo a través de un automata. Finalmente imprimo en `salida.txt` el resultado de los reconocimientos antes mencionados.

Para leer el archivo de entrada usamos la función `fgetc()`, la cual lee caracter por caracter, y para escribir en el archivo de salida usamos `fwrite()`.

La implementacion del automata finito la hicimos a traves de los siguientes datos:

### Automata
<div align="center">

![Automata](https://github.com/utn-frba-ssl/21-001-09/blob/main/01-Implementacion-de-un-AFD-para-GR/Automata.png)
</div>

### Tabla
<div align="center">

| **TT**  | 0    | [1-7]| [8-9] | [xX]  | [a-f][A-F]| Otro caracter |  
| :----:  | :---:| :---:| :---: | :---: | :---:     | :---:  | 
| **q0-** | q1   |	q2	|	q2	|	q6	|	q6	    |	q6	 |
| **q1+** | q5   | 	q5	| 	q6	|	q6	|	q3	    |	q6	 |
| **q2**  | q2   |  q2	| 	q2	|	q6	|	q6	    |	q6	 |
| **q3+** | q4   |  q4	| 	q4	|	q4	|	q6	    |	q6	 |
| **q4+** | q4 	 |  q4	| 	q4	|	q4	|	q6	    |	q6	 |
| **q5+** | q5 	 |  q5	| 	q6	|	q6	|	q6	    |	q6	 |
| **q6+** | q6 	 |  q6	| 	q6	|	q6	|	q6	    |	q6	 |
</div>