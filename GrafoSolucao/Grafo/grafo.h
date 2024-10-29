#pragma once

//Grafo Simples - N�o h� arestas m�ltiplas nem la�os
//Grafo Simples N�o-Direcionado e Ponderado

#include <iostream>

using namespace std;

typedef string TipoItem;


class Grafo {
	private: 
		int numVertices;
		int maxVertices;
		int arestaNula;			
		TipoItem* vertices;
		int** matrizAdjacencias;

	public:

		Grafo(int max, int valorArestaNula);
		~Grafo();
		int obterIndice(TipoItem item);
		bool estaCheio();
		void isereVertice(TipoItem item);
		void insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso);
		int obterPeso(TipoItem noSaida, TipoItem noEntrada);
		int obterGrau(TipoItem item);
		void imprimirMatriz();
		void imprimirVertices();

};

