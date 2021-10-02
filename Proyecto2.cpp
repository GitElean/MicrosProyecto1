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

#include <iostream>
#include <stdio.h>


#include "BFS.cpp" // Llamar elementos del archivo "BFS.cpp"
#include "bfsNodesTree.cpp"

void menu()
{
    Graph grafo(17);
    grafo.addEdge(1, 2);
    grafo.addEdge(2, 3);
    grafo.addEdge(2, 13);
    grafo.addEdge(3, 4);
    grafo.addEdge(3, 12);
    grafo.addEdge(4, 5);
    grafo.addEdge(4, 7);
    grafo.addEdge(5, 6);
    grafo.addEdge(7, 8);
    grafo.addEdge(7, 10);
    grafo.addEdge(8, 9);
    grafo.addEdge(10, 11);
    grafo.addEdge(13, 14);
    grafo.addEdge(14, 15);
    grafo.addEdge(14, 16);

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
            cout << grafo.bfs(num) << endl;
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