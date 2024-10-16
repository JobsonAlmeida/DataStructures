#include <iostream>
#include "pilhadinamica.h"
#include <cstddef> //para usar o NULL

using namespace std;

pilhadinamica::pilhadinamica() 
{
	NoTopo = NULL;
}

pilhadinamica::~pilhadinamica() 
{
	No* NoTemp;

	while (NoTopo != NULL) {
		NoTemp = NoTopo;
		NoTopo = NoTopo->proximo;
		delete NoTemp;
	}

	NoTemp = NULL; // aqui NoTopo possui o valor NULL, mas NoTemp não;

}

bool pilhadinamica::estavazio() 
{
	return (NoTopo == NULL);
}

bool pilhadinamica::estacheio() //tem memória? // isfull
{
	No* NoNovo;

	try {
		NoNovo = new No();
		delete NoNovo;
		return false;
	}
	catch(bad_alloc exception){
		return true;
	}
	
}

void pilhadinamica::inserir(TipoItem item) 
{
	if (estacheio()) {
		cout << "A pilha está cheia! É impossível inserir um novo elemento!\n\n";
	}
	else {
		No* NoNovo = new No;
		NoNovo->valor = item;
		NoNovo->proximo = NoTopo; //NoNovo->proximo armazena o mesmo endereço que está contido no ponteiro NoTopo
		NoTopo = NoNovo;
	}

}

TipoItem pilhadinamica::remover() 
{
	if (estavazio()) {
		cout << "A pilha está vazia! É impossível remover elemento!\n";
		return 0;
	}
	else {
		No* Aux = NoTopo;
		TipoItem valor = NoTopo->valor;
		NoTopo = NoTopo->proximo;
		delete Aux;
		Aux = NULL;

		return valor;
	}
}

void pilhadinamica::imprimir() 
{
	No* NoTemp = NoTopo;

	cout << "Pilha Dinâmica: [ ";

	while (NoTemp != NULL) {

		cout << NoTemp->valor << " ";
		NoTemp = NoTemp->proximo;
	}

	cout << " ]\n\n";

}