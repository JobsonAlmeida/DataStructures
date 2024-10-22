#pragma once

#include <iostream>]
#include "aluno.h"

struct No
{
	Aluno aluno;
	No* filhoEsquerda;
	No* filhoDireita;
};

class ArvoreBinariaDeBusca
{
	private:
		No* raiz;
	public:
		ArvoreBinariaDeBusca();
		~ArvoreBinariaDeBusca();
		void deletarArovre(No* NoAtual);
		No* obterRaiz();
		bool estaVazio();
		bool estaCheio();
		void inserir(Aluno aluno);
		void remover(Aluno aluno);

		// methods used in case 3 - node with two children
		void removerBusca(Aluno aluno, No* & noAtual);
		void deletarNo(No*& noAtual);
		void obterSucessor(Aluno& AlunoSucessor, No* temp);

		// methods used to search and print
		void buscar(Aluno& aluno, bool& busca);
		void imprimirPreOrdem(No* NoAtual);
		void imprimirEmOrdem(No* NoAtual);
		void imprimirPosOrdem(No* NoAtual);
};