/*---------------------------------------------------------------------------
* <h1> Proyecto 2 </h1>
* <h2> Breath First Search (BFS) Clase del algoritmo </h2>
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

#include <bits/stdc++.h>
#include <iostream>
#include <list>

#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// variables globales
list<int> theQueue;
bool *visited;

struct Check // Para transportar el puntero del numero solicitado
{
	int number;
};

// Hilo mutex
pthread_mutex_t theLock;

// Subrutina para llevar a cabo la parte critica del método BFS
// Para identificar si el vertice ya fue visitado
void* checkAdj(void *arg)
{
	pthread_mutex_lock(&theLock);

	struct Check *checking;
	checking = (struct Check *)arg;

	int j = checking -> number;
	int* i = &j;
	
	if(!visited[*i])
	{
		visited[*i] = true;

		theQueue.push_back(*i);
	}

	pthread_mutex_unlock(&theLock);

	return (void *)1;
}

class Graph{ // Clase grafo donde se ipmlementará todo lo necesario junto con BFS
private:
	//numero de vertices
	int vert;
	
	//puntero lista de adyacencia
	list<int>* adj;
		
public:
	//constructor
	Graph(int pVert)
	{
		//numero de vertices
		vert = pVert;
	
		//Lista de adyacencia
		adj = new list<int>[pVert];
	}
	
	//metodo para añadir una arista
	void addEdge(int v, int v2)//v = vertice 1, v2 = vertice 2
	{
		adj[v].push_back(v2);
	}

	//metodo de fuente del grafo
	string bfs(int s)
	{
		string information = "";
		//ningun vertice a sido recorrido
		visited = new bool[vert];
		for(int i = 0; i < vert; i++){
			visited[i] = false;
		}
	
		//cola bfs		
		theQueue.clear();
	
		//empieza a marcar los vertices como visitados
		visited[s] = true;
		theQueue.push_back(s);		

		// Implementación de hilos y mutex
		pthread_t tid;
		int createTreads;
		void *returned;

		if(pthread_mutex_init(&theLock, NULL) != 0)
		{
			return "ERROR: La inicializacion de mutex fallo";
		}
	
		//sigue hasta que la cola este vacia
		while(!theQueue.empty()){
			s = theQueue.front();
			information += to_string(s) + " ";
			theQueue.pop_front();
		
			// cout<< "Revisando los vertices adyacentes"<< s << endl;
			for(auto i = adj[s].begin(); i != adj[s].end(); i++){
				struct Check check;
				check.number = *i;

				createTreads = pthread_create(&tid, NULL, checkAdj, (void *)&check);

				pthread_join(tid, &returned);
			}		
		}	
		return information;
	}
};