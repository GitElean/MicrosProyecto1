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


#include "BFSGraph.cpp" // Llamar elementos del archivo "BFS.cpp"
//#include "bfsNodesTree.cpp"

void numberForNewVector(Graph grafo, int selected);

void menu()
{
    Graph grafo(20);
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

        printf("\nElija una de las siguientes opciones\n");
        printf("\n1. Buscar un numero en el arbol");
        printf("\n2. Desplegar el arbol");
        printf("\n3. Agregar un numero al arbol");
        printf("\n4. Salir del programa\n");

        opcion = 0;

        scanf("%d",&opcion);

        int num;

        switch (opcion)
        {
        case 1:
        //se busca un numero en el arbol
            printf("\nIngrese el numero que desea buscar\n");
            num = 0;
            scanf("%d",&num);

            (num > 0) ? cout << "\nResultado:\n" << grafo.bfs(num) << endl 
                    : cout << "\nNo debes ingresar numeros menores a 0\n";            
            break;

        case 2:
            //se imprime el arbol asi re nice
            cout << "\n" << grafo.bfs(1) << "\n" << endl;
            break;

        case 3:
            //se le agrega un numero al arbol
            char sNodo;
            printf("\nIngrese el Nodo donde desee ingresar el nuevo numero: \n");            
            printf("\na) Nodo #1\n");            
            printf("\nb) Nodo #13\n");            
            printf("\nc) Nodo #16\n");            
            cin >> sNodo;

            switch (sNodo)
            {
            case 'a':
                numberForNewVector(grafo, 1);
                break;

            case 'b':
                numberForNewVector(grafo, 13);
                break;

            case 'c':
                numberForNewVector(grafo, 16);                
                break;
            
            default:
                printf("\nOpcion inválida");
                break;
            }    

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

void numberForNewVector(Graph grafo, int selected)
{
    int agregar = 0;

    do
    {
        printf("\nIngrese el numero que desea agregar\n");            
        cin >> agregar;        

        if(agregar <= selected && (selected == 1 or selected == 13) == true)
        {
            agregar = 0;
            printf("Estos números son menores que el Nodo solicitado, porfavor implemente un valor mayor a %d", selected);
        }

    } while (agregar <= 0);

    grafo.addEdge(selected, agregar);
}

int main(void)
{
    printf("----- PROYECTO #2 - Microprocesadores -----\n");    
    menu();

    return 0;
}