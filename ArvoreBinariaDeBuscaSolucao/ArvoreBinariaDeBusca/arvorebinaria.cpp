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
	deletarArvore(raiz);
}

void ArvoreBinariaDeBusca::deletarArvore(No* NoAtual) 
{
	if (NoAtual != NULL) {

		deletarArvore(NoAtual->filhoEsquerda);
		deletarArvore(NoAtual->filhoDireita);

		delete NoAtual;
	}
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
	removerBusca(aluno, raiz);
}

void ArvoreBinariaDeBusca::removerBusca(Aluno aluno, No*& noAtual)
{
	if (aluno.obterRa() < noAtual->aluno.obterRa()) {
		removerBusca(aluno, noAtual->filhoEsquerda);
	}
	else if (aluno.obterRa() > noAtual->aluno.obterRa()) {
		removerBusca(aluno, noAtual->filhoDireita);
	}
	else {
		deletarNo(noAtual); // Actually, noAtual is a pointer to where the equality between RA occurred. 
	}	  
}

void ArvoreBinariaDeBusca::deletarNo(No*& noAtual) 
{
	No* temp = noAtual;
	if (noAtual->filhoEsquerda == NULL) {
		noAtual = noAtual->filhoDireita;
		delete temp;
	}
	else if (noAtual->filhoDireita == NULL) {
		noAtual = noAtual->filhoEsquerda;
		delete temp;
	}
	else {
		Aluno AlunoSucessor;
		obterSucessor(AlunoSucessor, noAtual);
		noAtual->aluno = AlunoSucessor;
		removerBusca(AlunoSucessor, noAtual->filhoDireita);
	}

}

void ArvoreBinariaDeBusca::obterSucessor(Aluno& AlunoSucessor, No* temp) 
{
	temp = temp->filhoDireita;
	while (temp->filhoEsquerda != NULL) {
		temp = temp->filhoEsquerda;
	}
	AlunoSucessor = temp->aluno;
}

void ArvoreBinariaDeBusca::buscar(Aluno& aluno, bool& busca)
{
	busca = false;
	No* noAtual = raiz;
	while (noAtual != NULL) {
		if (aluno.obterRa() < noAtual->aluno.obterRa()) {
			noAtual = noAtual->filhoEsquerda;
		}
		else if(aluno.obterRa() > noAtual->aluno.obterRa()){
			noAtual = noAtual->filhoDireita;
		}
		else{
			aluno = noAtual->aluno;
			busca = true;
			break; 
		}
	}

}

void ArvoreBinariaDeBusca::imprimirPreOrdem(No* NoAtual) 
{
	if (NoAtual != NULL) {

		cout << NoAtual->aluno.obterNome() << ": ";
		cout << NoAtual->aluno.obterRa() << endl;

		imprimirPreOrdem(NoAtual->filhoEsquerda);

		imprimirPreOrdem(NoAtual->filhoDireita);
	}

}

void ArvoreBinariaDeBusca::imprimirEmOrdem(No* NoAtual) 
{
	if (NoAtual != NULL) {

		imprimirEmOrdem(NoAtual->filhoEsquerda);

		cout << NoAtual->aluno.obterNome() << ": ";
		cout << NoAtual->aluno.obterRa() << endl;

		imprimirEmOrdem(NoAtual->filhoDireita);
	}

}

void ArvoreBinariaDeBusca::imprimirPosOrdem(No* NoAtual) 
{
	if (NoAtual != NULL) {

		imprimirPosOrdem(NoAtual->filhoEsquerda);

		imprimirPosOrdem(NoAtual->filhoDireita);

		cout << NoAtual->aluno.obterNome() << ": ";
		cout << NoAtual->aluno.obterRa() << endl;
	}

}