#include <iostream>
#include <cstddef>
#include "arvorebinaria.h"

using namespace std;

ArvoreBinariaDeBusca::ArvoreBinariaDeBusca()
{
	raiz = NULL;
}

ArvoreBinariaDeBusca::~ArvoreBinariaDeBusca() 
{

}

void ArvoreBinariaDeBusca::deletarArovre(No* NoAtual) 
{

}

No* ArvoreBinariaDeBusca::obterRaiz() 
{
	return raiz;
}

bool ArvoreBinariaDeBusca::estaVazio() {
	return (raiz == NULL);
}

bool ArvoreBinariaDeBusca::estaCheio() 
{
	try {
		No* temp = new No;
		delete temp;
		return false;
	}
	catch (bad_alloc exception) {
		return true;
	}

}

void ArvoreBinariaDeBusca::inserir(Aluno aluno) 
{
	if (estaCheio()) 
	{
		cout << "A árvore está cheia!\n";
		cout << "Não foi possível inserir este elemento!\n";
	}
	else
	{
		No* NoNovo = new No;
		NoNovo->aluno = aluno;
		NoNovo->filhoDireita = NULL;
		NoNovo->filhoEsquerda = NULL;

		if (raiz == NULL) {
			raiz = NoNovo;
		}
		else {
			No* temp = raiz;
			while (temp != NULL) {
				if (aluno.obterRa() < temp->aluno.obterRa()) {
					if (temp->filhoEsquerda == NULL) {
						temp->filhoEsquerda = NoNovo;
						break;
					}
					else {
						temp = temp->filhoEsquerda;
					}
				}
				else {
					if (temp->filhoDireita == NULL) {
						temp->filhoDireita = NoNovo;
						break;
					}
					else {
						temp = temp->filhoDireita;
					}
				}
			}
		}
		 
	}

}

void ArvoreBinariaDeBusca::remover(Aluno aluno) 
{

}

void ArvoreBinariaDeBusca::buscar(Aluno& aluno, bool& busca)
{

}

void ArvoreBinariaDeBusca::imprimirPreOrdem(No* NoAtual) {

}

void ArvoreBinariaDeBusca::imprimirEmOrdem(No* NoAtual) {

}

void ArvoreBinariaDeBusca::imprimirPosOrdem(No* NoAtual) {

}