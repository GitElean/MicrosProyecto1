/*---------------------------------------------------------------------------
* <h1> Proyecto 2 </h1>
* <h2> Breath First Search (BFS) </h2>
*
* <p> Implementación de Algoritmo BFS utilizando hilos </p>
*
* @author {
*   Elean Rivas,
*   Rebecca Smith,
*   Sara Paguaga,
*   Cristian Laynez
* }
* @date	6 - Septiembre - 2021
* Universidad del Valle de Guateamala
* Programación de Microprocesadores - Sección 20
---------------------------------------------------------------------------*/
 
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "BFS.cpp" // Llamar elementos del archivo "BFS.cpp"

int main(void)
{
    printf("----- PROYECTO #2 - Microprocesadores -----\n");

    Graph grafo(2);

    grafo.addEdge(5, 3);
    grafo.addEdge(5, 4);

    return 0;
}