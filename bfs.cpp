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

#include <iostream>
#include <list>

using namespace std;

class Graph{
private:
	//numero de vertices
	int vert;
	
	//puntero lista de adyacencia
	list<int>*adj;
	
	
public:
	//constructor
	Graph(int vert):
	
	//metodo para añadir una arista
	void addEdge(int v, int v2);//v = vertice 1, v2 = vertice 2

	//metodo de fuente del grafo
	void bfs(int s)
};

//constructor con el numero de vertices
Graph:: Graph(int vert){
	//numero de vertices
	vert = v
	
	//Lista de adyacencia
	adj = new list<int>[vert];
}


void Graph::addEdge(int v, int v2){
	adj[v].push_back[v2];
}

//bfs
void Graph::bfs(int s){
	//ningun vertice a sido recorrido
	bool *visited = new bool[vert];
	for(int i = 0; i < vert: i++){
	visited[i] = false;
	}
	
	//cola bfs
	list<int> queue;
	
	//empieza a marcar los vertices como visitados
	visited[s] = true;
	queue.push_back(s);
	
	//sigue hasta que la cola este vacia
	while(!queue.empty()){
		s = queue.front();
		queue.pop_front();
		
		cout<< "Revisando los vertices adyacentes"<< s << endl
		for(auto i = adj[s].begin; i != adj[s].end(); i++){
		//solo los nodos que no han sido recorridos
			if(!visited[*i]){
			cout<<"nodo visitado"<< *i << endl;
			visited[*i] = true;
			
			queue.push_back(*i);
			}
		}		
	}	
}
