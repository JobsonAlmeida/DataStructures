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
	return (quantItens == maxItens);
}

int Hash::obterTamanhoAtual() 
{
	return quantItens;

}

void Hash::inserir(Aluno aluno) 
{
	int local = funcaoHash(aluno);
	estrutura[local] = aluno;
	quantItens++;
}

void Hash::deletar(Aluno aluno) 
{
	int local = funcaoHash(aluno);

	if (estrutura[local].obterRa() != -1) {
		estrutura[local] = Aluno(-1, " ");
		quantItens--;
	}

}

void Hash::buscar(Aluno& aluno, bool& busca)
{
	int local = funcaoHash(aluno);
	Aluno aux = estrutura[local];

	if (aluno.obterRa() != aux.obterRa()) {
		busca = false;
	}
	else {
		busca = true;
		aluno = aux; // 
	}
}

void Hash::imprimir()
{
	cout << "Tabela Hash:\n";
	for (int i = 0; i < maxItens; i++) {
		if (estrutura[i].obterRa() != -1) {
			cout << "índice " << i << ": " << "ra: " << estrutura[i].obterRa() << " - ";
			cout << "nome: " << estrutura[i].obterNome() << endl;
		}
	}
	cout << endl;
}