#include <iostream>
#include "grafo.h"

using namespace std;

Grafo::Grafo(int max, int valorArestaNula) //construtor
{
	numVertices = 0;
	maxVertices = max;
	arestaNula = valorArestaNula;

	vertices = new TipoItem[maxVertices];

	matrizAdjacencias = new int*[maxVertices];
	for (int i = 0; i < maxVertices; i++) {
		matrizAdjacencias[i] = new int[maxVertices];
	}

	for (int i = 0; i < maxVertices; i++) {
		for (int j = 0; j < maxVertices; j++) {
			matrizAdjacencias[i][j] = valorArestaNula;
		}
	}

}

Grafo::~Grafo() 
{

}

int Grafo::obterIndice(TipoItem item) 
{

}

bool Grafo::estaCheio() 
{

}

void Grafo::isereVertice(TipoItem item) 
{

}

void Grafo::insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso) 
{

}

int Grafo::obterPeso(TipoItem noSaida, TipoItem noEntrada) 
{

}

int Grafo::obterGrau(TipoItem item) 
{

}

void Grafo::imprimirMatriz() 
{

}

void Grafo::imprimirVertices() 
{

}