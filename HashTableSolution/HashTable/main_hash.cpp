#include <iostream>
#include "hash.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Portuguese");

	int tamVetor, max;

	cout << "Programa gerador de Hash:\n\n";

	cout << "Digite o tamanho da Hash: ";
	cin >> tamVetor;

	cout << "Digite o numero maimo de elementos: ";
	cin >> max;

	cout << "O fator de carga e: " << ( (float)max / (float)tamVetor )<< "\n\n";

	Hash alunohash(tamVetor, max);
	int opcao;
	int ra;
	string nome;
	bool busca;

	do {
		cout << "Digite 0 para parar o algoritmo.\n";
		cout << "Digite 1 para inserir um elemento.\n";
		cout << "Digite 2 para remover um elemento.\n";
		cout << "Digite 3 para buscar um elemento.\n";
		cout << "Digite 4 para imprimir a Tabela Hash.\n";
		cin >> opcao;

		if (opcao == 1) {
			cout << "Qual é o ra do aluno a ser inserido?\n";
			cin >> ra;
			cout << "Qual é o nome do aluno?\n";
			cin >> nome;
			Aluno aluno(ra, nome);
			alunohash.inserir(aluno);
			cout << endl;
		}
		else if (opcao == 2) {
			cout << "Qual é o ra do aluno a ser removido?\n";
			cin >> ra;
			Aluno aluno(ra, " ");
			alunohash.deletar(aluno);
			cout << endl;
		}
		else if (opcao == 3) {
			cout << "Qual é o ra do aluno a ser buscado?\n";
			cin >> ra;
			Aluno aluno(ra, " ");
			alunohash.buscar(aluno, busca);
			if (busca) {
				cout << "Aluno encontrado:\n";
				cout << "RA: " << aluno.obterRa() << endl;
				cout << "Nome: " << aluno.obterNome() << endl;
				cout << endl;
			}
			else {
				cout << "Aluno não encontrado!\n";
				cout << endl;
			}
		}
		else if(opcao == 4){
			alunohash.imprimir();
		}
		else {
			cout << "Opção não encontrada!\n";
			cout << endl;
		}
	} while (opcao != 0);

	cout << "Programa finalizado!\n";

	return 0;
}