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
		cout << "O n�mero m�ximo de vertices foi alcan�ado!\n";
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

	if (linha == arestaNula) {
		cout << "Sa�da n�o existente!\n";
		return;
	}
	else if (coluna == arestaNula) {
		cout << "Entrada n�o existente!\n";
		return;
	}

	matrizAdjacencias[linha][coluna] = peso;
	matrizAdjacencias[coluna][linha] = peso; // not applied when graph is undirected

}

int Grafo::obterPeso(TipoItem noSaida, TipoItem noEntrada) 
{
	int linha = obterIndice(noSaida);
	int coluna = obterIndice(noEntrada);

	if (linha == arestaNula) {
		cout << "Sa�da n�o existente!\n";
		return linha;
	}
	else if (coluna == arestaNula) {
		cout << "Entrada n�o existente!\n";
		return coluna;
	}

	return matrizAdjacencias[linha][coluna];

}

int Grafo::obterGrau(TipoItem item) 
{
	int linha = obterIndice(item);
	int grau = 0;
	for (int i = 0; i < maxVertices; i++) {
		if (matrizAdjacencias[linha][i] != arestaNula) {
			grau++;
		}
	}

	return grau;
}

void Grafo::imprimirMatriz() 
{
	cout << "Matriz de adec�ncias: \n";

	for (int i = 0; i < maxVertices; i++) {
		for (int j = 0; j < maxVertices; j++) {
			cout << matrizAdjacencias[i][j] << " ";
		}
		cout << endl;
	}

}

void Grafo::imprimirVertices() 
{
	cout << "Lista de vertices\n";

	for (int i = 0; i < numVertices; i++) {
		cout << i << ": " << vertices[i] << endl;
	}

}