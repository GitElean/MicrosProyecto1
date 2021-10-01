#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
#define NTHREADS 17


struct Check
{
	int i;
	list<int> queue;
	bool *visited ;
	pthread_mutex_t lock;
};

struct Check testG;

void* checkAdj(void *arg)
{
	struct Check *checking;
	checking = (struct Check *)arg;
	pthread_mutex_t lock = checking -> lock;

	//pthread_mutex_lock(&lock);

	int i = checking -> i;
	int* ptr_i = &i;
	list<int> queue = checking -> queue;
	bool visited = checking -> visited;

	if(!visited[ptr_i]){
		visited[ptr_i] = true;
			
		queue.push_back(*ptr_i);
	}

	//pthread_mutex_unlock(&lock);		
	testG.queue = queue;	

	return (void*)1;
}

class Graph{
private:
	//numero de vertices
	int vert;
	
	//puntero lista de adyacencia
	list<int>* adj;

	// Preprar cancelar	
	pthread_mutex_t lock;
		
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
		string information = "XD:";
		//ningun vertice a sido recorrido
		bool *visited = new bool[vert];
		for(int i = 0; i < vert; i++){
			visited[i] = false;
		}
	
		//cola bfs
		list<int> queue;
	
		//empieza a marcar los vertices como visitados
		visited[s] = true;
		queue.push_back(s);

		// preparar informacion para la estructura
		struct Check check;
		check.queue = queue;
		check.visited = visited;

		void *returned;

		// Para llevar a cabo la ejecución de hilos
		pthread_t tid;
		int createTreads;		

		if(pthread_mutex_init(&lock, NULL) != 0)
		{
			return "ERROR: La inicializacion de mutex fallo";
		}

		//sigue hasta que la cola este vacia
		while(!queue.empty()){
			s = queue.front();
			information += to_string(s) + " ";
			cout << s << endl;
			queue.pop_front();
		
			// cout<< "Revisando los vertices adyacentes"<< s << endl;
            
			for(auto i = adj[s].begin(); i != adj[s].end(); i++){
			//solo los nodos que no han sido recorridos
				check.i = *i;
				
				createTreads = pthread_create(&tid, NULL, checkAdj, (void *)&check);
				
				pthread_join(tid, &returned);

				//queue = (Check)returned;
				queue = testG.queue;
			}		
		}	

		pthread_mutex_destroy(&lock);

		return information;
	}
};