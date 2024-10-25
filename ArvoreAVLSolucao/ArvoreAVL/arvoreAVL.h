#pragma once

#include <iostream>]
#include "aluno.h"

struct No
{
	Aluno aluno;
	No* filhoEsquerda;
	No* filhoDireita;

	int fatorB;
};

class ArvoreAVL
{
private:
	No* raiz;
public:
	ArvoreAVL();
	~ArvoreAVL();
	void deletarArvore(No* NoAtual);
	No* obterRaiz();
	bool estaVazio();
	bool estaCheio();
	void inserir(Aluno aluno); //modificada
	void remover(Aluno aluno); //modificada

	// methods used in case 3 - node with two children
	void removerBusca(Aluno aluno, No*& noAtual, bool & diminuiu); //modificada
	void deletarNo(No*& noAtual); //modificada
	void obterSucessor(Aluno& AlunoSucessor, No* temp);

	// methods used to search and print
	void buscar(Aluno& aluno, bool& busca);
	void imprimirPreOrdem(No* NoAtual);
	void imprimirEmOrdem(No* NoAtual);
	void imprimirPosOrdem(No* NoAtual);


	//novos métodos
	void rotacaoDireita(No*& tree);
	void rotacaoEsquerda(No*& tree);
	void rotacaoEsquerdaDireita(No*& tree);
	void rotacaoDireitaEsquerda(No*& tree);
	void realizaRotacao(No*& tree);
	void insereRecursivo(No*& noAtual, Aluno aluno, bool & cresceu);
};