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

int menu()
{
    int opcion;

    printf("Elija una de las siguientes opciones\n");
    printf("\n1. Buscar un numero en el arbol");
    printf("\n2. Desplegar el arbol");
    printf("\n3. Agregar un numero al arbol");
    printf("\n4. Salir del programa\n");

    opcion = 0;
    
    scanf("%d",opcion);

    int num;
    int agregar;

    switch (opcion)
    {
    case 1:
    //se busca un numero en el arbol
        printf("\nIngrese el numero que desea buscar");
        num =0;
        scanf("%d",num);
        break;

    case 2:
        //se imprime el arbol asi re nice
        break;

    case 3:
        //se le agrega un numero al arbol
        printf("\nIngrese el numero que desea agregar");
        agregar = 0;
        scanf("%d",agregar);
        break;

    case 4:
        printf("\nAdios :)");
        break;


    default:

        printf("\nIngrese una opcion valida");
        break;
    }

    return 0; 

}


int main(void)
{
    printf("----- PROYECTO #2 - Microprocesadores -----\n");

    printf("%d",menu());

    Graph grafo(2);

    grafo.addEdge(5, 3);
    grafo.addEdge(5, 4);

    return 0;
}