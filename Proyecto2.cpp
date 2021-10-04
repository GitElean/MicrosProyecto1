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
*
* NOTA:
* Comando para ejecutar el programa en la terminal
* gcc -o pro Proyecto2.cpp -pthread -lm -ldl -lstdc++
---------------------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>

#include "BFSGraph.cpp" // Llamar elementos del archivo "BFS.cpp"

int limiteGrafo = 30;

void numberForNewVector(Graph grafo, int selected);

void menu()
{    
    // Definir el arbol solicitado
    Graph grafo(limiteGrafo);
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

        scanf("%d",&opcion);

        int num;

        switch (opcion)
        {
        case 1:
        //se busca un numero en el arbol
            printf("\nIngrese el numero que desea buscar\n");
            num = 0;
            scanf("%d",&num);

            if(num >= limiteGrafo)            
                cout << "\nEl limite de vertices es " << limiteGrafo << ", porfavor ingresa un número mas pequenio" << endl;                        
            else
            {
                (num > 0) ? cout << "\nResultado:\n" << grafo.bfs(num) << endl 
                    : cout << "\nNo debes ingresar numeros menores a 0\n";            
            }            
            break;

        case 2:
            //se imprime el arbol asi re nice
            cout << "\n" << grafo.bfs(1) << "\n" << endl;
            break;

        case 3:
            //se le agrega un numero al arbol
            int sNodo;
            printf("\nIngrese el Nodo donde desee ingresar el nuevo numero: \n");                          
            scanf("%d",&sNodo);

            if(sNodo >= limiteGrafo)            
                printf("El limite de ingreso de numeros es %d, porfavor ingresa un numero mas pequenio", limiteGrafo);
            else if(sNodo < 0)
                printf("No debes de ingresar numero menores de 0");
            else            
                numberForNewVector(grafo, sNodo);
                        
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

// Para crear un nuevo vector
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
        if(agregar > limiteGrafo)
        {
            agregar = 0;   
            printf("El limite de ingreso de numeros es 30, porfavor ingresa un numero mas pequenio");             
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