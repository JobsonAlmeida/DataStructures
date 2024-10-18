#include <iostream>
#include "hash.h"

using namespace std;

Hash::Hash(int tamanhoVetor, int max) 
{
	maxPosicoes = tamanhoVetor;
	maxItens = max;
	quantItens = 0;

	estrutura = new Aluno[maxPosicoes]; // nessa criação do vetor estrutura com objetos da classe Aluno 
	                                    // será chamado o construtor padrão da classe Aluno
}

Hash::~Hash() 
{
	delete[] estrutura;
}

int Hash::funcaoHash(Aluno aluno)
{
	return (aluno.obterRa() % maxPosicoes);
}

bool Hash::estaCheio() 
{
	return (quantItens == maxItens)
}

int Hash::obterTamanhoAtual() 
{
	return quantItens;

}

void Hash::inserir(Aluno aluno) 
{

}

void Hash::deletar(Aluno aluno) 
{

}

void Hash::buscar(Aluno& aluno, bool& busca) 
{

}

void Hash::imprimir() 
{

}