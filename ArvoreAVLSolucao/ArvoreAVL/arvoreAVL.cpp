#include <iostream>
#include <cstddef>
#include "arvoreAVL.h"

using namespace std;

ArvoreAVL::ArvoreAVL()
{
	raiz = NULL;
}

ArvoreAVL::~ArvoreAVL()
{
	deletarArvore(raiz);
}

void ArvoreAVL::deletarArvore(No* NoAtual)
{
	if (NoAtual != NULL) {

		deletarArvore(NoAtual->filhoEsquerda);
		deletarArvore(NoAtual->filhoDireita);

		delete NoAtual;
	}
}

No* ArvoreAVL::obterRaiz()
{
	return raiz;
}

bool ArvoreAVL::estaVazio() {
	return (raiz == NULL);
}

bool ArvoreAVL::estaCheio()
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

void ArvoreAVL::inserir(Aluno aluno)
{
	bool cresceu;
	insereRecursivo(raiz, aluno, cresceu);
}

void ArvoreAVL::insereRecursivo(No*& noAtual, Aluno aluno, bool& cresceu)
{

	if (estaCheio())
	{
		cout << "A árvore está cheia!\n";
		cout << "Não foi possível inserir este elemento!\n";
	}
	else {

		if (noAtual == NULL) {
			noAtual = new No;
			noAtual->filhoDireita = NULL;
			noAtual->filhoEsquerda = NULL;
			noAtual->aluno = aluno;
			noAtual->fatorB = 0;
			cresceu = true;
			return;
		}
		if (aluno.obterRa() < noAtual->aluno.obterRa()) {
			insereRecursivo(noAtual->filhoEsquerda, aluno, cresceu);
			if (cresceu) {
				noAtual->fatorB -= 1;
			}
		}
		else {
			insereRecursivo(noAtual->filhoDireita, aluno, cresceu);
			if (cresceu) {
				noAtual->fatorB+= 1;
			}
		}

		realizaRotacao(noAtual);

		if (cresceu && noAtual->fatorB == 0) {
			cresceu = false;
		}
	}
}

void ArvoreAVL::remover(Aluno aluno)
{
	bool diminuiu;
	removerBusca(aluno, raiz, diminuiu);
}

void ArvoreAVL::removerBusca(Aluno aluno, No*& noAtual, bool& diminuiu)
{
	
	if (aluno.obterRa() < noAtual->aluno.obterRa()) {
		removerBusca(aluno, noAtual->filhoEsquerda, diminuiu);
		if (diminuiu) {
			noAtual->fatorB += 1;
		}
	}
	else if (aluno.obterRa() > noAtual->aluno.obterRa()) {
		removerBusca(aluno, noAtual->filhoDireita, diminuiu);
		if (diminuiu) {
			noAtual->fatorB -= 1;
		}
	}
	else {
		deletarNo(noAtual, diminuiu); // Actually, noAtual is a pointer to where the equality between RA occurred. 
	}

	if (noAtual != NULL) {
		realizaRotacao(noAtual);
		if (diminuiu && noAtual->fatorB != 0) {
			diminuiu = false;
		}
	}
}

void ArvoreAVL::deletarNo(No*& noAtual, bool& diminuiu)
{
	No* temp = noAtual;
	if (noAtual->filhoEsquerda == NULL) {
		noAtual = noAtual->filhoDireita;
		diminuiu = true;
		delete temp;
	}
	else if (noAtual->filhoDireita == NULL) {
		noAtual = noAtual->filhoEsquerda;
		diminuiu = true;
		delete temp;
	}
	else {
		Aluno AlunoSucessor;
		obterSucessor(AlunoSucessor, noAtual);
		noAtual->aluno = AlunoSucessor;
		removerBusca(AlunoSucessor, noAtual->filhoDireita, diminuiu);
		if (diminuiu) {
			noAtual->fatorB -= 1; 
		}
	}

}

void ArvoreAVL::obterSucessor(Aluno& AlunoSucessor, No* temp)
{
	temp = temp->filhoDireita;
	while (temp->filhoEsquerda != NULL) {
		temp = temp->filhoEsquerda;
	}
	AlunoSucessor = temp->aluno;
}

void ArvoreAVL::buscar(Aluno& aluno, bool& busca)
{
	busca = false;
	No* noAtual = raiz;
	while (noAtual != NULL) {
		if (aluno.obterRa() < noAtual->aluno.obterRa()) {
			noAtual = noAtual->filhoEsquerda;
		}
		else if (aluno.obterRa() > noAtual->aluno.obterRa()) {
			noAtual = noAtual->filhoDireita;
		}
		else {
			aluno = noAtual->aluno;
			busca = true;
			break;
		}
	}

}

void ArvoreAVL::imprimirPreOrdem(No* NoAtual)
{
	if (NoAtual != NULL) {

		cout << NoAtual->aluno.obterNome() << ": ";
		cout << NoAtual->aluno.obterRa() << endl;

		imprimirPreOrdem(NoAtual->filhoEsquerda);

		imprimirPreOrdem(NoAtual->filhoDireita);
	}

}

void ArvoreAVL::imprimirEmOrdem(No* NoAtual)
{
	if (NoAtual != NULL) {

		imprimirEmOrdem(NoAtual->filhoEsquerda);

		cout << NoAtual->aluno.obterNome() << ": ";
		cout << NoAtual->aluno.obterRa() << endl;

		imprimirEmOrdem(NoAtual->filhoDireita);
	}

}

void ArvoreAVL::imprimirPosOrdem(No* NoAtual)
{
	if (NoAtual != NULL) {

		imprimirPosOrdem(NoAtual->filhoEsquerda);

		imprimirPosOrdem(NoAtual->filhoDireita);

		cout << NoAtual->aluno.obterNome() << ": ";
		cout << NoAtual->aluno.obterRa() << endl;
	}

}

// Novos métodos
void ArvoreAVL::rotacaoDireita(No*& pai)
{
	No* novopai = pai->filhoEsquerda;
	pai->filhoEsquerda = novopai->filhoDireita;
	novopai->filhoDireita = pai;
	pai = novopai;
}

void ArvoreAVL::rotacaoEsquerda(No*& pai)
{
	No* novopai = pai->filhoDireita;
	pai->filhoDireita = novopai->filhoEsquerda;
	novopai->filhoEsquerda = pai;
	pai = novopai;
}

void ArvoreAVL::rotacaoDireitaEsquerda(No*& pai)
{
	No* filho = pai->filhoDireita;
	rotacaoDireita(filho);
	pai->filhoDireita = filho;
	rotacaoEsquerda(pai);
}

void ArvoreAVL::rotacaoEsquerdaDireita(No*& pai)
{
	No* filho = pai->filhoEsquerda;
	rotacaoEsquerda(filho);
	pai->filhoEsquerda = filho;
	rotacaoDireita(pai);
}

void ArvoreAVL::realizaRotacao(No*& pai)
{
	No* filho;
	No* neto;

	if (pai->fatorB == -2) // rotaciona para a direita
	{
		filho = pai->filhoEsquerda;

		if (filho->fatorB == -1) { // rotação simples para a direita
			pai->fatorB = 0;
			filho->fatorB = 0;
			rotacaoDireita(pai);
		}
		else if (filho->fatorB == 0) { // rotação simples para a direita
			pai->fatorB = -1;
			filho->fatorB = 1;
			rotacaoDireita(pai);
		}
		else if (filho->fatorB == +1) { // rotação dupla é necessária
			
			neto = filho->filhoDireita;

			if (neto->fatorB == -1) {
				pai->fatorB = 1;
				filho->fatorB = 0;
			}
			else if (neto->fatorB == 0) {
				pai->fatorB = 0;
				filho->fatorB = 0;
			}
			else if (neto->fatorB == +1) {
				pai->fatorB = 0;
				filho->fatorB = -1;
			}

			neto->fatorB = 0;

			rotacaoEsquerdaDireita(pai);
		
		}
	}
	else if (pai->fatorB == +2) //rotaciona para a esquerda
	{
		filho = pai->filhoDireita;
		if (filho->fatorB == 1) { // rotação simples para a esquerda
			pai->fatorB = 0;
			filho->fatorB = 0;
			rotacaoEsquerda(pai);
		}
		else if (filho->fatorB == 0) { // rotação simples para a esquerda         
			pai->fatorB = 1;
			filho->fatorB = -1;
			rotacaoEsquerda(pai);
		}
		else if (filho->fatorB == -1) { // rotação dupla é necessária
			neto = filho->filhoEsquerda;
			if (neto->fatorB == -1) {
				pai->fatorB = 0;
				filho->fatorB = 1;
			}
			else if (neto->fatorB == 0) {
				pai->fatorB = 0;
				filho->fatorB = 0;
			}
			else if (neto->fatorB == 1) {
				pai->fatorB = -1;
				filho->fatorB = 0;
			}

			neto->fatorB = 0;

			rotacaoDireitaEsquerda(pai);
		}
	}
}

