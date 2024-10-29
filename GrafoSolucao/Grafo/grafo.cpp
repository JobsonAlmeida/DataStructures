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

Grafo::~Grafo() //destrutor
{
	delete[] vertices;

	for (int i = 0; i < maxVertices; i++) {
		delete[] matrizAdjacencias[i];
	}

	delete[] matrizAdjacencias;

}

int Grafo::obterIndice(TipoItem item) 
{
	int indice = 0;
	while (item != vertices[indice]) {
		indice++;

		if (indice > maxVertices) {
			break;
		}
	}

	if (item == vertices[indice]) { //checking if ite was found
		return indice;
	}
	else {
		return -1;
	}

}

bool Grafo::estaCheio() 
{
	return (numVertices == maxVertices);
}

void Grafo::isereVertice(TipoItem item) 
{
	if (estaCheio()) {
		cout << "O número máximo de vertices foi alcançado!\n";
	}
	else {
		vertices[numVertices] = item;
		numVertices++;
	}
}

void Grafo::insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso) 
{
	int linha = obterIndice(noSaida);
	int coluna = obterIndice(noEntrada);

	if (linha == arestaNula || coluna == arestaNula) {
		cout << "Entrada ou Saída não existente!\n";
		return;
	}

	matrizAdjacencias[linha][coluna] = peso;
	matrizAdjacencias[coluna][linha] = peso; // not applied when graph is undirected

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