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

void menu()
{
    Graph grafo(4);
    grafo.addEdge(0, 1);
    grafo.addEdge(0, 2);
    grafo.addEdge(1, 2);
    grafo.addEdge(2, 0);
    grafo.addEdge(2, 3);
    grafo.addEdge(3, 3);

    cout << "TEST: " << grafo.bfs(2) << endl;

    bool test = false;
    do
    {
        int opcion;

        printf("Elija una de las siguientes opciones\n");
        printf("\n1. Buscar un numero en el arbol");
        printf("\n2. Desplegar el arbol");
        printf("\n3. Agregar un numero al arbol");
        printf("\n4. Salir del programa\n");

        opcion = 0;

        scanf("%d",&opcion);

        int num;
        int agregar;

        switch (opcion)
        {
        case 1:
        //se busca un numero en el arbol
            printf("\nIngrese el numero que desea buscar\n");
            num = 0;
            scanf("%d",&num);
            break;

        case 2:
            //se imprime el arbol asi re nice
            break;

        case 3:
            //se le agrega un numero al arbol
            printf("\nIngrese el numero que desea agregar\n");            
            cin >> agregar;
            printf("\nEl numero es %d:\n", agregar);
            break;

        case 4:
            printf("\nAdios :)");
            test = true;
            break;

        default:
            printf("\nIngrese una opcion valida");
            break;
        }
    } while (test != true);
    
}


int main(void)
{
    printf("----- PROYECTO #2 - Microprocesadores -----\n");
    
    menu();

    return 0;
}