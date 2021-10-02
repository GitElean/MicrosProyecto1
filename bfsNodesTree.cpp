#include<iostream>

using namespace std;

class Tree {

private: 
	int data;
	//Nodo izquierdo
	Tree* leftN;
	//Nodo derecho
	Tree* rightN;
	Tree* root;

public:
	
	Tree() {
		data = 0;
		//Nodo izquierdo
		leftN = NULL;
		//Nodo derecho
		rightN = NULL;
		root = NULL;
	}	

	//constructor
	Tree(int value)
	{
		data = value;
		//Nodo izquierdo
		leftN = NULL;
		//Nodo derecho
		rightN = NULL;
		root = NULL;
	}
	
	int TreeHeight(Tree* root)
	{
		// añadir nodos
		// ver altura
		// ver si está vacío
		if (root == NULL)
			return -1;
		
		int leftH = TreeHeight(root -> leftN);
		             //Poner altura
		int rightH = TreeHeight(root -> rightN);
		
		if(leftH > rightH){
			return (leftH + 1);			
		}

		return (rightH + 1);				    		
    }
	
	void addNode(Tree * nodeAdded) 
	{
    if (root == NULL) 
    {
      root = nodeAdded;
    } 
    else {
		Tree* tROOT = root;
		
      while (tROOT != NULL) {
		  //chequea si el nodo que se desea ser anadido al arbol es menor que el valor apuntado y
		  //si existe espacio para añadirlo, un espacio nulo 
		  if ((nodeAdded -> data < tROOT -> data) && (tROOT -> leftN == NULL)) 
		  {
			  //Asigna el nuevo elemento a un espacio de memoria
          tROOT -> leftN = nodeAdded;
          break;
          } 
          
          //En caso de que no haya sido nulo en el caso anterior chequea si a lo que apunta lo anterior es menor
          else if (nodeAdded -> data < tROOT -> data) 
          {
			  //asigna para que sea la nueva raiz temporal
          tROOT = tROOT -> leftN;
          }
           
           //Lo mismo pero con el lado derecho
          else if ((nodeAdded -> data > tROOT -> data) && (tROOT -> rightN == NULL)) 
          {
          tROOT -> rightN = nodeAdded;
          break;
          }
          else 
          {
          tROOT = tROOT -> rightN;
          }
      }
    }
  }   
};

int main(void)
{
    Tree raiz(1);

    cout << "DONE" << endl;

    return 0;
}
