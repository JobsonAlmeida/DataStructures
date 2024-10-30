#include <iostream>
#include "grafo.h"

using namespace std;

Grafo::Grafo(int max, int valorArestaNula) //construtor
{
	numVertices = 0;
	maxVertices = max;
	arestaNula = valorArestaNula;

	vertices = new TipoItem[maxVertices];
	marcador = new bool[maxVertices];

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

	if (linha == arestaNula) {
		cout << "Saída não existente!\n";
		return;
	}
	else if (coluna == arestaNula) {
		cout << "Entrada não existente!\n";
		return;
	}

	matrizAdjacencias[linha][coluna] = peso;
	//matrizAdjacencias[coluna][linha] = peso; // not applied when graph is undirected

}

int Grafo::obterPeso(TipoItem noSaida, TipoItem noEntrada) 
{
	int linha = obterIndice(noSaida);
	int coluna = obterIndice(noEntrada);

	if (linha == arestaNula) {
		cout << "Saída não existente!\n";
		return linha;
	}
	else if (coluna == arestaNula) {
		cout << "Entrada não existente!\n";
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
	cout << "Matriz de adjacências: \n";

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

void Grafo::limpaMarcador()
{
	for (int i = 0; i < maxVertices; i++) {
		marcador[i] = false;
	}
}

void Grafo::buscaEmLargura(TipoItem origem, TipoItem destino) // we want the search from one specific vertice to another specific vertice
{
	filadinamica filaVertices;
	bool encontrado = false;
	limpaMarcador();
	filaVertices.inserir(origem); 

	do {
		TipoItem verticeAtual = filaVertices.remover();
		if (verticeAtual == destino) {
			cout << "Visitando: " << verticeAtual << endl;
			cout << "Caminho encontrado!\n";
			encontrado = true;
		}
		else {
			int indice = obterIndice(verticeAtual);
			cout << "Visitando: " << verticeAtual << endl;
			for (int i = 0; i < maxVertices; i++) {
				if (matrizAdjacencias[indice][i] != arestaNula) {
					if (!marcador[i]) {
						cout << "Enfileirando: " << vertices[i] << endl;
						filaVertices.inserir(vertices[i]);
						marcador[i] = true;
					}
				}
			}
		}

	} while (!filaVertices.estavazio() && !encontrado);

	if (!encontrado) {
		cout << "Caminho não encontrado!\n";
	}
		
}

void Grafo::buscaEmProfundidade(TipoItem origem, TipoItem destino) 
{
	pilhadinamica pilhaVertices;
	bool encontrado = false;
	limpaMarcador();
	pilhaVertices.inserir(origem);

	do {
		TipoItem verticeAtual = pilhaVertices.remover();
		if (verticeAtual == destino) {
			cout << "Visitando: " << verticeAtual << endl;
			cout << "Caminho encontrado!\n";
			encontrado = true;
		}
		else {
			int indice = obterIndice(verticeAtual);
			cout << "Visitando: " << verticeAtual << endl;
			for (int i = 0; i < maxVertices; i++) {
				if (matrizAdjacencias[indice][i] != arestaNula) {
					if (!marcador[i]) {
						cout << "Empilhando: " << vertices[i] << endl;
						pilhaVertices.inserir(vertices[i]);
						marcador[i] = true;
					}
				}
			}
		}

	} while (!pilhaVertices.estavazio() && !encontrado);

	if (!encontrado) {
		cout << "Caminho não encontrado!\n";
	}

}