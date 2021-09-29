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

//Se define el numero de hilos
#define NTHREADS vert

using namespace std;

class Graph{
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
	
	struct Elements
	{
		//int s;
	    list<int> queue;
		//bool visited;
		bool visited = new bool[vert];
	}
	
	//list<int> queue, bool *visited
	void* checkVert(void *arg) {
		
		struct Elements *access;
		access = (struct Elements *)arg; 
		
		//en vez de esto
		s = queue.front();
		information += to_string(s) + " ";
		queue.pop_front();
		
		//solo esto?
		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
			//solo los nodos que no han sido recorridos
			if (!visited[*i]) {
				// cout<<"nodo visitado"<< *i << endl;
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	//metodo de fuente del grafo
	string bfs(int s)
	{
		string information = "";
		//ningun vertice a sido recorrido
		
		//bool *visited = new bool[vert];
		for(int i = 0; i < vert; i++){
			visited[i] = false;
		}

		//cola bfs
		//list<int> queue;

		//empieza a marcar los vertices como visitados
		visited[s] = true;
		queue.push_back(s);
		
		struct Elements accessMain;

		pthread_t tid;
		int createTreads;

		//sigue hasta que la cola este vacia
		while(!queue.empty()){
			// cout<< "Revisando los vertices adyacentes"<< s << endl;
			for(int j = 0; j = NTHREADS; j++){                      
				createThread = pthread_create(&tid, NULL, checkVert, (void *)&accessMain);
				
				if (createTreads != 0)  //Jalar queue y visited 
						cout << "\nNo se puede crear el hilo correctamente :(";	
			    
			    pthread_join(tid, &information);

		}
		return information;
	}
};
