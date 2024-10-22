#include <iostream>
#include "arvorebinaria.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Portuguese");

	ArvoreBinariaDeBusca ArvoreAlunos; 
	int opcao, ra, imp;
	string nome;
	bool busca = false;

	do 
	{
		cout << "Digite 0 para parar o algoritmos.\n";
		cout << "Digite 1 para inserir um elemento.\n";
		cout << "Digite 2 para remover um elemento.\n";
		cout << "Digite 3 para buscar um elemento.\n";
		cout << "Digite 4 para imprimir a àrvore.\n";
		cin >> opcao;

		if (opcao == 1) {
			cout << "Digite o nome do aluno: \n";
			cin >> nome;
			cout << "Digite o RA do aluno: \n";
			cin >> ra;
			Aluno aluno(ra, nome);

			ArvoreAlunos.inserir(aluno);

			cout << endl;

		}
		else if (opcao == 2){
			cout << "Digite o RA do aluno a ser removido: \n";
			cin >> ra;
			Aluno aluno(ra, " ");
			ArvoreAlunos.remover(aluno);

			cout << endl;

		}
		else if (opcao == 3) {
			cout << "Digite o RA do aluno a ser buscado: \n";
			cin >> ra;
			Aluno aluno(ra, " ");
			ArvoreAlunos.buscar(aluno, busca);
			if (busca) {
				cout << "Elemento encontrado!\n";
				cout << "Nome: " << aluno.obterNome() << endl;
				cout << "RA: " << aluno.obterRa() << endl;
			}
			else {
				cout << "Elemento não encontrado!\n";
			}

			cout << endl;

		}
		else if (opcao == 4) {
			cout << "Digite 1 para fazer a impressao em pre-ordem.\n";
			cout << "Digite 2 para fazer a impressao em ordem.\n";
			cout << "Digite 3 para fazer a impressao em pos-ordem.\n";
			cin >> imp;
			if (imp == 1) {
				ArvoreAlunos.imprimirEmOrdem(ArvoreAlunos.obterRaiz());
			}
			else if (imp == 2) {
				ArvoreAlunos.imprimirEmOrdem(ArvoreAlunos.obterRaiz());
			}
			else {
				ArvoreAlunos.imprimirPosOrdem(ArvoreAlunos.obterRaiz());
			}

			cout << endl;
		}
		else if (opcao == 0) {
			cout << "Execução do programa parada!\n";
		}
		else {
			cout << "Opção não encontrada!\n";
			cout << endl;
		}

	} while (opcao != 0);

	return 0;
}