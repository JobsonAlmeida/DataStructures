#pragma once

//Grafo Simples - Não há arestas múltiplas nem laços
//Grafo Simples Direcionado e Ponderado

#include <iostream>
#include "pilhadinamica.h"
#include "filadinamica.h"

using namespace std;

//typedef string TipoItem;

class Grafo {
	private: 
		int numVertices;
		int maxVertices;
		int arestaNula;			
		TipoItem* vertices;
		int** matrizAdjacencias;
		bool* marcador;

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

		//novos
		void limpaMarcador();
		void buscaEmLargura(TipoItem origem, TipoItem destino);
		void buscaEmProfundidade(TipoItem origem, TipoItem destino);
};

