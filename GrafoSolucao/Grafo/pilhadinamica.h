#pragma once

//Pilha Din�mica = Dynamic Stack

//typedef int TipoItem;
//
//struct No //Node
//{
//	TipoItem valor;
//	No* proximo;
//};

#include "No.h"

class pilhadinamica {
private:
	No* NoTopo;

public:
	pilhadinamica();
	~pilhadinamica();
	bool estavazio();
	bool estacheio();
	void inserir(TipoItem item);
	TipoItem remover();
	void imprimir();
};