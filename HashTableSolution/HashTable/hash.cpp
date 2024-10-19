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
	if (estaCheio()) {
		cout << "A tabela Hash está cheia!\n";
		cout << "O elemento não pode ser inserido!\n";
		return;
	}

	int local = funcaoHash(aluno);

	while (estrutura[local].obterRa() > 0) {
		local = (local+1) % maxPosicoes;
	}

	estrutura[local] = aluno;
	quantItens++; 
}

void Hash::deletar(Aluno aluno) 
{
	int local = funcaoHash(aluno);
	bool teste = false;
	while (estrutura[local].obterRa() != -1) {

		if (estrutura[local].obterRa() == aluno.obterRa()) {

			estrutura[local] = Aluno(-2, " ");
			quantItens--;

			cout << "Elemento removido!\n";
			break;

		}

		local = (local + 1) % maxPosicoes;

	}

	if (!teste) {
		cout << "O aluno não foi encontrado!\n";
		cout << "Nenhum elemento foi removido!\n";
	}

}

void Hash::buscar(Aluno& aluno, bool& busca)
{
	int local = funcaoHash(aluno);
	busca = false;

	while (estrutura[local].obterRa() != -1) {	
		if (estrutura[local].obterRa() == aluno.obterRa()) {
			busca = true;
			aluno = estrutura[local];
			break;
		}
		local = (local + 1)%maxPosicoes;	
	}
	
}

void Hash::imprimir()
{
	cout << "Tabela Hash:\n";
	for (int i = 0; i < maxItens; i++) {
		if (estrutura[i].obterRa() > 0) {
			cout << "índice " << i << ": " << "ra: " << estrutura[i].obterRa() << " - ";
			cout << "nome: " << estrutura[i].obterNome() << endl;
		}
	}
	cout << endl;
}