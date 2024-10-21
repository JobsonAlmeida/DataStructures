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

void ArvoreBinariaDeBusca::inserir(Aluno aluno) {

}

void ArvoreBinariaDeBusca::remover(Aluno aluno) {

}

void ArvoreBinariaDeBusca::buscar(Aluno& aluno, bool& busca) {

}

void ArvoreBinariaDeBusca::imprimirPreOrdem(No* NoAtual) {

}

void ArvoreBinariaDeBusca::imprimirEmOrdem(No* NoAtual) {

}

void ArvoreBinariaDeBusca::imprimirPosOrdem(No* NoAtual) {

}