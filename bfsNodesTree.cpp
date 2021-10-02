#include<iostream>

class Tree {

private: 
	int data;
	//Nodo izquierdo
	Tree* leftN;
	//Nodo derecho
	Tree* rightN;

public:
	//constructor
	Tree(int value)
	{
		data = value;
		//Nodo izquierdo
		leftN = NULL;
		//Nodo derecho
		rightN = NULL;
	}
	
	int TreeHeight(Tree* root)
	{
	// añadir nodos
	// ver altura
	// ver si está vacío
	if (root == NULL)
		return -1;
	else{                     //Obtenerlo de otra forma        
		int leftH = TreeHeight(root -> leftN);
		             //Poner altura
		int rightH = TreeHeight(root -> rightN);
		
		if(leftH > rightH)
			return (leftH + 1);
		else return (rightN + 1);
	    }
    }
	
	void addNode( 
	
	
	
}
