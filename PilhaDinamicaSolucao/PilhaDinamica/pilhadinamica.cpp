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


}

bool pilhadinamica::estavazio() 
{
	return (NoTopo == NULL);
}

bool pilhadinamica::estacheio() //tem mem�ria? // isfull
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
		cout << "A pilha est� cheia! � imposs�vel inserir um novo elemento!\n";
	}
	else {
		No* NoNovo = new No;
		NoNovo->valor = item;
		NoNovo->proximo = NoTopo; //NoNovo->proximo armazena o mesmo endere�o que est� contido no ponteiro NoTopo
		NoTopo = NoNovo;
	}

}

TipoItem pilhadinamica::remover() 
{
	if (estavazio()) {
		cout << "A pilha est� vazia! � imposs�vel remover elemento!\n";
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

}