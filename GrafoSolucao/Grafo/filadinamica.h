#pragma once

//Fila Dinamica = Dynamic Queue

//typedef int TipoItem;
//
//class No { // in this case we can use structure or class
//public:
//	TipoItem valor;
//	No* proximo;
//};

#include "No.h"

class filadinamica {
private:
	No* primeiro; //front
	No* ultimo; //rear

public:
	filadinamica();
	~filadinamica();
	bool estavazio();
	bool estacheio();
	void inserir(TipoItem item);
	TipoItem remover();
	void imprimir();

};