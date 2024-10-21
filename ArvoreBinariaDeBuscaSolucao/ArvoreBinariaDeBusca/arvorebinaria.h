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
		void buscar(Aluno& aluno, bool& busca);
		void imprimirPreOrdem(No* NoAtual);
		void imprimirEmOrdem(No* NoAtual);
		void imprimirPosOrdem(No* NoAtual);
};