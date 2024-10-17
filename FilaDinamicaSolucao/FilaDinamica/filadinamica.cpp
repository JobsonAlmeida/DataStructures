#include <iostream>
#include "filadinamica.h"
#include <cstddef>
#include <new>

using namespace std;

filadinamica::filadinamica() { 
	primeiro = NULL;
	ultimo = NULL;
}

filadinamica::~filadinamica() {

	No* notemp;
	primeiro = NULL;

	while (!estavazio()) {

		notemp = ultimo;
		ultimo = ultimo->proximo;

		delete notemp;
	}

}

bool filadinamica::estavazio() {

	return (primeiro == NULL && ultimo == NULL);

}

bool filadinamica::estacheio() {

	try {
		No* NoTemp;
		NoTemp = new No;

		delete NoTemp;

		return false;
	}
	catch (bad_alloc exception) {		
		return true;
	}

}

void filadinamica::inserir(TipoItem item) {

	if (estacheio()) {
		cout << "A fila está cheia! Impossível inserir um novo elemento!\n";
	}
	else if (estavazio()) {
		No* noTemp = new No;
		noTemp->valor = item;
		noTemp->proximo = ultimo;
		ultimo = noTemp;
		primeiro = noTemp;
	}
	else {
		No* noTemp = new No;
		noTemp->valor = item;
		noTemp->proximo = ultimo->proximo;
		ultimo = noTemp;
	}

}

TipoItem filadinamica::remover() {

	if (estavazio()) {
		cout << "A fila está vazia! Impossível remover um elemento!\n";
	}
	else {

		No* noTemp1 = ultimo;
		No* noTemp2 = ultimo;
		int valorRetorno;

		while (noTemp1->proximo != NULL) {
			noTemp2 = noTemp1;
			noTemp1 = noTemp1->proximo;
		}

		primeiro = noTemp2;
		valorRetorno = primeiro->valor;
		delete noTemp1;

		return valorRetorno;
	}
}

void filadinamica::imprimir() {

	No* notemp = ultimo;

	cout << "Fila Dinâmica: [ ";

	while (notemp != NULL) {
		cout << notemp->valor << " ";
		notemp = notemp->proximo;
	}

	cout << " ]";
}
